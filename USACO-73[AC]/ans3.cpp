#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 500*10000;
int f[510][2][510];
int a[510],ne[510],st[510],s[510],dfn[510];
int g[510];
int n,x,t;
void dfs(int x)
{
     for(int i = 0;i<=n;i++)
      f[x][0][i] = f[x][1][i] = -inf;
     s[x] = 1;
     t++;
     dfn[t] = x;
     for(int i = st[x];i;i = ne[i])
     {
      dfs(i);
      s[x]+=s[i];
     }
}
int main(int argc, char *argv[])
{
    freopen("tselect.in","r",stdin);
    freopen("tselect.out","w",stdout);
    scanf("%d%d",&n,&x);
    for(int i = 1;i<=n;i++)
    {
    int m;
    scanf("%d%d",&a[i],&m);
    ne[i] = st[m];
    st[m] = i;
    }
    dfs(0);
    for(int ty = t;ty>=1;ty--)
    {
     int x = dfn[ty];
     for(int i = 0;i<2;i++)
     {
      f[x][i][0] = i*a[x];
      for(int k = st[x];k;k=ne[k]){
        memcpy(g,f[x][i],sizeof(g));
        for(int l = 0;l<2;l++)
         for(int p = 0;p<=s[k];p++)
          for(int j = p+(l&i);j<=s[x];j++)
           g[j] = max(g[j],f[x][i][j-p-(l&i)]+f[k][l][p]);
        memcpy(f[x][i],g,sizeof(g));
      }
     }
    }
    int ans = 0;
    for(int i = n;i>=0;i--)
     if(f[0][0][i]>=x)
     {
      printf("%d\n",i);
      ans = 1;
      break;
     }
    if(!ans)
     puts("-1\n");
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
