#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef long long int64;
const int64 m = 1000000009;
int64 lb(int64 x)
{
    return (x&(-x));
}
int64 n;
typedef vector<int64>::iterator it;
vector<int64> v;
set<int64> s;
int64 b[100010];
int64 p = 0;
void add(int64 x,int64 y)
{
     while(x <= p)
     {
      b[x] = (b[x]+y)%m;
      x += lb(x);
     }
}
int64 sum(int64 x)
{
    int64 ans = 0;
    while(x > 0)
    {
     ans = (ans+b[x])%m;
     x-=lb(x);
    }
    return ans;
}
int64 a[100010];
it sx,et;
int main(int argc, char *argv[])
{
    freopen("protest.in","r",stdin);
    freopen("protest.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++){
     scanf("%I64d",&a[i]),a[i] += a[i-1];
     s.insert(a[i]);
    }
    s.insert(0);
    for(set<int64>::iterator i = s.begin();i != s.end();i++)
     v.push_back(*i);
    
    for(int64 i = 0;i<=n;i++)
    {   
            sx = v.begin();
            et = lower_bound(v.begin(),v.end(),a[i]);
            a[i] = et-sx+1;
            p = max(int(p),et-sx+1);
    }
    add(a[0],1);
    int64 ans = 0;
    for(int64 i = 1;i<=n;i++)
    {
      int64 f = sum(a[i])%m;
      add(a[i],f);
      ans = f%m;
    }
    printf("%I64d\n",ans);
    return EXIT_SUCCESS;
}
