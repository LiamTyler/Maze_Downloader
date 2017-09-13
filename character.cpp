#include <iostream>
#include "character.h"

using namespace std;

Character::Character() {
    symbol = 'X';
    x = 0;
    y = 1;
}

Character::Character(char sym, int sx, int sy) {
    symbol = sym;
    x = sx;
    y = sy;
}

ostream& operator<<(ostream& out, const Character& c) {
    return out << c.symbol;
}

void Character::Input(int& dx, int& dy) {
    char key;
    cin >> key;
    dx = 0; dy = 0;
    switch(key) {
        case 'w':
            dy = -1;
            break;
        case 's':
            dy = 1;
            break;
        case 'a':
            dx = -1;
            break;
        case 'd':
            dx = 1;
            break;
    }
}
    
void Character::Move(int nx, int ny) {
    x = nx;
    y = ny;
}
