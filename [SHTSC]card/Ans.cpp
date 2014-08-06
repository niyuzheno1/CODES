#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#define pi 3.1415926
using namespace std;
const int maxn = 1001000;
struct p
{
 double x,y;
 p()
 {
 }
 p(double xx,double yy)
 {
  x = xx;
  y = yy;
 }
 double det(p  b)
 {
  return x*b.y-y*b.x;
 }
 double dot(p b)
 {
  return x*b.x+y*b.y;
 }
 
 p operator-(p xx)
 {
  return p(this->x-xx.x,this->y-xx.y);
 }
 double abs()
 {
  return sqrt(x*x+y*y);
 }
};
bool operator <(p v,p u)
{
  double aa = acos(u.dot(p(1,0))/u.abs());
  if(u.y < 0)
   aa=-aa;
  double bb = acos(v.dot(p(1,0))/v.abs());
  if(v.y < 0)
   bb = -bb;
  return aa<bb;
}
p h[maxn];
p up[maxn];
int size1,size2;
int tot;
double ans;
int n;
void add(double x,double y,double a,double b,double z)
{
 tot++;
 p s = p(a,b);
 p sx = p(x,y);
 double theta = acos((s.dot(p(1,0)))/s.abs());
 if(s.y < 0)
  theta = -theta;
 theta += z;
 p u(s.abs()*cos(theta),s.abs()*sin(theta));
 h[tot].x = u.x+sx.x;
 h[tot].y = u.y+sx.y;
}
bool cmp1(p x,p y)
{
     return x.x<y.x;
}
int main(int argc, char *argv[])
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d",&n);
    double a,b,c;
    scanf("%lf%lf%lf",&a,&b,&c);
    a = a/2-c;b = b/2-c;
    for(int i = 1;i<=n;i++)
    {
     double x,y,theta;
     scanf("%lf%lf%lf",&x,&y,&theta);
     add(x,y,b,a,theta);
     add(x,y,-b,a,theta);
     add(x,y,b,-a,theta);
     add(x,y,-b,-a,theta);
    }
    sort(h+1,h+1+tot);
    for(int i = 1;i<=tot;i++)
     h[i+tot] = h[i];
    int size = 0;
    int st = 1;
    for(int i = 1;i<=tot;i++)
     if(h[i].x < h[st].x)
      st = i;
    for(int i = st;i<=st+tot;i++)
    {
     while(size>=2)
     {
      p u1 = h[i]-up[size-1];
      p u2 = up[size]-up[size-1];
      double ret = u1.det(u2);
      if(ret > 0)
       break;
      size--;
     }
     size++;
     up[size] = h[i];
    }
    for(int i = 2;i<=size;i++)
    {
     p u1 = up[i]-up[i-1];
     ans+=u1.abs();
    }
    printf("%.2f",ans+2*pi*c);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
