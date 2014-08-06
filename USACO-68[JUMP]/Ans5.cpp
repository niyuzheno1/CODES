#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
typedef long long int64;
const long long pxt = 64;
const long long  maxr = 2000;
long long  lowbit(long long  x)
{
 return (x&(-x));
}
typedef long long r[2010];
void p(r & x,r & y,long long  b,r & g)
{
     long long  a = 0,c = 0;
     a = b/pxt;b %= pxt;
     for(long long  i = a;i<=maxr;i++)
     {
      x[i] |= (y[c]<<int64(b));
      g[i] |= (y[c]<<int64(b));
      if(c-1>=0)
      {
      x[i] |= (y[c-1]>>int64(pxt-b));
      g[i] |= (y[c-1]>>int64(pxt-b));
      }
      c++;
     }
}
void q(r & x,r & y)
{
     for(long long  i = 0;i<=maxr;i++)
      x[i] |= y[i];
}
struct px
{
 long long  a,b;
 bool operator < (px x) const
 {
  return a > x.a;
 }
};
long long  n;
px t[61*3];
r f[61*3][61*3];
r g[61*3][61*3];
vector<long long > a,b;
long long pow[65];
FILE * ferr;
void dfs(long long  x,long long  y,long long  z,long long r)
{
    if(x <= 0)
    {
      for(long long  i = 0;i<a.size();i++)
       printf("%I64d\n",a[i]);
      for(long long  i = 0;i<b.size();i++)
       printf("%I64d\n",b[i]);
      return;
    }
    long long pp = pow[r];
    fprintf(ferr,"%I64d\n",z*64+r);
    if((f[x-1][y][z] & pp) != 0)
     b.push_back(t[x].b),dfs(x-1,y,z,r);
    else
    {
     a.push_back(t[x].b);
     long long  p = t[x].a;
     long long  nz = z-(p/pxt);
     long long  nr = r-(p%pxt);
     if(nr < 0)
      nr+=(pxt),nz--;
     dfs(x-1,y-1,nz,nr);
    }
}
long long po(long long x)
{
     long long ans = -1;
     while(x > 0)
     {
      ans++;
      x>>=1;
     }
     return ans;
}
int  main(int  argc, char *argv[])
{
    ferr = fopen("err.out","w");
    pow[0] = 1;
    for(long long i = 1;i<=pxt;i++)
     pow[i] = pow[i-1]*2;
    freopen("jpol.in","r",stdin);
    freopen("jpol.out","w",stdout);
    scanf("%I64d",&n);
    for(long long  i = 1;i<=3*n;i++)
     scanf("%I64d",&t[i].a),t[i].b = i;
    sort(t+1,t+1+3*n);
    for(long long  i = 2*n+1;i<=3*n;i++)
     printf("%I64d\n",t[i].b);
    long long  sumb = 0;
    for(long long  i = 1;i<=2*n;i++)
     sumb += t[i].a;
    f[0][0][0] = 1;
    for(long long  i = 1;i<=2*n;i++)
     for(long long  j = 0;j<=n;j++)
     {
      if(j-1>=0)
       p(f[i][j],f[i-1][j-1],t[i].a,g[i][j]);
      q(f[i][j],f[i-1][j]);
     }
    long long  a = 0,ans = 0;
    for(long long  i = 0;i<=maxr;i++)
    {
    a = i*pxt;
    long long x = f[2*n][n][i];
     while(x != 0)
     {
     long long  k = a+po(lowbit(x));
     if(sumb-k > 500*n && k > 500*n)
     {
      dfs(2*n,n,i,po(lowbit(x)));
      ans = 1;
      break;
     }
     x -=lowbit(x);
     }
     if(ans)
      break;
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
