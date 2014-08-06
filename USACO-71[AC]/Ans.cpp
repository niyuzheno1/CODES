#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 0x7f7f7f7f;
int dfn[10010],t;
struct p
{
 int ne;
 int v;
};
p lk[10010*2];
int tot;
int st[10010];
bool v[10010];
int f[10010][3];
int fa[10010],ter[10010];
int n;
void add(int x,int y)
{
     tot++;
     lk[tot].ne = st[x];
     lk[tot].v = y;
     st[x] = tot;
}
void dfs(int x)
{
    t++;
    dfn[t] = x;
    v[x] = 1;
    ter[x] = 1;
    for(int i = st[x];i != 0;i=lk[i].ne)
    if(!v[lk[i].v])
     dfs(lk[i].v),ter[x] = 0;
    else
     fa[x] = lk[i].v;
}
int main(int argc, char *argv[])
{
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n-1;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     add(x,y);add(y,x);
    }
    dfs(1);
    for(int i = t;i>=1;i--)
    {
     int x = dfn[i];
     bool leaf = true;
     int ans0 = 0,ans1 = 0,ans2 = inf;
     for(int j = st[x];j!= 0;j=lk[j].ne)
      if(lk[j].v != fa[x])
       leaf=false,ans0 += min(f[lk[j].v][1],f[lk[j].v][2]),ans1 += min(min(f[lk[j].v][1],f[lk[j].v][2]),f[lk[j].v][0]);
     for(int j = st[x];j!= 0;j=lk[j].ne)
      if(lk[j].v != fa[x])
       ans2 = min(ans2,ans0-min(f[lk[j].v][1],f[lk[j].v][2])+f[lk[j].v][1]);
     ans1++;
     f[x][0] = ans0;
     f[x][1] = ans1;
     f[x][2] = ans2;
     if(leaf)
     {
     f[x][0] = 0;
     f[x][1] = 1;
     f[x][2] = inf;
     }
    }
   
    printf("%d\n",min(f[1][2],f[1][1]));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
