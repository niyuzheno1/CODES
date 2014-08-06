#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<cctype>
#include<map>
using namespace std;
#define For(i,n) for(int i=1;i<=n;i++)
#define Rep(i,n) for(int i=0;i<n;i++)
#define Fork(i,k,n) for(int i=k;i<=n;i++)
#define ForD(i,n) for(int i=n;i;i--)
#define Forp(x) for(int p=pre[x];p;p=next[p])
#define RepD(i,n) for(int i=n;i>=0;i--)
#define MEM(a) memset(a,0,sizeof(a))
#define MEMI(a) memset(a,127,sizeof(a))
#define MEMi(a) memset(a,128,sizeof(a))
#define INF (2139062143)
#define MAXT (10+10)
#define MAXY (1000000000)
#define MAXN (1865060)
typedef long long ll;
ll gcd(ll a,ll b){if (!b) return a;return gcd(b,a%b);}
ll exgcd(ll a,ll b,ll &x, ll &y)
{
  if (!b) {x=1,y=0;return a;}
  ll g=exgcd(b,a%b,x,y);
  ll t=x;x=y;y=t-a/b*y;
  return g;	
}
ll pow2(ll a,int b,ll F)
{
  if (b==0) return 1;
  if (b==1) return a;
  ll c=pow2(a,b/2,F);
  c=c*c%F;
  if (b&1) c=c*a%F;
  return c;
}
void Modp(ll a,ll b,ll p)
{
  ll x,y;
  ll g=exgcd(a,p,x,y),d;
  if (b%g) {puts("Orz, I cannot find x!");return;}
  d=b/g;x*=d,y*=d;
  x=(x+abs(x)/p*p+p)%p;
  printf("%lld\n",x);
}

int h[MAXN]={0};
ll hnum[MAXN]={0};
int hash(ll x)
{
  int i=x%MAXN;
  while (h[i]&&hnum[i]!=x) i=(i+1)%MAXN;
  hnum[i]=x;
  return i;	
}

void babystep(ll a,ll b,int p)
{
  
  int m=sqrt(p);while (m*m<p) m++;
  ll res=b,ans=-1;
  
  ll uni=pow2(a,m,p);
  if (!uni) if (!b) ans=1;else ans=-1; //льеп
  else
  {
    
    Rep(i,m+1)
    {
      int t=hash(res);
      h[t]=i+1;
      res=(res*a)%p;
    }
    res=uni;
    
    For(i,m+1)
    {
      int t=hash(res);
      if (h[t]) {ans=i*m-(h[t]-1);break;}else hnum[t]=0;
      res=res*uni%p;
    }
    
    res=b;
    Rep(i,MAXN) h[i]=hnum[i]=0;
  }
  
  if (ans>-1) printf("%lld\n",ans);
  else puts("Orz, I cannot find x!");
}
int main()
{
	freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
  
  int T,p,x,y,z;
  while (scanf("%d%d",&T,&p)==2)
  {
    if (p==1)
    {
      For(i,T)
      {
        scanf("%d%d%d",&x,&y,&z);
        printf("%lld\n",pow2(x,y,z));
      }
    }
    else if (p==2)
    {
      For(i,T)
      {
        scanf("%d%d%d",&x,&y,&z);
        Modp(x,y%z,z);
      }
    }
    else
    {
      For(i,T)
      {
        scanf("%d%d%d",&x,&y,&z);
        babystep(x,y%z,z);
      }
    }
  }
  
  return 0;
}
