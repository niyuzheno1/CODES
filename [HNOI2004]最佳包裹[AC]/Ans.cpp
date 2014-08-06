#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int MAXN = 110;
const double eps = 10e-15;
int n;
struct po
{
 double x,y;
 po()
 {
  x = y = 0;
 }
 po(double _x,double _y)
  :x(_x),y(_y)
 {
 }
};
double det(po a,po b)
{
 return a.x*b.y-a.y*b.x;
}
struct vec
{
 double x,y,z;
 vec()
 {
  x = 0;y=0;z=0;
 }
 vec(double _x,double _y,double _z)
  :x(_x),y(_y),z(_z)
 {
 }
 vec operator-(vec g)
 {
  return vec(x-g.x,y-g.y,z-g.z);
 }
 void dit()
 {
  x += (rand()%100)*eps;
  y += (rand()%100)*eps;
  z += (rand()%100)*eps;
 }
 double abs()
 {
  return sqrt(x*x+y*y+z*z);
 }
};
vec normal(vec v,vec u)
{
 vec ret;
 ret.x = det(po(v.y,v.z),po(u.y,u.z));
 ret.y = det(po(u.x,u.z),po(v.x,v.z));
 ret.z = det(po(v.x,v.y),po(u.x,u.y));
 return ret;
}
double dot(vec a,vec b)
{
 return a.x*b.x+a.y*b.y+a.z*b.z;
}
vec a[MAXN];
int main(int argc, char *argv[])
{
    //srand(clock());
    //freopen("enwrap.in","r",stdin);freopen("enwrap.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].z);
     a[i].dit();
    }
    double ans = 0;
    for(int i = 1;i<=n;i++)
     for(int j = i+1;j<=n;j++)
      for(int k = j+1;k<=n;k++)
      {
       vec ab = (a[j]-a[i]),ac = (a[k]-a[i]);
       vec nor = normal(ab,ac);
       bool o1 = 0,o2 = 0;
       for(int l = 1;l<=n;l++)
        if(l != i && l != j && l != k){
        double ret = dot(a[l]-a[i],nor);
        if(ret > 0)
         o1 = 1;
        if(ret < 0)
         o2 = 1;
        if(o1 == 1 && o2 == 1)
         break;
       }
       if((o1^o2))
       ans += nor.abs();
      }
    printf("%lf\n",ans/2);
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
