#include "mode.h"
char str[50];
int main(int argc, char *argv[])
{
    for(int i = 1;i<=20;++i)
    {
     sprintf(str,"cp 2048%d.out 2048.in",i);
     system(str);
     system("msl");
     sprintf(str,"cp 2048.out 2048%d.txt",i);
     system(str);
    }
    return EXIT_SUCCESS;
}
