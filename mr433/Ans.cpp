#include <cstdlib>
#include <iostream>

using namespace std;
int n,m,c;
int f[1010][1010];
int p[1010][1010];
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
    for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr433.in%d",cani);
    sprintf(ouf,"mr433.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout); 
    scanf("%d%d%d",&n,&m,&c);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&p[i][j]);
    memset(f,0x7f,sizeof(f));
    for(int j = 1;j<=m;j++)
     f[0][j] = 0;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      for(int k = 1;k<=m;k++)
       if(j == k)
        f[i][j] = min(f[i][j],f[i-1][j]+p[i][j]);
       else
        f[i][j] = min(f[i][j],f[i-1][k]+c+p[i][j]);
    int ans = 0x7f7f7f7f;
    for(int i = 1;i<=m;i++)
     ans = min(ans,f[n][i]);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
