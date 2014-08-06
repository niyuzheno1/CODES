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

const int64 MN  = 10000010,N = MN-10;
int64 mu[MN],prime[MN],p[MN];
void init()
{
 int64 tot = 0;
 p[1] = mu[1] = 0;
 for(int64 i = 2;i<=N;++i)
 {
  if(!p[i]){prime[++tot] = i;mu[i] = 1;}
  for(int64 j = 1;j<=tot;++j)
  {
   int64 t = prime[j]; if(i * t > N ) break;p[i * t] = 1;      
   
   if(i % t == 0){ 
        mu[i*t] = 0;
        break;
   }
   mu[i*t] = -mu[i];
  
  }
 }
 for(int64 i = 2;i<=N;++i)
  if(mu[i])
   for(int64 j = i;j<=N ;j*=i)
    mu[j] = mu[i];
 for(int64 i = 2;i<=N;++i)
  mu[i] += mu[i-1];
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    int64 t = gi;
    while(t--)
    {
     int64 a = gi,b = gi,ans = 0;if(a>b)swap(a,b);
     for(int64 i = 1;i<=a;++i)
     {
      int64 t = min(a/(a/i),b/(b/i));
      ans += (mu[t]-mu[i-1])*(a/i)*(b/i);
      i = t;
     }
     printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
