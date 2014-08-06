#include "mode.h"
const int MN = 100100;
int C(int x)
{
 return (x*(x-1)*(x-2))/6;
}
int a[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    int T  = gi;
    while(T--)
    {
     int n = gi;
     for(int i = 1;i<=n;++i)
      a[i] = gi;
     sort(a+1,a+1+n);
     double ans = 0;
     for(int i = 2;i<=n-1;++i)
     {
      
     }
     /*
      for(int j = i+1;j<=n-1;++j)
       for(int k = j+1;k<=n;++k)
        if(a[i]+a[j]>a[k])
         ans++;*/
     double ans2 = C(n);
     printf("%.7f\n",ans/ans2);
    }
    closeIO();
    return EXIT_SUCCESS;
}
