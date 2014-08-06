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

const int64 MN = 11,mod = 9973; 
int64 n ,k;
class mat
{
public:
 int64 a[MN][MN];
 mat()
 {
 CLEAR(a,0);
 }
 void operator =(mat y) 
 {
  for(int64 i = 1;i<=n;++i)
   for(int64 j = 1;j<=n;++j)
    a[i][j] = y.a[i][j];
 }
 mat operator *(mat & y)
 {
  mat tmp;
  for(int64 i = 1;i<=n;++i)
   for(int64 j = 1;j<=n;++j)
    for(int64 k = 1;k<=n;++k)
     tmp.a[i][j] += ((a[i][k])%mod*(y.a[k][j])%mod)%mod,tmp.a[i][j] %= mod;
  return tmp;
 }
};
bool flag;
mat m;
void PowM(mat & u,int64 x)
{
 mat a=m,b=m;
 while(x)
 {
  if(x & 1)
   b = b*a;
  x/=2;
  a = (a*a);
 }
 u = b;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int64 T =gi;
    while(T--)
    {
     n = gi; k = gi;flag = 0;
     for(int64 i = 1;i<=n;++i)
      for(int64 j = 1;j<=n;++j)
       m.a[i][j] = gi;
      mat a;
      PowM(a,k-1);
      int64 ans = 0;
      for(int64 i = 1;i<=n;++i)
       ans += a.a[i][i],ans%=mod;
      printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
