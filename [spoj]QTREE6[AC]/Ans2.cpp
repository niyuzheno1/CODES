#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define L 0
#define R 1
#define P 2
using namespace std;
const int N = 100010;
FILE * d;
int ec,fa[N],col[N],st[N],nxt[N*2],lnk[N*2],n,m;
struct lct
{
 int ch[N][3],sz[N],w[N];
 inline void update(int x)
 {
  sz[x] = sz[ch[x][L]]+sz[ch[x][R]]+w[x]+1;
 }
 inline bool isrt(int x)
 {
   return (ch[x][P] == 0||(ch[ch[x][P]][0] != x && ch[ch[x][P]][1] != x));
 }
 void rotate(int x)
 {
  int y = ch[x][P];
  int z = ch[y][P];
  int dl = (ch[y][0]==x);
  int d2 = (ch[z][1]==y);
  int d3 = isrt(y);
  ch[y][!dl] = ch[x][dl];
  ch[ch[y][!dl]][P] = y;
  ch[x][dl] = y;
  ch[y][P] = x;
  if(!d3)
   ch[z][d2] = x;
  ch[x][P] = z;
  update(y);update(x);
 }
 void splay(int x)
 {
  while(!isrt(x))
  {
   int y = ch[x][P];
   if(!isrt(y))
   {
    int z = ch[y][P];
    int d1 = ((ch[z][0]==y)==(ch[y][0]==x));
    if(d1) rotate(y);
   }
   rotate(x);
  }
  update(x);
 }
 void access(int rt)
 {
  for(int x=rt,y=0;x;x=ch[x][P]){
   splay(x);
   if(ch[x][R]) w[x]+=sz[ch[x][R]];
   if(y) w[x] -=sz[y];
   ch[x][R] = y;
   update(y = x);
  }
  splay(rt);
 }
 void link(int x)
 {
  access(fa[x]);
  splay(x);
  ch[x][P] = fa[x];
  ch[fa[x]][R] = x;
  update(fa[x]);
 }
 void cut(int x)
 {
  access(x);
  ch[ch[x][L]][P] = 0,ch[x][L] = 0;
  update(x);
 }
 int find_rt(int x)
 {
  access(x);
  while(ch[x][L])
   x = ch[x][L];
  return x;
 }
 int query(int x)
 {
  x=find_rt(x);
  splay(x);
  return sz[ch[x][R]];
 }
}t[2];
void modify(int x)
{
     t[col[x]].cut(x);
     col[x] ^= 1;
     t[col[x]].link(x);
}
inline void addedge(int x,int y)
{
       ec++;
       nxt[ec] = st[x];
       lnk[ec] = y;
       st[x] = ec;
}
void dfs(int x)
{
 for(int i = st[x],v;i;i=nxt[i])
  if(fa[x] != (v = lnk[i])){
  t[0].ch[v][P] = fa[v] = x;
  dfs(v);
  t[0].w[x] += t[0].sz[v];
 }
 t[0].update(x);
 t[1].update(x);
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
    scanf("%d",&n);
    for(int i = 1,x,y;i<n;i++){
     scanf("%d%d",&x,&y);
     addedge(x,y);addedge(y,x);
    }
    dfs(1);
    fa[1] = n+1;
    t[0].ch[1][P] = n+1;t[0].w[n+1] = n+1;
    scanf("%d",&m);
    for(int x,y;m--;)
    {
     scanf("%d%d",&x,&y);
     if(x == 0)
      printf("%d\n",t[col[y]].query(y));
     else
      modify(y);
    }
    closeIO();
    return EXIT_SUCCESS;
}
