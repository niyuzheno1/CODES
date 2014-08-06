#include <cstdlib>
#include <iostream>

using namespace std;
int n,m;
int p[40010];
int id[40010],si;
int f[40010];
int g[40010];
int main(int argc, char *argv[])
{
    freopen("cleanup.in","r",stdin);
    freopen("cleanup.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&p[i]);
    memset(&g,0x7f,sizeof(g));
    for(int i = 1;i<=m;i++)
     f[i] = -1;
    si = 0;
    g[0] = 0;
    for(int i = 1;i<=n;i++)
    {
     int x = f[p[i]];
     int j = 0;
     for( ;j<=si;j++)
      if(id[j] == x)
       break;
     si = max(si,j);
     for(;j>=1;j--)
        id[j] = id[j-1];
     id[0] = i;
     f[p[i]] = i;
     for(int k = 1;k<=si;k++)
      g[i] = min(g[i],g[id[k]]+k*k);
    }
    printf("%d",g[n]);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
