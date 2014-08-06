#include "mode.h"
const int MN = 100009;
int n,m,ec;
int st[MN],nxt[MN*2],lnk[MN*2],fa[MN],q[MN],col[MN],we[MN];
struct node
{
 int C[3];
};
void ae(int x,int y)
{
 ec++;
 nxt[ec] = st[x],lnk[ec] = y,st[x] = ec;
}
struct lct
{
 int  w[MN],mv[MN];
 node  t[MN];
 multiset<int>s[MN];
 lct()
 {
  //t = NULL;mv = w = NULL;s = NULL;
 }
 ~lct()
 {
  //RENEW(mv);RENEW(t);RENEW(w);RENEW(s);
 }
 void init(int n)
 {
  /*RENEW(t);RENEW(w);RENEW(s);RENEW(mv);
  t = new node[n+2];
  w = new int[n+2];
  mv = new int[n+2];*/
  for(int i = 0;i<=n+1;++i)
   mv[i] =  t[i].L = t[i].R = t[i].F = 0,w[i]=-INF;
  //s = new multiset<int>[n+2];
 }
 bool isrt(int x)
 {
  return (t[x].F==0)||(t[t[x].F].L != x && t[t[x].F].R != x );
 }
 void update(int x)
 {
      mv[x] = w[x];
      if(s[x].size())mv[x] = max(mv[x],*s[x].rbegin());
      if(t[x].L)mv[x] = max(mv[t[x].L],mv[x]);
      if(t[x].R)mv[x] = max(mv[t[x].R],mv[x]);
 }
 void rotate(int x)
 {
  int y = t[x].F;
  int z = t[y].F;
  int d1 = (t[y].L==x);
  int d2 = (t[z].R==y);
  int d3 = isrt(y);
  t[y].C[!d1] = t[x].C[d1];t[t[y].C[!d1]].F = y;
  t[x].C[d1] = y;t[y].F = x;
  if(!d3) t[z].C[d2] = x;
  t[x].F = z;
  update(y);update(x);
 }
 void splay(int rt)
 {
  for(int x = rt;!isrt(x);)
  {
   int y = t[x].F;
   int z = t[y].F;
   if(!isrt(y) && (t[z].R == y)==(t[y].R == x))
    rotate(y);
   rotate(x);
  }
  update(rt);
 }
 void access(int rt)
 {
  for(int x = rt,y=0;x;x=t[x].F)
  {
   splay(x);
   if(t[x].R) s[x].insert(mv[t[x].R]);
   if(y) s[x].erase(s[x].find(mv[y]));
   t[x].R = y;
   update(y=x);
  }
  splay(rt);
 }
 void link(int x)
 {
  access(fa[x]);
  splay(x);
  t[fa[x]].R = x;
  t[x].F = fa[x];
  update(fa[x]);
 }
 void cut(int x)
 {
  access(x);
  t[t[x].L].F = 0;t[x].L = 0;
  update(x);
 }
 int frt(int x)
 {
  access(x);
  while(t[x].L) x = t[x].L;
  return x;
 }
 void modify(int x,int u)
 {
  access(x);
  w[x] = u;
  update(x);
 }
 int query(int x)
 {
  x = frt(x);
  splay(x);
  //ff(d,"%d\n",s[x].size());
  return mv[t[x].R];
 }
}t[2];
void bfs(int x)
{
 int r = 1;q[1] = x;
 for(int l = 1;l<=r;++l)
 {
  x = q[l];
  for(int i = st[x],v;i;i=nxt[i])
   if(fa[x] != (v=lnk[i]))
   {
    fa[v] = x;
    r++;
    q[r] = v;
   }
 }
 fa[1] = n+1;
 q[0] = n+1;
 for(int i = r;i>=0;i--)
 {
  x = q[i];
  if(x == 1)
   x = 1;
  t[0].w[x] = we[x];t[1].w[x] = we[x];
  t[0].update(x);t[1].update(x);
  if(fa[x] != 0){
   int y = col[x];
   t[y].t[x].F = fa[x];
   t[y].s[fa[x]].insert(t[y].mv[x]);
  }
 }
}
int main(int argc, char *argv[])
{
    setIO("QTREE7");
    scanf("%d",&n);
    t[1].init(n);t[0].init(n);
    for(int i = 1,x,y;i<=n-1;++i)
    {
     scanf("%d%d",&x,&y);
     ae(x,y);ae(y,x);
    }
    for(int i = 1;i<=n;++i)
     scanf("%d",&col[i]);
    for(int i = 1;i<=n;++i)
     scanf("%d",&we[i]);
    bfs(1);
    scanf("%d",&m);
    for(int i = 1,x,y,z;i<=m;i++)
    {
     scanf("%d%d",&x,&y);
     if(x == 0)
      printf("%d\n",t[col[y]].query(y));
     else if(x == 1)
     {
      t[col[y]].cut(y);
      col[y]^=1;
      t[col[y]].link(y);
     }
     else if(x == 2)
     {
     scanf("%d",&z);
     t[0].modify(y,z);
     t[1].modify(y,z);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
