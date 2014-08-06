#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ff fprintf
#define pi 3.14159265358
using namespace std;
FILE * d;
struct po
{
 double x,y;
 po()
 {
  x = y = 0;
 }
 po(double xx,double yy)
 {
  x = xx,y=yy;
 }
 po operator-(po u)
 {
  return po(x-u.x,y-u.y);
 }
 double abs()
 {
  return sqrt(x*x+y*y);
 }
 po turn(double an)
 {
  return po(x*cos(an)-y*sin(an),y*cos(an)+x*sin(an));
 }
 po operator*(double rt)
 {
  return po(x*rt,y*rt);
 }
 po operator+(po u)
 {
  return po(x+u.x,y+u.y);
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
int n;
po inse(po A,po B,po P,po Q)
{
 po u = A-B;
 double t = det(Q,u)/det(P,Q);
 return A+P*t;
}
void getd(po A,po B,po C)
{
     po v1 = C-B;
     double a1 = acos(dot(A-B,v1)/((A-B).abs()*v1.abs()));
     v1 = v1.turn(a1/3);
     po v2 = B-C;
     a1 = acos(dot(A-C,v2)/((A-C).abs()*v2.abs()));
     v2 = v2.turn(-a1/3);
     po ret = inse(B,C,v1,v2);
     printf("%.6lf %.6lf",ret.x,ret.y);
}
int main(int argc, char *argv[])
{
    #ifdef op
     freopen("uva11178.in","r",stdin);
     freopen("uva11178.out","w",stdout);
     d = fopen("debug.txt","w");
    #endif
    scanf("%d",&n);
    while(n--){
    po A,B,C;
    scanf("%lf%lf%lf%lf%lf%lf",&A.x,&A.y,&B.x,&B.y,&C.x,&C.y);
    getd(A,B,C);printf(" ");
    getd(B,C,A);printf(" ");
    getd(C,A,B);printf("\n");
    }
    #ifdef op
     fclose(stdin);
     fclose(stdout);
     fclose(d);
    #endif
    return EXIT_SUCCESS;
}
