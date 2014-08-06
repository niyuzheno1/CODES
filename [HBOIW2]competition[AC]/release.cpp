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


#define MN 2010
const int64 MOD = 1000000000LL+9LL;
int64 r[MN],a[MN],b[MN],f[MN][MN],g[MN][MN],c[MN][MN],t[MN];

void modadd(int64 & a,int64 b,int64 c)
{
  a = b+c;
  while(a < 0) a += MOD;
  while(a > MOD) a-=MOD;
}
void modmut(int64 & a,int64 b,int64 c)
{
  a = ((c%MOD)*(b%MOD))%MOD;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi,k = gi;
    c[0][0] = 1;
    if((n-k)&1){
     puts("0");
     closeIO();return 0;
    }
    k = (n-k)/2+k;
    for(int i = 0;i<n;++i) a[i] = gi;
    sort(a,a+n);
    for(int i = 0;i<n;++i) b[i] = gi;
    sort(b,b+n);
    for(int i = 1;i<=MN;++i)
     for(int j = 0;j<=i;++j)
      if(j == 0) c[i][0] = 1;
      else modadd(c[i][j],c[i-1][j],c[i-1][j-1]);
    t[0] = 1;
    for(int i = 1;i<=n;++i)
     modmut(t[i],t[i-1],i);
    for(int i = 0;i<n;++i)
    {
       if(i != 0) r[i] = r[i-1];
       while(r[i] < n && b[r[i]] < a[i]) ++ r[i];
    }
    f[0][0] = 1;
    for(int i = 0;i<n;++i)
     for(int j = 0;j<=i;++j)
     {
      if(f[i][j] == 0) continue;
      int64 tmp = 0;
      modmut(tmp,f[i][j],max(0LL,r[i]-j));
      modadd(f[i+1][j+1],tmp,f[i+1][j+1]);
      modadd(f[i+1][j],f[i][j],f[i+1][j]);
     }
    for(int i = n;i>=0;--i){
     modmut(f[n][i],f[n][i],t[n-i]);
     for(int j = i+1;j<=n+1;++j)
      {
       int64 tmp = 0;
       modmut(tmp,f[n][j],c[j][i]);
       modadd(f[n][i],f[n][i],-tmp);
      }
    }
    printf("%d\n",f[n][k]);
    closeIO();
    return EXIT_SUCCESS;
}
