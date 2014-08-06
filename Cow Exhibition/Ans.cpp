#include <cstdlib>
#include <iostream>

using namespace std;

const int maxn = 110,maxm = 1100*110,inf = 0x7f7f7f7f;
int _f[3][maxm*2];
int *f[3];
int boolopen = 0;
int N;
int main(int argc, char *argv[])
{
    scanf("%d",&N);
    f[1] = &_f[1][maxm];
    f[0] = &_f[0][maxm];
    for(int i = 0;i<=1;i++)
     for(int j = 0;j<=maxm*2-1;j++)
      _f[i][j] = -inf;
    for(int i = 1;i<=N;i++)
    {
     int S,F;
     scanf("%d %d",&S,&F);
     
     for(int j = -1000*100;j<=1000*100;j++)
      if(f[!boolopen][j-S] != -inf)
       f[boolopen][j] = max(f[!boolopen][j],f[!boolopen][j-S]+F);
      else
       f[boolopen][j] = f[!boolopen][j];
     f[boolopen][S] = max(f[boolopen][S],F);
     boolopen = !boolopen;
    }
    int ans = 0;
    boolopen = !boolopen;
    for(int i = 0;i<=1000*100;i++)
     if(f[boolopen][i] >= 0)
      
      ans =  max(ans,f[boolopen][i]+i);
    
    printf("%d",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
