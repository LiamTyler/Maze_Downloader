#include "maze.h"
#include "mazeDownloader.h"
#include <fstream>

using namespace std;

Maze::Maze() {
    map = nullptr;
    filename = "maze.txt";
    rows = 15;
    cols = 15;
    width = 3;
    height = 2;
    type = "text";
    seed = "";
    player = Character();
}

Maze::~Maze() {
    for (int r = 0; r < rows * height + 1; r++) {
        delete map[r];
    }
    delete map;
}

bool Maze::Download() {
    return downloadMaze(filename, rows, cols, width, height);
}

void Maze::Update() {
    const int endR = rows * height - 1;
    const int endC = cols * width - 1;

    int x = player.getX();
    int y = player.getY();
    int dx, dy;
    player.Input(dx, dy);
    int nr = max(0, min(rows * height, y + dy));
    int nc = max(0, min(cols * width, x + dx));
    if (map[nr][nc] == ' ') {
        player.Move(nc, nr);
        if (nr == endR && nc == endC)
            complete = true;
    }
}

void Maze::ParseMazeOut() {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Could not open file: " << filename << endl;
        return;
    }
    map = new char*[rows * height + 1];
    for (int r = 0; r < rows*height + 1; r++)
        map[r] = new char[cols * width + 1];

    string line;
    do {
        getline(file, line);
    } while(line.find("<pre>") == string::npos);

    for (int r = 0; r < rows * height + 1; r++) {
        getline(file, line);
        for (int c = 0; c < cols * width + 1; c++) {
            map[r][c] = line[c];
        }
    }
    file.close();
}

ostream& operator<<(ostream& out, const Maze& m) {
    int px = m.player.getX();
    int py = m.player.getY();
    for (int r = 0; r < m.rows * m.height + 1; r++) {
        for (int c = 0; c < m.cols * m.width + 1; c++) {
            if (r == py && c == px) {
                cout << m.player;
            } else {
                cout << m.map[r][c];
            }
        }
        cout << endl;
    }
    return out;
}

istream& operator>>(istream& in, Maze& m) {
    cout << "Please enter in the filename, rows, cols, width, height" << endl;
    return in >> m.filename >> m.rows >> m.cols >> m.width >> m.height;
}
