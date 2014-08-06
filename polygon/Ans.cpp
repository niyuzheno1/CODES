#include <cstdlib>
#include <iostream>

using namespace std;
int n;
struct u
{
 double x,y;
}p[101];
bool cmp(u x,u y)
{
  if(x.x*y.y-x.y*y.x > 0)
   return true;
  else
   return false;
}
int cross(int x,int y)
{
    return p[x].x*p[y].y-p[x].y*p[y].x;
}
int f[110][110];
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%f %f",&p[i].x,p[i].y);
    sort(p+1,p+n+1,cmp);
    f[0][0] = 1;
    for(int i = 1;i<=n;i++){
     int flag = true;
     for(int j = 0;j<=i;j++)
      if(p[i].x*p[j].y-p[i].y*p[j].x == 0)
       flag = false;
     if(flag)
      f[i][0] = 2;
     for(int j = 1;j<i;j++)
      for(int k = 0;k<j;k++)
       if()
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
