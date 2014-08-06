#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;
const double eps = 10e-7,inf = 10e7;
const double PI = acos(-1.0);
int cmp(double x)
{
 if(abs(x) < eps)
  return 0;
 if(x >0)
  return 1;
 if(x < 0)
  return -1; 
}
double d[10010];
int n,f;
int check(double xx)
{
 int ret = 0;
 for(int i = 1;i<=n;i++)
  ret += int(d[i]/xx);
 return ret;
}
int main(int argc, char *argv[])
{
    //freopen("pie.in","r",stdin);freopen("pie.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--)
    {
     double l = 0,r=0;
     scanf("%d%d",&n,&f);f++;
     for(int i = 1;i<=n;i++){
      scanf("%lf",&d[i]);
      d[i] = d[i]*d[i]*PI;
      r = max(r,d[i]);
     }
     
     while(true)
     {
      double mid = (l+r)/2;
      if(cmp(l-r) >= 0)
       break;
      if(check(mid) < f)
       r = mid-eps;
      else
       l = mid+eps;
     }
     printf("%.4f\n",(l+r)/2);
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
