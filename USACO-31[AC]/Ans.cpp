#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
typedef long long int64;
const int64 inf = 0x7f7f7f7f7f7f7f7fLL;
int64 n,c,f;
struct p
{
      int64 c,q;
      bool operator < (p x) const
      {
           return q < x.q;
      }
};
p cc[100010];
int64 d1[100010];
int64 d2[100010];
priority_queue<p> q;
bool cmp(p x,p y)
{
     if(x.c == y.c)
      return x.q < y.q;
     return x.c < y.c;
}
void solve1()
{
     int64 u = n/2;
     int64 x = 0;
     for(int64 i = c-u+1;i<=c;i++)
     {
      d1[i] = inf;
      q.push(cc[i]);
      x += cc[i].q;
     }
     for(int64 i = c-u;i>=1;i--)
     {
      d1[i] = x;
      if(cc[i].q < q.top().q)
      {
       x-=q.top().q;
       x+=cc[i].q;
       q.pop();
       q.push(cc[i]);
      }
     }
    
}
void solve2()
{
     while(!q.empty())
      q.pop();
     int64 u = n/2;
     int64 x = 0;
     for(int64 i = 1;i<=u;i++)
     {
      d2[i] = inf;
      q.push(cc[i]);
      x += cc[i].q;
     }
     for(int64 i = u+1;i<=c;i++)
     {
      d2[i] = x;
      if(cc[i].q < q.top().q)
      {
       x-=q.top().q;
       x+=cc[i].q;
       q.pop();
       q.push(cc[i]);
      }
     }
     
}
void solve()
{
     int64 ans = -1;
     for(int64 i = 1;i<=c;i++)
      if(d1[i]+d2[i]+cc[i].q <= f)
       ans = cc[i].c;
     printf("%I64d",ans);
}
int main(int argc, char *argv[])
{
    freopen("finance.in","r",stdin);
    freopen("finance.out","w",stdout);
    scanf("%I64d%I64d%I64d",&n,&c,&f);
    for(int64 i = 1;i<=c;i++)
     scanf("%I64d%I64d",&cc[i].c,&cc[i].q);
    sort(cc+1,cc+1+c,cmp);
    solve1();
    solve2();
    solve();
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
