#include "mode.h"

using namespace std;
#define TEST 10
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp eliminate%d.in sample.in",x);
     system(str);
     sprintf(str,"cp eliminate%d.ans sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=TEST;++i)
    {
     gotou(i);
     system("ans");
     system("eliminate_e sample.in sample.out sample.ans");
     freopen("hp_eval.score","r",stdin);
     char c;
     while (~(c=getchar()))
      printf("%c",c);
     fclose(stdin);
     system("del sample.in");
     system("del sample.ans");
     system("del sample.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
