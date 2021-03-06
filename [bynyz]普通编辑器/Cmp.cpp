#include "mode.h"

using namespace std;
char str[50];
void recycle(int & x)
{
     sprintf(str,"cp sample.in sample%d.in",x);
     system(str);
     sprintf(str,"cp sample.ans sample%d.ans",x);
     system(str);
     ++x;
}
int main(int argc, char *argv[])
{
    int u = 0;
    while(true)
    {clock_t start, finish;
    double duration;
    system("data");
    start = clock();
    system("ans3");
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    system("cp sample.out sample.ans");
    
    start = clock();
    system("ans2");
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
     if(system("fc sample.out sample.ans")==0){
      if(duration > 1)
       puts("TLE"),recycle(u);
      else
       puts("AC"),recycle(u);
     }else
      puts("WA"),recycle(u);
     if(u == 1)
      break;
    }
    return EXIT_SUCCESS;
}
