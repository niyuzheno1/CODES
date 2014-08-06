#include "mode.h"
#define MA 110
#define ME 100010
#define MN 510
#define MU 1010
typedef double mat[MA][MA];
struct edge{int a,b;}g[ME];
mat a,b,c;
double w[MN][MU],f[MN][MN],ans;
int n,m,d[MN],lim,tp[MN],p[MN],num;
void gauss(){
 double t;
 int i,j,k;
 for(i = 1;i<=n;++i){
  for(j = i;w[j][i]==0;++j);
  for(k = 1;k<=2*n;++k) swap(w[i][k],w[j][k]);
  for(k = i,t=w[i][i];k<=2*n;++k) w[i][k]/=t;
  for(j = i+1;j<=n;++j){
   if(w[j][i] == 0)continue;
   for(k = i,t = w[j][i];k<=2*n;++k) w[j][k]-=w[i][k]*t;
  }
 }
 for(i = n;i;--i)
  for(j = 1;j<i;++j){
   if(w[j][i]==0) continue;
   for(t = w[j][i],w[j][i]==0,k=n+1;k<=2*n;++k) w[j][k] -= w[i][k]*t;
  }
}
void mut(mat & a, mat b){
 int i,j,k;
 CLEAR(c,0);
 for(i = 1;i<=num;++i)
  for(j = 1;j<=num;++j)
   for(k = 1;k<=num;++k) c[i][j] += a[i][k]*b[k][j];
 memcpy(a,c,sizeof(a));
}
void mpw(int p){
 int i;
 CLEAR(a,0);
 for(i = 1;i<=num;++i) a[i][i] = 1;
 for(;p;p>>=1,mut(b,b))
  if(p&1) mut(a,b);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi, lim = gi;CLEAR(d,0);
    num = 0;
    for(int i = 1;i<=n;++i){
     tp[i] = gi;if(tp[i]) p[i] = ++num;
    }
    for(int i = 1;i<=m;++i) g[i].a=gi,g[i].b = gi,++d[g[i].a],++d[g[i].b];
    CLEAR(w,0);
    for(int i = 1;i<=n;++i) w[i][i] = w[i][i+n] = 1;
    for(int i = 1;i<=m;++i){
     if(!tp[g[i].a])
      w[g[i].b][g[i].a] -= 1.0/double(d[g[i].a]);
     if(!tp[g[i].b])
      w[g[i].a][g[i].b] -= 1.0/double(d[g[i].b]);
    }
    gauss();CLEAR(f,0);CLEAR(b,0);
    for(int i = 1;i<=n;++i)
     if(!tp[i])
      for(int j = 1;j<=n;++j) f[i][j] = w[j][i+n];
     else
      f[i][i] = 1;
    for(int i = 1;i<=m;++i){
     if(tp[g[i].a]){
      for(int j = 1;j<=n;++j)
       if(p[j])
        b[p[j]][p[g[i].a]]+=f[g[i].b][j]/double(d[g[i].a]);
        }
     if(tp[g[i].b]){
      for(int j = 1;j<=n;++j)
       if(p[j])
        b[p[j]][p[g[i].b]]+=f[g[i].a][j]/double(d[g[i].b]); 
      }
    }
    mpw(lim-2);
    ans = 0;
    for(int i = 1;i<=n;++i)
     if(p[i])
      ans += a[num][p[i]]*f[1][i];
    printf("%.9lf\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
