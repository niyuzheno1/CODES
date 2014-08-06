#include "mode.h"
const int64 MN = 1000010,N = 1000000;
int64 p[MN],prime[MN],mu[MN],sum[MN],a[4];
void init()
{
 mu[1] = p[1] = 1;
 int64 tot = 0;
 for(int64 i = 2;i<=N;++i)
 {
  if(p[i] == 0){ mu[i] = -1;prime[++tot] = i;}
  for(int64 j = 1;j<=tot;++j)
  {
   if(i * prime[j] > N) break;
   if(mu[i] && (i % prime[j] != 0))
    mu[i*prime[j]] = mu[i]*mu[prime[j]];
   p[i*prime[j]] = 1;
   if(i % prime[j] == 0) break;
  }
 }
 for(int64 i = 1;i<=N;++i)
  sum[i] = sum[i-1]+mu[i];
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    while(true)
    {
    for(int64 i = 1;i<=3;++i) a[i] = gi;
    if(a[1] == 0 && a[2] == 0 && a[3] == 0) break;
    for(int64 i = 1;i<=3;++i) a[i]--;
    int64 ans = 0 ;
    int64 i =  1 ; 
     while(i <= a[1] || i <= a[2] || i <= a[3]){
     int64 now = INF,tmp = 1;
     for(int64 j = 1;j<=3;++j)
      if( i <= a[j])
       now  = min (now , a[j]/(a[j]/i));
     for(int64 j = 1;j<=3;++j)
      tmp *= ((a[j]/now)+1);
     --tmp;
     ans = ans + (sum[now]-sum[i-1])* tmp;
     i = now+1;
     }
    printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
