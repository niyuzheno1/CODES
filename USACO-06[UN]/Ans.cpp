#include <cstdlib>
#include <iostream>

using namespace std;
typedef int lx[1010][1010];
int l[1010][1010];
int r[1010][1010];
int f[1010][1010];
int mp[1010][1010];
int n,m;
void print(lx m ,int x)
{
     for(int i = 1;i<=x;i++){
      for(int j = 1;j<=x;j++)
       printf("%d ",m[i][j]);
     printf("\n");
     }
}
int main(int argc, char *argv[])
{
    freopen("bigbrn.in","r",stdin);
    freopen("bigbrn.out","w",stdout);
    
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     mp[x][y] = 1;
    }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      if(mp[i][j] == 1)
       l[i][j] = 0;
      else
       l[i][j] = l[i][j-1] + 1;
  
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      if(mp[i][j] == 1)
       r[i][j] = 0;
      else
       r[i][j] = r[i-1][j] + 1;
   
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      if(mp[i][j] == 0)
       f[i][j] = min(min(l[i][j],r[i][j]),f[i-1][j-1]+1);
    
    int ans = 0;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      ans = max(f[i][j],ans);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
