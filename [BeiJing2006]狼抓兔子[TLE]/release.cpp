#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
const int INF =  1000000010;
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
FILE * debug;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str
 
(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}
 
int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}
struct Dinic
{
 int * st,*dis,n,tot,s,t;
 struct node
 {
  int v,f,n;
 };
 node * p;
 Dinic()
 {
  st = dis = NULL;
  p = NULL;
  n = tot  = 0;
 }
 /*~Dinic()
 {
  RENEW(st);RENEW(dis);RENEW(p);
 }*/
 void init(int x,int y,int z)
 {
  n = x;tot = 0;s = z;t = x;
  RENEW(st);RENEW(dis);RENEW(p);
  st = new int[x+100];dis = new int[x+100];p = new node[y+100];
  for(int i = s;i<=t;i++) st[i] = -1;
   
 }
 bool bfs()
 {
  queue<int> q;
  q.push(s);
  for(int i = s;i<=t;i++) dis[i] = INF;
  dis[s] = 0;
  while(!q.empty())
  {
   int x = q.front();q.pop();
   if(x == 11) 
    x = 11;
   for(int i = st[x],v;i!=-1;i=p[i].n)
    if(dis[v = p[i].v] > dis[x]+1 && p[i].f > 0)
    {
    dis[v] = dis[x]+1;q.push(v);
    }
  }
  return dis[t]!=INF;
 }
 void addedge(int x,int y,int z)
 {
  p[tot].n = st[x];p[tot].v = y;p[tot].f = z;st[x] = tot;
  tot++;
 }
 void ae(int x,int y,int z)
 {
  addedge(x,y,z);
  addedge(y,x,z);
 }
 int dfs(int x,int f)
 {
  if(x == t || f == 0) return f;
  int tmp = 0;
  for(int i = st[x],v,fl=0;i!=-1;i=p[i].n)
   if(dis[v = p[i].v] == dis[x]+1 && (fl = dfs(v,min(f,p[i].f))))
   {
    p[i].f -= fl;
    p[i^1].f += fl;
    tmp+=fl;
    f-=fl;
    if(f == 0) break;
   }
  return tmp;
 }
 int solve()
 {
  int flow = 0;
  while(bfs())
   flow += dfs(s,INF);
  return flow;
 }
};
Dinic solver;
int n,m;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;m = gi;
    solver.init(n*m+1,((n-1)*(m-1)+(n-1)*m+n*(m-1))*2+70,0);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m-1;++j)
     {
      int v = gi;
      solver.ae((i-1)*m+j,(i-1)*m+j+1,v);
     }
    for(int i = 1;i<=n-1;++i)
     for(int j = 1;j<=m;++j)
     {
      int v = gi;
      solver.ae((i-1)*m+j,i*m+j,v);
     }
    for(int i = 1;i<=n-1;++i)
     for(int j = 1;j<=m-1;++j)
     {
      int v = gi;
      solver.ae((i-1)*m+j,i*m+j+1,v);
     }
    solver.ae(0,1,INF);solver.ae(n*m,n*m+1,INF);
    printf("%d\n",solver.solve());
    closeIO();
    return EXIT_SUCCESS;
}