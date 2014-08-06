#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define CLEAR(x,y) memset(x,y,sizeof(x))
using namespace std;
const int N = 79,inf = 0x3f3f3f3f;
struct node
{
 int x,y;
 node(int _x = 0,int _y = 0):
  x(_x),y(_y)
 {
 }
}p[N][N];
FILE * d;
bool operator==(const node & lhs,const node & rhs)
{
 return lhs.x==rhs.x&&lhs.y==rhs.y;
}
int cpr(const node & a,const node & b,const node & c)
{
 return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int w[N][N],mate[N],lx[N],ly[N],visx[N],visy[N],Time,n;
bool dfs(int u)
{
 visx[u] = Time;
 for(int v = 1;v<=n;++v)
  if(visy[v] != Time && w[u][v] == lx[u]+ly[v])
  {
   visy[v] = Time;
   if(!mate[v] || dfs(mate[v]))
    return mate[v]=u,true;
  }
 return false;
}
void update()
{
 int d = inf;
 for(int i = 1;i<=n;++i)
  if(visx[i] == Time)
   for(int j = 1;j<=n;++j)
    if(visy[j] != Time)
     d = min(d,lx[i]+ly[j]-w[i][j]);
 for(int i = 1;i<=n;i++)
 {
  if(visx[i] == Time) lx[i] -= d;
  if(visy[i] == Time) ly[i] += d;
 }
}
node KM()
{
 CLEAR(ly,0);CLEAR(mate,0);
 CLEAR(lx,0xC0);
 for(int i = 1;i<=n;++i)
  for(int j = 1;j<=n;++j)
   lx[i] = max(lx[i],w[i][j]);
 for(int i = 1;i<=n;++i)
  while(1){
   ++Time;
   if(dfs(i)) break;
   update();
  }
 int res1 = 0,res2 = 0;
 for(int i = 1;i<=n;++i)
  res1 += p[mate[i]][i].x,res2 += p[mate[i]][i].y;
 return node(res1,res2);
}
int solve(const node &l,const node & r)
{
 int res = min(l.x*l.y,r.x*r.y);
 for(int i = 1;i<=n;++i)
  for(int j =1;j<=n;++j)
   w[i][j] = cpr(p[i][j],r,l);
 node mid = KM();
 if(mid == l || mid == r)
  return res;
 return min(res,min(solve(l,mid),solve(mid,r)));
}
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);d = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(d);
 #endif
}
int main(int argc, char *argv[])
{
    setIO("frame");
    int T;scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
      scanf("%d",&p[i][j].x);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
      scanf("%d",&p[i][j].y);
    for(int i = 1;i<=n;++i)
     for(int j =1;j<=n;++j)
      w[i][j] = -p[i][j].x;
    node s = KM();
    for(int i = 1;i<=n;++i)
     for(int j =1;j<=n;++j)
      w[i][j] = -p[i][j].y;
    node t = KM();
     printf("%d\n",solve(s,t));          
    }
    closeIO();
    return EXIT_SUCCESS;
}
