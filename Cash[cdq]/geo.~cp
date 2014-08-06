#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>
#define ff fprintf
using namespace std;
const double eps = 10e-7;
FILE * d;
int cmp(double x)
{
    if(abs(x) < eps)
     return 0;
    if(x > 0)
     return 1;
    else
     return -1;
}
struct po
{
 double x,y;
 po()
 {
 x=y=0;
 }
 po(double xx,double yy)
 {
  x = xx;y = yy;
 }
 bool operator<(po a)
 {
  return cmp(x-a.x)<0 || (cmp(x-a.x)==0&& cmp(y-a.y)<0);
 }
 bool operator==(po u)
 {
   return cmp(x-u.x)==0&&cmp(y-u.y)==0;
 }
 bool operator>(po a)
 {
  return cmp(x-a.x)>0 || (cmp(x-a.x)==0 && cmp(y-a.y)>0);
 }
 po operator=(po u)
 {
  x = u.x;y = u.y;
  return *this;
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
double dot(po x,po y)
{
 return x.x*y.x+x.y*y.y;
}
bool gori(po x,po y,po z)
{
 return cmp(det(z-x,y-x))>0;
}
int main(int argc, char *argv[])
{
    d = fopen("debug.txt","w");
    ff(d,"%d",gori(po(0,0),po(0,1),po(1,0)));
    fclose(d);
    return EXIT_SUCCESS;
}
