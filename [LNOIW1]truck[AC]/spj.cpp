#include "mode.h"
#include "spj.h"
/*A :in
  B :ans
  C :out
  D :res
*/
const double eps = 1e-4;
int main()
{
    setspj();
    int ret = 0;
    int o =0;
    while(1){
             ++o;
     double x,y;
     int ux = fr(B,"%lf",&x);
     int uy = fr(C,"%lf",&y);
     if(!(~ux) && !(~uy))
      break;
     if(y < eps && x < eps)
      continue;
     if(abs((x-y)/y) < eps)
      continue;
     else{
      ff(D,"%d",o);
      ret = 1;
     }
     
    }
    closespj();
    return ret;
}
