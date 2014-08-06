#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#define X first
#define Y second
#define lc(y) ((y-1)*2)
#define uc(y) (y*2)
using namespace std;
typedef map<int,int> mpii;
const int maxn = 13,mod = 4;
int n,m;
bool mp[maxn][maxn];
mpii dp[maxn][maxn];
char str[maxn];
void tran(int x,int y,int a,int b,int c)
{
 if(y == 1)
 {
  if((c% mod) == 2 || ((c>>(2*m))%mod>=1 &&(c>>(2*m))%mod <=2))
   return;
  int nw = c;nw>>=4;nw<<=4;
  int sy;
  if(c% mod == 1)
  {
   sy = nw;
   sy |= 1;
   dp[x][y][sy] += dp[a][b][c];
   sy = nw;
   sy |= ((2)<<2);
   dp[x][y][sy] += dp[a][b][c];
  }
  if((c % mod) == 0 || (c % mod) == 3)
  {
   sy = nw;
   sy |= 1;sy |= ((2)<<2);
   dp[x][y][sy] += dp[a][b][c];
  }
 }
 if(y != 1)
 {
 }
}
int main(int argc, char *argv[])
{
    freopen("ural1519.in","r",stdin);freopen("ural1519.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 0;i<=n+1;i++)
     for(int j = 0;j<=m+1;j++)
      mp[i][j] = 1;
    for(int i = 1;i<=n;i++)
    {
     scanf("%s",&str[1]);
     for(int j = 1;j<=m;j++)
      if(str[j] == '*')
       mp[i][j] = 1;
    }
    int l,r;
    for(l = 1;l<=n;l++){
     for(r = 1;r<=m;r++)
      if(mp[l][r] == 0)
       break;
     if(r <= m)
      break;
    }
    if(r == m)
     printf("%d\n",0);
    else{
    int mm = (1<<(2*(m+1)))-1;
    mm ^= (3<<lc(r));
    mm ^= (3<<uc(r));
    mm |= (1<<lc(r));
    mm |= (2<<uc(r));
    dp[l][r][mm] = 1;
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
       for(mpii::iterator it = dp[i][j].begin();it != dp[i][j].end();it++)
       {
        int z = (*it).X;
        if(j != m)
         tran(i,j+1,i,j,z);
        else
         tran(i+1,1,i,j,z);
       }
    printf("%d\n",dp[n+1][1][0]);
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
