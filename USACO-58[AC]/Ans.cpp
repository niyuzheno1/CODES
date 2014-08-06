#include <cstdlib>
#include <iostream>

using namespace std;
int n,q;
struct note
{
 int d,maxd;
};
note p[30010];
int f[30010];
int gf(int x)
{
 int z = x;
 int d = 0;
 while(z != f[z])
 {
  d += p[z].d;
  z = f[z];
 }
 int y = x;
 while(y != f[y])
 {
  d-=p[y].d;
  p[y].d += d;
  int tmp = f[y];
  f[y] = z;
  y = tmp;
 }
 return z;
}
int main(int argc, char *argv[])
{
    freopen("cubes.in","r",stdin);
    freopen("cubes.out","w",stdout);
    scanf("%d",&q);
    for(int i = 1;i<=30000;i++)
     f[i] = i,p[i].d = 0,p[i].maxd = 1;
    for(int i = 1;i<=q;i++)
    {
     char str[3];int x,y;
     scanf("%s",str);
     if(str[0] == 'M')
     {
      scanf("%d%d",&x,&y);
      int fx = gf(x);
      int fy = gf(y);
      p[fx].d = p[fy].maxd;
      f[fx] = fy;
      p[fy].maxd = p[fy].maxd+p[fx].maxd;
     }
     else
     {
      scanf("%d",&x);
      gf(x);
      printf("%d\n",p[x].d);
     }
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
