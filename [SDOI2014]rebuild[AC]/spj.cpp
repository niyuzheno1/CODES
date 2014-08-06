#include "mode.h"
#include "spj.h"
/*A :in
  B :ans
  C :out
  D :res
*/
int main()
{
    setspj();
     double x,y;
     fr(B,"%lf",&x);
     fr(C,"%lf",&y);
     if(abs((y-x)/x)  < 1e-4)
      ff(D,"AC");
     else
     {
         ff(D,"WA");
         return 1;
     }
    closespj();
    return 0;
}
