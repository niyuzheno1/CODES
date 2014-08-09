#include "mode.h"

using namespace std;
#define TEST 76
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp %02d sample.in",x);
     system(str);
     sprintf(str,"cp %02d.a sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=TEST;++i)
    {
     gotou(i);
     clock_t st , ed;
     st = clock();
     system("ans");
     ed = clock();
     double dur = (double)(ed - st) / CLOCKS_PER_SEC;
     printf( "%f seconds\n", dur );
  
     system("test sample.in sample.out sample.ans");
     system("del sample.in");
     system("del sample.ans");
     system("del sample.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
