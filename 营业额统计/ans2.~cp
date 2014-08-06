#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long int64;
set<int64> s;
const int64 inf = 0x7f7f7f7f;
int64 n;
int main(int argc, char *argv[])
{
    scanf("%lld",&n);
    int64 ans = 0;
    for(int64 i = 1;i<=n;i++){
     int64 x;
     scanf("%lld",&x);
     int64 ll = 0;
     set<int64>::iterator l = s.lower_bound(x);
     if(l == s.end())
      ll = inf;
     else
      ll = *l;
     int64 rr = 0;
     set<int64>::iterator r = l;
     
     if(s.size() == 0||l == s.begin())
      rr = inf;
     else{
      r--;
      rr = *r;
     }
     if(ll == inf && rr == inf)
      ans+=x;
     else
      ans+=min(abs(ll-x),abs(rr-x));
     s.insert(x);
    }
    printf("%lld",ans);
    return EXIT_SUCCESS;
}
