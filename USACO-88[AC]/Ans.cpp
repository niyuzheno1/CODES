#include <cstdlib>
#include <iostream>

using namespace std;
int m,n;
int mp[13][13];
int f[13][13][16383];
int cut(int x)
{
    return (x&((1<<n)-1));
}
int main(int argc, char *argv[])
{
    freopen("cowfood.in","r",stdin);
    freopen("cowfood.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=m;i++)
     for(int j = 1;j<=n;j++)
      scanf("%d",&mp[i][j]);
    f[1][1][0] = 1;
    int s  = (1<<n)-1;
    for(int i = 1;i<=m;i++)
     for(int j = 1;j<=n;j++)
      for(int k = 0;k<=s;k++)
      {
       bool flag = 1;
       flag = flag && (mp[i][j]);
       flag = flag && ((k&(1<<(n-1))) == 0);
       if(j != 1)
        flag = flag && ((k&1)==0);
       int p = 0;
       if(flag)
        p = 1;
       int ni = i,nj = j+1;
       if(nj > n)
        ni = i+1,nj=1;
       for(int z = 0;z<=p;z++)
        f[ni][nj][cut((k<<1)+z)] += f[i][j][k];
      }
    int ans = 0;
    for(int i = 0;i<=s;i++)
     ans+=f[m+1][1][i];
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
