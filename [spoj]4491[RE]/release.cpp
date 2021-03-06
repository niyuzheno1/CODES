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





#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
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
const int INF =  1000000010;
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

const int  MN  = 20000010,N = 10000000;
int p [ MN ] , prime [ MN ] , mu [ MN ] ;
int64 g [ MN ] ,sum [ MN  ] ;
int  n , m ;

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
     for(int i = 1,last = 0; i <= n;i = last+1)
     {
      last = min(n/(n/i),m/(m/i));
      ans += (sum[last]-sum[i-1])*(n/i)*(m/i);
     }
     printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
