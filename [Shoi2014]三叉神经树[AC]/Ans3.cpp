#include "mode.h"
#include "data.h"
#undef R
#define CON rt,1,Index
#define MN 500010*2+100
int o1[MN],o2[MN],to;
struct ch{
 int sz,v;
 int R[2];
 ch()
 {
  sz = v = -1;
  R[0] = R[1] = 0;
 }
 void cov(int x)
 {
  R[0] = R[1] = 0;  v = x; if(x<=2 && x >= 1) R[x-1] = sz;
 }
};
ch operator + (ch & u,ch & v)
{
 ch t;
 if(u.sz == -1) t = v;
 else if(v.sz == -1) t = u;
 else {
  t.sz = u.sz+v.sz;
  for(int i = 0;i<=1;++i) t.R[i] = (v.R[i]==v.sz)?(v.R[i]+u.R[i]):v.R[i];
 }
 return t;
}
ch o3[MN];
int rec[MN];
#define LCH(_t) o1[_t]
#define RCH(_t) o2[_t]
#define S(_t) o3[_t]

void updata(int x)
{
 S(x) = S(LCH(x))+S(RCH(x));
}
void pss(int x)
{
 if(S(x).v != -1)
 {
  int tmp = S(x).v;
  S(LCH(x)).cov(tmp);
  S(RCH(x)).cov(tmp);
  S(x).v = -1;
  S(x).R[0] = S(x).R[1] = 0;
 }
}
void build(TREE2)
{
  if(!_t) _t = ++to;
  if(_l == _r){
   S(_t).sz = 1;
   S(_t).cov(rec[_l]);
   return; 
  }
  M;build(LEFT);build(RIGHT);
  updata(_t);
}

void modify(TREE,int x,int v)
{
 if(_l == _r){
       S(_t).cov(v); 
       return;
 }
 pss(_t);
 M;if(x <= mid) modify(LEFT,x,v); else modify(RIGHT,x,v);
 updata(_t);
}
ch query(TREE,int x){
 if(_l == _r){
  return S(_t);
 }
 pss(_t);
 ch ret;
 M; if(x <= mid) ret = query(LEFT,x); else ret = query(RIGHT,x);
 updata(_t);
 return ret;
}
void modify(TREE,int l,int r,int v)
{
 if(l > r) return;
 if(l<=_l && _r <= r)
 {
  S(_t).cov(v);
  return;
 }
 pss(_t);
 M;
 if(l<=mid) modify(LEFT,l,r,v);
 if(mid<r ) modify(RIGHT,l,r,v);
 updata(_t);
}
ch query(TREE,int l,int r){
 if(l <= _l && _r <= r)
  return S(_t);
 pss(_t);
 ch rl,rr;M;
 if(l <= mid) rl = query(LEFT,l,r);
 if(mid < r)  rr = query(RIGHT,l,r);
 updata(_t);
 return rl+rr;
}
#undef MN
#define MN 500010*3
int p[MN],n,Index,pec[MN],q[MN],rt;
#undef MN
#define MN 500010
int id[MN],hz[MN],sz[MN],f[MN],st[MN];
void dfs(int x) {
  int y = x;
  while(y){
   id[y] = ++Index;
   f[y] = x;
   y = hz[y];
  }
}
struct edge{
 int v,f,n;
};
edge lk[MN];
void addedge(int x,int y)
{
 lk[++SIZE(st)].v = y;lk[SIZE(st)].n = st[x];st[x] = SIZE(st);
}
int ref(int x)
{
    TRA(u,x) sz[x]+=sz[lk[u].v],pec[x]+= pec[lk[u].v]>=2?1:0;
}
void transf(int x,int y)
{
 for(;x != 0;)
 {
  if(f[x] == x)
  {
   ch tmp = query(CON,id[x]);
   if(tmp.v == y){
    modify(CON,id[x],(y==1)?(tmp.v+1):(tmp.v-1));
    x = p[x];
   } else {
    modify(CON,id[x],(y==1)?(tmp.v+1):(tmp.v-1));
    break;
   }
  }
  else
  {
   int u = f[x];
   ch tmp = query(CON,id[u]+1,id[x]);
   if(tmp.R[y-1] == tmp.sz){
    modify(CON,id[u]+1,id[x],(y==1)?(y+1):(y-1));
    x = f[x];
   } else {
    int lst = id[x]-tmp.R[y-1];
    modify(CON,lst+1,id[x],(y==1)?(y+1):(y-1));
    tmp = query(CON,lst);
    modify(CON,lst,(y==1)?(tmp.v+1):(tmp.v-1));
    break;
   }
  }
 }
}
const int msg[] = {2,0,1,0};
int main(int argc, char *argv[])
{
    setIO("sample");CLEAR(st,0xff);st[0]=0;
    n = gi;
    for(int i = 1;i<=n;++i)
     for(int j = 1,x;j<=3;++j){
       x = gi;
       p[x] = i;
       if(x > n) ++sz[i];
       else addedge(i,x);
     }
    for(int i = n+1,x;i<=3*n+1;++i){
      x = gi,pec[i] = x?2:0;
      pec[p[i]] += pec[i]>=2?1:0;
    }
    int r = 1;q[r] = 1;
    for(int i = 1;i<=r;++i)
     TRA(u,q[i]) 
      ++r,q[r] = lk[u].v;
    for(int i = r,u;i>=1;--i){
     u = q[i];
     ref(u);
     if(p[u] && sz[hz[p[u]]]<sz[u])
      hz[p[u]] = u;
    }
    for(int i = 1;i<=r;++i){
     int u = q[i];
     if(!id[u]) dfs(q[i]);
    }
    for(int i = 1;i<=r;++i)
     rec[id[q[i]]] = pec[q[i]];
    build(rt,1,Index);
    int m = gi;
    for(int i = 1;i<=m;++i)
    {
     int x = gi;pec[x] = 2-pec[x];
     transf(p[x],msg[pec[x]]);
     printf("%d\n",query(CON,1).v>=2);
    }
    closeIO();
    return EXIT_SUCCESS;
}
