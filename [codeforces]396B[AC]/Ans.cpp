#include "mode.h"
#include "mathlab.h"
uint64 n;
int main(int argc, char *argv[])
{
    setIO("sample");
    int t;t =gi;
    while(t--)
    {
     read<uint64>(n);
     uint64 p = n;
     uint64 e = n+1;
     while(!isprime<uint64>(p))
      p--;
     while(!isprime<uint64>(e))
      e++;
     uint64 ans1 = p*e-2*e+2*(n-p+1),ans2 = 2*p*e;
     uint64 tmp = gcd<uint64>(ans1,ans2);
     ans1/=tmp;ans2/=tmp;
     printf("%I64d/%I64d\n",ans1,ans2);
    }
    closeIO();
    return EXIT_SUCCESS;
}
