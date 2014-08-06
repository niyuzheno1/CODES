#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxp = 3010,maxc = 20010,maxn = 3010,inf = 0x7f7f7f7f;
struct link
{
  int v,u,f,n;
};
int st[maxp*3],tot,p,c,n,d[maxp*3],s,t;
link lk[maxc*4];
void add1(int x,int y,int z,int f)
{
     lk[tot].v = y;
     lk[tot].u = z;
     lk[tot].f = f;
     lk[tot].n = st[x];
     st[x] = tot;
     tot++;
}
void add(int x,int y,int z,int f)
{
 add1(x,y,z,f);
 add1(y,x,-z,0);
}
bool bfs()
{
 memset(d,0x7f,sizeof(d));
 queue<int> q;q.push(s);
 d[s] = s;
 while(!q.empty())
 {
  int x = q.front();q.pop();
  for(int i = st[x];i!=-1;i=lk[i].n)
  {
   int uu = lk[i].v;
   if(d[uu] > d[x]+1 && lk[i].f>0)
   {
    d[uu] = d[x]+1;
    q.push(uu);
   }
  }
 }
 return d[t]!=inf;
}
int dfs(int x,int y)
{
  if(x == t)
   return y;
  int f = 0;
  for(int i = st[x];i!=-1;i=lk[i].n)
  {
   int uu = lk[i].v;
   int tmp = 0;
   if(d[uu] == d[x]+1 && (tmp=dfs(uu,min(y,lk[i].f))) >0)
   {
    lk[i].f -= tmp;
    lk[i^1].f += tmp;
    y-= tmp;
    f+=tmp;
    if(y == 0)
     break;
   }
  }
  return f;
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    freopen("damage2.in","r",stdin);
    freopen("damage2.out","w",stdout);
    scanf("%d%d%d",&p,&c,&n);
     s = 3,t = 2*(p+1);
    for(int i = 1;i<=p;i++)
     add(2*i,2*i+1,0,1);
    for(int i = 1;i<=c;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     add(2*x+1,2*y,0,1);
     add(2*y+1,2*x,0,1);
    }
    for(int i = 1;i<=n;i++)
    {
     int x;
     scanf("%d",&x);
     add(2*x,t,0,1);
    }
    int flow = 0;
    while(bfs())
    {
     flow += dfs(s,inf);
    }
    printf("%d",flow);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
