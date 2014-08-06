#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n,k;
int a[300010];
int b[300010];
int f[300010];
int g[300010];
char inf[100],ouf[100];
int calcu(int x,int y)
{
    int l = 0,r = 1;
    for(int i = x;i<=y;i++){
     int ll = l,rr = r;
     while(ll<rr)
     {
      int mid = (ll+rr)/2;
      if(g[mid] < b[i])
       ll = mid+1;
      if(g[mid] >= b[i])
       rr = mid;
     }
     g[(ll+rr)/2] = b[i];
     f[i] = (ll+rr)/2;
     r = max((ll+rr)/2+1,r);
    }
   
    return r-1;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr420.in%d",cani);
    sprintf(ouf,"mr420.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = k = 0;
    zero(a);zero(b);zero(f);zero(g);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=k-1;i++)
     if(a[i] < a[k])
      b[++b[0]] = a[i];
    int x = calcu(1,b[0]);
    b[0] = 0;
    for(int i = k+1;i<=n;i++)
     if(a[k] < a[i])
      b[++b[0]] = a[i];
    int y = calcu(1,b[0]);
    printf("%d",x+y+1);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
