#include "mode.h"
const int MN = 1010;
int lef[MN],righ[MN],tag[MN],V;
#define LEF(t) lef[t]
#define RIG(t) righ[t]
#include "data.h"
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
      if(tag[_t] == 1)
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

int main(int argc, char *argv[])
{
    setIO("Segtree");
    int n =  10;
    _initsgt();
    mkc(1,1,n,1,5,2);
    printf("%d\n",query(1,1,n,5));
    printf("%d\n",query(1,1,n,6));
    closeIO();
    return EXIT_SUCCESS;
}
