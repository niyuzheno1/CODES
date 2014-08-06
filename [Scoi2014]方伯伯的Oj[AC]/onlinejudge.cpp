#include "mode.h"
#include "data.h"
#define MN 5001000
const int N = 200000000;
int lef[MN],righ[MN],tag[MN],V;
#define LEF(t) lef[t]
#define RIG(t) righ[t]
void _initsgt()
{
  CLEAR(lef,0);CLEAR(righ,0);CLEAR(tag,0);
  tag[V = 1] = 0;
}
void pd(int & _t,int & _l,int & _r){_l = _t;_r = _t;_t = 0;}
void mkc(TREE,int l,int r,int c)
{
     if(_l < _r)
     {
      LEF(_t) == 0 ? LEF(_t) = ++V : 0;
      RIG(_t) == 0 ? RIG(_t) = ++V : 0;
      if(tag[_t])
       pd(tag[_t],tag[LEF(_t)],tag[RIG(_t)]);
     }
     if(_l == l && _r == r){
      tag[_t] = c;
      return;
     }M;
     if(r <= mid ) mkc(LEFT,l,r,c);
     else if(l > mid) mkc(RIGHT,l,r,c);
     else mkc(LEFT,l,mid,c),mkc(RIGHT,mid+1,r,c);
}
int query(TREE,int x)
{
 if(tag[_t]) return tag[_t];
 if(_t == 0) return 0;
 M;if(x <= mid)return query(LEFT,x); else return query(RIGHT,x);
}
#undef MN
#define MN 501000
struct ttype {int C[3];};
ttype t[MN];
int SUM[MN],right_range[MN],left_range[MN],root,Vv,n,m;
#define S(_t) SUM[_t]
#define RR(_t) right_range[_t]
#define LL(_t) left_range[_t]
#define UPD(_t,_x,_y) _t = _x , t[_t].F = _y;
void _initsplay(){
     CLEAR(t,0);CLEAR(SUM,0);CLEAR(right_range,0);CLEAR(left_range,0);
     Vv = root = 1,S(1) = n,LL(1) = 1,RR(1) = n;
}
void upd(int u)
{
 if(u != 0) S(u) = S(t[u].L)+S(t[u].R)+RR(u)-LL(u)+1;
}
void rotate(int x)
{
     int y = t[x].F;int z = t[y].F;int d1 = (t[y].L == x);int d2 = (t[z].R == y);
     UPD(t[y].C[!d1],t[x].C[d1],y);UPD(t[x].C[d1],y,x);UPD(t[z].C[d2],x,z);
     upd(y);upd(x);upd(z);
}
void splay(int x,int v)
{
     while(t[x].F != v)
     {int y = t[x].F; int z = t[y].F;
      if(z != v && (t[y].L == x)==(t[z].L == y)) rotate(y);
      rotate(x);}
     if(!v) root = x;
     upd(x);
}
void Get(int p,int x){
 splay(x,0);
 if(LL(x) < p){
  int k = ++Vv;
  if(x == 4)
   x = 4;
  LL(k) = LL(x),RR(k) = p-1;
  upd(t[t[k].L = t[x].L].F = k);
  upd(t[t[x].L = k].F = x);
  mkc(1,1,N,LL(k),RR(k),k);
 }
 if(RR(x) > p){
  int k = ++Vv;
  LL(k) = p+1,RR(k) = RR(x);
  upd(t[t[k].R = t[x].R].F = k);
  upd(t[t[x].R = k].F = x);
  mkc(1,1,N,LL(k),RR(k),k);
 }
 LL(x) = RR(x) = p;
}
int Max(int x){
     for(;t[x].R;x = t[x].R);
     return x;
}
int Min(int x){
     for(;t[x].L;x = t[x].L);
     return x;
}
int Select(int s){
 int x;
 for(x = root;;){
  if(s >= S(t[x].L) && s-S(t[x].L) < RR(x)-LL(x)+1)
  { s-=S(t[x].L);break;}
  if(s < S(t[x].L)) x = t[x].L;
  else  s-=S(t[x].L)+RR(x)-LL(x)+1, x = t[x].R;
  
 }
 splay(x,0);
 return LL(x)+s;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;m = gi;_initsgt();_initsplay();
    mkc(1,1,N,1,n,1);
    int ans  = 0;
    while(m--){
     int a = gi,b = gi,c,d;
     b-=ans;
     if(a == 1){
      c = gi;c-=ans;
      d = query(1,1,N,b);
      Get(b,d);
      printf("%d\n",ans = S(t[d].L)+1);
      mkc(1,1,N,b,b,0);
      mkc(1,1,N,c,c,d);
      LL(d) = RR(d) = c;
     }else if(a == 2){
      c = query(1,1,N,b);
      Get(b,c);
      printf("%d\n",ans = S(t[c].L)+1);
      if(t[c].L){
       splay(d = Max(t[c].L),c);
       upd(t[t[d].R = t[c].R].F = d);
       t[c].L = 0;upd(t[t[c].R = d].F = c);
      }
     }else if(a == 3){
      c = query(1,1,N,b);
      Get(b,c);
      printf("%d\n",ans = S(t[c].L)+1);
      if(t[c].R){
       splay(d = Min(t[c].R),c);
       upd(t[t[d].L = t[c].L].F = d);
       t[c].R = 0;
       upd(t[t[c].L = d].F = c);
      }
     }else printf("%d\n",ans = Select(b-1));
    }
    closeIO();
    return EXIT_SUCCESS;
}
