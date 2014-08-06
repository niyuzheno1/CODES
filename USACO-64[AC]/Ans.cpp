#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 1000001;
int n,m,t;
int mp[310][310];
int main(int argc, char *argv[])
{
    freopen("hurdles.in","r",stdin);
    freopen("hurdles.out","w",stdout);
    scanf("%d%d%d",&n,&m,&t);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      mp[i][j] = inf;
    for(int i = 1;i<=n;i++)
     mp[i][i] = 0;
    for(int i = 1;i<=m;i++)
    {
     int x,y,z;
     scanf("%d%d%d",&x,&y,&z);
     mp[x][y] = z;
    }
    for(int k = 1;k<=n;k++)
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=n;j++)
       if(i != j && j != k && k != i)
       mp[i][j] = min(mp[i][j],max(mp[i][k],mp[k][j]));
    for(int i = 1;i<=t;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     printf("%d\n",mp[x][y]==inf?-1:mp[x][y]);
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
