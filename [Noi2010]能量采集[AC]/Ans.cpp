#include "mode.h"
const int64 MN  = 100010;
int64 n , m , p[ MN ] , prime[ MN ] , mu [ MN ] ,sum [ MN ];
int64 N =  0;
void init ()
{
 int64 tot = 0;
 p[ 1 ] = mu[ 1 ] = 1;
 for (int64 i  = 2; i<= N ; ++i)
 {
  if(!p[i]) { prime[ ++tot ] = i;mu[ i ] = -1;}
  for(int64 j = 1;j<=tot;++j)
  {
   int64 t = prime[ j ];
   if(t * i > N ) break;
   if(mu[i] != 0&&(i % t != 0))
    mu[i*t] = mu[i] * mu[t] ;
   p[i*t] = 1;
   if(i % t == 0) break;
  }
 }
 for(int64 i = 1;i<=N;++i)
  sum[i] = sum[i-1] + mu[i];
}
int64 query(int64 a,int64 b)
{
    int64 uf = min(a,b);
    int64 ret = 0;
    for(int64 i = 1,last = 0;i<=uf;i=last+1)
    {
     last = min(a/(a/i),b/(b/i));
     ret += (sum[last]-sum[i-1])*(a/i)*(b/i);
    }
    return ret;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi; m = gi;N = max(n,m);
    init();
    int64 uf = min(n,m),ans = 0;
    for(int64 i = 1;i<=uf;++i)
     ans += i*query(n/i,m/i);
    ans *= 2;ans -= n*m;
    printf(I64D,ans);
    closeIO();
    return EXIT_SUCCESS;
}
