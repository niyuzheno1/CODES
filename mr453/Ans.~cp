#include <cstdlib>
#include <iostream>

using namespace std;
long long n,k,m;
long long a[500010];
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
  for(int cani = 0;cani<=2;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr453.in%d",cani);
    sprintf(ouf,"mr453.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = k = m;
    memset(&a,0,sizeof(a));
    scanf("%I64d%I64d%I64d",&n,&k,&m);
    for(int i = 1;i<=k;i++)
    {
     long long x,y;
     scanf("%I64d%I64d",&x,&y);
     if(y == 0)
      a[i] = x,m++;
     else
      a[i] = -x+1;
     
    }
    sort(a+1,a+1+k);
    a[k+1] = n;
    int u = m/k;
    int v = m%k;
    if(v == 0)
     u--,v = k;
    int f = n-a[k-v+1]+1;
    printf("%I64d",u*(2*n-2)+f-1);
    	  fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
