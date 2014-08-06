#include <cstdlib>
#include <iostream>

using namespace std;
const int infi = 0x7f7f7f7f;
int n,m;
int f[251][251];
int a[251][251];
char inf[1100],ouf[1100];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    m = 0;
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr436.in%d",cani);
    sprintf(ouf,"mr436.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(a,0x7f,sizeof(a));
    memset(f,0x7f,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++){
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     a[x][y] = z;
     a[y][x] = f[x][y] = f[y][x] = a[x][y];
    }
    for(int i = 1;i<=n;i++)
     f[i][i] = 0;
    int ans = 0x7f7f7f7f;

     
    for(int k = 1;k<=n;k++){
     for(int i = 1;i<=k;i++)
      if(i != k)
       for(int j = i+1;j<=k;j++)
        if(j != i && j != k)
         if(a[k][i] != infi && f[i][j] != infi && a[j][k] != infi)
         ans = min(ans,a[k][i]+f[i][j]+a[j][k]);
      for(int i = 1;i<=n;i++)
       for(int j = 1;j<=n;j++)
        if(f[i][k] != infi && f[k][j] != infi)
         f[i][j] = min(f[i][j],f[i][k]+f[k][j]);    
     }
    if(ans == infi)
     printf("He will never come back.");
    else
     printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
