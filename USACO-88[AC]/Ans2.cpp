#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int in[13];
int dp[13][1<<12];
int r,c,c2;
vector<int> va;
int mod = 100000000;
int main(int argc, char *argv[])
{
    freopen("cowfood.in","r",stdin);
    freopen("cowfood.out","w",stdout);
    scanf("%d%d",&r,&c);
    c2 = 1<<c;
    for(int i = 1;i<=r;i++)
     for(int j = 1;j<=c;j++)
     {
      int x;
      scanf("%d",&x);
      if(!x) in[i] |= 1<<(j-1);
     }
    for(int i = 0;i<c2;i++)
     if(!(i &(i<<1)))
      va.push_back(i);
    for(int i = 0;i<c2;i++)
     dp[0][i] = 1;
    for(int i = 1;i<=r;i++){
         for(int j = 0;j<c2;j++){
          if(~j & in[i]) continue;
          for(int k = 0;k<va.size();k++){
          int u = va[k];
          if(u & j) continue;
          dp[i][j] += dp[i-1][u | in[i-1]];
          dp[i][j] %= mod;
          }
         }        
    }
    printf("%d",dp[r][in[r]]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
