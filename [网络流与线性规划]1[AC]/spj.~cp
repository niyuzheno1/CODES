#include "mode.h"
#include "spj.h"
/*A :in
  B :ans
  C :out
  D :res
*/
int mp[110][110];
int mtc[110];
int main()
{
    setspj();
    int n = 0,m=0;fr(A,"%d%d",&m,&n);
    int x,y;
    while(fr(A,"%d%d",&x,&y) && x != -1 && y != -1)
     mp[y][x] =  mp[x][y] = 1;
    fr(C,"%d",&m);
    for(int i = 1;i<=m;++i)
    {
    int x,y;
     fr(C,"%d%d",&x,&y);
    if((!mp[x][y])||(mtc[x]) || mtc[y])
      return 1;
    mtc[x] = mtc[y] = 1; 
    }
    closespj();
    return 0;
}
