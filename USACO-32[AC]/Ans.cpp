#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef long long int64;
struct pp
{
      int64 c,p;
      bool cost;
      bool operator <(pp x) const
      {
           return c > x.c;
      }
};
priority_queue<pp> q;
int64 k,n,m;
pp c[50010];
bool f[50010];
int main(int argc, char *argv[])
{
    freopen("coupons.in","r",stdin);
    freopen("coupons.out","w",stdout);
    scanf("%I64d%I64d%I64d",&n,&k,&m);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&c[i].c,&c[i].p);
    for(int64 i = 1;i<=n;i++)
    {
     pp x;
     x = c[i];
     x.p = i;
     q.push(x);
     x.c = c[i].p;
     x.p = i;
     x.cost = 1;
     q.push(x);
    }
    int64 ans = 0;int64 x = 0;
    while(!q.empty())
    {
     if(q.top().cost == 1 && k <= 0)
     {
      q.pop();
      continue;
     }
     if(q.top().c + x > m || f[q.top().p])
     {
      q.pop();
      continue;
     }
     x += q.top().c;
     f[q.top().p] = 1;
     if(q.top().cost)
      k--;
     q.pop();
     ans++;
    }
    printf("%I64d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
