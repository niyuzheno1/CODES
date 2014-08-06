#include "mode.h"
#include "data.h"
#define SIZE(a) a[0]
#define MN 3000010
int o1[MN],o2[MN],cnt[MN],qt[MN],t1,low;
#define LEF(_t) o1[_t]
#define RIG(_t) o2[_t]
#define S(_t) cnt[_t]
void mkc(TREE2,int x,int c)
{
     int p = ++t1;
     if(_t != 0) LEF(p) = LEF(_t),RIG(p) = RIG(_t);
     S(p)=S(_t)+c;
     _t = p;if(_l == _r) return ;
     M;if(x <= mid)  mkc(LEFT,x,c); else mkc(RIGHT,x,c);
     return ;
}
int query(int k)
{
  int _l = 1,_r = low;
  while(_l<_r)
  {
   int s = 0;
   for(int i = 1;i<=SIZE(qt);++i)
     s += S(LEF(qt[i]));
   M;
   if(k <= s){_r = mid;for(int i = 1;i<=SIZE(qt);++i) qt[i] = LEF(qt[i]);} 
   else{k-=s;_l = mid+1;for(int i = 1;i<=SIZE(qt);++i) qt[i] = RIG(qt[i]);}
  }
  return (_l+_r)>>1;
}
#undef S
#undef LEF
#undef RIG
#undef MN
//part 2
#define MN 3000010
int a[MN],o3[MN],o4[MN],t[MN],t2;
#define LEF(_t) o3[_t]
#define RIG(_t) o4[_t]
#define S(_t) t[_t]
void init()
{CLEAR(a,0xff);t2 = 0;t1 = 0;}
int ref;
void mkch(TREE2,int x,int c)
{
 if(_t == 2) 
  _t = 2;
 if(_t == 0) _t = ++t2;
 if(a[ref] != -1) mkc(S(_t),1,low,a[ref],-1);
 mkc(S(_t),1,low,c,1);
 if(_l == _r) return;
 M; if(x <= mid) mkch(LEFT,x,c); else mkch(RIGHT,x,c); 
}
void query(TREE,int l,int r)
{
     if(_t == 0) return;
     if(l<=_l && r>= _r){
              ++SIZE(qt);qt[SIZE(qt)] = S(_t); 
     return;}
     M;if(l <= mid) query(LEFT,l,r);if(r >= mid) query(RIGHT,l,r);
     return;
}
//part 3 user design
int rt,b[MN],c[MN];
#undef MN
#undef TRA
#define TRA(x,y) for(int x = st[y],v;~x;x=lk[x].n) if(!lk[x].f)
#define MN  2010
struct edge{ int f,v,n;};
edge lk[MN*2];int st[MN],size[MN],tot,n,m,q[MN],r,son[MN],fa[MN],pfa[MN],q2[MN],r2,dep[MN],num[MN];
void addedge(int x,int y){lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;++tot;}
void queryont(int x,int y)
{
    while(x != y)
    {
     if(pfa[x] == pfa[y] && pfa[x] != 0){
      if(num[x] > num[y]) swap(x,y);
      query(rt,1,n,num[x],num[y]);
      return;
     }
     else{
      if(dep[pfa[x]?pfa[x]:fa[x]] < dep[pfa[y]?pfa[y]:fa[y]]) swap(x,y);
      if(pfa[x])
       query(rt,1,n,num[pfa[x]]+1,num[x]);
      else
       query(rt,1,n,num[x],num[x]);
      x = pfa[x]?pfa[x]:fa[x];
     }
    }
    query(rt,1,n,num[x],num[x]);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    CLEAR(st,0xff);
    n = gi;m = gi;
    for(int i = 1,x;i<=n;++i){x = gi; b[i] = c[i] = x;}
    SIZE(c) = n;
    for(int i = 1,x,y;i<n;++i){
             x =gi;y=gi;
             addedge(x,y);addedge(y,x);}
    for(int i = 1,x,y,z;i<=m;++i)
    {
     int opt = gi;
     switch(opt){
      case 1:
           x = gi, y = gi,z = gi;
           break;
      case 2:
           x = gi, y = gi;
           c[++SIZE(c)] = y;
           break;
     }
    }
    setIO("sample");
    n = gi,m = gi;
    for(int i = 1,x;i<=n;++i) x = gi;
    sort(c+1,c+1+SIZE(c));
    low = unique(c+1,c+1+SIZE(c))-c;--low;
    for(int i = 1,x,y;i<n;++i) 
     x =gi,y=gi;
    q[r = 1] = 1;
    dep[1] = 1;
    for(int i = 1,u;i<=r;++i)
     TRA(j,(u = q[i])){v = lk[j].v,++r,q[r] = v,lk[j^1].f = 1;dep[v] = dep[u]+1;}
    for(int i = r,u;i>=1;--i){
     size[ u = q[i]] = 1;
     TRA(j,q[i]){v = lk[j].v,size[u] += size[v];fa[v] = u;
     if(size[v] > size[son[u]]) pfa[son[u]] = 0,son[u] = v,pfa[v] = u;}
    }
    for(int i = r,u;i>=1;--i)
     if(son[u = q[i]] == 0)
     {
      int p ,k;
      for(p = u;pfa[p];p = fa[p]);
      ++SIZE(num);num[p] = SIZE(num);
      for(k = son[p];k;k=son[k]){ pfa[k] = p;++SIZE(num);num[k] = SIZE(num);}
     }
    for(int i = 1;i<=n;++i){ 
     b[i] = lower_bound(c+1,c+1+low,b[i])-c;
     mkch(rt,1,n,num[i],b[i]);
     a[i] = b[i];
    }
    for(int i = 1,opt,x,y,z;i<=m;++i){
     opt = gi;
     switch(opt){
      case 1:
           x = gi, y = gi,z = gi;
           SIZE(qt) = 0;
           queryont(x,y);
           printf("%d\n",c[query(z)]);
           break;
      case 2:
           x = gi, y = gi;
           ref = x;
           y = lower_bound(c+1,c+1+low,y)-c;
           mkch(rt,1,n,num[x],y);
           a[x] = y;
           break;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
