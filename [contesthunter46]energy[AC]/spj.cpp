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
    while(1){
     int u = fr(B,"%d",&x);
     int v = fr(C,"%d",&y);
     if(!(~u) && !(~v))
      break;
     if(x != y)
      return 1;
    }   

    closespj();
    return 0;
}