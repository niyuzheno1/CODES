#include "mode.h"

using namespace std;
#define TEST 20
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp pyramid%d.in sample.in",x);
     system(str);
     sprintf(str,"cp pyramid%d.out sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=TEST;++i)
    {
     gotou(i);
     clock_t start, finish;
     double duration;
     start = clock();
     system("ans");
     finish = clock();
     duration = (double)(finish - start) / CLOCKS_PER_SEC;
     printf( "%f seconds\n", duration );
     if(system("fc sample.ans sample.out"))
      printf("WA:%d\n",i);
     else if(duration > 1.0)
      printf("TLE:%d\n",i);
     else
      printf("AC\n");
     system("del sample.in");
     system("del sample.ans");
     system("del sample.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
