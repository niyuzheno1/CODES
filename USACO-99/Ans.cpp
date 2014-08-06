#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define in(x) (x)*2
#define ou(x) (x)*2+1
using namespace std;
const int maxn = 100010,maxm = 1000100,inf = 0x7f7f7f7f;
int st[maxn];
struct link
{
 int v,u,f,n,from;
};
link lk[maxm];
int d[maxn];
int pp[maxn];
int tot;
void add1(int x,int y,int z,int f)
{
 lk[tot].v = y;
 lk[tot].from = x;
 lk[tot].u = z;
 lk[tot].f = f;
 lk[tot].n = st[x];
 st[x] = tot;
 tot++;
}
void add(int x,int y,int z,int f)
{
 if(tot == 30)
  tot = 30;
 add1(x,y,z,f);
 add1(y,x,-z,0);
 
}
int D,N,M,A,B,P,s,t;
bool bfs()
{
     memset(d,0x7f,sizeof(d));
     d[s] = 0;queue<int> q;
     q.push(s);
     pp[s] = -1;
     while(!q.empty())
     {
      int x = q.front();q.pop();
      for(int i = st[x];i!=-1;i=lk[i].n)
      {
       int uu = lk[i].v;
       if(d[uu] > d[x]+lk[i].u && lk[i].f > 0)
       {
       d[uu] = d[x]+lk[i].u;
       pp[uu] = i^1;
       q.push(uu);
       }
      }
     }
     return d[t]!=inf;
}
int ag()
{
 int f = inf,ret =0;
 for(int i = pp[t];i!=-1;i=pp[lk[i].v])
  f = min(f,lk[i^1].f);
 for(int i = pp[t];i!=-1;i=pp[lk[i].v])
 {
  int rev = i^1;
  lk[rev].f -= f;
  lk[i].f += f;
  ret += lk[rev].u*f;
 }
 return ret;
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    freopen("toy.in","r",stdin);
    freopen("toy.out","w",stdout);
    scanf("%d%d%d%d%d%d",&D,&N,&M,&A,&B,&P);
     s = 0,t = 2*(D+1);
    for(int i =1;i<=D;i++){
     int u;scanf("%d",&u);
     add(in(i),ou(i),0,u);
    }
    
     add(s,in(1),P,inf);
    for(int i =1;i<=D;i++)
    {
     if(i+N <= D)
      add(ou(i),in(i+N),A,inf);
     if(i+M <= D)
      add(ou(i),in(i+M),B,inf);
     if(i+1<= D)
      add(in(i),in(i+1),0,inf);
    }
    for(int i = 1;i<=D;i++)
     add(ou(i),t,0,inf);
    int flow = 0;
    while(bfs())
     flow += ag();
    printf("%d\n",flow);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
