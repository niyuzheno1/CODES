#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<double,double> p;
const double inf = 10e14;
double abs(p x,p y)
{
 double ans = sqrt((x.X-y.X)*(x.X-y.X)+(x.Y-y.Y)*(x.Y-y.Y));
 return ans;
}
double b(double x,double y)
{
 return abs(p(x,(x-3)*(x-3)-1),p(y,(y-2)*(y-2)+3));
}

double a(double x)
{
       double yl,yr;
       yl = -inf,yr = inf;
       while(yl < yr)
       {
        double mid = (yl+yr)/2;
        if(b(x,mid+(1e-2))-b(x,mid) > 0)
         yr = mid-(1e-14);
        else
         yl = mid+(1e-14);
       }
       return b(x,(yl+yr)/2);
}
int main(int argc, char *argv[])
{
    double xl,xr;
    xl = -inf;
    xr = inf;
    while(xl < xr)
    {
     double mid = (xl+xr)/2;
     if(a(mid+(1e-2))-a(mid) > 0)
      xr = mid-1e-14;
     else
      xl = mid+1e-14;
    }
    printf("%f",a((xl+xr)/2));
    system("PAUSE");
    return EXIT_SUCCESS;
}
