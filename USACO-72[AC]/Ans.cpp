#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 1000;
int n,p,tot,dfn[151],ti;
int f[151][151];
struct pp
{
 int ne;
 int v;
};
pp lk[151*2];
int st[151];
int fa[151];
void add(int x,int y)
{
     tot++;
     lk[tot].v = y;
     lk[tot].ne = st[x];
     st[x] = tot;
}
void dfs(int x,int f)
{
  fa[x] = f;
  ti++;dfn[ti] = x;
  for(int i = st[x];i!=0;i=lk[i].ne)
   if(lk[i].v != f)
    dfs(lk[i].v,x);
}
int main(int argc, char *argv[])
{
    freopen("roads.in","r",stdin);
    freopen("roads.out","w",stdout);
    scanf("%d%d",&n,&p);
    for(int i = 1;i<=n-1;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     add(x,y);
     add(y,x);
    }
    dfs(1,-1);
    for(int i = ti;i>=1;i--)
    {
     int son = 0;int x = dfn[i];
     for(int j = st[x];j != 0;j=lk[j].ne)
      if(fa[x] != lk[j].v)
       son++;
     if(!son)
     {
      f[x][0] = 1;f[x][1] = 0;
      for(int j = 2;j<=p;j++)
       f[x][j] = inf;
     }
     else
     {
      int q[151][151],u = 1;
      for(int j = 0;j<=n;j++)
       for(int pp = 0;pp<=p;pp++)
        q[j][pp] = inf;
      q[0][0] = 0;
      for(int j = st[x];j!=0;j=lk[j].ne)
       if(fa[x] != lk[j].v)
       {
        for(int k = 0;k<=p;k++)
         for(int e = p;e>=k;e--)
          q[u][e] = min(q[u][e],q[u-1][e-k]+f[lk[j].v][k]);
       u++;
       }
      for(int j = 1;j<=p;j++)
       f[x][j] = q[son][j-1];
      f[x][0] = 1;
     }
    }
    int ans = 0x7f7f7f7f;
    for(int i = 1;i<=n;i++)
     if(i == 1)
     ans = min(ans,f[i][p]);
     else
     ans = min(ans,f[i][p]+1);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
