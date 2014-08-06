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
#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LEF(_t),_l,mid
#define RIGHT RIG(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}

#define mod 100000000 
#undef M
int M,N,top = 0;
int state[600],num[110];
int dp[20][500];
int cur[20];

inline bool ok(int x){
 if(x&x<<1) return 0;
 return 1;
}
void init(){
 top = 0;
 int total = 1<<N;
 for(int i = 0;i<total;++i)
  if(ok(i)) state[++top] = i;
}
inline bool fit(int x,int k){
 if(x & cur[k])  return 0;
 return 1;
}
inline int jcount(int x)
{
       int cnt= 0;
       while(x)
        ++cnt,x&=(x-1);
       return cnt;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    while(~scanf("%d%d",&M,&N)){
    init();
    CLEAR(dp,0);
     for(int i = 1;i<=M;++i){
      cur[i] =0 ;
      int num;
      for(int j = 1;j<=N;++j){
       scanf("%d",&num);
       if(num == 0) cur[i] += (1<<(N-j));
      }
     }
    
    for(int i = 1;i<=top;++i){
     if(fit(state[i],1))
      dp[1][i] = 1;
    }
    for(int i = 2;i<=M;++i)
     for(int k = 1;k<=top;++k)
     {
      if(!fit(state[k],i)) continue;
      for(int j = 1;j<=top;++j){
       if(!fit(state[j],i-1)) continue;
       if(state[k] & state[j]) continue;
       dp[i][k] = (dp[i-1][j]+dp[i][k])%mod;
      }
     }
    int ans = 0;
    for(int i = 1;i<=top;++i)
     ans = (ans + dp[M][i])%mod;
    printf("%d\n",ans);
    }
    closeIO();
    return EXIT_SUCCESS;
}
