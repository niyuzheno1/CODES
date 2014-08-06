#include "mode.h"
typedef double ld;
const ld eps = 1e-15; 
ld a[21][21];
inline int dcmp(double p){
 if(fabs(p) < eps) return 0;return p>eps ? 1 : -1;
}
inline void gauss(int n){
 double tmp = 1.0,an = 1.0,p;
 for(int i = 1,pos;i<=n;++i){
  for(pos = i;(!dcmp(a[pos][i]))&&pos<=n;++pos);
  if(pos > n) continue;
  for(int j = i;j<=n;++j) swap(a[pos][j],a[i][j]);
  for(int j = i+1;j<=n;++j)
   if(dcmp(a[j][i])){
    if(dcmp(a[i][i])== 0 || dcmp(a[j][i])==0){ printf("0\n");return;}
    tmp *= (p = a[i][i]/a[j][i]);
    for(int k = i;k<=n;++k) a[j][k] = a[i][k]-a[j][k]*p;
   }
 }for(int i = 1;i<=n;++i) an = an*a[i][i];
 if(n & 1) an *= -1;
 printf("%.0lf\n",fabs(an/tmp));
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n,m,x,y,tc;tc = gi;
    while(tc--){
    n = gi;m=gi;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j)
      a[i][j] = 0;
    for(int i = 1;i<=m;++i){
     scanf("%d%d",&x,&y);
     a[x][y] = a[y][x] = -1;
     a[x][x] +=1 ; a[y][y] += 1;
    }
    gauss(n-1);
    }
    
    closeIO();
    return EXIT_SUCCESS;
}
