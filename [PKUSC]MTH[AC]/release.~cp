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

const int mod = 1000000003,MN = 60,MX = 40;
int n,t,m[MN],f[MN][MX],dp[MN][MX][2],va[MX],ans;
int main(int argc, char *argv[])
{
    setIO("sample");
    while(true)
    {
     n = gi,t = gi,ans = 0,va[31] = 1;
     if(n == t && t== 0)
      break;
     for(int i = 1;i<=n;++i) m[i] = gi,++m[i];
     for(int i = 1;i<=n;++i)
      for(int j = 0;j<31;++j)
       f[i][j] = f[i-1][j]^(m[i] & (1<<j));
     for(int i = 30;i>=0;--i) va[i] = va[i+1]&&(f[n][i]==(t&(1<<i)));
     CLEAR(dp,0),dp[0][0][0] = 1;
     for(int i = 1;i<=n;++i)
      for(int j =0;j<31;++j)
       for(int s = 0;s<2;++s)
       {
        if(dp[i-1][j][s]==0) continue;
        for(int k = 0;k<31;++k)
         if(m[i]&(1<<k))
         {
          int a,b,c;
          if(k > j) a = j,b= k,c = (f[i-1][k]?1:0);
          else
          {
           int tm = (k == j?0:m[i]  &(1<<j));
           a = k,b = j,c = s^(tm?1:0);
          }
          dp[i][b][c] = ((int64)(dp[i-1][j][s])*(int64(1)<<int64(a))+dp[i][b][c])%mod;
         }
       }
     int ans = 0;
     for(int i = 30;i>=0;--i)
     {
      if(va[i+1]) ans = (ans+dp[n][i][(t&(1<<i))?1:0])%mod;
      else break;
     }
     printf("%d\n",ans);  
    }
    closeIO();
    return EXIT_SUCCESS;
}
