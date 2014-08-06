#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#define X first
#define Y second
using namespace std;
const int inf = 0x7f7f7f7f;
typedef pair<int,int> pr;
int mp[110][110];
int f[15][65536];
int n,m,k;
int b[15];
queue<pr> q;
int main(int argc, char *argv[])
{
    freopen("cavecow1.in","r",stdin);
    freopen("cavecow1.out","w",stdout);
    memset(mp,0xfe,sizeof(mp));
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=k;i++)
     scanf("%d",&b[i]);
    for(int i = 1;i<=m;i++)
    {
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     mp[x][y] = z;
     mp[y][x] = z;
    }
    for(int i = 1;i<=n;i++)
     mp[i][i] = inf;
    for(int p = 1;p<=n;p++)
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=n;j++)
       if(i != j && j != p && p != i)
       mp[i][j] = max(mp[i][j],min(mp[i][p],mp[p][j]));
    int s = 1<<(k+1);
    s--;
    memset(f,0xfe,sizeof(f));
    f[0][1] = 0;
    b[0] = 1;
    q.push(pr(0,1));
    while(!q.empty())
    {
     pr p = q.front();q.pop();
     for(int i = 0;i<=k;i++)
      if((p.Y & (1<<i)) == 0)
       if(mp[b[p.X]][b[i]] >= f[p.X][p.Y])
        if(f[p.X][p.Y]+1 > f[i][(p.Y | (1<<i))])
        {
        f[i][(p.Y | (1<<i))] = f[p.X][p.Y]+1;
        q.push(pr(i,(p.Y | (1<<i))));
        }
        
    }
    /*for(int i = 0;i<=k;i++)
     for(int j = 0;j<=s;j++)
      for(int l = 0;l<=k;l++)
       if((j & (1<<l)) == 0)
        if(mp[b[i]][b[l]] >= f[i][j])
        f[l][(j | (1<<l))] = max(f[l][(j | (1<<l))],f[i][j]+1);*/
    int ans = 0;
    for(int i = 0;i<=k;i++)
     for(int j = 0;j<=s;j++)
      if(f[i][j] > ans && mp[b[i]][1] >= f[i][j])
       ans = f[i][j];
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
