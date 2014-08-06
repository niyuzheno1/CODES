#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
int n;
typedef int e[7][7];
e x;
char h[10];
int query(e m,int x,int y)
{
  if(x<1 || x > 5)
   return 1;
  if(y<1 || y > 5)
   return 1;
  return m[x][y];
}
int solve(int d,e m)
{
    if(d > 6)
     return 0x7f7f7f7f;
    int ans = d;
    e t;
    for(int i = 1;i<=5;i++)
     for(int j = 1;j<=5;j++)
      if(m[i][j] == 0){
       ans = 0x7f7f7f7f;
       break;
      }
    memcpy(m,t,sizeof(e));
    if(ans != d)
    for(int i = 1;i<=5;i++)
     for(int j = 1;j<=5;j++)
      if(!query(t,i,j) || !query(t,i,j+1) || !query(t,i,j-1)|| !query(t,i-1,j)|| !query(t,i+1,j)){
     
     t[i][j] = !t[i][j];
     t[i][j+1] = !t[i][j+1];
     t[i][j-1] = !t[i][j-1];
     t[i+1][j] = !t[i+1][j];
     t[i-1][j] = !t[i-1][j];
     ans = min(ans,solve(d+1,t));
     t[i][j] = !t[i][j];
     t[i][j+1] = !t[i][j+1];
     t[i][j-1] = !t[i][j-1];
     t[i+1][j] = !t[i+1][j];
     t[i-1][j] = !t[i-1][j];
     }
    return ans;
}
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     for(int j = 1;j<=5;j++)
     {
             scanf("%s",&h);
             for(int k = 0;k<5;k++)
              x[j][k+1] = h[k]-'0';
     }
     int ans = solve(0,x);
     if(ans == 0x7f7f7f7f)
      printf("-1\n");
     else
      printf("%d\n",ans);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
