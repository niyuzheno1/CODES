#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
const int N = 100009;
FILE*d;
int ec,son[N],lnk[N*2],nxt[N*2],col[N],fa[N];
struct lct
{
 int l[N],r[N],p[N],sz[N],w[N];
 void init(int n)
 {
  ++n;
  for(int i = 0;i<=n;++i)l[i]= r[i]=p[i]=sz[i]=w[i] =0;
 }
 inline void update(int x){
  sz[x] = sz[l[x]]+sz[r[x]]+w[x]+1;
 }
 inline bool isrt(int x)
 {
  return !p[x]||(l[p[x]] != x && r[p[x]] !=x);
 }
 void rig(int x)
 {
  int y = l[x];
  p[y] = p[x];
  if(l[p[y]] == x)l[p[y]] = y;
  if(r[p[y]] == x)r[p[y]] = y;
  p[r[y]] = x;
  l[x] = r[y];
  p[x] = y;
  r[y] = x;
  update(x);
 }
 void lef(int x)
 {
  int y = r[x];
  p[y] = p[x];
  if(l[p[y]] == x) l[p[y]] = y;
  if(r[p[y]] == x) r[p[y]] = y;
  p[l[y]] = x;
  r[x] = l[y];
  p[x] = y;
  l[y] = x;
  update(x);
 }
 void splay(int x)
 {
  while(!isrt(x)){
   int y = p[x],z=p[y];
   if(!isrt(y) && l[z] == y && l[y] == x)rig(z),rig(y);
   else if(!isrt(y) && r[z] == y && r[y] == x)lef(z),lef(y);
   else if(l[y] == x) rig(y);
   else lef(y);
  }
  update(x);
 }
 void access(int rt)
 {
  for(int y = rt,x=0;y;y=p[y]){
   splay(y);
   if(r[y])w[y]+=sz[r[y]];
   if(x) w[y]-=sz[x];
   r[y] = x;
   update(x=y);
  }
  splay(rt);
 }
 int find_rt(int x)
 {
   access(x);
   while(l[x]) x = l[x];
   return x;
 }
 void cut(int x)
 {
   access(x);
   p[l[x]] = 0,l[x] = 0;
   update(x);
 }
 void link(int x)
 {
  access(fa[x]);
  splay(x);
  p[x] = fa[x];
  r[fa[x]] = x;
  update(fa[x]);
 }
 int query(int x)
 {
  x = find_rt(x);
  splay(x);
  return sz[r[x]];
 }
}t[2];
void toggle(int x)
{
 t[col[x]].cut(x);
 col[x]^=1;
 t[col[x]].link(x);
}
void dfs(int u)
{
 for(int i = son[u];i;i=nxt[i])
  if(fa[u]  != lnk[i]){
   t[0].p[lnk[i]] = fa[lnk[i]] = u;
   dfs(lnk[i]);
   t[0].w[u] += t[0].sz[lnk[i]];
  }
 t[0].update(u);
 t[1].update(u);
}
inline void addedge(int x,int y)
{
 ++ec;
 nxt[ec] = son[x];
 lnk[son[x] = ec] = y;
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
    setIO("QTREE6");
    int n,m;
    scanf("%d",&n);
    for(int i = 1;i<=n;++i) col[i] = son[i] = 0;
    t[0].init(n);t[1].init(n);
    ec = 0;
    for(int i = 1,x,y;i<n;++i){
     scanf("%d%d",&x,&y);
     addedge(x,y);addedge(y,x);
    }
    dfs(1);
    fa[1] = n+1;
    t[0].p[1] = n+1;t[0].sz[n+1] = n+1;
    scanf("%d",&m);
    for(int x,y;m--;){
     scanf("%d%d",&x,&y);
     if(!x) printf("%d\n",t[col[y]].query(y));
     else toggle(y);
    }
    closeIO();
    return EXIT_SUCCESS;
}
