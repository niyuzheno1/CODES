#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
const int inf = 0x7f7f7f7f;
int f[1010][1010][5];
int n,k,bb,t;
bool mp[4][5];
struct pt
{
 int x,y;
 bool operator<(pt t) const
 {
  return y<t.y;
 }
};
pt a[1010];
int b[1010],c[1010];
int ca(int x,int y)
{
    if(y <= 4 && y>=3)
     return x*2;
    else
     return x;
}
int main(int argc, char *argv[])
{
    freopen("lazy.in","r",stdin);
    freopen("lazy.out","w",stdout);
    mp[3][3] = mp[3][4] = 1;
    mp[1][1] = mp[1][3] = mp[1][4] = 1;
    mp[2][2] = mp[2][3] = mp[2][4] = 1;
    scanf("%d%d%d",&n,&k,&bb);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++){
     t++;
     c[t] = a[i].y;
     if(a[i].y == a[i+1].y)
      b[t] = 3,a[i+1].x = 0,t--;
     else if(a[i].x == 1)
      b[t] = 1;
     else if(a[i].x == 2)
      b[t] = 2;
     
    }
    b[0] = b[1];
    for(int i = 1;i<=k;i++)
     for(int j = 1;j<=4;j++)
      f[0][i][j] = inf;
    f[0][0][3] = f[0][0][4] = inf;
    for(int i = 1;i<=t;i++){
     for(int j = 1;j<=4;j++)
      f[i][0][j] = inf;
     for(int j = 1;j<=k;j++)
     {
      for(int k = 1;k<=4;k++)
       if(mp[b[i]][k])
        f[i][j][k] = f[i-1][j][k]+ca(c[i]-c[i-1],k);
       else
        f[i][j][k] = inf;
      int p = inf,q = inf;
      for(int k = 1;k<=4;k++)
       p = min(p,f[i-1][j-1][k]);
      for(int k = 1;k<=4;k++)
       if(j-2 >= 0)
       q = min(q,f[i-1][j-2][k]);
      for(int k = 1;k<=3;k++)
       if(mp[b[i]][k])
        f[i][j][k] = min(f[i][j][k],p+ca(1,k));
      if(mp[b[i]][4])
       f[i][j][4] =min(f[i][j][4],q+2);
      for(int k = 1;k<=2;k++)
       if(mp[b[i]][k])
       f[i][j][k] = min(f[i][j][k],f[i-1][j][4]+c[i]-c[i-1]);
      if(mp[b[i]][4] && j-1 > 0){
       f[i][j][4] = min(f[i][j][4],f[i-1][j-1][1]+c[i]-c[i-1]+1);
       f[i][j][4] = min(f[i][j][4],f[i-1][j-1][2]+c[i]-c[i-1]+1);
      }
     }
    }
    int ans = inf;
    for(int j = 0;j<=k;j++)
     for(int k = 1;k<=4;k++)
      if(mp[b[t]][k])
       ans = min(ans,f[t][j][k]);
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
