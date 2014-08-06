#include "mode.h"
#define MN 52
#undef ff
#define ff
typedef long double ld;
const ld eps = 1e-4;
int dcmp(ld x)
{
    if(fabs(x) < eps)
     return 0;
    if(x > eps)
     return 1;
    return -1;
}
typedef ld mx[MN][MN];
mx a;
int n,f[MN],g[MN];
int gf(int x)
{
    if(x == f[x]) return x;
    return (f[x]=gf(f[x]));
}
void mg(int x,int y)
{
     f[gf(x)] = f[gf(y)];
}
vector<ld> c[MN][MN];
mx b;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;f[i]=i,++i);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j){
      cin>>a[i][j];
      if(dcmp(a[i][j]-1.0)==0){
       if(i<=j&&gf(i) == gf(j))
       {
        puts("0");
        closeIO();
        return 0;
       }
       else if(i<=j)
        mg(i,j);
      }
     }
    int tot = 0;
    for(int i = 1;i<=n;++i)
     if(f[i] == i)
      g[i] = ++tot;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
      if(dcmp(1-a[i][j])!=0 && ( gf(i) != gf(j)|| i < j))
      c[g[gf(i)]][g[gf(j)]].pb(a[i][j]);
    ld allcut = 1.0;
    for(int i = 1;i<=tot;++i)
     for(int j = 1;j<=tot;++j)
     {
      ld cut=1.0,notcut=0.0;
      for(int k = 0;k<c[i][j].size();++k)
       cut *= (1.0-c[i][j][k]);
      for(int k = 0;k<c[i][j].size();++k)
       notcut += ((c[i][j][k])/(1.0-c[i][j][k]))*cut;
      ff(debug,"%lf %lf\n",cut,notcut);
      if(i<=j) allcut *= cut;
      if(i != j)
      b[i][j] = notcut*(1.0/cut);
     }
    for(int i = 1;i<=tot;++i)
     for(int j = 1;j<=tot;++j)
      if(i != j)
      {
       b[i][i] += b[i][j];
       b[i][j] = -b[i][j]; 
      }
    --tot;
    for(int i = 1;i<=tot;++i){
     int j = i;
     for(;j<=tot;++j)
      if(dcmp(b[i][j])!= 0)
       break;
     if(j > tot) continue;
     for(int k = 1;k<=tot;++k) swap(b[i][k],b[j][k]);
     for(j = i+1;j<=tot;++j)
      if(dcmp(b[j][i])!=0){
       ld t = b[j][i]*(1.0/b[i][i]);
       for(int k = 1;k<=tot;++k)
        b[j][k] -= b[i][k]*t; 
      }
    }
    ld det = 1.0;
    for(int i = 1;i<=tot;++i)
     det *= b[i][i];
    cout.setf(ios::fixed);
    cout<< setprecision(20) <<det*allcut;
    closeIO();
    return EXIT_SUCCESS;
}
