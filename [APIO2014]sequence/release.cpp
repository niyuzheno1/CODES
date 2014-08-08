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

#undef pii

typedef long long ll;
typedef pair<ll,ll> pii;
pii operator -( const pii & a,const pii & b){
 return MP(a.X-b.X,a.Y-b.Y);
}
ll det(const pii & a,const pii & b){
 return a.X*b.Y-a.Y*b.X;
}
ll det (const pii & a,const pii & b,const pii & c){
 return det((b-a),(c-a));
}
#define MN 100010
#define MK 210
ll f[MN][2];
int s[MN],n,k,g[MN][MK],ans2[MK];
struct qlst{
       pii y;
       int x;
};
qlst deq[MN];
int l,r;
bool gen(pii a,pii b,pii c){
     pii B = b-a,C = c-a;
     if(B.X == 0)
     {
      if(B.Y == 0)
       return 1;
      return B.Y * C.X  <= 0;
     }
     if(C.X == 0)
     {
      if(C.Y == 0)
       return 1;
      return B.X * C.Y >= 0;
     }
     return C.Y / C.X <= B.Y / B.X;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,k = gi;
    //int tmp = det(MP(1,1),MP(2,0),MP(3,2)); => det >=0 delete
    for(int i = 1;i<=n;++i)
     s[i] = gi;
    for(int i = 1;i<=n;++i) 
     s[i] += s[i-1];
    CLEAR(f,0xfe);
    int now = 0;
    for(int i = 1;i<=k;now^=1,++i){
     l = 1; r = 0;
     if(i == 1)
      ++r,deq[r].y = MP(0,0),deq[r].x = 0;
     if(i == 2)
      i = 2;
     for(int j = 1;j<=n;++j)
     {
      while(r-l+1 >= 2 && (((deq[l+1].y.X-deq[l].y.X)==0 && (deq[l+1].y.Y-deq[l].y.Y)>=0 ) || ((deq[l+1].y.X-deq[l].y.X)!=0 &&(s[n]-s[j]) <= ((deq[l+1].y.Y-deq[l].y.Y)/(deq[l+1].y.X-deq[l].y.X)))) )
       ++l;
      if(r-l+1 >= 1){
      f[j][now] = deq[l].y.Y + (s[j]-deq[l].y.X)*(s[n]-s[j]);
      g[j][i] = deq[l].x;
      }
      else{
      f[j][now] = f[0][1];
      g[j][i] = 0; 
      }
      pii tmp = MP(s[j],f[j][now^1]);
      while(r-l+1 >= 2 && det(deq[r-1].y,deq[r].y,tmp)>=0)
       --r;
      ++r,deq[r].y = tmp,deq[r].x = j;
      f[j][now^1] = f[0][1];
     }
    }
    ll ans=-INF;
    int pos = 0;
    now ^= 1;
    for(int i = 1;i<=n;++i)
      if(f[i][now] > ans)
      {
       ans = f[i][now];
       pos = i;
      }
    printf(I64D,ans);puts("");
    now = k;
    while(now)
    {
     ans2[now] = pos;
     pos = g[pos][now];
     --now;
    }
    for(int i = 1;i<=k;++i)
     printf("%d ",ans2[i]);
    closeIO();
    return EXIT_SUCCESS;
}
