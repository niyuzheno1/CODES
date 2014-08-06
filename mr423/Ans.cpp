#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n,m,t,a;
int b;
int c[101][101];
int d[101][101];
char inf[100],ouf[100];
int f[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr423.in%d",cani);
    sprintf(ouf,"mr423.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = m =t =a =b = 0;
    zero(c);
    zero(d);
    zero(f);
    scanf("%d%d%d%d",&n,&m,&t,&a);
    b = min(a,t);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&c[i][j]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&d[i][j]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      for(int k = b;k>=1;k--)
       if(c[i][j] != 0)
        for(int l = 1;l<=d[i][j];l++)
         if(k-l*(i+j)*2 >= 0)
          f[k] = max(f[k],f[k-l*(i+j)*2]+c[i][j]*l);
    int ans=0;
    for(int i = 1;i<=b;i++)
     ans = max(ans,f[i]);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
