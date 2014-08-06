#include "mode.h"
#include "data.h"

using namespace std;
#define MN 1010
struct ch
{
 int len[3];//0 L 1 R 2 M
 int l[2];
 ch(){ CLEAR(l,0);CLEAR(len,0);}
};
void merge(ch & _a,ch & b,ch & c)
{
 ch tmp;tmp.len[0] = b.len[0];tmp.len[1] = c.len[1];
 if(b.l[1] == c.l[0] && b.len[0]==b.len[1] )tmp.len[0] = b.len[0]+c.len[0];
 if(b.l[1] == c.l[0] && c.len[0]==c.len[1] )tmp.len[1] = b.len[1]+c.len[1];
 if(b.l[1] == c.l[0]) tmp.len[2] = b.len[1]+c.len[0];
 for(int i = 0;i<=1;++i) tmp.len[2] = max(tmp.len[2],tmp.len[i]);
 tmp.l[0] = b.l[0];tmp.l[1] = b.l[1];
 _a = tmp;
}
int o1[MN],o2[MN],tag[MN];
ch m[MN];
#define LCH(x) o1[x]
#define RCH(x) o2[x]
#define t(x) tag[x]
#define s(x) m[x]
void updata(int x) {merge(s(x),s(LCH(x)),s(RCH(x)));}
void pushdown(int x,int _l,int _r){
M;
s(LCH(x)).l[0] = s(LCH(x)).l[1] = t(x);
for(int i  = 0 ;i<= 2;++i)s(LCH(x)).len[i] = mid-_l+1; 
s(RCH(x)).l[0] = s(RCH(x)).l[1] = t(x);
for(int i  = 0 ;i<= 2;++i)s(RCH(x)).len[i] = _r-mid;
s(x) = ch(),t(x) = 0;
}
void build(TREE2)
{
     if(_t == 0)_t = ++SIZE(o1);
     if(_l == _r){for(int i = 0;i<=2;++i)s(_t).len[i] = 1;for(int i = 0;i<=1;++i)s(_t).l[i] = 0; return;}
     M;build(LEFT),build(RIGHT);
     updata(_t);
     return ;
}
void change(TREE,int l,int r,int x)
{
     if(tag[_t] && _l != _r) pushdown(_t,_l,_r);
     if(l<=_l && _r <= r)
     {
      t(_t) = x;
      s(_t).l[0] = s(_t).l[1] = x;
      for(int i = 0 ;i<= 2;++i) s(_t).len[i] = _r-_l+1;
      return;
     }
     M;
     if(l <= mid) change(LEFT,l,r,x);
     if(r >  mid) change(RIGHT,l,r,x);
     if(_l != _r )updata(_t);
     return ;
}

ch query(TREE,int l,int r)
{
  ch ret1,ret2,ret;
  int flag1 = 0,flag2 = 0;
  if( l<=_l && _r <= r) return s(_t);
  M;
  if(l <= mid) flag1 = 1,ret1 = query(LEFT,l,r);
  if(r >  mid) flag2 = 1,ret2 = query(RIGHT,l,r);
  if(flag1 && flag2)
   merge(ret,ret1,ret2);
  else if(flag1)ret = ret1;
  else ret = ret2;
  return ret;
}

#undef t
#undef s
#undef LCH 
#undef RCH
int n,rt,u;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,u=gi;
    build(rt,1,n);
    for(int i = 1;i<=n;++i){
     int x = gi;
     change(rt,1,n,i,i,x);
    }
    for(int i = 1,opt,x,y,z;i<=u;++i){
     opt = gi;
     switch(opt){
     case 1:
          x = gi,y = gi,z=gi;
          change(rt,1,n,x,y,z);
          break;
     case 2:
          x = gi,y = gi;
          printf("%d\n",(query(rt,1,n,x,y)).len[2]);
          break;
     }
    }
     
    closeIO();
    return EXIT_SUCCESS;
}
