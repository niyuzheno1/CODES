#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 0x7f7f7f7f;
const int finf = 0x81818181;
int t,s,n;
struct le
{
int m,l,a;
};
le p[110];
int ta[110];
int f[100010][110];
int main(int argc, char *argv[])
{
    freopen("ski.in","r",stdin);
    freopen("ski.out","w",stdout);
    memset(f,0x81,sizeof(f));
    memset(ta,0x7f,sizeof(ta));
    scanf("%d%d%d",&t,&s,&n);
    for(int i = 1;i<=s;i++)
     scanf("%d%d%d",&p[i].m,&p[i].l,&p[i].a);
    for(int i = 1;i<=n;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     ta[x] = min(ta[x],y);
    }
    f[0][1] = 0;
    int ans = 0;
    for(int i = 0;i<=t;i++)
     for(int j = 1;j<=100;j++)
      if(f[i][j] != finf)
      {
       ans = max(ans,f[i][j]);
       f[i+1][j] = max(f[i+1][j],f[i][j]);
       for(int k = 1;k<=j;k++)
        if(ta[k] != inf)
         f[i+ta[k]][j] = max(f[i+ta[k]][j],f[i][j]+1);
       for(int k = 1;k<=s;k++)
        if(p[k].m <= i)
         f[i+p[k].l][p[k].a] = max(f[i+p[k].l][p[k].a],f[i][j]);
      }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
