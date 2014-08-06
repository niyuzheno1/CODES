#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 0x7f7f7f7f;
int n,m;
char str[2010];
char tmp[2010];
int ins[256];
int del[256];
int f[2010][2010];
int dfs(int x,int y)
{
     if(f[x][y])
      return f[x][y];
     if(y <= x)
      return 0;
     int ans = inf;
     if(str[x] == str[y])
      ans = min(ans,dfs(x+1,y-1));
     ans = min(ans,dfs(x+1,y)+min(ins[str[x]],del[str[x]]));
     ans = min(ans,dfs(x,y-1)+min(ins[str[y]],del[str[y]]));
     f[x][y] = ans;
     return ans;
}
int main(int argc, char *argv[])
{
    freopen("cheappal.in","r",stdin);
    freopen("cheappal.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%s",&str[1]);
    for(int i = 1;i<=n;i++)
    {
     int x,y;
     scanf("%s%d%d",tmp,&x,&y);
     ins[tmp[0]] = x;
     del[tmp[0]] = y;
    }
    printf("%d\n",dfs(1,m));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
