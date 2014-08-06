#include "mode.h"
#include "data.h"
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
