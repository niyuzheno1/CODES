#include "mode.h"
#include "spj.h"
/*A :in
  B :ans
  C :out
  D :res
*/
char x[5],y[5];
int main()
{
    setspj();
    int c = 1;
    while(1)
    {
     int flag1 = (~fr(B,"%s",&x)),flag2 = (~fr(C,"%s",&y));
     if(!(flag1 ||flag2))break;
     if(strcmp(x,y)!=0)
      ff(D,"%d\n",c);
     ++c;
    }
    closespj();
    return 0;
}
