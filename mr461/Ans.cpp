#include <cstdlib>
#include <iostream>

using namespace std;
int n,m;
int a[1510][1510];
int h[1510][1510];
int k[1510][1510];
int f[1510][1510];
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
  for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr461.in%d",cani);
    sprintf(ouf,"mr461.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);  
    memset(a,0,sizeof(a));
    memset(h,0,sizeof(h));
    memset(k,0,sizeof(k));
    memset(f,0,sizeof(f));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&a[i][j]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      if(a[i][j] == 1){
       h[i][j] = h[i][j-1]+1;
       k[i][j] = k[i-1][j]+1;
      }
     int ans=0;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      if(a[i][j] == 1)
       if(f[i-1][j-1]+1<=h[i][j]&&f[i-1][j-1]+1<=k[i][j]){
         f[i][j] = f[i-1][j-1]+1;
         ans = max(f[i][j],ans);
       }
    printf("%d\n",ans);
  	fclose(stdin);fclose(stdout);
}
 
    return EXIT_SUCCESS;
}
