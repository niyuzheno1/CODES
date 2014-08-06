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

#define MN 43
const int dx[] = {0,-1,-1,-1,-2};
const int dy[] = {0,1 ,0,-1,0};
int64 ans[MN],m,n;
int64 f[MN][MN],g[MN][MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;m = gi;
    for(int i = 1;i<=m;++i) g[1][i] = int64(1)<<int64(i);
    for(int i = 2;i<=n+1;++i)
     for(int j = 1;j<=m;++j)
      for(int k = 1;k<=4;++k)
       g[i][j] ^= g[i+dx[k]][j+dy[k]];
    for(int i = 1;i<=m;++i)
     for(int j = 1;j<=m;++j)
      f[i][j] = ((g[n+1][i]>>j)&1);
    for(int i = 1;i<=m;++i)
    {
     int tmp = i;
     while(!f[tmp][i]) ++tmp;
     if(tmp > m) continue;
     for(int j = i;j<=m;++j) swap(f[tmp][j],f[i][j]);
     for(int j = i+1;j<=m;++j)
     {
      int u = f[j][i];
      if(!u) continue;
      for(int k = i;k<=m;++k)
       f[j][k] ^= f[i][k];
     }
    }
    //up process 
    for(int i = m;i>=1;--i)
    {
     if(!f[i][i]) ans[i] = 1;
     for(int j = i-1;j>=1;--j)
     if(f[j][i])
     {
      f[j][i] ^= 1;
      ans[j] ^= ans[i];
     }
    }
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;printf("%c",j==m?'\n':' '),++j)
     {
     int64 u = g[i][j],v = 0;//ff(debug,I64D,u);ff(debug,"\n");
      for(int k = 1;k<=m;++k)
       if(((u>>k)&1)) v ^= ans[k];
      printf(I64D,v);
     }
    closeIO();
    return EXIT_SUCCESS;
}
