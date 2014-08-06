#include <cstdlib>
#include <iostream>

using namespace std;
int n;
struct
{
      double x,y;
}a[5010];
bool ok(double yy)
{
     double L,R;
     L = 0;R = 0x7f7f7f7f;
     for(int i = 1;i<=n-1;i++){
      
      if(a[i].y < a[i+1].y)
       R = min(R,a[i].x+(a[i+1].x-a[i].x)*(yy-a[i].y)/(a[i+1].y-a[i].y));
      if(a[i].y == a[i+1].y)
       if(yy < a[i+1].y)
        return false;
      if(a[i].y > a[i+1].y)
       L = max(L,a[i+1].x+(a[i].x-a[i+1].x)*(yy-a[i+1].y)/(a[i].y-a[i+1].y));
     }
     
     if(L <= R)
      return true;
     else
      return false;
}
double eps = 10e-10;
int main(int argc, char *argv[])
{
    freopen("hill.in","r",stdin);
    freopen("hill.out","w",stdout);
    double l = 0,r = 1000001;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%lf%lf",&a[i].x,&a[i].y);
    
    ok(3);
    while(r-l > eps)
    {
      double mid = (l+r)/2;
      if(ok(mid))
       r = mid;
      else
       l = mid+eps;
    }
    printf("%.6f\n",(l+r)/2);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
