#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <map>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n;
typedef pair<int,int> p;
map<p,int> f;
int v[17][17];
int u;
int dfs(int x,int y)
{
    if(y == 0)
     return 0;
    if(f[p(x,y)])
     return f[p(x,y)];
    int ans = 0x7f7f7f7f;
    for(int i = 1;i<=n;i++)
     if((y & (1<<(i-1))) != 0)
      ans = min(ans,dfs(i,(y & (~(1<<(i-1)))))+v[x][i]);
     f[p(x,y)] = ans;
     return ans;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    zero(v);
    f.clear();
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr490.in%d",cani);
    sprintf(ouf,"mr490.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      scanf("%d",&v[i][j]);
    u = (1<<n)-1;
    int ans = 0x7f7f7f7f;
    for(int i = 0;i<n;i++)
     ans = min(ans,dfs(i+1,u & (~(1<<i))));
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
