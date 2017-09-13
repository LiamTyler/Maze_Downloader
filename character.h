#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <iostream>

class Character {
 public:
  Character();
  Character(char sym, int nx, int ny);
  friend std::ostream& operator<<(std::ostream& out, const Character& c);
  inline int getX() const { return x; }
  inline int getY() const { return y; }
  void Input(int& dx, int& dy);
  void Move(int dx, int dy);

 private:
  char symbol;
  int x;
  int y;

};

#endif  // CHARACTER_H_

