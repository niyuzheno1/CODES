#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
int n,m,tot;
int st[1010];
int d[1010];
int d1[1010];
int v[1010];
struct
{
 int a,b,c;
}c[100010];
struct
{
 int v,ne,w;
}lk[100010];
void li(int a,int b,int c)
{
  tot++;
  lk[tot].ne = st[a];
  lk[tot].v  = b;
  lk[tot].w = c;
  st[a] = tot;
}
void dj(int m)
{
  d[m] = 0;
  priority_queue<p,vector<p>,greater<p> > q;
  q.push(p(0,m));
  while(!q.empty()){
   int x = q.top().Y;
   q.pop();
   if(v[x])
    continue;
   v[x] = 1;
   for(int i = st[x];i!=0;i = lk[i].ne)
    if(d[lk[i].v] > d[x]+lk[i].w){
     d[lk[i].v] = d[x]+lk[i].w;
     q.push(p(d[lk[i].v],lk[i].v));
    }
  }
}
int main(int argc, char *argv[])
{
    freopen("post.in","r",stdin);
    freopen("post.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
     scanf("%d%d%d",&c[i].a,&c[i].b,&c[i].c);
    memset(st,0,sizeof(st));
    memset(lk,0,sizeof(lk));
    memset(v,0,sizeof(v));
    memset(d,0x7f,sizeof(d));
    tot = 0;
    for(int i = 1;i<=m;i++)
      li(c[i].a,c[i].b,c[i].c);
    dj(1);
    memcpy(d1,d,sizeof(d1));
    memset(st,0,sizeof(st));
    memset(lk,0,sizeof(lk));
    memset(v,0,sizeof(v));
    memset(d,0x7f,sizeof(d));
    tot = 0;
    for(int i = 1;i<=m;i++)
      li(c[i].b,c[i].a,c[i].c);
    dj(1);
    int ans = 0;
    for(int i = 1;i<=n;i++)
     ans = ans+ d[i]+d1[i];
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
