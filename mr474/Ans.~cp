#include <cstdlib>
#include <iostream>
#define zero(x) memset(x,0,sizeof(x))
using namespace std;
int n,s;
int a[110];
int f[110][110];
int dfs(int l,int r)
{
    if(l>r||l==r)
     return  0;
    if(f[l][r])
     return f[l][r];
    int ans = 0;
    if((n-(r-l+1))%2 == 0)
     ans = max(dfs(l+1,r)+a[l],dfs(l,r-1)+a[r]);
    else
     ans = min(dfs(l+1,r),dfs(l,r-1));
    return f[l][r] = ans;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr474.in%d",cani);
    sprintf(ouf,"mr474.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = s = 0;
    zero(a);zero(f);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]),s+=a[i];
    printf("%d %d",dfs(1,n),s-dfs(1,n));
    fclose(stdin);fclose(stdout);
}
   
    return EXIT_SUCCESS;
}
