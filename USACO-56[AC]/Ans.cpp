#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long int64;
int64 n;
struct pp
{
 int64 d;
 int64 p;
 bool operator <(pp y) const
 {
  return d < y.d;
 }
};
pp t[100010];
priority_queue<int64,vector<int64>,less<int64> > q;
int main(int argc, char *argv[])
{
    freopen("job.in","r",stdin);
    freopen("job.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&t[i].d,&t[i].p);
    sort(t+1,t+1+n);
    q.push(t[n].p);
    int64 ans = 0;
    for(int64 i = n-1;i>=0;i--)
    {
     int64 tt = t[i+1].d-t[i].d;
     tt = min(size_t(tt),q.size());
     while(tt > 0)
      ans+=q.top(),q.pop(),tt--;
     q.push(t[i].p);
    }
    printf("%I64d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
