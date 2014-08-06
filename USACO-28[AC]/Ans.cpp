#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
const int inf = 0x7f7f7f7f;
int n,m,s;
int f[300][300][300];
int dfs(int x,int y,int z)
{
    
    if(x <= 0)
     return (0);
    if(f[x][y][z] != inf)
     return f[x][y][z];
    int & ans = f[x][y][z];
    for(int i = 1;i<=sqrt(z);i++)
     ans = min(ans,dfs(x-i,y,z-i*i)+1);
    if(y >= 1)
    for(int i = 1;i<=sqrt(m-(s-x));i++)
     ans = min(ans,dfs(x-i,y-1,m-(s-x)-i*i)+1);
    return ans;
}
int main(int argc, char *argv[])
{
    freopen("cycling.in","r",stdin);
    freopen("cycling.out","w",stdout);
    memset(f,0x7f,sizeof(f));
    scanf("%d%d%d",&n,&m,&s);
    /*printf("%d",dfs(s,n-1,m));*/
    for(int i = 0;i<=n;i++)
     for(int j = 0;j<=m;j++)
      f[0][i][j] = 0;
    for(int i = 1;i<=s;i++)
     for(int j = 0;j<=n-1;j++)
      for(int k = 0;k<=m;k++)
      {
       for(int a = 1;a<=sqrt(k);a++)
        f[i][j][k] = min(f[i][j][k],f[(i-a)<0? 0 :(i-a)][j][k-a*a]+1);
       if(j >=1 )
       for(int a = 1;a<=sqrt(m-(s-i));a++)
        f[i][j][k] = min(f[i][j][k],f[(i-a)<0? 0 :(i-a)][j-1][m-(s-i)-a*a]+1);
      }
    printf("%d",f[s][n-1][m]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
