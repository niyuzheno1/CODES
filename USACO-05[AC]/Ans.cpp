#include <cstdlib>
#include <iostream>

using namespace std;
int f[1010][31][3];
int n,k;
int a[1010];
int c(int x)
{
    if(x == 1)
     return 2;
    else
     return 1;
}
int main(int argc, char *argv[])
{
    freopen("bcatch.in","r",stdin);
    freopen("bcatch.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    int ans = 0;
    for(int i = 1;i<=n;i++){
     f[i][0][1] = f[i-1][0][1] + (a[i]==1);
     f[i][0][2] = f[i-1][0][2] + (a[i]==2);
     for(int j = 1;j<=k;j++)
      for(int l = 1;l<=2;l++)
      {
      f[i][j][l] = max(f[i-1][j-1][c(l)],f[i-1][j][l])+(a[i] == l);
      }
    }
    for(int j = 0;j<=k;j++)
      for(int l = 1;l<=2;l++)
       ans = max(ans,f[n][j][l]);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
