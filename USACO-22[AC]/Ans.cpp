/*
注意左端点的选择 
*/
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int f[410];
const double eps = 0.000001;
struct p
{
  int u,v;
  double c,t;
  double n;
  void refresh(double ans)
  {
       n = c+t*ans;
  }
  bool operator < (p x) const
  {
        return n < x.n;
  }
};
int gf(int x)
{
    if(f[x] == x)
     return x;
    return (f[x] = gf(f[x]));
}
void uf(int x,int y)
{
     x = gf(x);
     y = gf(y);
     f[x] = f[y];
}
p u[10010];
int t;
int n,m,fa,sm;
void ad(int x,int y,double z,double q)
{
 t++;
 u[t].u = x,u[t].v = y,u[t].c = z,u[t].t = q;
}
void init(double mid)
{
     for(int i = 1;i<=n;i++)
      f[i] = i;
     for(int i = 1;i<=m;i++)
      u[i].refresh(mid);
     sort(u+1,u+1+m);
}
double solve(double mid)
{
       double ret = 0;
       for(int i = 1;i<=m;i++)
        if(gf(u[i].u) != gf(u[i].v))
        {
         uf(u[i].u,u[i].v);
         ret += u[i].n;
        }
       return ret;
}
int main(int argc, char *argv[])
{
    freopen("quake.in","r",stdin);
    freopen("quake.out","w",stdout);
    scanf("%d%d%d",&n,&m,&fa);
    for(int i = 1;i<=m;i++)
    {
     int u,v,c,t;
     scanf("%d%d%d%d",&u,&v,&c,&t);
     sm += c;
     ad(u,v,c,t);
    }
    double l = -fa,r = fa;
    while(l < r)
    {
     double mid = (l+r)/2;
     init(mid);
     double ca = solve(mid);
     if(abs(ca-fa) < eps)
      l = r = mid;
     if(ca > fa)
      r = mid-eps;
     if(ca < fa)
      l = mid+eps;
    }
    if((l+r)/2 < 0)
    printf("0.0000");
    else
    printf("%.4lf",(l+r)/2);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
