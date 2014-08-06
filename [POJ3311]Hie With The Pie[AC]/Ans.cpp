#include "mode.h"
int dis[12][12];
int dp[1<<11][12];
int n,ans,_min;
int main(int argc, char *argv[])
{
    setIO("sample");
    while(scanf("%d",&n) && n)
    {
        for(int i = 0;i<=n;++i)
         for(int j = 0;j<=n;++j)
          scanf("%d",&dis[i][j]);
         for(int k = 0;k<=n;++k)
          for(int i = 0;i<=n;++i)
           for(int j = 0;j<=n;++j)
            dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);             
        int All = (1<<n)-1;
        for(int S = 0;S<=All;++S)
         for(int i = 1;i<=n;++i)
         {
                 if(S & (1<<(i-1)))
                 {
                  if(S == (1<<(i-1)))  dp[S][i] = dis[0][i];
                  else {
                   dp[S][i] = INF;
                   for(int j = 1;j<=n;++j)
                    if((S&(1<<(j-1))) && j != i)
                     dp[S][i] = min(dp[S][i],dis[j][i]+dp[S^(1<<(i-1))][j]);
                  }
                 }
         }
       ans = dp[All][1]+dis[1][0];
       for(int i = 2;i<=n;++i)
       ans = min(ans,dp[All][i]+dis[i][0]);
       printf("%d\n",ans);
    }
    closeIO();
    return EXIT_SUCCESS;
}
