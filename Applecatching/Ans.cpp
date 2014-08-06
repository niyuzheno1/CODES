#include <cstdlib>
#include <iostream>

using namespace std;
int T,W,ans;
int f[1010][31][3];
int Not(int x)
{
    if(x==1)
    return 2;
    else
    return 1;
}
int main(int argc, char *argv[])
{
    scanf("%d%d",&T,&W);
    for(int i = 0;i<=W;i++)
     f[0][i][2] = -0x7f7f7f7f;
    for(int i = 1;i<=T;i++)
    {
     int u;
     scanf("%d",&u);
     for(int j = 1;j<=W;j++){
      f[i][j][u] = max(f[i-1][j][u],f[i-1][j-1][Not(u)])+1;
      f[i][j][not(u)] = max(f[i-1][j-1][u],f[i-1][j][Not(u)]);
      if(i == T)
      ans = max(ans,max(f[i][j][u],f[i][j][Not(u)]));
    
     }
     f[i][0][u] = f[i-1][0][u]+1;
     f[i][0][Not(u)] = f[i-1][0][not(u)];
     if(i == T)
      ans = max(ans,max(f[i][0][u],f[i][0][Not(u)]));
    }
    printf("%d",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
