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
    int u = 0;
    while((~fr(B,"%d",&x))|(~fr(C,"%d",&y)))
    {
     if(x != y){
      ff(D,"%d",u);
      return 1;
     }
     ++u;
    }
    closespj();
    return 0;
}
