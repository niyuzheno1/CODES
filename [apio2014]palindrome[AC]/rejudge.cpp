#include "mode.h"

using namespace std;
#define TEST 18
char str[50];
void gotou(int & x)
{
     sprintf(str,"cp %02d palindrome.in",x);
     system(str);
     system("ans2");
     sprintf(str,"cp palindrome.out palindrome.ans",x);
     system(str);
}
int main(int argc, char *argv[])
{
    for(int i = 1;i<=TEST;++i)
    {
     gotou(i);
     system("ans");
     if(system("fc palindrome.ans palindrome.out"))
      printf("WA:%d\n",i);
     else
      printf("AC\n");
     system("del palindrome.in");
     system("del palindrome.ans");
     system("del palindrome.out");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
