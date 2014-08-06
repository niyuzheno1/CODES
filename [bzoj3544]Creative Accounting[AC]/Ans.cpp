#include "mode.h"
typedef set<int64> si;
typedef si::iterator iter;
const int64 MN = 200010;
int64 a[MN],n,m,tmp;
set<int64> S;

int main(int argc, char *argv[])
{
    setIO("CA");
    read(n);
    read(m);
    for(int64 i = 1;i<=n;i++)
     read(a[i]);
    int64 ans = 0;
    S.insert(0);
    for(int64 i = 1;i<=n;i++)
    {
     tmp += a[i];tmp %= m;
     while(tmp < 0) tmp+= m;
     tmp %= m;
     ans = max(tmp,ans);
     iter it = S.upper_bound(tmp);
     if(it != S.end())
     {
      int64 q = tmp-*it; q%=m;
      while(q < 0) q+=m;
      q %= m;
      ans = max(ans,q);
     }
     S.insert(tmp);
    }
    printf("%lld\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
