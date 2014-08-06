#include <cstdlib>
#include <iostream>

using namespace std;
int K,E,N;
struct Store
{
 int X,F,C;
 bool operator <( Store a) const 
 {
      return X<a.X;
 }
};
Store shop[110];
int f[110][360];
int main(int argc, char *argv[])
{
    scanf("%d%d%d",&K,&E,&N);
    for(int i = 1;i<=N;i++)
     scanf("%d%d%d",&shop[i].X,&shop[i].F,&shop[i].C);
    shop[N+1].X = E;
    shop[N+1].F = 0;
    shop[N+1].C = 0;
    N++;
    memset(f,0x7f,sizeof(f));
    sort(shop+1,shop+1+N);
    for(int i = 1;i<=N;i++){
     f[i][0] = 0;
     for(int j = 1;j<=K;j++)
       for(int w = 0;w<=j;w++)
        if(j-w <= shop[i].F)
         f[i][j] = min(f[i][j],f[i-1][w]+(shop[i].X-shop[i-1].X)*w+(j-w)*shop[i].C);
    }
    cout<<f[N][K]<<endl;
    
    return EXIT_SUCCESS;
}
