#include <cstdlib>
#include <iostream>
#include <map>
#include <cstdio>
#define X first
#define Y second
#define sqr(x) ((x)*(x))
using namespace std;
int n,tot;
int st[50010];
const int inf = 0x7f7f7f7f;
struct p
{
 int ne,v;
};
typedef map<int,int> mp;
p lk[50010*2];
int son[50010],br[50010],dfn[50010];
mp f[50010];
void add(int x,int y)
{
     tot++;
     lk[tot].ne = st[x];
     lk[tot].v = y;
     st[x] = tot;
}
void dfs(int x,int y)
{
 tot++;
 dfn[tot] = x;
 br[x] = son[y];
 son[y] = x;
 for(int i = st[x];i;i=lk[i].ne)
  if(lk[i].v != y)
   dfs(lk[i].v,x);
}
int t[50010];
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 1;i<=n-1;i++)
    {
     int A,B;
     scanf("%d%d",&A,&B);
     add(A,B);add(B,A);
    }
    tot = 0;
    dfs(1,0);
    for(int xp = tot;xp>=1;xp--)
    {
     int i = dfn[xp];
     if(son[i] == 0)
      f[i][0] = 0;
     else
     {
      memset(t,0x7f,sizeof(t));
      int c = 1;
      int p = 0;
      for(int j = son[i];j;j=br[j],c++){
       for(mp::iterator k = f[j].begin();k != f[j].end();k++)
       {
        int kk = (*k).X;
        t[c] = min(t[c],(*k).Y+sqr(kk+1));
       }
       p+=t[c];
      }
      c--;
      int uc = 1;
      for(int j = son[i];j;j=br[j],uc++)
       for(mp::iterator k = f[j].begin();k != f[j].end();k++)
       {
        int kk = (*k).X;
        f[i][kk+1] = min(f[i][kk+1]==0?inf:f[i][kk+1],(*k).Y+p-t[uc]);
       }
      if(c >= 2)
      {
      uc = 1;
      for(int j = son[i];j;j=br[j],uc++){
       int up = 1;
       for(int z = son[i];z;z=br[z],up++)
        if(z != j)
         for(mp::iterator k = f[j].begin();k != f[j].end();k++)
          for(mp::iterator pk = f[z].begin();pk != f[z].end();pk++)
           f[i][0] = min(f[i][0]==0?inf:f[i][0],sqr((*k).X+(*pk).X+2)+p-(t[uc]+t[up])+(*k).Y+(*pk).Y);
       }
      }
     }
    }
    printf("%d",f[1][0]);
    system("PAUSE");
    return EXIT_SUCCESS;
}
