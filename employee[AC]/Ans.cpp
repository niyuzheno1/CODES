#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
const int inf = 0x7f7f7f7f;
const int maxn = 1010,maxm = 10000*4;
int n,m;
int a[maxn];
int flow;
struct link
{
 int v,c,va,n;
};
link lk[maxm];
int st[maxn],tot,d[maxn];
void add1(int x,int y,int z,int f)
{
 lk[tot].v = y;
 lk[tot].c = f;
 lk[tot].va = z;
 lk[tot].n = st[x];
 st[x] = tot;
 tot++;
}
void add(int x,int y,int z,int f)
{
 add1(x,y,z,f);
 add1(y,x,-z,0);
}
int s,t;
int pp[maxn];
bool flower()
{
 memset(d,0x7f,sizeof(d));
 queue<int> q;
 q.push(s);
 d[s] = 0;
 pp[s] = -1;
 while(!q.empty())
 {
  int x = q.front();q.pop();
  for(int i = st[x];i!=-1;i=lk[i].n)
   if(lk[i].c > 0 && d[lk[i].v] > d[x]+lk[i].va)
   {
    pp[lk[i].v] = i^1;
    d[lk[i].v] = d[x]+lk[i].va;
    q.push(lk[i].v);
   }
 }
 return !(d[t] == inf);
}
void ag()
{
     int delta = inf;
     for(int i = pp[t];i!=-1;i=pp[lk[i].v])
      delta = min(delta,lk[i^1].c);
     for(int i = pp[t];i!=-1;i=pp[lk[i].v])
     {
      int rev = i^1;
      lk[rev].c -= delta;
      lk[i].c += delta;
      flow += lk[rev].va*delta;
     }
}
int main(int argc, char *argv[])
{
    memset(st,0xff,sizeof(st));
    freopen("employee.in","r",stdin);
    freopen("employee.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=m;i++)
    {
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     add(x,y+1,z,inf);
    }
    s = 0,t = n+2;
    for(int i = 1;i<=n+1;i++)
    {
     int c = a[i]-a[i-1];
     if(i != 1)
      add(i,i-1,0,inf);
     if(c < 0)
      add(i,t,0,-c);
     else
      add(s,i,0,c);
    }
    while(flower())
     ag();
    printf("%d",flow);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
