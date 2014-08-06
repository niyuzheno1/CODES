#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1000010;
struct lt
{
 int dist,key;
 int l,r;
};
lt he[MAXN];
int merge1(int x,int y)
{
 int tmp;
 if(!x)return y;
 if(!y)return x;
 if(he[x].key < he[y].key)
  tmp = x,x = y,y = tmp;
 he[x].r = merge1(he[x].r,y);
 int dis = he[he[x].r].dist+1;
 if(dis > he[he[x].l].dist+1)
   tmp = he[x].l,he[x].l = he[x].r,he[x].r = tmp;
 he[x].dist = he[he[x].r].dist+1;
 return x;
}
int f[MAXN],G[MAXN],tot,n,m;
int gf(int x)
{
 if(f[x] == x)
  return x;
 return f[x]=gf(f[x]);
}
int ins(int y,int x)
{
 tot++;
 he[tot].key = x;
 return merge1(y,tot);
}
int del(int x)
{
 return merge1(he[x].l,he[x].r);
}
void init()
{
 scanf("%d",&n);
 for(int i = 1;i<=n;i++){
  int x;
  f[i] = i;
  scanf("%d",&x);
  tot++;
  he[tot].key = x;
  G[i] = tot;
 }
 scanf("%d",&m);
 
}
void solve()
{
 for(int i = 1;i<=m;i++){
  int x,y;scanf("%d%d",&x,&y);
  gf(x);gf(y);
  if(f[x] == f[y])
   printf("-1\n");
  else
  {
   int u = f[x],v = f[y];
   int fat = 0;
   int uu = he[G[u]].key,vv = he[G[v]].key;
   G[u] = del(G[u]);G[v] = del(G[v]);
   G[u] = ins(G[u],uu/2);G[v] = ins(G[v],vv/2);
   G[u] = merge1(G[u],G[v]);
   f[v] = u;
   G[v] = G[u];
   printf("%d\n",he[G[u]].key);
  }
 }
}
int main(int argc, char *argv[])
{
    //#ifndef ONLINE_JUDGE
    //freopen("zoj2334.in","r",stdin);freopen("zoj2334.out","w",stdout);
    //#endif
    init();solve();
    //#ifndef ONLINE_JUDGE
    //fclose(stdin);fclose(stdout);
    //#endif
    return EXIT_SUCCESS;
}
