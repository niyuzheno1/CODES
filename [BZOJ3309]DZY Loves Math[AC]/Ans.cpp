#include "mode.h"
const int64 MN  = 10000010,N = MN-10;
int64 mu[MN],prime[MN],p[MN];
void init()
{
 int64 tot = 0;
 p[1] = mu[1] = 0;
 for(int64 i = 2;i<=N;++i)
 {
  if(!p[i]){prime[++tot] = i;mu[i] = 1;}
  for(int64 j = 1;j<=tot;++j)
  {
   int64 t = prime[j]; if(i * t > N ) break;p[i * t] = 1;      
   
   if(i % t == 0){ 
        mu[i*t] = 0;
        break;
   }
   mu[i*t] = -mu[i];
  
  }
 }
 for(int64 i = 2;i<=N;++i)
  if(mu[i])
   for(int64 j = i;j<=N ;j*=i)
    mu[j] = mu[i];
 for(int64 i = 2;i<=N;++i)
  mu[i] += mu[i-1];
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    int64 t = gi;
    while(t--)
    {
     int64 a = gi,b = gi,ans = 0;if(a>b)swap(a,b);
     for(int64 i = 1;i<=a;++i)
     {
      int64 t = min(a/(a/i),b/(b/i));
      ans += (mu[t]-mu[i-1])*(a/i)*(b/i);
      i = t;
     }
     printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
