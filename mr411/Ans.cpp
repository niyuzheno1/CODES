#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n,m;
int q[101*101],tot;
bool map[110][2*110+10];
int dfs(int x,int y,int z)
{
    if(x > n)
     return 0; 
    for(int i = y;i<=y+z*2;i++)
     if(map[x][i])
      return 0;
     
    int ans = 0;
    for(int i = y;i<=y+z*2;i++)
     map[x][i] = 1,ans++;
    ans = ans + dfs(x+1,y,z+1);
    return ans;
    
}
bool cmp(int x,int y)
{
     return x > y;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
    for(int cani = 0;cani<=0;cani++){
    memset(q,0,sizeof(q));
    memset(map,0,sizeof(map));
    tot = n = m= 0;
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr411.in%d",cani);
    sprintf(ouf,"mr411.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     map[x][y] = 1;
    }
    for(int i = 1;i<=n;i++)
     for(int j = 2*i-1;j<=2*i-1;j++)
      if(!map[i][j] && j%2 == 1)
      {
       tot++;
       q[tot] = dfs(i,j,0);
      }
    sort(q+1,q+1+tot,cmp);
    printf("%d\n",q[1]+q[2]);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
