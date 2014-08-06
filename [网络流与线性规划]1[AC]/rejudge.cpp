#include "mode.h"
#include <windows.h>
using namespace std;
#define TEST 10
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp air%d.in sample.in",x);
     system(str);
     sprintf(str,"cp air%d.out sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 10;i<=TEST;++i)
    {
     gotou(i);
     system("ans");
     if(system("spj"))
      printf("WA:%d\n",i);
     else
      printf("AC\n");
     Sleep(3000);
     system("del sample.in");
     system("del sample.ans");
     system("del sample.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
