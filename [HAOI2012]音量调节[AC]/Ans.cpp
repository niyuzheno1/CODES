#include "mode.h"
const int MN = 51,ML = 1010;
bool f[MN][ML];
int n,bl,ml,c[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n=gi;bl = gi;ml = gi;
    for(int i = 1;i<=n;++i) c[i] = gi;
    f[0][bl] = 1;
    for(int i  = 1;i<=n;++i)
     for(int j = 0;j<=ml;++j){
      if(j - c[i] >= 0)
       f[i][j] = f[i][j]||f[i-1][j-c[i]];
      if(j + c[i] <= ml)
       f[i][j] = f[i][j]||f[i-1][j+c[i]]; 
     }
    for(int  i = ml;i>=0;--i)
     if(f[n][i]){
      printf("%d",i);
      return 0;
     }
    printf("-1\n");
    closeIO();
    return EXIT_SUCCESS;
}
