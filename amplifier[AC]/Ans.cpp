#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
//#define ff fprintf
#define pi acos(-1.0)
using namespace std;
FILE * d;
int n;
const int maxn =  500010;
const double eps = 10e-7;
int cmp(double x)
{
  if(abs(x) < eps)
   return 0;
  if(x > 0)
   return 1;
  if(x < 0)
   return -1;
}
struct po
{
 double x,y;
 po()
 {
  x = y = 0;
 }
 po(double xx,double yy)
 {
  x = xx;y = yy;
 }
 po turn(double a)
 {
  return po(cos(a)*x-sin(a)*y,sin(a)*x+cos(a)*y);
 }
 po operator-(po xx)
 {
  return po(x-xx.x,y-xx.y);
 }
 po operator+(po xx)
 {
  return po(x+xx.x,y+xx.y);
 }
 po operator/(double xx)
 {
  return po(x/xx,y/xx);
 }
 po cha(double k)
 {
  return po(x/k,y);
 }
 double abs()
 {
  return sqrt(x*x+y*y);
 }
 po operator*(double u)
 {
  return po(x*u,y*u);
 }
};
double det(po x,po y)
{
 return x.x*y.y-x.y*y.x;
}
struct li
{
 po q,v;
 li()
 {
  q = v = po(0.0,0.0);
 }
 li(po a,po b)
 {
  q = a;
  v = (a-b);
 }
};
po inse(li a,li b)
{
 po c = a.q-b.q;
 double xx = det(b.v,c)/det(a.v,b.v);
 return a.q+a.v*xx;
}
po cen(po a,po b,po c)
{
  if(cmp(det(b-a,c-a))==0)
  {
   if(b.x < a.x)
    swap(b,a);
   if(c.x < a.x)
    swap(c,a);
   if(c.x < b.x)
    swap(c,b);
   return (a+c)/2;
  }
  li ab = li(a,b);
  li bc = li(a,c);
  ab.v = ab.v.turn(-pi/2);
  ab.q = (a+b)/2;
  bc.v = bc.v.turn(-pi/2);
  bc.q = (a+c)/2;
  po ret =  inse(ab,bc);
  return ret;
}
po a[maxn];
double solve()
{
 po ce = a[1];double r = 0;
 for(int i = 2;i<=n;i++)
 if((a[i]-ce).abs() > r+eps){
  ce = a[i];r = 0;
  for(int j = 1;j<i;j++)
  if((a[j]-ce).abs() > r+eps){
   ce = (a[j]+a[i])/2;
   r = (a[j]-a[i]).abs()/2;
   for(int k = 1;k<j;k++)
    if((a[k]-ce).abs() > r+eps){
    ce = cen(a[i],a[j],a[k]);
    r = max((a[k]-ce).abs(),(a[j]-ce).abs()); 
   }
  }
 }
 return r;
}
int main(int argc, char *argv[])
{
    freopen("amplifier.in","r",stdin);
    freopen("amplifier.out","w",stdout);
    //d = fopen("debug.txt","w");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%lf%lf",&a[i].x,&a[i].y);
    double ag = 0;
    scanf("%lf",&ag);ag = (ag*pi)/180;
    double l = 0;scanf("%lf",&l);
    for(int i = 1;i<=n;i++)
    {
     double s = a[i].abs();
     a[i] = a[i].turn(-ag);
     a[i] = a[i]/a[i].abs()*s;
     a[i] = a[i].cha(l);
     //ff(d,"%d:x:%lf y:%lf\n",i,a[i].x,a[i].y);
    }
    random_shuffle(a+1,a+1+n);
    printf("%.3f\n",solve());
    fclose(d);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
