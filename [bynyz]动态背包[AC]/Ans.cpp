#include "mode.h"
#include "data.h"

#define MN 110
#define ML 10
#define MV 100010

int f[ML][MV],ans[MN],v[MN],c[MN],n,m,V,lastans;

void dfs(CDQVAR,int d)
{
 if(_l == _r)
 {
  ans[_l] = f[d][V];return;
 }M;
 memcpy(f[d+1],f[d],sizeof(f[d]));
 for(int i = mid+1;i<=_r;++i)
  for(int j = v[i];j<=V;++j)
   f[d+1][j] = max(f[d+1][j],f[d+1][j-v[i]]+c[i]);
 dfs(GOLEF,d+1);
 memcpy(f[d+1],f[d],sizeof(f[d]));
 for(int i = _l;i<=mid;++i)
  for(int j = v[i];j<=V;++j)
   f[d+1][j] = max(f[d+1][j],f[d+1][j-v[i]]+c[i]);
 dfs(GORIG,d+1);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi,V= gi;
    for(int i = 1;i<=n;++i) v[i] = gi,c[i] = gi;
    dfs(1,n,1);
    for(int i = 1;i<=m;++i)
    {
     int k = gi;k^=lastans;
     printf("%d\n",(lastans = ans[k]));
    }
    closeIO();
    return EXIT_SUCCESS;
}
