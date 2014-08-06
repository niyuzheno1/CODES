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

typedef double ld;
const int MN =  110;
int f[MN][MN];
int64 g[MN][MN];
double ans[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi, m =gi;
    CLEAR(f,0x10);
    for(int i = 1;i<=n;++i)
     f[i][i] = 0,g[i][i] = 1;
    for(int i = 1,a,b,c;i<=m;++i)
    {
     a= gi;b = gi;c = gi;
     f[a][b] = f[b][a] = c; 
     g[a][b] = g[b][a] = 1;
    }
    for(int k = 1;k<=n;++k)
     for(int i = 1;i<=n;++i)
      for(int j = 1;j<=n;++j)
       if(i != j && j != k && i != k){
       if(f[i][k]+ f[k][j] == f[i][j])
        g[i][j] += g[i][k]*g[k][j];
       if(f[i][k]+ f[k][j] <  f[i][j])
        f[i][j] = f[i][k]+ f[k][j],g[i][j] = g[i][k]*g[k][j];
      }
    
    for(int k = 1;k<=n;++k)
     for(int i = 1;i<=n;++i)
      for(int j = 1;j<=n;++j)
      if(i != j && j != k && i != k){
       if(f[i][k]+ f[k][j] == f[i][j])
        ans[k] += (ld(g[i][k])*ld(g[k][j]))/ld(g[i][j]);
      }
    for(int k = 1;k<=n;++k)
     printf("%.3f\n",ans[k]);
    closeIO();
    return EXIT_SUCCESS;
}
