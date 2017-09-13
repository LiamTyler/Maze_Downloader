#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char* argv[]) {
    Maze m;
    cin >> m;
    m.Download();
    m.ParseMazeOut();
    cout << m;

    return 0;
}
