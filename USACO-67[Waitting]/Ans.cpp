#include <cstdlib>
#include <iostream>

using namespace std;
int n,c,m;
int a[110];
int f[110][1010][1010];
int dfs(int x,int y,int z)
{
    if(x > n)
     return 0;
    if(f[x][y][z])
     return f[x][y][z];
    int ans = 0;
    if(z > 0)
    {
     if(c-a[x] >= 0)
      ans=max(ans,dfs(x+1,c-a[x],z-1)+1);
     ans=max(ans,dfs(x+1,c,z-1));
    }
    if(y-a[x]>=0)
     ans=max(ans,dfs(x+1,y-a[x],z-1)+1);
    ans=max(ans,dfs(x+1,y,z));
    return f[x][y][z]=ans;    
}
int main(int argc, char *argv[])
{
    freopen("rockers.in","r",stdin);
    freopen("rockers.put","w",stdout);
    scanf("%d%d%d",&n,&c,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    printf("%d\n",dfs(1,c,m));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
