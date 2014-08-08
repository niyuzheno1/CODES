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
typedef pair<int,int> _reserve_type_1;
typedef pair<int64,int64> pll;
#define pii _reserve_type_1
FILE * debug;
#define setIO _func_2_
void _func_2_(string file = "sample")
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

#define ERROR_FILE_END -1
#define FILEOF(X) func_1_(X)
int func_1_(FILE * X)
{
 int cur = ftell(X);
 fseek(X,0L,SEEK_END);
 int ret  = ftell(X);
 fseek(X,cur,SEEK_SET);
 return ret;
}
class iomgr{
 FILE * A;
 char * rb, * endb;
 int fl;
public:
 void setting(FILE * _A){
	 A = _A;fl = FILEOF(stdin);rb = new char[fl+3];fread(rb,1,fl,stdin);rb[fl] = -1;endb = rb+fl;
 }
 char exgetchar(){
	char ret = *rb; ++rb;
	return ret;
 }
 template <class T>
 void exread(T & x)
 {
  if(rb >= endb) return;
  char tmp = 0; T flag = 1,ret = 0;while(tmp != -1 && tmp != '-' && !isdigit(tmp)) tmp = exgetchar();
  if(tmp == -1) return;
  if(tmp == '-') flag = -1,tmp=exgetchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = exgetchar();
  x = flag *ret;
 }
 int64 exgetint()
 {
	int64 ret = ERROR_FILE_END;exread(ret);return ret;
 }
};
iomgr _global_reader_;
#undef setIO
void _func_3_(string file = "sample"){
 _func_2_(file);
 _global_reader_.setting(stdin);
}
#define setIO _func_3_
#undef gi
#define gi _global_reader_.exgetint()

const int modd = 10301;
#define mut(a,b) (a*b)%modd
inline int add(int x,int y){
       x += y;
       while(x >= modd) x-=modd;
       return x; 
}
inline int sub(int x,int y){
       x -= y;
       while(x < 0) x+= modd;
       return x;
}
struct node
{
       int a2,b2,ab;
       int c[5];
};
void operator >> (const node & a, node & b)
{
     int nc[5];
     nc[0] = nc[1] = nc[2] = nc[3] = 0;
     int tmpa2 = mut(mut(a.c[0],a.c[0]),b.a2);
     tmpa2 = add(tmpa2,mut(mut(a.c[0],a.c[1])*2,b.ab));
     tmpa2 = add(tmpa2,mut(mut(a.c[1],a.c[1]),b.b2));
     int tmpab = mut(mut(a.c[0],a.c[2]),b.a2);
     tmpab = add(tmpab,mut(add(mut(a.c[0],a.c[3]),mut(a.c[1],a.c[2])),b.ab));
     tmpab = add(tmpab,mut(mut(a.c[1],a.c[3]),b.b2));
     int tmpb2 = mut(mut(a.c[2],a.c[2]),b.a2);
     tmpb2 = add(tmpb2,mut(mut(a.c[2],a.c[3])*2,b.ab));
     tmpb2 = add(tmpb2,mut(mut(a.c[3],a.c[3]),b.b2));
     b.a2 = tmpa2,b.b2 = tmpb2,b.ab = tmpab;
     nc[0] = add(mut(a.c[0],b.c[0]),mut(a.c[1],b.c[2]));
     nc[1] = add(mut(a.c[0],b.c[1]),mut(a.c[1],b.c[3]));
     nc[2] = add(mut(a.c[2],b.c[0]),mut(a.c[3],b.c[2]));
     nc[3] = add(mut(a.c[2],b.c[1]),mut(a.c[3],b.c[3]));
     b.c[0] = nc[0];b.c[1] = nc[1];b.c[2] = nc[2];b.c[3] = nc[3];
}
void operator --(node & a){a.c[0] = 1,a.c[1] = 0,a.c[2] = 0,a.c[3] = 1;}
void operator ++(node & a){a.a2 = a.b2 = a.ab = 0;}
void operator <<(node & a,const node & b)
{
 a.a2 = add(a.a2,b.a2);a.b2 = add(a.b2,b.b2);a.ab = add(a.ab,b.ab);
}
#define lch(x) (x<<1)
#define rch(x) ((x<<1)+1)
#define M int mid = (l+r)>>1;
#define gol lch(t),l,mid
#define gor rch(t),mid+1,r
#define con 1,1,n
#define t1 int t,int l,int r
#define N 100010
node a[N*4],d[3];
int b[N],c[N],n,m;
void pd(int x)
{
  a[x] >> a[lch(x)];
  a[x] >> a[rch(x)];
  --a[x];
}
void upd(int x)
{
 ++a[x];
 a[x] << a[lch(x)];
 a[x] << a[rch(x)]; 
}
void build(t1)
{
     --a[t];
     if(l == r)
     {
      a[t].a2 = mut(b[l],b[l]);
      a[t].ab = mut(b[l],c[l]);
      a[t].b2 = mut(c[l],c[l]);
      return ;
     }M;build(gol);build(gor);
     upd(t);
}
void modify(t1,int ll,int rr,int opt){
     if(ll <= l && r <= rr)
     {
     int offest = (opt == 1)?1:2;
     d[offest] >> a[t];
     return ;
     }M;
     pd(t);
     if(ll <= mid) modify(gol,ll,rr,opt);
     if(rr > mid)  modify(gor,ll,rr,opt);
     upd(t);
}
int sum(t1,int ll,int rr){
  if(ll <= l && r <= rr){
        return a[t].ab;
        }
  M;
  pd(t);
  int ret = 0;
  if(ll <= mid)
   ret = sum(gol,ll,rr);
  if(rr > mid)
   ret = add(ret,sum(gor,ll,rr));
  upd(t);
  return ret;
}
int main(int argc, char *argv[])
{
    setIO("tsinsenD5530");
    d[1].c[0] = d[1].c[1] = d[1].c[3] = 1;
    d[2].c[0] = d[2].c[2] = d[2].c[3] = 1;
    n = gi;m = gi;
    for(int i = 1;i<=n;++i)
    {
     b[i] = gi%modd;
     c[i] = gi%modd;
    }
    build(con);
    for(int i = 1;i<=m;++i)
    {
     int opt = gi,x= gi,y = gi;
     if(opt <= 2)
      modify(con,x,y,opt);
     else{
      int tmp = sum(con,x,y);
      printf("%d\n",tmp%modd);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
