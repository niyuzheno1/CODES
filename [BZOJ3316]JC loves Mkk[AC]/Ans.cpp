#include "mode.h"
#define MN 200005
#define Eps 1e-10
#define top 1e9
typedef long double lb;
typedef long long ll;
#define rep(i,x,y) for(int i = x;i<=y;++i)
int N,L,R,d[2][MN],q[2],p[2];
ll a[MN],ansx,ansy,x;
lb mid,l,r;
inline lb calc(int x,int y) { return (lb)a[y]-(lb)a[x]-(y-x)*mid;}
ll gcd(ll a,ll b) { if (!b) return a; return gcd(b,a%b);}
int main(int argc, char *argv[])
{
    setIO("sample");
    int N=gi,L=gi,R=gi;
    rep(i,1,N) a[i] = gi,a[i+N] = a[i],a[i]+=a[i-1];
    rep(i,N+1,N*2) a[i] += a[i-1];
    N<<=1;
    if(L & 1) ++L;
    for(l = 0,r = top;r-l>Eps;){
     mid =(l+r)/2.0;
     bool flag = false;
     q[1] = q[0] = 1;
     p[1] = p[0] = 0;
     rep(i,1,N){
      int v = i&1;
      while(q[v] <= p[v] && i-d[v][q[v]]>R)++q[v];
      if(i<L) continue;
      while(p[v] >= q[v] && calc(d[v][p[v]],i)<calc(i-L,i)) --p[v];
      d[v][++p[v]] = i-L;
      if(q[v] <= p[v] && calc(d[v][q[v]],i)>0){flag = true;break;}
     }
     if(flag) l = mid;else r = mid;
    }
    ansx = ansy = 1;
    rep(i,L,R){
     if(i&1) continue;
     x = (ll)(l*i);
     if(abs((lb)x/i-l)<abs((lb)ansx/ansy-l))ansx = x,ansy = i;++x;
     if(abs((lb)x/i-l)<abs((lb)ansx/ansy-l))ansx = x,ansy = i; x-=2;
     if(abs((lb)x/i-l)<abs((lb)ansx/ansy-l))ansx= x,ansy = i;
    }
    ll g = gcd(ansx,ansy);
    ansx/=g,ansy/=g;
    if(ansy==1)printf(I64D,ansx);
    else printf(I64D,ansx),printf("/"),printf(I64D,ansy);
    closeIO();
    return EXIT_SUCCESS;
}
