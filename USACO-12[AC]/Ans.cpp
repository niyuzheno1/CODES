#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
int64 n;
struct p
{
      int64 v,x;
      bool operator <(p x) const 
      {
           return v < x.v;
      }
};
int64 lowbit(int64 x)
{
    return x&(-x);
}
struct tr
{
   int64 n;
   int64 a[20010];
   void add(int64 x,int64 y)
   {
        while(x <= n)
        {
         a[x] += y;
         x+= lowbit(x);
        }
   }
   int64 sum(int64 x)
   {
        int64 ret = 0;
        while(x > 0){
         ret += a[x];
         x-= lowbit(x);
        }
        return ret;
   }
   int64 sa(int64 x,int64 y)
   {
        return sum(y)-sum(x-1);
   }
};
p q[20010];
int64 maxx;
tr t[2];
int main()
{
    freopen("moofest.in","r",stdin);
    freopen("moofest.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&q[i].v,&q[i].x),maxx = max(maxx,q[i].x);
    t[0].n = t[1].n = maxx;
    sort(q+1,q+1+n);
    int64 ans = 0;
    for(int64 i = 1;i<=n;i++)
    {
     int64 x = q[i].x;
     int64 y = 0;
     int64 z = 0;
     z = t[1].sa(1,x);
     y = t[0].sa(1,x);
     ans += (y*x-z)*q[i].v;
     z = t[1].sa(x+1,maxx);
     y = t[0].sa(x+1,maxx);
     ans += (z-y*x)*q[i].v;
     y = z = 0;
     t[0].add(x,1);
     t[1].add(x,x);
    }
    printf("%I64d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
