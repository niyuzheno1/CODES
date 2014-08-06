#include "mode.h"
#define show(uu,vv,tt) for(int i = 1;i<=vv;++i,ff(debug,"\n")) for(int j = 0;j<tt;++j,ff(debug," ")) ff(debug,"%d",uu[i][j]); 
#define show2(uu,vv,tt) for(int i = 1;i<=vv;++i,ff(debug,"\n")) for(int j = 0;j<tt;++j,ff(debug," ")) ff(debug,"%d:%d",uu[i][j][0],uu[i][j][1]);
const int mod = 1000000003,MN = 60,MX = 40;
int n,t,m[MN],f[MN][MX],dp[MN][MX][2],va[MX],ans;
int main(int argc, char *argv[])
{
    setIO("sample");
    while(true)
    {
     n = gi,t = gi,ans = 0,va[31] = 1;
     if(n == t && t== 0)
      break;
     for(int i = 1;i<=n;++i) m[i] = gi,++m[i];
     for(int i = 1;i<=n;++i)
      for(int j = 0;j<31;++j)
       f[i][j] = f[i-1][j]^(m[i] & (1<<j));
     show(f,n,31);
     for(int i = 30;i>=0;--i) va[i] = va[i+1]&&(f[n][i]==(t&(1<<i)));
     CLEAR(dp,0),dp[0][0][0] = 1;
     for(int i = 1;i<=n;++i)
      for(int j =0;j<31;++j)
       for(int s = 0;s<2;++s)
       {
        if(dp[i-1][j][s]==0) continue;
        for(int k = 0;k<31;++k)
         if(m[i]&(1<<k))
         {
          int a,b,c;
          if(k > j) a = j,b= k,c = (f[i-1][k]?1:0);
          else
          {
           int tm = (k == j?0:m[i]  &(1<<j));
           a = k,b = j,c = s^(tm?1:0);
          }
          dp[i][b][c] = ((int64)(dp[i-1][j][s])*(int64(1)<<int64(a))+dp[i][b][c])%mod;
         }
       }
     show2(dp,n,31);
     int ans = 0;
     for(int i = 30;i>=0;--i)
     {
      if(va[i+1]) ans = (ans+dp[n][i][(t&(1<<i))?1:0])%mod;
      else break;
     }
     printf("%d\n",ans);  
    }
    closeIO();
    return EXIT_SUCCESS;
}
