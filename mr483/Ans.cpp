#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
const int in = 0x7f7f7f7f;
int n,k;
int f[11][11][32];
int g[11][1010];
char inf[101],ouf[101];
int dfs(int x,int y)
{
    if(y == k+1)
    {
      if(x == n)
       return 0;
      else
       return in;
    }
    if(g[x][y])
     return g[x][y];
    int ans = in;
    for(int i = 1;i<=n;i++)
    {
     int delta = (y%f[x][i][0])+1;
     if(f[x][i][delta] != 0)
     ans = min(ans,dfs(i,y+1)+f[x][i][delta]);
    }
    return g[x][y] = ans;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(f);
    zero(g);
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr483.in%d",cani);
    sprintf(ouf,"mr483.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      if(i != j)
      {
      int d = 0;
      scanf("%d",&d);
      f[i][j][0] = d;
      for(int k = 2;k<=d;k++)
       scanf("%d",&f[i][j][k]);
      scanf("%d",&f[i][j][1]);
      }
      else
       f[i][j][0] = 1;
    printf("%d",dfs(1,1));
    fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
