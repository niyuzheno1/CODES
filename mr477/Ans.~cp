#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n;
int a[1000010][3];
int f[1000010][5];
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr477.in%d",cani);
    sprintf(ouf,"mr477.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(&a,0,sizeof(a));
    memset(&f,0,sizeof(f));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i][1]);
    for(int i = 1;i<=n;i++){
     scanf("%d",&a[i][2]);
     f[i][1] = f[i][2] = f[i][3] = f[i][4] = -10000000;
    }
    f[0][2] = f[0][3] = f[0][4] = -10000000;
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
    f[i][1] = max(f[i-1][1],0)+a[i][1]+a[i][2];
    if(i-1 != 0){
    f[i][2] = max(f[i-1][1],f[i-1][2])+a[i][1];
    f[i][3] = max(f[i-1][1],f[i-1][3])+a[i][2];
    f[i][4] = max(max(f[i-1][3],f[i-1][2]),f[i-1][4])+a[i][1]+a[i][2];
    }
    ans = max(ans,f[i][4]);
    }
    printf("%d",ans);
     fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
