#include "mode.h"
typedef long long LL;
int T;
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d",&T);
    while(T--)
    {
     LL x,y;
     scanf(I64D,&x);
     scanf(I64D,&y);
     printf(I64D,abs(x)+abs(y));puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
