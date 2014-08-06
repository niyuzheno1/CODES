#include "mode.h"
const int MN =  110;
int  n;
ld p[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 0;i<n;++i) scanf("%lf",&p[i]);
    sort(p,p+n);
    reverse(p,p+n);
    ld c0 = 1.0,c1 = 0.0;
    ld res  = -1.0;
    for(int i = 0;i<n;++i)
    {
     ld pl = p[i];
     c1 *= (1-pl);
     c1 += pl*c0;
     c0 *= (1-pl);
     res = max(res,c1);
    }
    printf("%.10f",res);
    closeIO();
    return EXIT_SUCCESS;
}
