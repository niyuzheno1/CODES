#include "mode.h"
#undef pii
/*
最后几个点开了O2还是这么快TT
0.447000 seconds
ok contestant found the optimal answer: 19874432173 == 19874432173
2.542000 seconds
ok contestant found the optimal answer: 497313449256899208 == 49731344925689920

0.299000 seconds
ok contestant found the optimal answer: 374850090734572421 == 37485009073457242

2.734000 seconds
ok contestant found the optimal answer: 36183271951 == 36183271951
2.077000 seconds
ok contestant found the optimal answer: 51629847150471 == 51629847150471
2.123000 seconds
ok contestant found the optimal answer: 124074747024496432 == 12407474702449643

1.724000 seconds
ok contestant found the optimal answer: 309959349080800 == 309959349080800
2.198000 seconds
ok contestant found the optimal answer: 124113525649823701 == 12411352564982370

2.664000 seconds
ok contestant found the optimal answer: 124309619349406845 == 12430961934940684
 
*/
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
ll f[MN][2];
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
    int now = 0;
    for(int i = 1;i<=k;now^=1,++i){
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
      f[j][now] = deq[l].y.Y + (s[j]-deq[l].y.X)*(s[n]-s[j]);
      g[j][i] = deq[l].x;
      }
      else{
      f[j][now] = f[0][1];
      g[j][i] = 0; 
      }
      pii tmp = MP(s[j],f[j][now^1]);
      while(r-l+1 >= 2 && det(deq[r-1].y,deq[r].y,tmp)>=0)
       --r;
      ++r,deq[r].y = tmp,deq[r].x = j;
      f[j][now^1] = f[0][1];
     }
    }
    ll ans=-INF;
    int pos = 0;
    now ^= 1;
    for(int i = 1;i<=n;++i)
      if(f[i][now] > ans)
      {
       ans = f[i][now];
       pos = i;
      }
    printf("%I64d\n",ans);
    now = k;
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
