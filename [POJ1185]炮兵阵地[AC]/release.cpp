#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
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

#define MM 71
#define MF 21
#define MN 110
int n,m;
char map[MN][MN];
int num[MN],top,stk[MN],cur[MN],dp[MN][MN][MN];
inline bool ok(int x){
 if(x &(x<<1)) return 0;
 if(x &(x<<2)) return 0;
 return 1;
}
void init()
{
 top = 0;
 int total = 1<<n;
 for(int i = 0;i<total;++i)
  if(ok(i))
   stk[++top] = i;
}
inline bool fit(int x,int k)
{
       if(cur[k] & x) return 0;
       return 1;
}
int count(int x)
{
    int cnt = 0;
    while(x)
    {
     ++cnt;
     x &= (x-1);
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    while(~scanf("%d%d",&m,&n)){
     if(n == 0 && m == 0) break;
     init();
     for(int i=1;i<=m;++i) scanf("%s",map[i]+1);
     for(int i = 1;i<=m;++i){
      cur[i] = 0;
      for(int j = 1 ; j <= n; ++ j)
       if(map[i][j] == 'H') 
       cur[i] += (1<<(j-1));
       
     }
     CLEAR(dp,0xff);
     for(int i = 1;i<=top;++i)
     {
      num[i] = count(stk[i]);
      if(fit(stk[i],1))
       dp[1][1][i] = num[i];
     }
     for(int i =2;i<=m;++i)
      for(int t = 1;t<=top;++t){
       if(!fit(stk[t],i)) continue;
       for(int j = 1;j<=top;++j){
        if(stk[t]&stk[j]) continue;
        for(int k = 1;k<=top;++k)
        {
         if(stk[t] & stk[k]) continue;
         if(dp[i-1][j][k]==-1)continue;
         dp[i][k][t] = max(dp[i][k][t],dp[i-1][j][k]+num[t]);
        }
       }
      }
    
    int ans = 0;
    for(int i = 1;i<=m;++i)
     for(int j =1;j<=top;++j)
      for(int k = 1;k<=top;++k)
       ans = max(ans,dp[i][j][k]);
    printf("%d\n",ans);}
    closeIO();
    return EXIT_SUCCESS;
}
