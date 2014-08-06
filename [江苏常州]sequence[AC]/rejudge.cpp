#include "mode.h"

using namespace std;
#define TEST 20
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp sequence%d.in sample.in",x);
     system(str);
     sprintf(str,"cp sequence%d.out sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=TEST;++i)
    {
     gotou(i);
     double st = clock(),ed,dr;
     system("ans");
     ed = clock();
     dr = (double)(ed - st) / CLOCKS_PER_SEC;;
     if(system("fc sample.ans sample.out"))
      printf("WA:%d\n",i);
     else
     {
      if(dr > 2.0) printf("TLE\n");
      else
      printf("AC\n");
     }
     system("del sample.in");
     system("del sample.ans");
     system("del sample.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
