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

typedef long long LL;
const LL mod  = 1000000007;
int gcd(int x,int y)
{
    if(y == 0) return x;
    return gcd(y,x%y);
}
void mutmod(LL & u,LL v,LL w)
{
     u = ((v%mod)*(w%mod))%mod;
}
#define MN 100010
int a[MN],vis[MN];

int main(int argc, char *argv[])
{
    setIO("sample");
    int T;
    scanf("%d",&T);
    while(T--)
    {
     vector<int> o;
     int n;scanf("%d",&n);CLEAR(vis,0);
     for(int i =1;i<=n;++i) scanf("%d",&a[i]);
     LL ret = 1;
     for(int i =1;i<=n;++i)
     if(!vis[i]){
             vis[i] = 1;
             int s = 1;
             int u = a[i];
             while(!vis[u])
             {
              vis[u] = 1;
              ++s;u = a[u];
             }
     o.pb(s);
     }
     int u = o[0];
     for(int i = 1;i<o.size();++i)
      u = gcd(u,o[i]);
     ret = o[0];
     for(int i = 1;i<o.size();++i)
     {
      mutmod(ret,ret,o[i]/u);
     }
     printf(I64D,ret);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
