#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10009;
int f[N][15],dep[N],dist[N],n,ec,son[N],lnk[N*2],nxt[N*2],len[N*2];
void dfs(const int u)
{
 for(int v,i=son[u];i;i=nxt[i]){
  if((v = lnk[i])==f[u][0]) continue;
  f[v][0] = u;
  dep[v] = dep[u]+1;
  dist[v] = dist[u]+len[i];
  dfs(v);
 }
}
FILE * d;
void addedge(const int x,const int y,const int z)
{
 nxt[++ec] = son[x];
 son[x] = ec;
 lnk[ec] = y;
 len[ec] = z;
}
int gtlca(int x,int y)
{
 if(dep[y] > dep[x]) swap(x,y);
 for(int i = 14;i>=0;--i)
  if(dep[f[x][i]] >= dep[y]) x = f[x][i];
 if(x == y)
  return x;
 for(int i = 14;i>=0;--i)
  if(f[x][i] != f[y][i])
   x = f[x][i],y = f[y][i];
 return f[x][0];
}
int gkt(int x,int k)
{
 for(int i = 0;k;++i,k/=2)
   if(k & 1) x = f[x][i];
 return x;
}
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);d = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(d);
 #endif
}
int main(int argc, char *argv[])
{
    setIO("Qtree2");
    int T = 0;scanf("%d",&T);
    while(T--)
    {
     scanf("%d",&n);
     for(int i = 1;i<=n;++i) son[i] = 0;
     ec = 0;
     for(int x,y,z,i=1;i<n;++i){
      scanf("%d%d%d",&x,&y,&z);
      addedge(x,y,z);
      addedge(y,x,z);
     }
     dep[1] = 1;
     dfs(1);
     for(int i = 1;i<15;++i)
      for(int j =1;j<=n;++j)
       f[j][i] = f[f[j][i-1]][i-1];
     char s[10];
     for(int x,y,z;scanf("%s",s),s[1] != 'O';){
      scanf("%d%d",&x,&y);
      int lca  = gtlca(x,y);
      if(s[0] == 'D') printf("%d\n",dist[x]+dist[y]-dist[lca]*2);
      else
      {
       scanf("%d",&z);
       if(dep[x]-dep[lca]+1>=z) printf("%d\n",gkt(x,z-1));
       else printf("%d\n",gkt(y,dep[x]+dep[y]-2*dep[lca]+1-z));
      }
     }
     puts("");
    }
    
    closeIO();
    return EXIT_SUCCESS;
}
