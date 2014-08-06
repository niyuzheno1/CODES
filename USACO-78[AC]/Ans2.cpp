#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef long long int64;
struct p
{
 int64 key;
 int64 x;
 bool operator <(p px) const
 {
  return key<px.key;
 }
 p()
 {
 x = key = 0;
 }
 p(int64 a,int64 b)
 {
  key = a;x = b;
 }
};
priority_queue<p> q;
int64 f[100010];
int64 sum[100010];
int64 n,k;
int main(int argc, char *argv[])
{
    freopen("mowlawn.in","r",stdin);
    freopen("mowlawn.out","w",stdout);
    scanf("%I64d%I64d",&n,&k);
    for(int64 i = 1;i<=n;i++)
    {
     int64 x;
     scanf("%I64d",&x);
     sum[i] = sum[i-1]+x;
    }
    p px;
    px.x = 0;
    px.key = 0;
    q.push(px);
    px.x = 1;
    px.key = f[0]-sum[1];
    q.push(px);
    for(int64 i = 1;i<=n;i++)
    {
     while(!q.empty() && i-q.top().x > k)
      q.pop();
     f[i] = q.top().key+sum[i];
     q.push(p(f[i]-sum[i+1],i+1));
    }
    int64 ans = 0;
    for(int64 i = 1;i<=n;i++)
     ans = max(f[i],ans);
    printf("%I64d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
