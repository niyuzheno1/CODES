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


#define MT 10+10
#define MN 1865060

const char unans[] = "Orz, I cannot find x!";

typedef long long ll;

ll gcd(ll a,ll b)
{
          return !b ? a:gcd(b,a%b);
}

ll exgcd(ll a,ll b,ll& x,ll & y){
  if(!b) {x = 1,y = 0;return a;}
  ll g = exgcd(b,a%b,x,y);
  ll t = x;x = y;y = t-(a/b)*y;
  return g;
}

ll pow2(ll a,int b,ll F){
 if(b ==0 ) return 1;
 if(b == 1) return a;
 ll c = pow2(a,b/2,F);
 c = c*c%F;
 if(b & 1) c = c*a%F;
 return c;
}

void Modp(ll a,ll b,ll p){
 ll x,y;
 ll g = exgcd(a,p,x,y),d;
 if(b % g){puts(unans);return;}
 d = b/g;x *= d,y *= d;
 x = (x+abs(x)/p*p+p)%p;
 printf(I64D,x);printf("\n");
}

int h[MN] = {0};
ll hnum[MN] = {0};
int hash(ll x){
 int i = x%MN;
 while(h[i] && hnum[i] != x) i =(i+1)%MN;
 hnum[i] = x;
 return i;
}

void babystep(ll a,ll b, int p ){
 int m = sqrt(p);while(m * m < p) ++m;
 ll res =  b, ans = - 1;     
 ll uni = pow2(a,m,p);
 if(!uni){ if(!b) ans = 1;else ans = -1;}
 else
 {
  for(int i = 0;i<=m;++i)
  {
   int t = hash(res);
   h[t] = i+1;
   res = (res*a)%p;
  }
  res = uni;
  for(int i = 0;i<=m;++i){
   int t = hash(res);
   if(h[t])
   { 
   ans=i*m-(h[t]-1);
   break;
   }
   else
    hnum[t] = 0;
   res = (res*uni)%p;
  }
  res = b;
  for(int i = 0;i<MN;++i) h[i] = hnum[i] = 0;
 }
 if(ans >-1 ) printf(I64D,ans),printf("\n");
 else puts(unans);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    int T,K,y,z,p;
    while(scanf("%d%d",&T,&K)==2){
     for(int i = 1;i<=T;++i)
     {
      scanf("%d%d%d",&y,&z,&p);
      if(K == 1)
       printf(I64D,pow2(y,z,p)),printf("\n");
      else if(K == 2)
       Modp(y,z%p,p);
      else
       babystep(y,z%p,p);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
