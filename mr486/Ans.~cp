#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#define X first
#define Y second
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
typedef pair<int,int> p;
int n,k;
vector<p> m[101][101];
int f[101][101];
char inf[101],ouf[101];
int ans = 0;
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr486.in%d",cani);
    sprintf(ouf,"mr486.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    for(int i = 0;i<=100;i++)
     for(int j = 0;j<=100;j++)
      m[i][j].clear();
    n = k = 0;
    memset(f,0x7f,sizeof(f));
    f[0][1] = 0;
    ans = 0x7f7f7f7f;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     scanf("%d",&k);
     for(int j = 1;j<=k;j++)
     {
     int x,y;
     while(true){
      scanf("%d",&x);
      if(x == 0)
       break;
      scanf("%d",&y);
      m[i][j].push_back(p(x,y));
      }
     }
     m[i][0].push_back(p(k,0));
    }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m[i][0][0].X;j++){
      for(int k = 0;k<m[i][j].size();k++)
       if(f[i][j] > f[i-1][m[i][j][k].X]+m[i][j][k].Y)
        f[i][j] = f[i-1][m[i][j][k].X]+m[i][j][k].Y;
     if(i == n)
      ans = min(ans,f[i][j]);
     }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
