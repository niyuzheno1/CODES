#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 518000959;
int k,n,m,s,e;
int f[1010][1010][21];
int best[1010];
int best2[1010];
int h[1010];
int p(int x)
{
    if(h[x])
     return h[x];
    n++;
    h[x] = n;
    return n;
}
int main(int argc, char *argv[])
{
    freopen("relays.in","r",stdin);
    freopen("relays.out","w",stdout);
    n = 0;
    for(int i = 1;i<=1000;i++)
     for(int j = 1;j<=1000;j++)
      for(int z = 0;z<=20;z++)
       f[i][j][z] = inf;
    for(int i = 1;i<=1000;i++)
     best2[i] = best[i] = inf;
    
    
    scanf("%d%d%d%d",&k,&m,&s,&e);
    for(int i = 1;i<=m;i++)
    {
     int l,u,v;
     scanf("%d%d%d",&l,&u,&v);
     u = p(u);
     v = p(v);
     f[u][v][0] = min(f[u][v][0],l);
     f[v][u][0] = min(f[v][u][0],l);
    }
    s = p(s);e = p(e);
    for(int p = 1;(1<<p)<=k;p++)
     for(int q = 1;q<=n;q++)
      for(int i = 1;i<=n;i++)
       for(int j = 1;j<=n;j++)
        if(f[i][q][p-1] != inf && f[i][j][p-1] != inf)
        f[q][j][p] = min(f[q][j][p],f[q][i][p-1]+f[i][j][p-1]);
    best[s] = 0;
    for(int p = 0;(1<<p)<=k;p++)
     if((k & (1<<p)) != 0)
     {
      for(int i = 1;i<=n;i++)
       best2[i] = inf;
      for(int i = 1;i<=n;i++)
       for(int j = 1;j<=n;j++)
        if(best[i] != inf)
         best2[j] = min(best2[j],best[i]+f[i][j][p]);
     memcpy(best,best2,sizeof(best2));
     }
    printf("%d\n",best[e]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}