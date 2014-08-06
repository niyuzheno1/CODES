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
#define INF  1000000010;
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

#define mod 1000000007
int64 n;
const int MN = 16000005;
int T,S,d[10],tot,mk;
int64 dp[MN];
void pre(int n)
{
      for(int i = 2;i*i<=n;++i)
       if(n%i == 0)
       {
        int s = 0;
        while(n%i == 0) n/=i,++s,d[++tot] = i;
        if(s > 1) mk = 1;
       }
      if(n != 1) d[++tot] = n;
      if(!mk){
       int sum = 0;
       for(int i = 1;i<=tot;++i) sum+=d[i];
       dp[sum] = 1;
       for(int i = 1;i<=tot;++i)
        for(int j = d[i];j <= tot*S;++j){
         dp[j] += dp[j-d[i]];
         if(dp[j] >= mod) dp[j]%=mod; 
        }
      }
      dp[0] = 1;
}
int solve(int64 N)
{
    static int y[10];
    static int64 x[10];
    int64 n = N/S,m = N%S;
    for(int i = 0;i<tot;++i) y[i] = dp[i*S+m];
    int64 sum = 0;
    for(int i = 0;i<tot;++i){
     int64 sum1 = y[i],s=0,sign = 1;
     for(int j = 0;j<tot;++j)
       if(i != j)
       {
       if(n < j) sign *=-1;
       x[++s] = abs(n-j);
       }
     for(int j = 0;j<tot;++j)
      if(i != j)
      {
       if(i < j) sign *= -1;
       int val = abs(i-j);
       for(int k = 1;k<=s;++k)
        if(x[k] % val == 0)
        {
        x[k]/=val;break;
        }
      }
     for(int j = 1;j<=s;++j)sum1= ((x[j]%mod)*(sum1%mod))%mod;
     if(sign == 1) sum = (sum+sum1)%mod;
     else sum = (sum-sum1+mod)%mod;
    }
    return sum;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    S = gi;
    pre(S);
    T = gi;
    while(T--)
    {
     n = gi;
     if(mk) puts("0");
     else printf("%d\n",solve(n));
    }
    closeIO();
    return EXIT_SUCCESS;
}
