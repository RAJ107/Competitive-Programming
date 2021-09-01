#include <fstream>
#include <iostream>
using namespace std;

int main()

{
  int width = 100, height = 100;

  int count = 0;
  for (int z = 0; z < 5; z++)
  {
    ofstream img("img_" + to_string(z+1) + ".pgm");
    img << "P2" << endl;
    img << width << ' ' << height << endl;
    img << "255" << endl;
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        img << 255 << " ";
      }
      img << endl;
    }
  }
  return 0;
}