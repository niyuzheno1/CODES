#include "mode.h"


const int64 MN = 1000100;
int64 prime[MN],mu[MN],p[MN],tot;
int64 pbreak = 0;
void callbreak()
{
 pbreak = 1;
}
void init()
{
 mu[1] = 1;
 tot = 0;
 p[1] = 1;
 for(int64 i = 2;i<MN;++i)
 {
  if(!p[i]) mu[i] = -1,prime[++tot] = i;
  for(int64 j = 1;j<=tot;++j)
  {
   if(i*prime[j] > MN) break;
   if(i*prime[j] == 30)
     callbreak();
   if(mu[i] && !(i%prime[j] == 0)){
    mu[i*prime[j]] = mu[i]*mu[prime[j]];
   }
   p[i*prime[j]] = 1;
   if(i%prime[j] == 0) break;
  }
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int64 t=gi;
    init();
    while(t--)
    {
     int64 n = gi;
     int64 ans = 3;
     for(int64 i = 1;i<=n;++i)
      ans += (n/i)*(n/i)*((n/i)+3)*mu[i];
     printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
