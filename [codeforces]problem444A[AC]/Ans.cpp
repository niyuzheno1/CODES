#include "mode.h"
#include "algorithm.h"
#define MN 510
int n,m;
double a[MN];
double ans = 0.0;
int main(int argc, char *argv[])
{
    setIO("sample");
    cin>>n>>m;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1,x,y;i<=m;++i)
    {
     double c = 0.0;
     cin>>x>>y>>c;
     up(ans,(a[x]+a[y])/c);
    }
    printf("%.9lf",ans);
    closeIO();
    return EXIT_SUCCESS;
}
