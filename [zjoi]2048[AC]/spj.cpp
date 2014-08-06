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
    int o = 1,x,y;
    while((~fr(B,"%d",&x))&&(~fr(C,"%d",&y)))
    {
    if(x != y) break;
                                         ++o;
    }
    ff(D,"%d",o);
    closespj();
    return 0;
}
