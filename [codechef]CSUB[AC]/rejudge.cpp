#include "mode.h"

using namespace std;
#define TEST 9
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp sample%d.in sample.in",x);
     system(str);
     sprintf(str,"cp sample%d.ans sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 0;i<=TEST;++i)
    {
     gotou(i);
     system("ans");
     if(system("fc sample.ans sample.out"))
      printf("WA:%d\n",i);
     else
      printf("AC\n");
     system("del sample.in");
     system("del sample.ans");
     system("del sample.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
