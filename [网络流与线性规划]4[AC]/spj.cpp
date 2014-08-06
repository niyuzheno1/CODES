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
    int x,y;
    fr(B,"%d",&x);
    fr(C,"%d",&y);
    if(x != y)
      return 1;
    closespj();
    return 0;
}
