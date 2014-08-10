#include "mode.h"
#undef INF
typedef long long ll;
const ll INF = (~0ULL>>2);
#define MN 100010
ll n;
ll d[MN],p[MN],u[MN],m[MN],c[MN],fl[MN],ct[MN],fl1[MN];
//fl1 => [l,r]+ , single point query  => BIT
//fl =>  single point query and change , [l,r] min , [l,r] + => segment tree
//ct => [l,r]+ ,[l,r] min=> segment tree
pii a[MN];
ll delta,cost;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(ll i = 1;i<=n;++i) d[i] = gi;
    for(ll i = 1;i<=n;++i) u[i] = gi;
    for(ll i = 1;i<=n;++i) p[i] = gi;
    for(ll i = 1;i<=n-1;++i) m[i] = gi;
    for(ll i = 1;i<=n-1;++i) c[i] = gi;
    for(ll i = 1;i<=n;++i) a[i] = MP(a[i-1].X+c[i-1],i);
    for(ll i = 1;i<=n;++i) a[i].X += p[i];
    sort(a+1,a+n+1);
    ll j = 1;
    for(ll i = 1;i<=n;delta -= c[i],++i){
     if(i == 3)
      i = 3;
     while(d[i] > 0)
     {
      ll forward = INF,backward = INF,cc=0;
      if(j <= n){
      while(j<= n && (a[j].Y <i || (u[a[j].Y] == 0)))
       ++j;
      if(j <= n)
      forward = a[j].X+delta;
      }
      for(ll k = i-1;k>=1;--k)
       if(backward > ct[k]+p[k])
       {
        backward = ct[k]+p[k];
        cc = k;
       }
      if(forward < backward){
        ll mcap = min(u[a[j].Y],d[i]);
        u[a[j].Y] -= mcap,d[i] -= mcap;
        cost += forward * mcap;
        for(ll k = i;k<a[j].Y;++k) 
         fl1[k]+=mcap;
      }else{
       ll mcap = min(u[cc],d[i]);
       for(ll k = cc;k<i;++k)
        mcap = min(mcap,fl[k]);
       for(ll k = cc;k<i;++k)
        fl[k] -= mcap;
       
       ll ncost = backward;
       u[cc] -= mcap,d[i] -= mcap;
       if(u[cc] == 0) ct[cc] = INF;
       cost += ncost * mcap;
       for(ll k = cc;k<i;++k)
        if(fl[k] == 0 )
        {
        ll delta = c[k]+m[k];
        fl[k] = INF;
        for(ll o = k;o>=1;--o)
         ct[o] += delta;
        }
      }
     }
     if(fl1[i] > 0 )
      {
       fl[i] = fl1[i];
       for(ll k = 1;k<=i;++k)
        ct[k] += -c[i];
      }else{
       fl[i] = INF;
       for(ll k = 1;k<=i;++k)
        ct[k] += m[i];
      }
    }
    printf("%I64d\n",cost);
    closeIO();
    return EXIT_SUCCESS;
}
