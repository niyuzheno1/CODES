#include "mode.h"
#define MN 1000005
int p[MN],f[MN];
int64 phi[MN],ans;
int o1[MN],o2[MN];
void init(int n)
{
 f[1] = 1;
 for(int i = 2;i<=n;++i)
 {
  if(!f[i]) ++SIZE(p),p[SIZE(p)] = i,phi[i] = i-1; 
  for(int j = 1;i*p[j]<MN&& j<=SIZE(p);++j)
  {
   f[i*p[j]] = 1;
   
   if(i % p[j] == 0)
   {
    phi[i*p[j]] =phi[i]*p[j]; 
    break;
   }
   else
    phi[i*p[j]] = phi[i]*(p[j]-1); 
  }
 }
 phi[1] = 1;
 for(int i = 3;i<=n;++i)
  phi[i] = (i*phi[i])>>1;
 //show1D(int,phi);
}
int N;
void dfs(int x,int y)
{
     if(x > SIZE(o1))
     {
      if(y != 0) ans += N*phi[N/y];
      return ;
     }
     for(int i = 0;i<=o2[x];++i)
     {
             dfs(x+1,y);
             y *= o1[x];
     }
}
void solve(int x)
{
 SIZE(o1) =0 ;
 for(int i = 2;i*i<=x;++i)
 {
  if(x % i == 0){++SIZE(o1);o1[SIZE(o1)] = i;}
  while(x%i==0){++o2[SIZE(o1)];x/=i;}
 }
 if(x && x!=1){++SIZE(o1);o1[SIZE(o1)]=x;++o2[SIZE(o1)];}
 ans = 0;
 dfs(1,1);
 printf(I64D,ans);puts("");
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init(MN-5);
    int T = gi;
    while(T--)
    {
     int n = gi;N = n;
     solve(n);
    }
    closeIO();
    return EXIT_SUCCESS;
}
