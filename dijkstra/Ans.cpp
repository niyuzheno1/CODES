#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
priority_queue<p,vector<p> , greater<p> > Q;
int dis[1001];
bool flag[1001];
vector<p> q[1001];
int n,m;
void init()
{
     scanf("%d%d",&n,&m);
     for(int i = 1;i<=m;i++)
     {
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      q[x].push_back(p(y,z));
      q[y].push_back(p(x,z));
     }
}
void dijkstra(int s)
{
     memset(dis,0x7f,sizeof(dis));
     dis[s] = 0;
     Q.push(p(0,s));
     while(!Q.empty())
     {
      while(!Q.empty() && flag[Q.top().Y])
       Q.pop();
      if(Q.empty())
       break;
      p c = Q.top();Q.pop();
      flag[c.Y] = 1;
      int dist = c.X;
      dis[c.Y] = dist;
      for(int i = 0;i<q[c.Y].size();i++)
       Q.push(p(q[c.Y][i].Y+dist,q[c.Y][i].X));
     }
     while(!Q.empty())
      Q.pop();
}
int sum = 0;
void prim(int s)
{
  memset(flag,0,sizeof(flag));
  Q.push(p(0,s));
  while(!Q.empty())
  {
      while(!Q.empty() && flag[Q.top().Y])
       Q.pop();
      if(Q.empty())
       break;
      p c = Q.top();Q.pop();
      flag[c.Y] = 1;
      int dist = c.X;
      sum+=  dist;
      for(int i = 0;i<q[c.Y].size();i++)
       Q.push(p(q[c.Y][i].Y,q[c.Y][i].X));
  }
}
void print(int s)
{
 for(int i = 1;i<=n;i++)
  printf("%d -> %d : %d \n",s,i,dis[i]);
 printf("%d\n",sum);
}
int main(int argc, char *argv[])
{
    init();
    dijkstra(1);
    prim(1);
    print(1);
    system("PAUSE");
    return EXIT_SUCCESS;
}
