#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <map>
#define X first
#define Y second
using namespace std;
const long long inf =0x7f7f7f7f;
long long n,m;
long long s[36];
pair<long long,long long> f[1<<18];
int main(int argc, char *argv[])
{
    freopen("lights.in","r",stdin);
    freopen("lights.out","w",stdout);
    scanf("%I64d%I64d",&n,&m);
    long long p = n/2;
    long long t = (1LL<<p)-1;
    for(long long i = 1;i<=n;i++)
     s[i-1] = (1LL<<(i-1));
    for(long long i = 1;i<=m;i++)
    {
     long long a,b;scanf("%I64d%I64d",&a,&b);a--,b--;
     s[a] |= (1LL<<b);s[b] |= (1LL<<a);
    }
    for(long long i = 0;i<=t;i++)
    {
     for(long long j = 0;j<n/2;j++)
      if((i & (1<<j)))
       f[i].X ^= s[j],f[i].Y++;
    }
    sort(f,f+t);
    long long ans =inf;
    for(long long i = 0;i<=((1LL<<(n-p))-1);i++)
    {
    long long st = 0,ct = 0;
    for(long long j = 0;j<n-p;j++)
      if((i & (1<<j)))
       st ^= s[p+j],ct++;
    long long p = lower_bound(f,f+t,make_pair(((1LL<<n)-1)^(st),0LL))-f;
     if((f[p].X ^ st) == ((1LL<<n)-1))
      ans = min(ans,f[p].Y+ct);
    }
    printf("%I64d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
