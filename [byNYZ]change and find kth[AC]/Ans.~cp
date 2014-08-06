#include "mode.h"
#include "data.h"
//preprocess
#define SIZE(a) a[0]
//part 1
#define MN 5010
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
#define MN 5010
int a[MN],o3[MN],o4[MN],t[MN],t2,tt;
#define LEF(_t) o3[_t]
#define RIG(_t) o4[_t]
#define S(_t) t[_t]
void init()
{CLEAR(a,0xff);t2 = 0;t1 = 0;}
void mkch(TREE2,int x,int c)
{
 if(_t == 2) 
  _t = 2;
 if(_t == 0) _t = ++t2;
 if(a[x] != -1) mkc(S(_t),1,low,a[x],-1);
 mkc(S(_t),1,low,c,1);
 if(_l == _r) return;
 M; if(x <= mid) mkch(LEFT,x,c); else mkch(RIGHT,x,c); 
}
void query(TREE,int l,int r)
{
     if(_t == 0) return;
     if(l<=_l && r>= _r){++SIZE(qt);qt[SIZE(qt)] = S(_t); return;}
     M;if(l <= mid) query(LEFT,l,r);if(r >= mid) query(RIGHT,l,r);
     return;
}
//part 3 user design
int n,m,rt,b[MN],c[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    n = gi;m = gi;
    for(int i = 1;i<=n;++i)
     c[i] = b[i] = gi;
    tt = n;
    for(int i = 1,x,y,z;i<=m;++i)
    {
     int opt = gi;
     switch(opt){
      case 1:
           x = gi, y = gi,z = gi;
           break;
      case 2:
           x = gi, y = gi;
           ++tt;
           c[tt] = y;
           break;
     }
    }
    setIO("sample");
    n = gi,m = gi;
    for(int i = 1,x;i<=n;++i) x = gi;
    sort(c+1,c+1+tt);
    low = unique(c+1,c+1+tt)-c;--low;
    for(int i = 1;i<=n;++i){
     b[i] = lower_bound(c+1,c+1+low,b[i])-c;
     mkch(rt,1,n,i,b[i]);
     a[i] = b[i];
    }
    
    for(int i = 1,x,y,z;i<=m;++i){
     int opt = gi;
     switch(opt){
      case 1:
           SIZE(qt) = 0;
           x = gi, y = gi,z = gi;
           query(rt,1,n,x,y);
           printf("%d\n",c[query(z)]);
           break;
      case 2:
           x = gi, y = gi;
           y = lower_bound(c+1,c+1+low,y)-c;
           mkch(rt,1,n,x,y);
           a[x] = y;
           break;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
