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

const int MM = 3,mod = 10000,MN = 2;
int n;
class Mat
{
public:
 int a[MM][MM];
 Mat()
 {CLEAR(a,0);}
 void operator =(Mat b)
 {
  for(int i = 1;i<=MN;++i)
   for(int j = 1;j<=MN;++j)
    a[i][j] = b.a[i][j];
 }
 Mat operator * (Mat & b)
 {
  Mat c;
  for(int i = 1;i<=MN;++i)
   for(int j = 1;j<=MN;++j)
    for(int k = 1;k<=MN;++k)
     c.a[i][j] += (a[i][k])%mod*(b.a[k][j])%mod,c.a[i][j] %= mod;
  return c;
 }
};
Mat m,a;
inline void PowK(Mat & c,int x)
{
 Mat u = m,v = m;
 while(x)
 {
   if(x & 1) u = u*v;
   x>>=1;
   v = v*v;
 }
 c = u;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    m.a[1][1] = 1;m.a[1][2] = 1;
    m.a[2][1] = 1;m.a[2][2] = 0;
    while(1)
    {
     n = gi;if(!(~n)) break;
     if(n == 0)
      puts("0");
     else
     {
      PowK(a,n-1);
      printf("%d\n",(a.a[2][1]*1+a.a[2][2]*0)%mod);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
