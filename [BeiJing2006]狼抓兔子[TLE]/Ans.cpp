#include "mode.h"
const int MN = 2010;
/*struct Dinic
{*/
 int  st[MN*MN],dis[MN*MN],n,tot,s,t;
 struct node
 {
  int v,f,n;
 };
 node  p[MN*MN*4];
 /*Dinic()
 {
  st = dis = NULL;
  p = NULL;
  n = tot  = 0;
 }
 ~Dinic()
 {
  RENEW(st);RENEW(dis);RENEW(p);
 }*/
 void init(int x,int y,int z)
 {
  n = x;tot = 0;s = z;t = x;
  //RENEW(st);RENEW(dis);RENEW(p);
  //st = new int[x+100];dis = new int[x+100];p = new node[y+100];
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
/*};
Dinic solver;*/
int np,m;
int main(int argc, char *argv[])
{
    setIO("sample");
    np = gi;m = gi;
    /*solver*/init(np*m+1,((np-1)*(m-1)+(np-1)*m+np*(m-1))*2+70,0);
    for(int i = 1;i<=np;++i)
     for(int j = 1;j<=m-1;++j)
     {
      int v = gi;
      /*solver.*/ae((i-1)*m+j,(i-1)*m+j+1,v);
     }
    for(int i = 1;i<=np-1;++i)
     for(int j = 1;j<=m;++j)
     {
      int v = gi;
      /*solver.*/ae((i-1)*m+j,i*m+j,v);
     }
    for(int i = 1;i<=np-1;++i)
     for(int j = 1;j<=m-1;++j)
     {
      int v = gi;
      /*solver.*/ae((i-1)*m+j,i*m+j+1,v);
     }
    /*solver.*/ae(0,1,INF);/*solver.*/ae(np*m,np*m+1,INF);
    printf("%d\n",/*solver.*/solve());
    closeIO();
    return EXIT_SUCCESS;
}
