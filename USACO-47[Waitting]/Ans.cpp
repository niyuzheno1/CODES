#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
int64 n,f[1276][1276];
int64 dfs(int x,int y,int z)
{
    if(f[y][z])
     return f[y][z];
    if(x > n)
     if(y == z)
      return 1;
     else
      return 0;
    return (f[y][z] = dfs(x+1,y+x,z)+dfs(x+1,y,z+x));
}
int main(int argc, char *argv[])
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    scanf("%I64d",&n);
    printf("%I64d",dfs(1,0,0)/2);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
