#include "mode.h"
const int MN = 100100;
int64 a[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi;
    for(int i = 1;i<=n;++i) a[i] = gi;
    int64 x= 0,y = 0;
    for(int i = 2;i<=n;++i)
    {
    int64 b = a[i]-a[i-1];
    if(b > 0) x+=b;
    else  y-=b;
    }
    int64 ans = 0;
    if(x > y)
     printf(I64D,x),ans = x-y;
    else
     printf(I64D,y),ans = y-x;
    puts("");
    printf(I64D,ans+1);
    closeIO();
    return EXIT_SUCCESS;
}
