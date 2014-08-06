#include <cstdlib>
#include <iostream>

using namespace std;
double cs(double dx,double h1,double h2)
{
    return 0.5*dx*(h1+h2);
}
double gf(double x,double y)
{
       x -= y/4;
       return x; 
}
double gl(double x,double y)
{
       x += y/4;
       return x;
}
double ch(double x1,double y1,double x)
{
       return -4*(x-x1)+y1;
}
double ga(double x1,double y1,double x2,double y2)
{
       double mid = 0.5*(gf(x2,y2)+gl(x1,y1));
       if(mid > x2)
        return -1;
       else
        return ch(x1,y1,mid);
}
int n;
double a[100010],b[100010];
double fa[100010],fb[100010];
struct p
{
       double f;
       double x,y;
       bool operator < (p u) const
       {
           if(f == u.f)
            return y<u.y;
           return f < u.f;
       }
};
p o[100010*2];
p u;
int main(int argc, char *argv[])
{
    freopen("majesty.in","r",stdin);
    freopen("majesty.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%lf%lf",&fa[i],&fb[i]);
     a[i] = (fa[i]+fb[i])/2;
     b[i] = (fb[i]-fa[i])*2;
    }
    for(int i = 1;i<=n;i++){
     o[2*i].f = gf(a[i],b[i]);
     o[2*i].x = a[i];o[2*i].y = b[i];
     o[2*i-1].f = gl(a[i],b[i]);
     o[2*i-1].x = gl(a[i],b[i]);o[2*i-1].y = 0;
    }
    sort(o+1,o+1+2*n);
    u.x = -65536,u.y = 0;
    double s = 0;
    for(int i = 1;i<=2*n;i++)
    {
     if(gf(o[i].x,o[i].y)>gl(u.x,u.y))
      u.f = o[i].f,u.x = o[i].x,u.y = o[i].y;
     else if(u.f == o[i].f && u.y < o[i].y)
      u.f = o[i].f,u.x = o[i].x,u.y = o[i].y;
     else
     {
      double y = ga(u.x,u.y,o[i].x,o[i].y);
      if(y == -1)
       continue;
      s += cs(o[i].f-u.f,y,u.y);
      u.f = o[i].f,u.x = o[i].x,u.y = o[i].y;
     }
    }
    printf("%d",int(s));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
