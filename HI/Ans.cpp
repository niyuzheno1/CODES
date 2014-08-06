#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 10010;
const double inf = 10e9,eps = 10e-9;
typedef double D;
int cmp(double x)
{
 if(abs(x) < eps)
  return 0;
 else if(x > 0)
  return 1;
 else
  return -1;
}
struct po
{
 D x,y;
 po()
 {
  x = y = 0;
 }
 po(double xx,double yy)
 {
  x = xx;y = yy;
 }
 double abs()
 {
  return sqrt(x*x+y*y);
 }
 po operator*(double xx)
 {
  return po(xx*x,xx*y);
 }
 po operator+(po xx)
 {
  return po(x+xx.x,y+xx.y);
 }
 bool operator==(po xx)
 {
  bool flag = cmp(x-xx.x);
  flag = flag && cmp(y-xx.y);
  return flag;
 }
 po operator-(po xx)
 {
  return po(x-xx.x,y-xx.y);
 }
};
double det(po x,po y)
{
 return x.x*y.y-x.y*y.x;
}
struct L
{
 po v,s;
 double ang;
 L()
 {
  v = s = po(0,0);
 }
 L(po x,po y)
 {
  v = x*(1/x.abs());
  s = y;
  ang = atan2(v.y,v.x);
 }
 bool operator <(L y)const
 {
  return ang<y.ang;
 }
};
L l[maxn];
L h[maxn];
po p[maxn];
int n;
bool OnLeft(L lx,po y)
{
 return cmp(det(lx.v,y-lx.s))>0;
}
po inse(L a,L b)
{
 po u = a.s-b.s;
 double t = det(b.v,u)/det(a.v,b.v);
 return a.s+a.v*t;
}
double dot(po x,po y)
{
 return x.x*y.x+x.y*y.y;
}
int main(int argc, char *argv[])
{
    freopen("HI.in","r",stdin);
    freopen("HI.out","w",stdout);
    scanf("%d",&n);
    /*l[1] = L(po(1,0),po(0,inf));
    l[2] = L(po(0,1),po(inf,0));*/
    for(int i = 1;i<=n;i++)
    {
     double k,A,B;
     scanf("%lf%lf%lf",&k,&A,&B);//y=Ax+B
     l[i] = L(po(k*1,A),po(0,B));
    }
    sort(l+1,l+1+n);
    int he = 0,t = 0;
    h[0] = l[1];
    for(int i = 2;i<=n;i++)
    {
     while(t>he && !OnLeft(l[i],p[t-1]))
      t--;
     while(t>he && !OnLeft(l[i],p[he]))
      he++;
     h[++t] = l[i];
     if(t-he>=0&&!cmp(det(h[t].v,h[t-1].v)) && cmp(dot(h[t].v,h[t-1].v)/(h[t].v.abs()*h[t-1].v.abs()))>0)
     {
      t--;
      if(OnLeft(h[t],l[i].s))
       h[t] = l[i];
     }
     if(t>he)
      p[t-1] = inse(h[t],h[t-1]);
    }
    if(t-he <= 0)
     printf("phi\n");
    else
    {
     p[t] = inse(h[t],h[he]);
     for(int i = he;i<=t;i++)
      printf("%lf %lf\n",p[i].x,p[i].y);
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
