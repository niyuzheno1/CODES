#include "mode.h"
#define MN 3010
typedef pair<int,pii> piii;
piii v[MN];
int n ,times[MN],x[MN],fa[MN],xsum;
int gf(int x)
{
    if(x == fa[x]) return x;
    return gf(fa[x]);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int i = 1;n = gi;
    for( i = 1;i<=n-1;++i) v[i].Y.X = gi,v[i].Y.Y = gi,v[i].X = gi;
    sort(v+1,v+n);
    for( i = 1;i<=n;fa[i]=i,++i){
     times[i] = x[i] = gi;xsum+=x[i];++times[i];
    }
    for(i =1;i<=n-1;++i){
     times[gf(v[i].Y.Y)] += times[gf(v[i].Y.X)];
     fa[gf(v[i].Y.X)] = fa[gf(v[i].Y.Y)];
     if(times[gf(v[i].Y.Y)] > xsum)
      break;
    }
    printf("%d",v[i].X);
    closeIO();
    return EXIT_SUCCESS;
}
