#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].f)
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
#define SIZE(a) a[0]
#define INF  1000000010
using namespace std;
typedef  double ld;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file = "sample")
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}

void endline()
{
     ff(debug,"\n");
}

#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LCH(_t),_l,mid
#define RIGHT RCH(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}

typedef long long LL;
const LL modd = 1000000009LL;
#define MN 300005
struct ma{
       LL a[3][3];
};
ma mut(ma x,ma y)
{
 ma re;
 CLEAR(re.a,0);
 for(int i = 0 ;i<3;++i)
  for(int j = 0;j<3;++j)
   for(int k = 0;k<3;++k)
    re.a[i][j] = (re.a[i][j]+x.a[i][k]*y.a[k][j])%modd;
  return re;
}
void addmod(LL & x,LL y,LL z)
{
     y %= modd; z  %= modd;
     x = y+z;
     while(x>=modd) x-=modd;
     while(x < 0) x+= modd;
}
ma a[MN];
int n,m,y[MN];
LL sum[MN*4],c1[MN*4],c2[MN*4],l[MN*4],r[MN*4];
#define LCH(_t) _t*2
#define RCH(_t) _t*2+1
void upd(int _t)
{
     addmod(sum[_t],sum[LCH(_t)],sum[RCH(_t)]);
}
LL f(LL p,LL q,int k)
{
     LL re;
     addmod(re,a[k-1].a[0][0]*p,a[k-1].a[0][1]*q);
     return re;
}
LL s(LL p,LL q,int k)
{
        LL re;
        addmod(re,a[k].a[2][0]*p,a[k].a[2][1]*q);
        return re;
}
void pd(int o)
{
     LL d1,d2;
     if(c1[o] || c2[o])
     {
      addmod(c1[LCH(o)],c1[LCH(o)],c1[o]);
      addmod(c2[LCH(o)],c2[LCH(o)],c2[o]);
      addmod(sum[LCH(o)],sum[LCH(o)],s(c1[o],c2[o],r[LCH(o)]-l[LCH(o)]+1));
      d1 = f(c1[o],c2[o],r[LCH(o)]-l[LCH(o)]+2);
      d2 = f(c1[o],c2[o],r[LCH(o)]-l[LCH(o)]+3);
      addmod(c1[RCH(o)],c1[RCH(o)],d1);
      addmod(c2[RCH(o)],c2[RCH(o)],d2);
      addmod(sum[RCH(o)],sum[RCH(o)],s(d1,d2,r[RCH(o)]-l[RCH(o)]+1));
      c1[o] = c2[o] = 0;
     }
}
void mkt(TREE)
{
     l[_t] = _l;r[_t] = _r;c1[_t] = c2[_t] = 0;
     if(_l == _r)
     {
      sum[_t] = y[_l];
      return;
     }
     M;
     mkt(LEFT);mkt(RIGHT);
     upd(_t);
}
LL getsum(TREE,int l,int r)
{
 if(l<=_l && _r <= r) return sum[_t];
 pd(_t);
 M;
 LL ret = 0;
 if(l <= mid) addmod(ret,ret,getsum(LEFT,l,r));
 if(r > mid) addmod(ret,ret,getsum(RIGHT,l,r));
 return ret;
}
void change(TREE,int l,int r,LL f1,LL f2)
{
     if(l<=_l && _r <= r){
      addmod(c1[_t],c1[_t],f1);
      addmod(c2[_t],c2[_t],f2);
      addmod(sum[_t],sum[_t],s(f1,f2,_r-_l+1));
      return;
     }
     pd(_t);
     M;
     if(r<=mid) change(LEFT,l,r,f1,f2);
     else if(l > mid) change(RIGHT,l,r,f1,f2);
     else
     {
         change(LEFT,l,mid,f1,f2);
         change(RIGHT,mid+1,r,f(f1,f2,mid-l+2),f(f1,f2,mid-l+3));
     }
     upd(_t);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi,m = gi;
    for(int i  =1;i<=n;++i) y[i] = gi;
    for(int i = 0;i<=2;++i) a[0].a[i][i]=1;
    a[1].a[0][1]=a[1].a[1][0]=a[1].a[1][1]=a[1].a[2][0]=a[1].a[2][2]=1;
    for(int i = 2;i<=n;++i) a[i] = mut(a[i-1],a[1]);
    mkt(1,1,n);
    for(int i = 1;i<=m;++i)
    {
     int o=gi,p=gi,q=gi;
     if(o == 1) change(1,1,n,p,q,1LL,1LL);
     else printf("%I64d\n",getsum(1,1,n,p,q));
    }
    closeIO();
    return EXIT_SUCCESS;
}
