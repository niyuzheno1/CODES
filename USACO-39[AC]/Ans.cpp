#include <cstdlib>
#include <iostream>

using namespace std;
int n;
int a[5010];
int f[3][5010][5010];
int dfs(int x,int y,int z)
{
    if(f[x][y][z] != 0)
     return f[x][y][z];
    if(y == z)
     return x==0?a[y]:0;
    else
    {
     int ans = 0;
     if(x % 2 == 0)
       ans = max(dfs(1,y+1,z)+a[y],dfs(1,y,z-1)+a[z]);
     else
       ans = min(dfs(0,y+1,z),dfs(0,y,z-1));
     f[x][y][z] = ans;
     return ans;
    }
}
int main(int argc, char *argv[])
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    printf("%d\n",dfs(0,1,n));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
