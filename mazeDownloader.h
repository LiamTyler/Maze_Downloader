#ifndef MAZEDOWNLOADER_H_
#define MAZEDOWNLOADER_H_

#include <string>
using std::string;

void downloadFile(char* url);
bool downloadMaze(string filename, int rows, int cols, int width,
                  int height, string type="text", string seed="");

#endif  // MAZEDOWNLOADER_H_

