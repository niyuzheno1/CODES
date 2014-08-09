#include "mode.h"
#undef pii
typedef long long ll;
typedef pair<ll,ll> pii;
pii operator -( const pii & a,const pii & b){
 return MP(a.X-b.X,a.Y-b.Y);
}
ll det(const pii & a,const pii & b){
 return a.X*b.Y-a.Y*b.X;
}
ll det (const pii & a,const pii & b,const pii & c){
 return det((b-a),(c-a));
}
#define MN 100010
#define MK 210
ll f[MN][MK];
int s[MN],n,k,g[MN][MK],ans2[MK];
struct qlst{
       pii y;
       int x;
};
qlst deq[MN];
int l,r;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,k = gi;
    //int tmp = det(MP(1,1),MP(2,0),MP(3,2)); => det >=0 delete
    for(int i = 1;i<=n;++i)
     s[i] = gi;
    for(int i = 1;i<=n;++i) 
     s[i] += s[i-1];
    CLEAR(f,0xfe);
    f[0][0] = 0;
    for(int i = 1;i<=k;++i){
     l = 1; r = 0;
     if(i == 1)
      ++r,deq[r].y = MP(0,0),deq[r].x = 0;
     if(i == 2)
      i = 2;
     for(int j = 1;j<=n;++j)
     {
      while(r-l+1 >= 2 && (deq[l+1].y.X-deq[l].y.X)*(s[n]-s[j]) <= (deq[l+1].y.Y-deq[l].y.Y) )
       ++l;
      if(r-l+1 >= 1){
      f[j][i] = deq[l].y.Y + (s[j]-deq[l].y.X)*(s[n]-s[j]);
      g[j][i] = deq[l].x;
      }
      else{
      f[j][i] = f[0][1];
      g[j][i] = 0; 
      }
      pii tmp = MP(s[j],f[j][i-1]);
      while(r-l+1 >= 2 && det(deq[r-1].y,deq[r].y,tmp)>=0)
       --r;
      ++r,deq[r].y = tmp,deq[r].x = j;
     }
    }
    ll ans=-INF;
    int pos = 0;
    for(int i = 1;i<=n;++i)
      if(f[i][k] > ans)
      {
       ans = f[i][k];
       pos = i;
      }
    printf("%I64d\n",ans);
    int now = k;
    while(now)
    {
     ans2[now] = pos;
     pos = g[pos][now];
     --now;
    }
    for(int i = 1;i<=k;++i)
     printf("%d ",ans2[i]);
    closeIO();
    return EXIT_SUCCESS;
}
