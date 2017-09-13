#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char* argv[]) {
    Maze m;
    cin >> m;
    m.Download();
    m.ParseMazeOut();

    while (!m.Complete()) {
        cout << m;
        m.Update();
        cout << endl;
    }
    cout << endl << "You win!!!" << endl;

    return 0;
}
