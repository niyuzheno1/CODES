#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ff fprintf
using namespace std;
const double eps = 10e-7;
const int maxn = 50010;
FILE * d;
int cmp(double x)
{
 if(abs(x) < eps)
  return 0;
 else if(x < 0)
  return -1;
 else
  return 1;
}
struct po
{
 double x,y;
 bool operator<(po u) const
 {
  if(cmp(x-u.x) == 0)
   return cmp(y-u.y)<0;
  else 
   return cmp(x-u.x)<0;
 }
 po()
 {
  x = y = 0;
 }
 po(double xx,double yy)
 {
  x = xx,y = yy;
 }
 po operator-(po u)
 {
  return po(x-u.x,y-u.y);
 }
 double abs()
 {
  return x*x+y*y;
 }
};
po h[maxn*2];
int ta;
double det(po x,po y)
{
  return x.x*y.y-x.y*y.x;
}
po p[maxn];
int main(int argc, char *argv[])
{
    d = fopen("debug.txt","w");
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%lf%lf",&p[i].x,&p[i].y);
    
    sort(p+1,p+1+n);
    for(int i = 1;i<=n;i++){
     while(ta >= 2 && det(h[ta-1]-h[ta-2],p[i]-h[ta-2])<=0)
      ta--;
     h[ta++]=p[i];
    }
    for(int i = n-1,u = ta;i>=1;i--)
    {
      while(ta >= u+1 && det(h[ta-1]-h[ta-2],p[i]-h[ta-2])<=0 )
       ta--;
      h[ta++]=p[i];
    }
    ff(d,"%d",ta);
    double ans = 0;
    if(ta <= 3)
    {
     printf("%.0f\n",(h[0]-h[1]).abs());
     return 0;
    }
    ta--;
    int i = 0,j=0;
    for(int k = 0;k<ta;k++)
    {
     if(!(h[i] < h[k]))
      i = k;
     if(h[j] < h[k])
      j = k;
    }
    int si = i,sj = j;
    while(i != sj || j != si)
    {
     ans = max(ans,(h[i]-h[j]).abs());
     if(cmp(det(h[i+1]-h[i],h[j+1]-h[j]))<0)
      i = (i+1)%ta;
     else
      j = (j+1)%ta;
    }
    printf("%.0f\n",ans);
    return EXIT_SUCCESS;
}
