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

const int MN = 3,mod = 7;
class Mat
{
public:
      int a[MN+1][MN+1];
      Mat(){CLEAR(a,0);}
      void operator = (Mat  x)
      {
       for(int i = 1;i<=MN;++i)for(int j = 1;j<=MN;++j)a[i][j] = x.a[i][j];
      }
      Mat operator * (Mat &  x)
      {
       Mat tmp;
       for(int i = 1;i<=MN;++i)
        for(int j = 1;j<=MN;++j)
         for(int k = 1;k<=MN;++k)
          tmp.a[i][j] = (tmp.a[i][j]+a[i][k]*x.a[k][j])%mod,tmp.a[i][j] %= mod;
       return tmp;
      }
};
Mat m;
void PowK(Mat & c,int k)
{
 Mat u=m,v=m;
 while(k)
 {
  if(k & 1) u = u*v;
  k>>=1;
  v = v*v;
 }
 c = u;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    while(true)
    {
     CLEAR(m.a,0);
     m.a[1][1] = gi;m.a[1][2] = gi;
     m.a[2][1] = 1;m.a[3][2] = 1;
     int n = gi;--n;
     if(m.a[1][1] == 0 && m.a[1][2] == 0 && n == -1)
      break;
     Mat a;PowK(a,n);
     printf("%d\n",(1*a.a[3][1]+1*a.a[3][2]+0*a.a[3][3])%7);
    }
    closeIO();
    return EXIT_SUCCESS;
}
