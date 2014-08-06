#ifdef SPLAY
#define L C[0]
#define R C[1]
#define F C[2]
#endif
#ifdef SSPLAY
#define L 0
#define R 1
#define F 2
#endif
#ifdef SGT
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LEF(_t),_l,mid
#define RIGHT RIG(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}
#endif
