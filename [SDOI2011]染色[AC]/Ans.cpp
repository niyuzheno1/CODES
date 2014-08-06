#include "mode.h"
#include "data.h"
#define MN 1000005
#define tt TREE
#define gol LEFT
#define gor RIGHT
#define LCH(_t) (_t<<1)
#define RCH(_t) ((_t<<1)|1)
struct edge{
       int v,n,f;
}lk[MN<<1];
struct N{
       int num,l,r;
}que[MN<<2];
int n ,m , M ,st[MN],E,tot;
int top[MN],fa[MN],dep[MN],son[MN],siz[MN];
int w[MN],W[MN],val[MN],cov[MN<<2];
#define M int mid = (_l+_r)>>1;
#undef L
#undef R
N up(N L , N R)
{
       if(!L.num)return R;
       if(!R.num)return L;
       N ans;
       ans.num = L.num+R.num-(L.r == R.l);
       ans.l = L.l ,ans.r = R.r;
       return ans;
}
void down(int rt){
 if(cov[rt] != -1){
 cov[LCH(rt)] = cov[RCH(rt)] = cov[rt];
 que[LCH(rt)] = que[RCH(rt)] = (N){1,cov[rt],cov[rt]};
 cov[rt] = -1;
 }
}
void build(tt){
 cov[_t] = -1;
 if(_l == _r){
  que[_t] = (N){1,W[_l],W[_r]};
  return ;
 }
 M;
 build(gol);build(gor);
 que[_t] = up(que[LCH(_t)],que[RCH(_t)]);
}
void upd(tt,int l,int r,int c)
{
     if(l<=_l && _r <= r)
     {
      cov[_t] = c;
      que[_t] = (N){1,c,c};
      return;
     }
     down(_t);
     M;
     if(mid >= l) upd(gol,l,r,c);
     if(r > mid) upd(gor,l,r,c);
     que[_t] = up(que[LCH(_t)],que[RCH(_t)]);
}
N query(tt ,int l,int r){
 if(_l >= l && _r <= r) return que[_t];
 down(_t);
 M;
 N res = (N){0,-1,-1};
 if(mid >= l) res = query(gol,l,r);
 if(r > mid){
  if(res.num) return up(res,query(gor,l,r));
  else return query(gor,l,r);
 }
 return res;
}
void init(){
     E = 0,tot = 0,top[1] = 1;
     CLEAR(st,0xff);
}
void add(int u,int v)
{
     lk[E].v = v,lk[E].n = st[u],st[u] = E++;
}
void dfs1(int f,int u,int d){
     fa[u] = f,dep[u] = d,siz[u] = 1,son[u] = -1;
     int Max = 0;
     TRA(i,u)
     {
      int v = lk[i].v;
      lk[i^1].f = 1;
      dfs1(u,v,d+1);
      siz[u] += siz[v];
      if(siz[v] > Max){
       Max = siz[v];
       son[u] = v;
      }
     }
}
void dfs2(int f,int u){
 w[u] = ++tot;W[tot] = val[u];
 if(son[u]==-1) return;
 TRA(i,u){
  int v = lk[i].v;
  if(v != son[u]) continue;
  top[v] = top[u];
  dfs2(u,v);
 }
 TRA(i,u){
  int v = lk[i].v;
  if(v == son[u]) continue;
  top[v] = v;
  dfs2(u,v);
 }
}
void C(int a,int b,int c){
 while(top[a] != top[b]){
  int f1 = top[a] ,f2 = top[b];
  if(dep[f1] >= dep[f2])
  {
   upd(1,1,m,w[f1],w[a],c);
   a = fa[f1];
  } else {
   upd(1,1,m,w[f2],w[b],c);
   b = fa[f2];
  }
 }
 if(dep[a] >= dep[b])
  upd(1,1,m,w[b],w[a],c);
 else
  upd(1,1,m,w[a],w[b],c);
}
N Q(int a,int b){
 N L,R;
 L = R = (N){0,-1,-1};
 if(top[a] != top[b]){
   while(top[a] != top[b])        
   {
    int f1 = top[a],f2 = top[b];
    if(dep[f1] >= dep[f2]){
     L = up(query(1,1,m,w[f1],w[a]),L);
     a = fa[f1];
    }else{
     R = up(query(1,1,m,w[f2],w[b]),R);
     b = fa[f2];
    }
   }
  if(dep[a] >= dep[b])
   L = up(query(1,1,m,w[b],w[a]),L);
  else
   R = up(query(1,1,m,w[a],w[b]),R);
  swap(L.l,L.r);
  return up(L,R);
 }else 
  if(dep[a] >= dep[b]) return query(1,1,m,w[b],w[a]);
  else return query(1,1,m,w[a],w[b]);
}
#undef M
int main(int argc, char *argv[])
{
    setIO();
    n = gi;M = gi;
    for(int i = 1;i<=n;++i)
     val[i] = gi;
    init();
    for(int i = 1,a,b;i<n;++i)
     a = gi,b = gi,add(a,b),add(b,a);
    dfs1(0,1,0);
    dfs2(0,1);
    m = tot;
    build(1,1,m);
    while(M--){
     char op[2];
     int a,b,c;
     scanf("%s%d%d",op,&a,&b);
     if(op[0] == 'C'){
      scanf("%d",&c);
      C(a,b,c);
     }else {
      printf("%d\n",Q(a,b).num);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
