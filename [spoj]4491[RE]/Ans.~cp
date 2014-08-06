#include "mode.h"
const int64  MN  = 10000010,N = MN-10;
int64 p [ MN ] , prime [ MN ] , mu [ MN ] , g [ MN ] ,sum [ MN  ] ;
int64  n , m ;

void init ( ) 
{
 p[ 1 ] = mu [ 1 ]  = 1;
 int64 tot  = 0 ;
 for(int64 i  = 2; i <= N ; ++ i)
 {
  if(!p[ i ] ){prime[ ++ tot ]  = i ; mu[ i ] = -1; g[ i ] = 1 ;}
  for ( int64  j = 1; j <=  tot ;++ j )
  {
   if(prime[j] *  i  > N) break;
   if( i % prime[j] == 0 )
    g[ i * prime[ j ] ] = mu[ i ];
   else
    g[ i * prime[ j ] ]  =  - g[ i ] + mu[ i ]; 
   if(mu[i] && (i % prime[j] != 0) )
    mu [ i * prime [ j ] ] = mu [ i ] * mu[ prime [ j ] ]; 
   p[ i * prime [ j ] ]  = 1;
   if(i % prime[j]   == 0 ) break;
  }
 }
 for(int64 i = 1; i <= N ; ++ i)
  sum [ i  ] = sum[ i - 1] + g[ i ];
}

int main(int argc, char *argv[])
{
    setIO("sample");
    int64 T = gi;
    init ( ) ;
    while(T--)
    {
     n =  gi ; m  = gi ; 
     if( n > m ) swap ( n , m);
     int64 ans = 0;
     for(int64 i = 1,last = 0; i <= n;i = last+1)
     {
      last = min(n/(n/i),m/(m/i));
      ans += (sum[last]-sum[i-1])*(n/i)*(m/i);
     }
     printf(I64D,ans);puts("");
    }
    
    closeIO();
    return EXIT_SUCCESS;
}
