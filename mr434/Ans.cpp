#include <cstdlib>
#include <iostream>

using namespace std;
const int infi = 0x7f7f7f7f;
int n,m;
int f[251][251];
int a[251];
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr434.in%d",cani);
    sprintf(ouf,"mr434.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(f,0x7f,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=m;i++)
    {
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     f[x][y] = min(f[x][y],z+a[x]);
    }
    for(int i = 1;i<=n;i++)
     f[i][i] = 0;
    for(int k = 1;k<=n;k++)
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=n;j++)
       if(f[i][k] != infi  && f[k][j] != infi)
       f[i][j] = min(f[i][j],f[i][k]+f[k][j]);
    int ans = 0x7f7f7f7f;
    for(int i = 2;i<=n;i++)
     ans = min(ans,f[1][i]+f[i][1]);
    if(ans == 0x7f7f7f7f)
    printf("-1\n");
    else
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
