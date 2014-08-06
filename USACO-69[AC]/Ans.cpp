#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;
const int inf = 0x7f7f7f7f;
int k,v;
int c[51],s[51];
int p[51][11],e[51][11];
map<int,int> f[51][51];
int dfs(int v,int x,int y)
{
 if(x > k)
  return 0;
 if(f[x][y][v] != 0)
  return f[x][y][v];
 int ans = -inf;
 
 if(y == 0 && (v-c[x])>0)
  ans=max(ans,dfs(v-c[x],x,1));
 if(y != 0 && y<=s[x] && (v-p[x][y])>=0)
  ans=max(ans,dfs(v-p[x][y],x,y+1)+e[x][y]);
 if(y != 0 && y <= s[x])
  ans=max(ans,dfs(v,x,y+1));
 ans = max(ans,dfs(v,x+1,0));
 f[x][y][v] = ans;
 return ans;
}
int main(int argc, char *argv[])
{
    freopen("vidgame.in","r",stdin);
    freopen("vidgame.out","w",stdout);
    scanf("%d%d",&k,&v);
    for(int i = 1;i<=k;i++)
    {
     scanf("%d%d",&c[i],&s[i]);
     for(int j = 1;j<=s[i];j++)
      scanf("%d%d",&p[i][j],&e[i][j]);
    }
    int ans = dfs(v,1,0);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
