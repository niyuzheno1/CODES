#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
int n,t;
int a[41][3][3];
typedef pair<int,int> p;
typedef pair<p,int> p2;
map<p2,int> f;
int dfs(int x,int y,int z)
{
    int ans = 0,ans2 = 0;
    p2 s = p2(p(x,y),z);
    if(f[s])
     return f[s];
    if(x > n)
     return ans;
    
    ans = a[x][z][1];
    for(int i = 0;i<=2;i++)
      if(y-a[x+1][i][2] >= 0)
       ans2 = max(ans2,dfs(x+1,y-a[x+1][i][2],i)); 
    f[s] = ans+ans2;
    return ans+ans2;
    
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
    for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr449.in%d",cani);
    sprintf(ouf,"mr449.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = t = 0;
    memset(a,0,sizeof(a));
    f.clear();
    scanf("%d%d",&n,&t);
    for(int i = 1;i<=n;i++)
     scanf("%d%d%d%d",&a[i][1][1],&a[i][1][2],&a[i][2][1],&a[i][2][2]);
    int ans2 = 0;
    for(int i = 0;i<=2;i++)
      if(t-a[1][i][2] >= 0)
       ans2 = max(ans2,dfs(1,t-a[1][i][2],i)); 
    printf("%d\n",ans2);
    fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
