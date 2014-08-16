#include "mode.h"

int main(int argc, char *argv[])
{
    freopen("sample.in","w",stdout);
    puts("1000000 1000000");
    for(int i = 1;i<=1000000;++i)
     printf("%d ",i);
    printf("\n");
    for(int i = 1;i<=1000000-1;++i)
     printf("Cut 1 500000 1\n");
    printf("Print 1");
    return EXIT_SUCCESS;
}
