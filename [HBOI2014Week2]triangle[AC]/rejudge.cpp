#include "mode.h"

using namespace std;
#define TEST 9
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp triangle%d.in sample.in",x);
     system(str);
     sprintf(str,"cp triangle%d.out sample.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=TEST;++i)
    {
     gotou(i);
     system("ans");
     if(system("SPJ_Cena") == -1){
      printf("WA:%d",i);system("PAUSE");
      break;
     }
     sprintf(str,"cp result.txt triangle%d.res",i);
     system(str);
     system("del sample.in");
     system("del sample.ans");
     system("del sample.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
