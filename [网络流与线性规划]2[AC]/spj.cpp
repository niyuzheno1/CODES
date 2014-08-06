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
    int x = 0,y= 0;
    while(~fr(B,"%d",&x))
     y = x;
    int u = 0,v = 0;
    while(~fr(C,"%d",&u))
     v = u;
    if(v != y){
     ff(D,"WA");
     return 1;
    }
    closespj();
    exit(0);
    return 0;
}
