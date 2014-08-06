#include "mode.h"
const int Mod = (int)1e9+7,N = 1000010,MN=1000000;
int n,m;
int phi[N],K[N],mm[N];
int q[N],top;
vector<int> yueshu[N];
map<int,int> S[N/10];
void update(int & a,int b)
{
 a+=b;
 if(a>=Mod)a-= Mod;
}
int64 calc(int n,int m)
{
   int t =  K[n];
   if(m == 0) return 0;
   if(t != n && n != 1) return (n/t)*calc(t,m)%Mod;
   if(S[n].find(m) != S[n].end()) return S[n][m];
   int & ans = S[n][m];
   if(n == 1)
   {
    int now = m,next,t;
    for(;now>=2;now=next){
     t = m/now;
     next = m/(t+1);
     update(ans,(now-next)*calc(1,t)%Mod);
    }
    return (ans = (((int64)m*(m+1)/2-ans+Mod)%Mod));
   }
   for(int i = 0;i<yueshu[n].size();++i){
    int d = yueshu[n][i];
    update(ans,(phi[n/d]*calc(d,m/d))%Mod);
   }
   return ans;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi,m = gi;
    mm[1] = phi[1] = K[1] = 1;
    for(int i = 2;i<=MN;++i){
     if(!mm[i])
     {
      mm[i] = i;phi[i] = i-1;
      K[i] = i;q[++top] = i;
     }
     for(int j = 1;j<=top && q[j]*i<=MN;++j)
     {
      int u = q[j]*i;
      mm[u] = q[j];
      phi[u] = phi[i];
      K[u] = K[i];
      if(i%q[j] == 0) {phi[u]*=q[j];break;}
      phi[u]*=(q[j]-1);
      K[u]*=q[j];
     }
    }
  
    for(int i = 1;i<=n;++i)
     for(int j = i;j<=n;j+=i)
      yueshu[j].pb(i);
    int now = 0;
    for(int i = 1;i<=MN;++i)
    {
     update(now,phi[i]);
     S[1][i] = now;
    }
    int ans = 0;
    for(int i = 1;i<=n;++i)
     update(ans,calc(i,m));
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
