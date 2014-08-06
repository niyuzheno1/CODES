#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1010;
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
int T;
int a[MAXN][MAXN];
int f[MAXN][MAXN];
int sl[MAXN][MAXN];
int su[MAXN][MAXN];
int g[MAXN][MAXN];
int main(int argc, char *argv[])
{
    setIO("2059");
    scanf("%d",&T);
    while(T--)
    {
     int n,m;
     scanf("%d%d",&n,&m);
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
       scanf("%d",&a[i][j]);
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++){
       su[i][j] = su[i-1][j]+a[i][j];
       sl[i][j] = su[i][j-1]+a[i][j];
       f[i][j] = a[i][j];
       g[i][j] = 1;
      }
     int ans = 0;
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=m;j++)
      {
       f[i][j] = max(f[i][j],f[i-1][j-1]+);
       ans = max(ans,f[i][j]);
      }
    }
    closeIO();
    return EXIT_SUCCESS;
}
