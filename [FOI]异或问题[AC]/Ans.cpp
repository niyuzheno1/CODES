#include "mode.h"
#define show(uu,vv,tt) for(int i = x;i<=vv;++i,ff(debug,"\n")) for(int j = 0;j<tt;++j,ff(debug," ")) ff(debug,"%d",uu[i][j]);
#define show2(uu,vv,tt) for(int i = x;i<=vv;++i,ff(debug,"\n")) for(int j = 0;j<tt;++j,ff(debug," ")) ff(debug,"%d:%d",uu[i][j][0],uu[i][j][1]);
const int MN = 20001,mod = 1000000007;
pair<int,pii> d[MN];
mii pp;
int n,m,a[MN],b[MN],c[MN],p[MN],va[34];
int f[MN][34],dp[MN][34][2];
bool cmp(int x,int y)
{
     return c[x]<c[y];
}
void rebuild(int x)
{
     for(int i = x;i<=n;++i)
      for(int j = 0;j<31;++j)
       f[b[i]][j] = 0;
     for(int i = x;i<=n;++i)
      for(int j = 0;j<31;++j)
       f[b[i]][j] = f[b[i-1]][j]^(a[b[i]] & (1<<j));
     show(f,n,31);
     /*CLEAR(dp,0),*/dp[0][0][0] = 1;
     for(int i = x;i<=n;++i)
      for(int j =0;j<31;++j)
       dp[b[i]][j][0] = dp[b[i]][j][1] = 0;
     for(int i = x;i<=n;++i)
      for(int j =0;j<31;++j)
       for(int s = 0;s<2;++s)
       {
        if(dp[b[i-1]][j][s]==0) continue;
        for(int k = 0;k<31;++k)
         if(a[b[i]]&(1<<k))
         {
          int o,u,c;
          if(k > j) o = j,u= k,c = (f[b[i-1]][k]?1:0);
          else
          {
           int tm = (k == j?0:a[b[i]]  &(1<<j));
           o = k,u = j,c = s^(tm?1:0);
          }
          dp[b[i]][u][c] = ((int64)(dp[b[i-1]][j][s])*(int64(1)<<int64(o))+dp[b[i]][u][c])%mod;
         }
       }
      show2(dp,n,31);
}
int ok(int t)
{
  int ans = 0;
  va[31] = 1;
  for(int i = 30;i>=0;--i) va[i] = va[i+1]&&(f[b[n]][i]==(t&(1<<i)));
  for(int i = 30;i>=0;--i)
  {
      if(va[i+1]) ans = (ans+dp[b[n]][i][(t&(1<<i))?1:0])%mod;
      else break;
  }
  return ans;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    for(int i = 1;i<=n;++i) a[i] = gi,++a[i],b[i] = i;
    p[0] = 1;
    for(int i = 1;i<=32;++i) p[i] = p[i-1]*2;
    for(int i = 1;i<=m;++i){ d[i].X = gi,d[i].Y.X = gi;
     if(d[i].X == 1) d[i].Y.Y = gi,c[d[i].Y.X] = 1;
    }
    sort(b+1,b+1+n,cmp);
    for(int i = 1;i<=n;++i)
     pp[b[i]] = i;
    rebuild(1);
    for(int i = 1;i<=m;++i)
    {
     if(d[i].X == 1){
     a[d[i].Y.X] = d[i].Y.Y+1;
     rebuild(pp[d[i].Y.X]-1);
     }else
      printf("%d\n",ok(d[i].Y.X));
    }
    closeIO();
    return EXIT_SUCCESS;
}
