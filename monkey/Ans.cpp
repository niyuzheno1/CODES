#include <cstdlib>
#include <iostream>

using namespace std;
int n,m;
int t[200010][3];
int f[200010];
int e[200010];
void dfs1(int x,int y)
{
     if(x == -1)
      return;
     f[x] = y;
     if(y != t[x][1])
      dfs1(t[x][1],x);
     if(y != t[x][2])
      dfs1(t[x][2],x);
     return;
}
void dfs(int x,int u)
{
     if(x == -1)
      return;
     int nu = u;
     nu = min(nu,e[x]);
     e[x] = nu;
     if(f[x] != t[x][1])
      dfs(t[x][1],nu);
     if(f[x] != t[x][2])
      dfs(t[x][2],nu);
     return;
}
int main(int argc, char *argv[])
{
    freopen("monkey.in","r",stdin);
    freopen("monkey.out","w",stdout);
    memset(&e,0x7f,sizeof(e));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&t[i][1],&t[i][2]);
    dfs1(1,0);
    for(int i = 1;i<=m;i++)
    {
     int x= 0, y = 0;
     scanf("%d%d",&x,&y);
     if(t[x][y] != f[x])
      e[t[x][y]] = min(e[t[x][y]],i);
     else
      e[x] = min(i,e[x]);
    }
    dfs(1,0x7f7f7f7f);
    for(int i = 1;i<=n;i++)
     if(e[i] == 0x7f7f7f7f)
      printf("-1\n");
     else
      printf("%d\n",e[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
