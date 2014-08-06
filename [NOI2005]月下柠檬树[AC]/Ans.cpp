#include "mode.h"
#undef L
#undef R
#define _bound(L,R,x) dblcmp(L-x)<=0 && dblcmp(R-x)>=0
typedef double ld;
typedef pair<ld,ld> pdd;
const int MN = 510;
const double eps = 10e-7;
pdd s[MN],t[MN],c[MN];
int n = 0;ld ag = 0.0,sm = 0.0;
int dblcmp(double x){if(abs(x) < eps) return 0;if(x < 0) return -1;return 1; }
double f(double x)
{
 double ret = 0.0;
 for(int i = 1;i<=n;++i)
  if(_bound(s[i].X,t[i].X,x))
   ret = max(ret , s[i].Y + (x-s[i].X)/(t[i].X-s[i].X)*(t[i].Y-s[i].Y));
 for(int i = 1;i<=n+1;++i)
  if(_bound(c[i].X-c[i].Y,c[i].X+c[i].Y,x))
   ret = max(ret , sqrt(sqr(c[i].Y)-sqr(c[i].X-x)));
 return ret;
}
double simpson(double l,double r)
{
 return (f(l)+f(r)+4*f((l+r)/2.0))*(r-l)/6.0;
}
double rsimpson(double L,double R)
{
  double mid = (L+R)/2.0;
  if(dblcmp(simpson(L,R)-(simpson(L,mid)+simpson(mid,R))) == 0)
   return simpson(L,R);
  return rsimpson(L,mid)+rsimpson(mid,R);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    
    scanf("%d%lf",&n,&ag);
    ag = 1.0/tan(ag);
    double L = 0.0,R = 0.0;
    for(int i = 1;i<=n+1;++i)
    {
     scanf("%lf",&c[i].X);sm += c[i].X;c[i].X = sm * ag;
    }
    for(int i = 1;i<=n;++i) scanf("%lf",&c[i].Y);L = c[1].X;R = c[n+1].X;
    for(int i = 1;i<=n;++i)
    {
     L = min(L,c[i].X-c[i].Y),R = max(R,c[i].X+c[i].Y);
     if(dblcmp(c[i+1].X-c[i].X-fabs(c[i+1].Y-c[i].Y)) > 0){
     double o = (c[i+1].Y-c[i].Y)/(c[i+1].X-c[i].X);
     s[i] = MP(c[i].X-c[i].Y*o,c[i].Y*sqrt(1-o*o));
     t[i] = MP(c[i+1].X-c[i+1].Y*o,c[i+1].Y*sqrt(1-o*o));
     }
    }
    printf("%.2lf\n",2*rsimpson(L,R));
    closeIO();
    return EXIT_SUCCESS;
}
