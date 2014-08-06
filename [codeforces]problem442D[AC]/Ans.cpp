#include "mode.h"
#define MN 1100000
int n;
int dp[MN],max1[MN],fa[MN],max2[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 2;i<=n+1;++i){
     fa[i] = gi;
     dp[i] = 1;
     int t = i;
     while(t != 1){
             if(dp[t] > max1[fa[t]]) max2[fa[t]] = max1[fa[t]],max1[fa[t]] = dp[t];
             else max2[fa[t]] = max(max2[fa[t]],dp[t]);
             t = fa[t];
             if(max(max1[t],max2[t]+1)==dp[t]) break;
             dp[t] = max(max1[t],max2[t]+1);
     }
     printf("%d ",max1[1]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
