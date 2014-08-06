#include "mode.h"
const int N = 10000010;
bitset<N> pr;
int64 p[N];
int64 phi[N];
int64 f[N],k;
void ip()
{
 pr.set();
 for(int i = 2;i<=N;++i)
  if(pr[i])
  {
   p[++k] = i;
   for(int j = i+i;j<N;j+=i)
    pr[j] = false;
  }
}
void init()
{
  for(int i = 1;i<N;++i) phi[i] = i-1;
  phi[0] = 0;
  for(int i = 4;i<N;i+=2) phi[i] /= 2;
  for(int i = 3;i<N;i+=2)
   if(phi[i] == i-1)
   {
    for(int j = i+i;j<N;j+=i)
     phi[j] /= i,phi[j]*=i-1;
   }
 f[1] = 0;
 for(int i = 2;i<N;++i)
  f[i] = f[i-1]+phi[i];
}
int64 n ;
void solve()
{
 int64 ans = 0;
 for(int i = 1;i<=k;++i)
  if(p[i] > n)
   break;
  else
   ans += f[n/p[i]]*2+1;
 printf("%I64d\n",ans);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    ip();init();
    n = gi;
    solve();
    closeIO();
    return EXIT_SUCCESS;
}
