#include "mode.h"
int tttt[5];
#define MN 100010
struct _edge{
       int n,f,v;
}lk[MN*2];
int st[MN];
#define tot tttt[0]
inline void addedge(int a,int b){
 lk[++tot].n = st[a];st[a] = tot,lk[tot].v = b;
}
#undef tot
#undef SIZE
#define SIZE 2000000
#define LOG 17
struct Node {
        int l,r;
        int full;
        int d;
}tree[SIZE+1];

#define l(_t) tree[_t].l
#define r(_t) tree[_t].r
#define full(_t) tree[_t].full
#define d(_t) tree[_t].d
int n,col[MN],tcnt = 0,rt[MN],sg[MN],sum[MN],up[MN],v[MN];
inline int newnode(){
 return ++tcnt;
}
inline void upd(int x){
 full(x) = full(l(x)) && full(r(x));
}
inline void push(int x){
 if(d(x)){
  if(l(x)) d(l(x)) ^= d(x)>>1;
  if(r(x)) d(r(x)) ^= d(x)>>1;
  if(d(x) & 1) swap(l(x),r(x));
  d(x) = 0;
 }
}
int merge(int l,int r){
if(!l || full(r) ) return r;
if(!r || full(l) ) return l;
int ret = newnode();
push(l),push(r);
l(ret) = merge(l(l),l(r));
r(ret) = merge(r(l),r(r));
upd(ret);
return ret;
}
inline int rev(int x){
 int r = 0;
 for(int i = LOG;i>0;--i)
  if( x >> i-1 & 1)
   r += 1<<LOG-i;
 return r;
}
int bk = 0;
void insert(int x,int v,int p){
  push(x);
  if(v >> p-1 & 1){
   if(!r(x)) r(x) = newnode();
   if(p != 1) insert(r(x),v,p-1);
   else full(r(x)) = 1;
  }else {
   if(!l(x)) l(x) = newnode();
   if(p != 1) insert(l(x),v,p-1);
   else full(l(x)) = 1;
  }
  if(l(x) == 200 ||  r(x) == 200)
   bk = 1;
  upd(x);
}
int mex(int x){
    if(x == 220)
     x = 220;
    int r = 0;
    for(int i = LOG;x;--i){
     push(x);
     if(full(l(x)))
       r += 1<<i-1,x=r(x);
     else x = l(x);
    }
    return r;
}
void calc(int x){
 v[x] = 1;
 int xorsum = 0;
 int & r = rt[x];
 TRA(i,x){
  int node = lk[i].v;
  if(v[node]) continue;
  calc(node);
  v[node] = 0;
  xorsum ^= sg[node];
 }
 if(x == 2)
  x = 2;
 TRA(i,x){
  int node = lk[i].v;
  if(v[node])continue;
  d(rt[node]) ^= rev(xorsum ^ sg[node]);
  r = merge(r,rt[node]); 
 }
 if(!col[x]) insert(r,xorsum,LOG);
 sg[x] = mex(r);sum[x] = xorsum;
}
int ans[MN],cnt = 0;
void find(int x){
 v[x] = 1;
 if((up[x] ^ sum[x])==0 && col[x] == 0) ans[++cnt] = x;
 TRA(i,x){
  int node = lk[i].v;
  if(v[node]) continue;
  up[node] = up[x] ^ sum[x] ^ sg[node];
  find(node);
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");CLEAR(st,0xff);
    scanf("%d",&n);
    for(int i = 1;i<=n;++i)  scanf("%d",&col[i]);
    for(int i = 1;i<n;++i){
     int x,y;
     scanf("%d%d",&x,&y);
     addedge(x,y);addedge(y,x);
    }
    for(int i = 1;i<=n;++i) rt[i] = newnode();
    calc(1);
    for(int i = 1;i<=n;++i) v[i] = 0;
    find(1);
    if(cnt == 0) puts("-1");
    else{
     sort(ans+1,ans+1+cnt);
     for(int i = 1;i<=cnt;++i)
      printf("%d\n",ans[i]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
