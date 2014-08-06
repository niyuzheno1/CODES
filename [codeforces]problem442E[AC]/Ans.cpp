#include "mode.h"
#include "mathlab.h"
#include <iomanip>
#define MN 1010
const double eps = 1e-9;
int sgn(const double & x){
 if(x < -eps) return -1;
 else if(x > eps) return 1;
 return 0;
}
#define  x X
#define  y Y
typedef pair<double,double> pdd;
int n;
double w,h;
pdd po[MN];
int curCov;
int eve_n;
double eveA[(MN+8)*2];
int eveId[(MN+8)*2];
void nA(double & a){
 while(a < -PI) a += 2*PI;
 while(a > PI) a -= 2*PI;
}
void add(double l, double r){
 nA(l);nA(r);
 eveA[eve_n++] = l,eveA[eve_n++] = r;
 if(l>r)
  curCov++;
}
inline bool lesseveid(const int & i,const int & j)
{
 if(sgn(eveA[i]-eveA[j]) != 0)
  return eveA[i]<eveA[j];
 return (i&1)<(j&1);
}
bool check(int p,double r){
 if(sgn(r) == 0) return true;
 curCov = 0;
 eve_n = 0;
 pdd o = po[p];
 if(r > o.x){
  double th = acos(o.x/r);
  add(-PI-th,-PI+th);
  add(-PI-th,-PI+th);
 }
 if(r > w-o.x){
  double th = acos((w-o.x)/r);
  add(-th,th);
  add(-th,th);
 }
 if(r > o.y){
  double th = acos(o.y/r);
  add(-PI/2.0-th,-PI/2.0+th);
  add(-PI/2.0-th,-PI/2.0+th);
 }
 if(r > h-o.y){
  double th = acos((h-o.y)/r);
  add(PI/2.0-th,PI/2+th);
  add(PI/2.0-th,PI/2+th);
 }
 for(int i = 0;i<n;++i)
  if(i != p)
  {
   double d = hypot(po[i].x-o.x,po[i].y-o.y);
   if(d == 0 || d >= 2*r )continue;
   double alpha = atan2(po[i].y-o.y,po[i].x-o.x),th = acos(d/(2*r));
   add(alpha - th,alpha + th);
  }
 for(int i = 0;i<eve_n;++i) eveId[i] = i;
 sort(eveId,eveId+eve_n,lesseveid);
 if(curCov <= 1) return true;
 for(int i = 0;i<eve_n;++i)
  {
   curCov += (eveId[i]&1)?-1:1;
   if(curCov<=1) return true;
  }
 return false;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    srand(192737);
    cin>>w>>h>>n;
    for(int i = 0;i<n;++i)cin>>po[i].x>>po[i].y;
    random_shuffle(po,po+n);
    double res =  0.0;
    for(int i = 0;i<n;++i)
     if(check(i,res+1e-9))
     {
       double ri = hypot(w,h);double delta = ri-res;
       while(delta > 1e-10)
       {
        double mid = (res+ri)/2;
        if(check(i,mid))
         res = mid;
        else
         ri = mid;
        delta/=2;
       }
     }
    cout<<fixed<<setprecision(10)<<res;
    closeIO();
    return EXIT_SUCCESS;
}
