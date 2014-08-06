#include <cstdlib>
#include <iostream>

using namespace std;
int gc(int x)
{
    return x%1000000000;
}
int f[2][2010];
int boolopen;
int N,F;
int main(int argc, char *argv[])
{
    boolopen = 0;
    memset(&f,0,sizeof(f));
    f[1][0] = 1;
    scanf("%d%d",&N,&F);
    for(int i = 1;i<=N;i++){
     int tmp = 0;
     scanf("%d",&tmp);
     for(int j = F-1;j>=0;j--)
      f[boolopen][(j+tmp)%F] = gc(gc(f[!boolopen][(j+tmp)%F])+gc(f[!boolopen][j]));
     boolopen = (boolopen+1)%2;
    }
    cout<<f[!boolopen][0]-1;
    system("PAUSE");
    return EXIT_SUCCESS;
}
