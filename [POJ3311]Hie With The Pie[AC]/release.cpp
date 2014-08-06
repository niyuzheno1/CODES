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

int dis[12][12];
int dp[1<<11][12];
int n,ans,_min;
int main(int argc, char *argv[])
{
    setIO("sample");
    while(scanf("%d",&n) && n)
    {
        for(int i = 0;i<=n;++i)
         for(int j = 0;j<=n;++j)
          scanf("%d",&dis[i][j]);
         for(int k = 0;k<=n;++k)
          for(int i = 0;i<=n;++i)
           for(int j = 0;j<=n;++j)
            dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);             
        int All = (1<<n)-1;
        for(int S = 0;S<=All;++S)
         for(int i = 1;i<=n;++i)
         {
                 if(S & (1<<(i-1)))
                 {
                  if(S == (1<<(i-1)))  dp[S][i] = dis[0][i];
                  else {
                   dp[S][i] = INF;
                   for(int j = 1;j<=n;++j)
                    if((S&(1<<(j-1))) && j != i)
                     dp[S][i] = min(dp[S][i],dis[j][i]+dp[S^(1<<(i-1))][j]);
                  }
                 }
         }
       ans = dp[All][1]+dis[1][0];
       for(int i = 2;i<=n;++i)
       ans = min(ans,dp[All][i]+dis[i][0]);
       printf("%d\n",ans);
    }
    closeIO();
    return EXIT_SUCCESS;
}
