//for splay
#define L C[0]
#define R C[1]
#define F C[2]
//for fenwick tree
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LCH(_t),_l,mid
#define RIGHT RCH(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}
//for treap
template<class _type>
void zig(_type * & y)
{
  _type * x = y->lc;
  y->lc = x->rc;
  x->rc = y;
  y = x;
}

template<class _type>
void zag(_type * & y){
  _type * x = y->rc;
  y->rc = x->lc;
  x->lc = y;
  y = x;
}
