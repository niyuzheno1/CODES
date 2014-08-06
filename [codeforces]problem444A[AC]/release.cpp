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

//algorithm.h
template<class type,type Mod>
inline type & add(type & a,const type & b,const type & c)
{
    a = b+c;
    if(a>=Mod) a-= Mod;
    return a;
}

template<class type,type Mod>
inline type &sub(type & a,const type &b,const type & c)
{
   a= b-c;
   if(a<0) a+=Mod;
   return a;
}

template<class type,type Mod>
inline type &mut(type & a,const type & b,const type & c)
{
   a = ((b%Mod)*(c%Mod))%Mod;
   return a;
}
#ifdef DIVONMOD
template<class type,type Mod>
inline type &div(type & a,const type & b,const type & c)
{
   type u = 0,v = 0;
   type d = exgcd(a,Mod,u,v);
   a = ((b%Mod)*(d%Mod))%Mod;
   return a;
}
#endif
template<class type>
inline type & up(type & u, type v)
{
       if(v > u) u = v;
       return u;
}
template<class type>
inline type & dn(type & u, type v)
{
       if(v < u) u = v;
       return u;
}

#define MN 510
int n,m;
double a[MN];
double ans = 0.0;
int main(int argc, char *argv[])
{
    setIO("sample");
    cin>>n>>m;
    for(int i = 1;i<=n;++i) cin>>a[i];
    for(int i = 1,x,y;i<=m;++i)
    {
     double c = 0.0;
     cin>>x>>y>>c;
     up(ans,(a[x]+a[y])/c);
    }
    printf("%.9lf",ans);
    closeIO();
    return EXIT_SUCCESS;
}
