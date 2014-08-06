#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int MAXN = 10100,MAXE = MAXN*2,MAXD = 17;
int n,dfn[MAXN],tot,dfs_clock;
struct lik{ int n,v,c;};
struct sta{int st;int f[MAXD],len,dep;};
lik lk[MAXE];
sta st[MAXN];
char str[MAXD];
void add1(int x,int y,int z){tot++;lk[tot].v = y;lk[tot].c = z;lk[tot].n = st[x].st;st[x].st = tot;}
void add(int x,int y,int z){add1(x,y,z);add1(y,x,z);}
void dfs(int x,int y,int z,int dep)
{
 dfs_clock++;dfn[dfs_clock] = x;
 st[x].len = z;st[x].f[0] = y;st[x].dep = dep;
 for(int i = st[x].st;i;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v == y)continue;
  dfs(v,x,z+lk[i].c,dep+1);
 }
}
int lca(int x,int y)
{
 if(st[x].dep > st[y].dep)
  swap(x,y);
 int up = st[y].dep-st[x].dep;
 for(int i = MAXD-1;i>=0;i--)
  if((up&(1<<i)))
   y = st[y].f[i];
 if(y == x)
  return x;
 int l = 0,r = MAXD-1,mid = 0;
 while(l<r)
 {
  mid = (l+r)/2;
  if(st[x].f[mid] == st[y].f[mid])
   r = mid;
  else
   l = mid+1;
 }
 mid = (l+r)/2;
 x = st[x].f[mid];
 y = st[y].f[mid];
 if(x != y)
  return st[x].f[0];
 else
  return x;
}
int dis(int x,int y)
{
 int u = lca(x,y);
 return st[x].len+st[y].len-st[u].len*2;
}
int que(int x,int y)
{
 for(int i = MAXD-1;i>=0;i--)
  if((y & (1<<i)))
   x = st[x].f[i];
 return x;
}
int query(int x,int y,int z)
{
 int u = lca(x,y);
 int d = st[x].dep-st[u].dep;
 if(z < d)
  que(x,z-1);
 else
  que(y,st[x].dep+st[y].dep-2*st[u].dep-z+1);
}
int main(int argc, char *argv[])
{
    //freopen("qtree2.in","r",stdin);freopen("qtree2.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
     dfs_clock = 0;tot = 0;memset(st,0,sizeof(st));
     scanf("%d",&n);
     for(int i = 1;i<=n-1;i++)
     {
      int x,y,z;scanf("%d%d%d",&x,&y,&z);
      add(x,y,z);
     }
     dfs(1,0,0,0);
     for(int i = 1;i<MAXD;i++)
      for(int k = 1;k<=dfs_clock;k++){
       int j = dfn[k];
       st[j].f[i] = st[st[j].f[i-1]].f[i-1];
      }
     while(scanf("%s",str) && str[1] != 'O')
     {
      int x,y,z;scanf("%d%d",&x,&y);
      if(str[0] == 'D')
       printf("%d\n",dis(x,y));
      else{
       scanf("%d",&z);
       printf("%d\n",query(x,y,z));
      }
     }
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
