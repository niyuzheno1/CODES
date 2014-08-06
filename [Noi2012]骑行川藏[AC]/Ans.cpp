#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define sqr(x) (x)*(x)
using namespace std;
const double inf = 10e4;
const int MAXN = 10010;
int n;
double E;
struct p
{
 double s,k,v,m;
};
p a[MAXN];
double sol(double a,double b,double l,double r)
{
 for(int i = 1;i<=100;i++)
 {
  double mid = (l+r)/2;
  if(a*(mid-b)*sqr(mid)+1 < 0)
   r = mid;
  else
   l = mid;
 }
 return (l+r)/2;
}
int main(int argc, char *argv[])
{
    freopen("bicycling.in","r",stdin);freopen("bicycling.out","w",stdout);
    scanf("%d%lf",&n,&E);
    double r = 0,l = -inf;
    for(int i = 1;i<=n;i++){
     scanf("%lf%lf%lf",&a[i].s,&a[i].k,&a[i].v);
     a[i].m = sqrt(E/(a[i].k*a[i].s))+a[i].v;
     r = min(r,-1.0/(2*a[i].k*sqr(a[i].m)*(a[i].m-a[i].v)));
    }
    r = 0;
    double ans = 0,ans1 = 0;
    for(int i = 1;i<=60;i++){
     double mid = (l+r)/2;
     ans = 0;ans1 = 0;
     for(int j = 1;j<=n;j++)
     {
     double v = sol(2*mid*a[j].k,a[j].v,max(0.00001,a[j].v),a[j].m);
     ans1 += a[j].k*sqr(v-a[j].v)*a[j].s;
     ans += a[j].s/v;
     }
     if(ans1 > E)
      r = mid;
     else
      l = mid;
    }
    printf("%.8lf",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
