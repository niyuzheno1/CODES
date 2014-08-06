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

const int64 N = 100000100,P = 5761461+10;
char p[N],prime[P],mu[N];
int64 a[21];
void init()
{
 int64 tot = 0;
 mu[1] = p[1] = 1;
 for(int64 i = 2;i<=N-10;++i)
 {
  if(!p[i]){prime[++tot] = i;mu[i] = -1;}
  for(int64 j = 1;j<=tot;++j)
  {
  int64 y = prime[j];
  if(i*y > (N-10)) break;
  if(mu[i] && (i%y != 0))
   mu[i*y] = mu[i]*mu[y];
  p[i*y] = 1;
  if(i%y == 0) break;
  }
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    int64 T = gi;
    while(T--)
    {
     int64 n = gi;
     int64 minval = INF;
     for(int64 i = 1;i<=n;++i)
      a[i] = gi,minval = min(minval,a[i]);
     int64 ans = 0;
     for(int64 i = 1;i<=minval;++i)
     {
      int64 tmp = 1;
      for(int64 j = 1;j<=n;++j)
       tmp *= (a[j]/i);
      ans += tmp*mu[i];
     }
     printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
