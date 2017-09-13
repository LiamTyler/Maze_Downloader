#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>
#include <string>
#include "character.h"

using std::string;

class Maze {
 public:
  Maze();
  ~Maze();
  bool Download();
  void ParseMazeOut();
  void Update();
  bool Complete() { return complete; }
  friend std::ostream& operator<<(std::ostream& out, const Maze& m);
  friend std::istream& operator>>(std::istream& in, Maze& m);

 private:
  char** map;
  string filename;
  int rows;
  int cols;
  int width;
  int height;
  // defaults already provided
  string type;
  string seed;

  bool complete;
  Character player;

};

#endif  // MAZE_H_

