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
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\





#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
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
const int INF =  1000000010;
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file)
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

#undef L
#undef R
#define _bound(L,R,x) dblcmp(L-x)<=0 && dblcmp(R-x)>=0
typedef double ld;
typedef pair<ld,ld> pdd;
const int MN = 510;
const double eps = 10e-5;
pdd s[MN],t[MN],c[MN];
int n = 0;ld ag = 0.0,sm = 0.0;
int dblcmp(double x){if(abs(x) < eps) return 0;if(x < 0) return -1;return 1; }
double f(double x)
{
 double ret = 0.0;
 for(int i = 1;i<=n;++i)
  if(_bound(s[i].X,t[i].X,x))
   ret = max(ret , s[i].Y + (x-s[i].X)/(t[i].X-s[i].X)*(t[i].Y-s[i].Y));
 for(int i = 1;i<=n+1;++i)
  if(_bound(c[i].X-c[i].Y,c[i].X+c[i].Y,x))
   ret = max(ret , sqrt(sqr(c[i].Y)-sqr(c[i].X-x)));
 return ret;
}
double simpson(double l,double r)
{
 return (f(l)+f(r)+4*f((l+r)/2.0))*(r-l)/6.0;
}
double rsimpson(double L,double R)
{
  double mid = (L+R)/2.0;
  if(dblcmp(simpson(L,R)-(simpson(L,mid)+simpson(mid,R))) == 0)
   return simpson(L,R);
  return rsimpson(L,mid)+rsimpson(mid,R);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    
    scanf("%d%lf",&n,&ag);
    ag = 1.0/tan(ag);
    double L = 0.0,R = 0.0;
    for(int i = 1;i<=n+1;++i)
    {
     scanf("%lf",&c[i].X);sm += c[i].X;c[i].X = sm * ag;
    }
    for(int i = 1;i<=n;++i) scanf("%lf",&c[i].Y);L = c[1].X;R = c[n+1].X;
    for(int i = 1;i<=n;++i)
    {
     L = min(L,c[i].X-c[i].Y),R = max(R,c[i].X+c[i].Y);
     if(dblcmp(c[i+1].X-c[i].X-fabs(c[i+1].Y-c[i].Y)) > 0){
     double o = (c[i+1].Y-c[i].Y)/(c[i+1].X-c[i].X);
     s[i] = MP(c[i].X-c[i].Y*o,c[i].Y*sqrt(1-o*o));
     t[i] = MP(c[i+1].X-c[i+1].Y*o,c[i+1].Y*sqrt(1-o*o));
     }
    }
    printf("%.2lf\n",2*rsimpson(L,R));
    closeIO();
    return EXIT_SUCCESS;
}
