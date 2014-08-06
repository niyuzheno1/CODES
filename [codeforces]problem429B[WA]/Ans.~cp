#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;
const int MAXN = 1010;
int n,m;
void setIO(string x)
{
#ifndef Release
 string input = x+".in";
 string output = x + ".out";
 freopen(input.c_str(),"r",stdin);
 freopen(output.c_str(),"w",stdout);
#endif
}
void closeIO()
{
 fclose(stdin);
 fclose(stdout);
}
int a[MAXN][MAXN];
int f[4][MAXN][MAXN];
int main(int argc, char *argv[])
{
    setIO("problem429B");
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&a[i][j]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++){
      f[0][i][j] = max(f[0][i][j],f[0][i][j-1]+a[i][j-1]);
      f[0][i][j] = max(f[0][i][j],f[0][i-1][j]+a[i-1][j]);
     }
    for(int i = 1;i<=n;i++)
     for(int j = m;j>=1;j--){
      f[1][i][j] = max(f[1][i][j],f[1][i-1][j]+a[i-1][j]);
      f[1][i][j] = max(f[1][i][j],f[1][i][j+1]+a[i][j+1]);
     }
    for(int i = n;i>=1;i--)
     for(int j = 1;j<=m;j++){
      f[2][i][j] = max(f[2][i][j],f[2][i+1][j]+a[i+1][j]);
      f[2][i][j] = max(f[2][i][j],f[2][i][j-1]+a[i][j-1]);
     }
    for(int i = n;i>=1;i--)
     for(int j = m;j>=1;j--){
      f[3][i][j] = max(f[3][i][j],f[3][i+1][j]+a[i+1][j]);
      f[3][i][j] = max(f[3][i][j],f[3][i][j+1]+a[i][j+1]);
     }
    int ans = 0;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      ans =max(ans,f[0][i][j]+f[1][i][j]+f[2][i][j]+f[3][i][j]);
    printf("%d",ans);
    closeIO();
    return EXIT_SUCCESS;
}
