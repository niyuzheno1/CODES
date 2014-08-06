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
    int x = 0,y =0;
    while(1)
    {
     int flag = (~fr(B,"%d",&x)),flag2=(~fr(C,"%d",&y));
     if(!(flag || flag2))break;
     if(x != y)
      return 1;
    }
    closespj();
    return 0;
}
