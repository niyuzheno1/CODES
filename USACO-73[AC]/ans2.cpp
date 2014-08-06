#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 10000*500;
int son[510],br[510];
int c[510];
int f[510][510];
int g[510][510];
int dfn[510],ti;
void dfs(int x)
{
     if(x == -1)
      return;
     ti++;
     dfn[ti] = x;
     dfs(br[x]);
     dfs(son[x]);
}
int n,x;
void a(int x,int y)
{
     br[x] = son[y];
     son[y] = x;
}
int main(int argc, char *argv[])
{
    freopen("tselect.in","r",stdin);
    freopen("tselect.out","w",stdout);
    memset(br,0xff,sizeof(br));
    memset(son,0xff,sizeof(son));
    scanf("%d%d",&n,&x);
    for(int i = 0;i<=n;i++)
     for(int j = 0;j<=n;j++)
      f[i][j] = g[i][j] = -inf;
    for(int i = 1;i<=n;i++)
    {
    int C,P;
    scanf("%d%d",&C,&P);
    c[i] = C;
    a(i,P);
    }
    dfs(0);
    for(int q = ti;q>=1;q--){
     int i = dfn[q];
     for(int u = 0;u<=n;u++){
      if(son[i] != -1 && br[i] != -1)
      {
       if(i != 0)
       for(int p = 0;p<=u-1;p++)
        g[i][u] = max(g[i][u],g[son[i]][p]+g[br[i]][u-p-1]+c[i]);
       for(int p = 0;p<=u;p++)
       {
        if(i != 0)
        f[i][u] = max(f[i][u],g[son[i]][p]+f[br[i]][u-p]+c[i]);
        f[i][u] = max(f[i][u],f[son[i]][p]+f[br[i]][u-p]);
        g[i][u] = max(g[i][u],f[son[i]][p]+g[br[i]][u-p]);
       }
      }
      else if(son[i] != -1 && br[i] == -1)
      {
       if(i != 0){
       f[i][u] =  max(f[son[i]][u],g[son[i]][u]+c[i]);
       g[i][u] =  max(g[son[i]][u-1]+c[i],f[son[i]][u]);
       }
       else
       {
       f[i][u] =  f[son[i]][u];
       g[i][u] =  f[son[i]][u];
       }
      }
      else if(son[i] == -1 && br[i] != -1)
      {
       if(i != 0){
       f[i][u] =  max(f[br[i]][u]+c[i],f[br[i]][u]);
       g[i][u] =  max(g[br[i]][u-1]+c[i],g[br[i]][u]);
       }
       else
       {
       f[i][u] =  max(f[br[i]][u]+c[i],f[br[i]][u]);
       g[i][u] =  -inf;
       }
      }
      else
      {
       if(u == 0)
        f[i][u] = c[i];
       else
        f[i][u] = -inf;
       if(u == 0)
        g[i][u] = 0;
       else if(u == 1)
        g[i][u] = c[i];
       else
        g[i][u] = -inf;
      }
     }
   }
    int ans = 0;
    /*for(int i = 0;i<=n;i++){
     for(int j = 0;j<=n;j++)
      printf("%d ",f[i][j]);
     printf("\n");
    }
   printf("\n");
    for(int i = 0;i<=n;i++){
     for(int j = 0;j<=n;j++)
      printf("%d ",g[i][j]);
     printf("\n");
    }*/
    for(int i = 0;i<=n;i++)
     if(f[0][i] > x)
      ans = i;
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
