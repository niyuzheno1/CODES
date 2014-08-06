#include <cstdlib>
#include <iostream>

using namespace std;
int n,m,tot;
int st[10010];
struct
{
 int a,b;
}lk[50010*2];
int fl[50010*2],t,ans[10010*2];
void ad(int x,int y)
{
     t++;
     lk[t].a = st[x];
     lk[t].b = y;
     st[x] = t;
}
void dfs(int x)
{
     for(int i = st[x];i;i=lk[i].a)
      if(!fl[i])
      {
       fl[i] = 1;
       dfs(lk[i].b);
      }
     tot++;
     ans[tot] = x;
}
int main(int argc, char *argv[])
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     ad(x,y);ad(y,x);
    }
    dfs(1);
    for(int i = tot;i>=1;i--)
     printf("%d\n",ans[i]);
    system("PAUSE");
    return EXIT_SUCCESS;
}
