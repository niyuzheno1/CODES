#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define rep(i,n) for(int i = 1;i<=n;i++)
#define per(i,n) for(int i = n;i>=1;i--)
using namespace std;
char a[101],b[101];
int n;
int dp[101][101];
int ans[101];
int main(int argc, char *argv[])
{
    for(int i = 1;i<=100;i++){
     ans[i] = 100000;
     for(int j = 1;j<=100;j++)
      dp[i][j] = 100000;
    }
    scanf("%s%s",&a[1],&b[1]);
    n = strlen(&a[1]);
    rep(i,n)
     rep(j,n)
      if(i < j)
       dp[i][j] = j-i+1;
    per(i,n-1)
     rep(j,n)
      if(i < j)
      {
       dp[i][j] = dp[i+1][j]+1;
       for(int k= i+1;k<=j;k++)
        if(a[i] == a[k])
         dp[i][j] = min(dp[i][j],dp[i+1][k-1]+dp[k][j]);
      }
    rep(i,n)
    {
     ans[i] = dp[1][i];
     if(a[i] == b[i])
      ans[i] = ans[i-1];
     for(int j = 1;j<i;j++)
      ans[i] = min(ans[i],ans[j]+dp[j+1][i]);
    }
    printf("%d\n",ans[n]);
    system("PAUSE");
    return EXIT_SUCCESS;
}
