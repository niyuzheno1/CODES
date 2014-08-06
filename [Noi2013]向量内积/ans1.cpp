#include "mode.h"

using namespace std;
const int MN = 100000+10,MD =100+10;
int n,d,k;
int a[MN][MD];
int b[MD][MN];
int x[MN];
int y[MN];
int ans1[MN],ans2[MN];
int main(int argc, char *argv[])
{
    srand(1);
    setIO("meow");
    n = gi,d = gi,k = gi;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=d;++j){
      a[i][j] = b[j][i] = (gi)&1;
     }
    int sumx1 = 0;
    for(int i = 1;i<=n;++i) x[i] = rand()%2,sumx1+=x[i];
    x[1] = 0,x[2] = 0;
    for(int i = 1;i<=n;++i) ans2[i] = (sumx1 - x[i])%2;
    for(int i = 1;i<=d;++i)
     for(int j = 1;j<=n;++j)
      y[i] = (y[i]+x[j]*a[j][i])%2;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=d;++j)
      ans1[i] = (ans1[i]+y[j]*b[j][i])%2;
    int flag = 0 ;
    for(int i = 1;i<=n;++i)
     if(ans1[i] != ans2[i])
      flag = i;
    if(!flag) printf("-1 -1\n");
    else{ 
     int another = 0;
     for(int i = 1;i<=n &&(~another);++i)
     if(i != flag){
      int res = 0;
      for(int j = 1;j<=d;++j)
       res += a[i][j]*a[flag][j];
      if(res%2 == 0)
       another = res;
     }
     if(flag > another)swap(flag,another);
     printf("%d %d\n",flag,another);
    }
    closeIO();
    return EXIT_SUCCESS;
}
