#include "mode.h"
#include "iodata.h"

using namespace std;
#define ML 1032323
int main(int argc, char *argv[])
{
    init("sample.in");
    printf("1 1\n");
    for(int i = 1;i<=1;++i,puts(""))
     for(int j = 1;j<=1-1;++j,printf(" "))
      printf("%d",rand()%ML);
    for(int i = 1;i<=1-1;++i,puts(""))
     for(int j = 1;j<=1;++j,printf(" "))
      printf("%d",rand()%ML);
    for(int i = 1;i<=1-1;++i,puts(""))
     for(int j = 1;j<=1-1;++j,printf(" "))
      printf("%d",rand()%ML);
    closeIO();
    return EXIT_SUCCESS;
}
