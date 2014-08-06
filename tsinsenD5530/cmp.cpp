#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
char file[11];
int main(int argc, char *argv[])
{
    int test = 0;
    while(test <= 10)
    {
     system("data");
     system("Ans");
     system("test");
     int ret = system("fc tsinsenD5530.ans tsinsenD5530.out");
     if(ret != 0)
     {
      test++;
      sprintf(file,"cp tsinsenD5530.in tsinsenD5530%d.in",test);
      system(file);
     }
    }
    return EXIT_SUCCESS;
}
