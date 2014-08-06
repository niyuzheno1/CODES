#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <map>
#define X first
#define Y second

using namespace std;
const int dx[] = {0,1,-1,0,0};
const int dy[] = {0,0,0,1,-1};
const int inf = 0x7f7f7f7f;
typedef pair<int,int> p;
int n,sx,sy;
int mp[1010][1010];
int f[1010][1010];
queue<p> q1;
queue<p> q2;
void up(int x,int y,int X,int Y)
{
     if(X <= 1001 && X >= 0)
      if(Y <= 1001 && Y >= 0)
       if(f[X][Y] > f[x][y]+mp[X][Y]){
      f[X][Y] = f[x][y]+mp[X][Y];
      if(mp[X][Y] != 0)
       q2.push(p(X,Y));
      else
       q1.push(p(X,Y));
      }
}
int main()
{
    freopen("tractor.in","r",stdin);
    freopen("tractor.out","w",stdout);
    memset(f,0x7f,sizeof(f));
    scanf("%d%d%d",&n,&sx,&sy);
    f[sx][sy] = 0;
    q1.push(p(sx,sy));
    for(int i = 1;i<=n;i++)
    {
            int x,y;
            scanf("%d%d",&x,&y);
            mp[x][y] = 1;
    }
    while(f[0][0] == inf)
    {
     if(q1.empty())
      while(!q2.empty()){
       q1.push(q2.front());
       q2.pop();
      }
     p u = q1.front();q1.pop();
     for(int i = 1;i<=4;i++)
      up(u.X,u.Y,u.X+dx[i],u.Y+dy[i]);
    }
    printf("%d\n",f[0][0]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
