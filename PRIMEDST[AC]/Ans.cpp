#include "mode.h"
#define MN 50010
#define MM 100020
#define pi 3.1415926535897932384626
int p[MM],n1[MM],h[MN],sz[MN],vis[MN]={0},ee=0,n;
int size,root,mincnt,maxdis,d[MN];
int64 cnt[MN],allcnt[MN],f[MN],ans;
int isprime[MN]={0},prime[MN],pcnt = 0,flag[MN]={0},tmp[100];
#define pr pii
#define mp MP
pr son[MN];
struct FFT{
       struct cpx{
          double a,b;
          cpx operator +(const cpx & o) const{
           return (cpx){a+o.a,b+o.b};
          }
          cpx operator -(const cpx & o) const{
           return (cpx){a-o.a,b-o.b};
          }
          cpx operator *(const cpx & o) const{
           return (cpx){a*o.a-b*o.b,a*o.b+b*o.a};
          }
       }c[MN*4],d[MN*4];
       int swap(cpx * u,int x,int y)
       {
        cpx  tmp = u[x];u[x] = u[y],u[y] = tmp;
        return 0;
       }
       int len;
       int rev(int x){
        tmp[0] = 0;
        for(;x;x>>=1) tmp[++tmp[0]]=x&1;
        int t = 0;
        for(int i = 1;i<=tmp[0];++i) if(tmp[i]) t+=1<<(len-i);
        return t;
       }
       void fft(cpx * A,int n,int fl = 1){
        for(int i = 0;i<n;++i) {int t = rev(i);i<t?swap(A,i,t):0;}
        for(int m = 2;m<=n;m*=2){
         cpx w = (cpx){cos(fl*2*pi/double(m)),sin(fl*2*pi/double(m))};
         for(int k = 0;k<n;k+=m){
          cpx cur = (cpx){1,0};
          for(int j =k;j<k+(m>>1);++j,cur=cur*w){
           cpx t = cur*A[j+(m>>1)],u=A[j];
           A[j] = u+t;
           A[j+(m>>1)] = u-t;
          }
         }
        }
       }
       int64 C[MN*4],D[MN*4],ans[MN*4];
       void merge(int L){
        len = 0;
        while((1<<len)<2*L) ++len;
        for(int i = 0;i<(1<<len);++i){
         if(i <= L){
          c[i] = (cpx){double(C[i]),0};
          d[i] = (cpx){double(D[i]),0};
         }else{
          c[i] = (cpx){0,0};
          d[i] = (cpx){0,0};
         }
        }
        fft(c,1<<len);
        fft(d,1<<len);
        for(int i = 0;i<(1<<len);++i) c[i] = c[i]*d[i];
        fft(c,1<<len,-1);
        for(int i =0;i<(1<<len);++i) ans[i] = int64(double(c[i].a)/double(1<<len)+0.5);
        }
}F;
void pre(int n){
 for(int i = 2;i<=n;++i){
  if(!flag[i]) isprime[i] = 1,prime[++pcnt]=i;
  for(int j= 1;j<=pcnt&&i*prime[j]<=n;++j){
   flag[i*prime[j]] = 1;
   if(i%prime[j] == 0) break;
  }
 }
}
void ae(int x,int y)
{
 p[ee] = y;n1[ee] = h[x];h[x] = ee;++ee;
 p[ee] = x;n1[ee] = h[y];h[y] = ee;++ee;
}
void findroot(int u,int fa){
 sz[u] = 1;
 int mx = 0;
 for(int i = h[u];~i;i=n1[i]){
  if(vis[p[i]] || p[i] == fa) continue;
  findroot(p[i],u);
  sz[u] += sz[p[i]];
  mx = max(sz[p[i]],mx);
 }
 mx = max(mx,size-sz[u]);
 if(mx < mincnt)
  mincnt = mx,root = u;
}
void dfs(int u,int fa){
 ++cnt[d[u]];
 maxdis = max(maxdis,d[u]);
 for(int i = h[u];~i;i=n1[i]){
  if(p[i] == fa ||vis[p[i]]) continue;
  d[p[i]] = d[u]+1;
  dfs(p[i],u);
 }
}
void merge(int l){
 for(int i = 0;i<=l;++i) F.C[i] = allcnt[i],F.D[i]=cnt[i];
 F.merge(l);
 for(int i = 1;i<=l;++i) allcnt[i] += cnt[i];
 for(int i = 1;i<=l;++i) if(isprime[i]) ans += F.ans[i];
}
void solve(int u){
 int scnt = 0;
 for(int i = h[u];~i;i=n1[i]){
  if(vis[p[i]]) continue;
  d[p[i]] = 1,maxdis= 0;
  dfs(p[i],u);
  son[++scnt] = mp(maxdis,p[i]);
 }
 sort(son+1,son+1+scnt);
 memset(allcnt,0,sizeof(allcnt));
 allcnt[0] = 1;son[0].X = 1;
 for(int i = 1;i<=scnt;++i){
  memset(cnt,0,sizeof(cnt));
  d[son[i].Y] = 1;
  dfs(son[i].Y,u);
  merge(son[i-1].X+son[i].X);
 }
 vis[u] = 1;
 findroot(u,0);
 for(int i = h[u];~i;i=n1[i]){
  if(vis[p[i]]) continue;
  mincnt = size = sz[p[i]];
  findroot(p[i],u);
  solve(root);
 }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    pre(n);
    CLEAR(h,0xff);
    for(int i = 1,x,y;i<n;++i){
     x= gi,y = gi;
     ae(x,y);
    }
    mincnt = size = n;
    findroot(1,0);
    solve(root);
    long long all = int64(1)*int64(n)*int64(n-1)/int64(2);
    printf("%.8lf\n",double(ans)/double(all));
    closeIO();
    return EXIT_SUCCESS;
}
