#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 10000;
int n,m;
struct p
{
 int mp[110][110];
 void init()
 {
  for(int i = 1;i<=n;i++)
   for(int j = 1;j<=n;j++)
    mp[i][j] = inf;
 }
 void cal()
 {
  for(int k = 1;k<=n;k++)
   for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++)
     if(i != j && j != k && k != i)
     mp[i][j] = min(mp[i][j],mp[i][k]+mp[k][j]);
 }
};
p q,t;
int main(int argc, char *argv[])
{
    freopen("contest.in","r",stdin);
    freopen("contest.out","w",stdout);
    scanf("%d%d",&n,&m);
    q.init();t.init();
    for(int i = 1;i<=m;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     q.mp[x][y] = t.mp[y][x] = 1;
    }
    q.cal();t.cal();
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
     int x = 0;
     for(int j = 1;j<=n;j++)
      if(q.mp[i][j] != inf || t.mp[i][j] != inf)
       x++;
     if(x == n-1)
      ans++;
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
