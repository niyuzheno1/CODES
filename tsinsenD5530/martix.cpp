#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef int ele[3][3];
struct martix
{
 ele e;
 int x,y;
 martix()
 {memset(e,0,sizeof(e));x=y=0;}
 martix(int _x,int _y,ele z)
 {
  x = _x;y=_y;
  for(int i = 0;i<x;i++)
   for(int j = 0;j<_y;j++)
    e[i][j] = z[i][j];
 }
 martix operator*(martix & u)
 {
  if(u.x != this->y)
   return martix();
  martix tmp;
  tmp.x = this->x;tmp.y = u.y;
  for(int i = 0;i<tmp.x;i++)
   for(int j = 0;j<tmp.y;j++)
    for(int k = 0;k<this->y;k++)
     tmp.e[i][j] += e[i][k]*u.e[k][j];
  return tmp;
 }
 void print()
 {
  for(int i = 0;i<x;i++,printf("\n"))
   for(int j = 0;j<y;j++)
    printf("%d ",e[i][j]);
 }
 void scan()
 {
  scanf("%d%d",&x,&y);
  for(int i = 0;i<x;i++)
   for(int j = 0;j<y;j++)
    scanf("%d",&e[i][j]);
 }
};
martix A,B,C;
int main(int argc, char *argv[])
{
    freopen("martix.in","r",stdin);freopen("martix.out","w",stdout);
    A.scan();B.scan();
    C = A*B;
    C.print();
    fclose(stdout);fclose(stdin);
    return EXIT_SUCCESS;
}
