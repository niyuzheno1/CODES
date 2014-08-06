#include "mode.h"
#define MN 100010
typedef long long LL;
int a[MN];
LL gcd(LL a,LL b,LL & x,LL & y)
{
   if(b == 0)
   {
    x = 1,y = 0;
    return a;
   }
   LL ret = gcd(b,a%b,x,y);
   LL t = y;y = x-(a/b)*y,x = t;
   return ret;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int T = gi;
    while(T--)
    {
     int n = gi;LL T1 = gi,T2 = gi;
     for(int i = 1;i<=n;++i) a[i] = gi;
     for(int i = 1;i<=n;++i){
      LL s = 1,u = a[i];
      while(u != i)
       u = a[u],++s;
      LL t1 = T1%s,t2 = T2%s;
      LL x = 0,y = 0;
      gcd(t2,s,x,y);
      x %= s;
      x = (x * t1)%s;
      while(x < 0) x += s;
       u = i;
      while(x)
       u = a[u],--x;
      printf("%d",u);
      printf((i!=n)?" ":" \n");
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
