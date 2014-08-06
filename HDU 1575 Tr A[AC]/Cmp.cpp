#include "mode.h"

using namespace std;
char str[50];
void recycle(int & x)
{
     sprintf(str,"cp sample.in sample%d.in",x);
     system(str);
     ++x;
}
int main(int argc, char *argv[])
{
    int u = 0;
    while(true)
    {
    system("data");
    system("brute");
    system("cp sample.out sample.ans");
    clock_t start, finish;
    double duration;
    start = clock();
    system("ans");
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
     if(system("fc sample.out sample.ans")==0)
      puts("AC");
     else
      puts("WA"),recycle(u);
     if(u == 10)
      break;
    }
    return EXIT_SUCCESS;
}
