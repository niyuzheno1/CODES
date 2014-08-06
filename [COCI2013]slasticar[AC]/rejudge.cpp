#include "mode.h"

using namespace std;
#define TEST 15
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp slasticar.in.%d sample.in",x);
     system(str);
     sprintf(str,"cp slasticar.out.%d sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=TEST;++i)
    {
     gotou(i);
     system("ans");
     if(system("spj"))
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
