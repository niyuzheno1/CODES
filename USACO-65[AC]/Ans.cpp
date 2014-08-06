#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
const int64 inf = (0x7f7f7f7f);
int64 n,m,k;
int64 f[251][251];
int64 e[251][251];
int64 dis[251][251];
int64 c[251],d[251];
int main(int argc, char *argv[])
{
    freopen("toll.in","r",stdin);
    freopen("toll.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int64 i = 1;i<=n;i++)
     for(int64 j = 1;j<=n;j++)
      f[i][j] = e[i][j] = inf;
    for(int64 i = 1;i<=n;i++)
      f[i][i] = e[i][i] = 0;
    for(int64 i = 1;i<=n;i++)
     scanf("%d",&c[i]),d[i]=c[i];
    sort(d+1,d+1+n);
    for(int64 i = 1;i<=m;i++)
    {
     int64 a,b,l;
     scanf("%d%d%d",&a,&b,&l);
     e[b][a] = e[a][b] = min(e[a][b],l);
    }
    for(int64 i = 1;i<=n;i++)
    {
     memset(dis,0x7f,sizeof(dis));
     int64 x = d[i];
     for(int64 j = 1;j<=n;j++)
      if(c[j] <= x)
       for(int64 k = 1;k<=n;k++)
        if(c[k] <= x)
         dis[k][j] = dis[j][k] = e[k][j];
     for(int64 k = 1;k<=n;k++)
      for(int64 ii = 1;ii<=n;ii++)
       for(int64 j = 1;j<=n;j++)
        if(k != ii && ii != j && j != k)
         if(dis[ii][k] < inf && dis[k][j] < inf)
        dis[ii][j] = min(dis[ii][j],dis[ii][k]+dis[k][j]);
     for(int64 ii= 1;ii<=n;ii++)
      for(int64 j = 1;j<=n;j++)
       if(dis[ii][j] < inf)
       f[ii][j] = min(f[ii][j],dis[ii][j]+x);   
    }
    for(int64 i= 1;i<=k;i++)
    {
     int64 x,y;
     scanf("%d%d",&x,&y);
     printf("%d\n",f[x][y]);
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
