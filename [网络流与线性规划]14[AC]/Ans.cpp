#include "mode.h"
#undef INF 
#define MK 1<<9+10
#define MN 12
const int dx[] = {0,1,-1,0,0};
const int dy[] = {0,0,0,1,-1};
#define INF 0x7f7f7f7f
typedef vector<int> vi;
typedef pair<pii,pii> pir; 
typedef pair<pii,int> hu;
typedef map<pir,int> mpp;
typedef map<pii,vi> mp2;
mpp a;
mp2 b;
int f[MK][MN][MN];
int n,m,p,k,s;
bool range(int x,int y){
 return x>=1 && x<=n && y <= m && y >= 1;
}
int ans = INF;
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d%d%d",&n,&m,&p);
    scanf("%d",&k);
    for(int i = 1;i<=k;++i)
    {
     int x1,y1,x2,y2,g;
     scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
     if(g == 0) g = -1;
     a[MP(MP(x1,y1),MP(x2,y2))] = g;
     a[MP(MP(x2,y2),MP(x1,y1))] = g;
    }
    scanf("%d",&s);
    for(int i = 1;i<=s;++i)
    {
     int x,y,q;
     scanf("%d%d%d",&x,&y,&q);
     b[MP(x,y)].pb(q-1);
    }
    CLEAR(f,0x7f);
    queue<hu> q;
    int key = 0;
    for(int i = 0;i<b[MP(1,1)].size();++i)
     key |= (1<<b[MP(1,1)][i]);
    q.push(MP(MP(1,1),key));
    f[0][1][1] = 0;
    while(!q.empty())
    {
     hu top = q.front();q.pop();
     if(top.X.X == n &&  top.X.Y == m)
      ans = min(ans,f[top.Y][top.X.X][top.X.Y]);
     if(f[top.Y][top.X.X][top.X.Y] >= ans) break;
     for(int i = 1;i<=4;++i){
      int nx = top.X.X+dx[i];
      int ny = top.X.Y+dy[i];
      int ns = top.Y;
      if(!range(nx,ny)) continue;
      int p = a[MP(top.X,MP(nx,ny))];
      if(p == -1) continue;
      if(p == 0 || (ns & (1<<(p-1))))
      {
       int u = 0;
       for(int j = 0;j<b[MP(nx,ny)].size();++j)
        u |= 1<<b[MP(nx,ny)][j];
       ns |= u;
       if(f[ns][nx][ny] > f[top.Y][top.X.X][top.X.Y]+1)
       {
        f[ns][nx][ny] = f[top.Y][top.X.X][top.X.Y]+1;
        q.push(MP(MP(nx,ny),ns));
       }
      }
     }
    }
    if(ans >= INF)
     puts("-1");
    else
     printf("%d\n",ans);   
    closeIO();
    return EXIT_SUCCESS;
}
