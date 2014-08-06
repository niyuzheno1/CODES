#include <cstdlib>
#include <iostream>
#include <set>
#include <queue>
using namespace std;
const int maxn = 5010;
const double inf = 10e10;
double eps(double x)
{
 if(x < 10e-4)
  return 0;
 else
  return x;
}
struct point
{
 bool f;
 double k,x,y;
 point()
 {}
 point(double xx,double yy,double zz)
 {
  f = 0;
  k = xx,x = yy,y = zz;
 }
 bool operator==(point xx)
 {
  if(eps(xx.x-x)  == 0&&eps(xx.y-y)  == 0)
   return true;
  return false;
 }
 bool operator<(point xx)const
 {
  if(!xx.f && !f){
   if(x == xx.x)
    return xx.y<y;
   return x < xx.x;
  }
  else
   return k > xx.k;
 }
 point operator-(point xx)
 {
  return point(k,x-xx.x,y-xx.y);
 }
 double det(point xx)
 {
  return this->x*xx.y-this->y*xx.y;
 }
};

typedef set<point> setp;
typedef setp::iterator it;
setp s;
priority_queue< double,vector< double > ,less< double > > t;
double f[maxn];
double a[maxn],b[maxn],r[maxn];
int n;
void ins(point x)
{
     while(true){
     it m = s.upper_bound(x);
     if(m == s.end() || m == s.begin())
      break;
     point xx = *m;
     m--;
     point yy = *m;
     if(yy == x)
       return;
     point t1 = (x-yy),t2 = xx-yy;
     double ret = t1.x*t2.y-t1.y*t2.x;
     if(ret > 0)
      return;
     else
      break;
     }
     while(true){
      it m = s.lower_bound(x);
      if(m == s.end() || m == s.begin())
       break;
      point xx = *m;
      m--;
      point yy = *m;
      point t1 = (x-yy),t2 = xx-yy;
      double ret = t1.x*t2.y-t1.y*t2.x;
      if(ret > 0)
      {
       m++;
       s.erase(m);
      }
      else
       break;
     }
     while(true){
      it m = s.lower_bound(x);
      if(m == s.end())
       break;
      point xx = *m;
      m++;
      if(m == s.end())
       break;
      point yy = *m;
      point t1 = (yy-x),t2 = (xx-x);
      double ret = t1.x*t2.y-t1.y*t2.x;
      if(ret > 0)
      {
       m++;
       s.erase(m);
      }
      else
       break;
     }
     it m = s.lower_bound(x);
     if(!(m == s.end()))
      x.k = ((x.y-(*m).y)/(x.x-(*m).x));
     s.insert(x);
     m = s.lower_bound(x);
     point newx = *m;
     m++;
     if(m != s.end())
     {
      newx = *m;
      s.erase(x);
      newx.k = (newx.y-x.y)/(newx.x-x.x);
      s.insert(newx);
     }
}
point find(double x)
{
      point u;
      u.f = 1;
      u.k = x;
      u.x = u.y = 0;
      it m = s.upper_bound(u);
      return *m;
}
int main(int argc, char *argv[])
{
    freopen("cash.in","r",stdin);
    freopen("cash.out","w",stdout);
    scanf("%d%lf",&n,&f[1]);
    for(int i = 1;i<=n;i++)
     scanf("%lf%lf%lf",&a[i],&b[i],&r[i]);
    s.insert(point(inf,-1,-inf));
    s.insert(point(-inf,inf,0));
    ins(point(inf,f[1]*(r[1]/(1+r[1])),f[1]*(1/(1+r[1]))));
    t.push(f[1]*(r[1]/(1+r[1])));
    for(int i = 2;i<=n;i++)
    {
     if(b[i] == 0)
      f[i] = t.top();
     else
     {
      point xx = find(-b[i]/a[i]);
      f[i] = a[i]*xx.x+b[i]*xx.y;
     }
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
