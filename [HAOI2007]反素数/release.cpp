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

#define MM 40
typedef long long LL;
int prime[MM],p[MM],tot;
void si()
{
     for(int i = 2;i<MM;++i)
     {
      if(!p[i])++tot,prime[tot]=i;
      for(int j = 1;j<=tot;++j)
      {
       int u = prime[j]*i;
       if(u >= MM)break;
       p[u] = 1;
       if(u % i == 0) break;
      }
     }prime[0]=1;
}
int ans = 1,cnt = 1,n;
void dfs(LL x,LL y,LL z,LL w)
{
     if(x == 12)
     {
      if(y > ans && z>cnt){ans = y;cnt = z;}
      if(y <= ans && z >= cnt){ans = y;cnt = z;}
      return;
     }
     LL t = 1;
     for(int i = 0;i<=w;++i)
     {
      dfs(x+1,y*t,z*(i+1),i);
      t *= prime[x];
      if(y*t>n)break;
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;si();
    dfs(1,1,1,20);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
