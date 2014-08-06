#include <cstdlib>
#include <iostream>
#define sqr(x) (x)*(x)
using namespace std;
typedef long long int64;
int64 n;
int64 x[1100],y[1100],r[1100];
int64 m;
int64 a[1100*1100],b[1100*1100];
char inf[1100],ouf[1100];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    m = 0;
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr435.in%d",cani);
    sprintf(ouf,"mr435.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d%I64d",&x[i],&y[i],&r[i]);
    for(int64 i = 1;i<=n;i++)
     for(int64 j = i+1;j<=n;j++)
      if(sqr(x[i]-x[j])+sqr(y[i]-y[j]) <= sqr(r[i]+r[j]))
      {
       m++;
       a[m] = i;b[m] = j;
      }
    printf("%I64d\n",m);
    for(int64 i = 1;i<=m;i++)
     printf("%I64d %I64d\n",a[i],b[i]);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
