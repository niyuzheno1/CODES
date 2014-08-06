#include <cstdlib>
#include <iostream>

using namespace std;

const int inf = 1000010;
const int maxn = 310,maxm = (310-1)*310+10,mlog = 9;
typedef int mt[maxn][maxn];
int n,m;
void c(mt & a,mt b,mt c)
{
 for(int i = 1;i<=n;i++)
  for(int j = 1;j<=n;j++)
  {
   int val = inf;
   for(int k = 1;k<=n;k++)
    val = min(val,b[i][k]+c[k][j]);
   a[i][j] = val;
  }
}
int vd(mt a)
{
     int ans=  inf;
     for(int i= 1;i<=n;i++)
      ans = min(a[i][i],ans);
     return ans;
}
void print(mt x)
{
     /*for(int i =1;i<=n;i++,printf("\n"))
      for(int j = 1;j<=n;j++)
       printf("%d ",x[i][j]);*/
} 
mt e;
mt f[mlog+1];
mt tmp;
void cpy(mt &x,mt y)
{
     for(int i = 1;i<=n;i++)
      for(int j = 1;j<=n;j++)
       x[i][j] = y[i][j];
}
int main(int argc, char *argv[])
{
    freopen("utrka.in","r",stdin);
    freopen("utrka.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      e[i][j] = inf;
    for(int i = 1;i<=n;i++)
     e[i][i] = 0;
    for(int i = 1;i<=m;i++)
    {
     int x,y,a,b;
     scanf("%d%d%d%d",&x,&y,&a,&b);
     e[x][y] = a-b;
    }
   cpy(f[0],e);
   for(int i = 1;i<=mlog;i++)
     c(f[i],f[i-1],f[i-1]);
   int ans1 = 1,ans2 = 0;
    for(int i = mlog;i>=0;i--)
    {
     c(tmp,e,f[i]);
     if(vd(tmp) >= 0)
     {
     ans1 += (1<<i);
     cpy(e,tmp);
     }
    }
    if(vd(e) >= 0)
     c(tmp,e,f[0]),cpy(e,tmp),ans1++;
    ans2 = vd(e);
    printf("%d %d\n",ans1,-ans2);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
