#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define X first
#define Y second
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
typedef pair<int,int> p;
int d[501][501];
vector<p> u;
queue<p> q;
p operator +(p x,p y)
{
     return p(x.X+y.X,x.Y+y.Y);
}
int n,m,a,b;
char inf[100],ouf[100];
int main(int argc, char *argv[])
{
    u.push_back(p(1,0));u.push_back(p(-1,0));u.push_back(p(0,1));u.push_back(p(0,-1));
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr421.in%d",cani);
    sprintf(ouf,"mr421.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    zero(d);
    memset(d,0xff,sizeof(d));
    
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      d[i][j] = 0x7f7f7f7f;
    for(int i = 1;i<=a;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     q.push(p(x,y));
     d[x][y] = 0;
    }
    while(!q.empty())
    {
     p x = q.front();q.pop();
     for(int i = 0;i<u.size();i++)
     {
      p y = x+u[i];
      if(d[x.X][x.Y]+1 < d[y.X][y.Y]){
      d[y.X][y.Y] = d[x.X][x.Y]+1;
      q.push(y);
      }
     }
    }
     for(int i = 1;i<=b;i++)
     {
     int x,y;
     scanf("%d%d",&x,&y);
     printf("%d\n",d[x][y]);
     }
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
