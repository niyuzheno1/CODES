#include "mode.h"
const int MM = (int)1e5 + 10,MN = (int)1e5 + 10;
int Q,mx,f[MM],miu[MM];
pii a[MM];
struct T
{
 int N,M,K,id;
 void read(){
 N = gi,M = gi,K = gi,mx= max(mx,max(N,M));
 }
}in[MM];
inline bool cmpk(const T & a,const T & b)
{
 return a.K < b.K;
}
void EulerSelect()
{
 static int prime[MN],p[MN],s[MN];
 static bool notprime[MN];
 int tot = 0;
 miu[1] = 1;
 for(int i = 2;i<=mx;++i)
 {
  if(!notprime[i]) prime[++tot]=i,s[i]=i,p[i] = i,miu[i]=-1;
  for(int j = 1;j<=tot;++j)
  {
   if(i*prime[j] > mx) break;
   notprime[i*prime[j]] = 1;
   s[i*prime[j]] = prime[j];
   if(i%prime[j] == 0)
   {
    p[i*prime[j]] = p[i]*prime[j];
    miu[i*prime[j]] = 0;
    break;
   }
   p[i*prime[j]] = prime[j];
   miu[i*prime[j]] = miu[i]*miu[prime[j]];
  }
 }
 a[1] = MP(f[1]=1,1);
 for(int i = 2;i<=mx;++i)
 {
  if(i == p[i]) f[i] = ((int64)p[i]*s[i]-1)/(s[i]-1);
  else f[i] = f[i/p[i]]*f[p[i]];
  a[i] = MP(f[i],i);
 }
}
int C[MN];
inline void Insert(int x,int v)
{
 for(;x<=mx;x+=lb(x)) C[x]+=v;
}
inline int Query(int x)
{
 int ret = 0;
 for(;x;x-=lb(x)) ret += C[x];
 return ret;
}
void init()
{
     Q = gi;
     for(int i = 1;i<=Q;++i) in[i].read(),in[i].id = i;
     EulerSelect();
     sort(a+1,a+1+mx);
     sort(in+1,in+1+Q,cmpk);
}
int res[MN];
void Work()
{
 int last = 0;
 for(int i = 1;i<=Q;++i)
 {
  for(int j = last+1;;++j)
  {
   if(a[j].X > in[i].K || a[j].X == 0) break;
   last = j;
   for(int k = 1;k<=mx;++k)
    if(a[j].Y * k <= mx)
     Insert(a[j].Y*k,a[j].X*miu[k]);
    else
     break;
  }
  int ans = 0,N = in[i].N,M = in[i].M;
  for(int j = 1;j<=N && j<=M;)
  {
  int _j = min(N/(N/j),M/(M/j));
  ans += (N/j)*(M/j)*(Query(_j)-Query(j-1));
  j = _j+1;
  }
  ans = ans & ((111<<31)-1);
  if(ans < 0) ans += 111<<31;
  res[in[i].id] = ans;
 }
 for(int i = 1;i<=Q;++i)
  printf("%d\n",res[i]);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init();Work();
    closeIO();
    return EXIT_SUCCESS;
}
