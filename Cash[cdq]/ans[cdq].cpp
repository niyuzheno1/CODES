#include <cstdlib>
#include <iostream>
#include <cmath>
#include <stack>
#define ff fprintf
using namespace std;
const int maxn = 1000100;
const double eps = 10e-8;
int cmp(double y)
{
 if(abs(y) < eps)
  return 0;
 else if(y > 0)
  return 1;
 else if(y < 0)
  return -1;
}
FILE * d;
struct da
{
 double a,b,c;
 int d;
 bool operator<(da m)const
 {
  return b*m.a>m.b*a;
 }
};
da a[maxn],b[maxn],c[maxn];
struct po
{
 double x,y;
 po()
 {
  x =  y= 0;
 }
 po(double xx,double yy)
 {
  x = xx;y = yy;
 }
 bool operator<(po u)const
 {
  return x<u.x||(cmp(x-u.x)==0 && y < u.y);
 }
 po operator-(po u)
 {
 return po(x-u.x,y-u.y);
 }
};
double det(po x,po y)
{
 return x.x*y.y-x.y*y.x;
}
bool gori(po x,po y,po z)
{
 return cmp(det(z-x,y-x))>0;
}
double v[maxn];
po u[maxn];
po t[maxn];
int st[maxn],h;
double ans;
void sol(int l,int r,double m)
{
     if(l == r)
     {
      v[l] = max(v[l],m);
      u[l].x = v[l]*a[l].c/(a[l].a*a[l].c+a[l].b);
      u[l].y = u[l].x/a[l].c;
      return;
     }
     int mid = (l+r)/2;
     int s1 = l-1,s2 = mid;
     for(int i = l;i<=r;i++)
      if(b[i].d <= mid)
      {s1++;c[s1] = b[i];}
      else
      {s2++;c[s2] = b[i];}
     for(int i = l;i<=r;i++)
      b[i] = c[i];
     sol(l,mid,m);
     h = 0;
     for(int i = l;i<=mid;i++)
     {
      while(h >= 2 && !gori(u[st[h-1]],u[st[h]],u[i]))
       h--;
      h++;
      st[h] = i;
     }
     int x = 1;
     for(int i = mid+1;i<=r;i++)
     {
      po slope = po(b[i].b,-b[i].a);
      if(x<h && cmp(det(slope,u[st[x+1]]-u[st[x]]))>0)
       x++;
      v[b[i].d] = max(v[b[i].d],b[i].a*u[st[x]].x+b[i].b*u[st[x]].y);
     }
     sol(mid+1,r,v[mid]);
     merge(u+l,u+mid+1,u+mid+1,u+r+1,t+l);
     for(int i = l;i<=r;i++)
      u[i] = t[i];
}
int main(int argc, char *argv[])
{
    freopen("cash.in","r",stdin);
    freopen("cash.out","w",stdout);
    d = fopen("debug.txt","w");
    int n;double m;
    scanf("%d%lf",&n,&m);
    for(int i = 1;i<=n;i++){
     scanf("%lf%lf%lf",&a[i].a,&a[i].b,&a[i].c);
     a[i].d = i;
     b[i] = a[i];
    }
    for(int i = 1;i<=n;i++)
     v[i] = 0;
    ans = m;
    sort(b+1,b+n+1);
    sol(1,n,m);
    printf("%.3f\n",v[n]);
    fclose(d);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
