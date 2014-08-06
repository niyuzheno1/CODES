#include <cstdlib>
#include <iostream>

using namespace std;
const int dx[] = {0,0,-1,0,1};
const int dy[] = {0,1,0,-1,0};
int n,q,m;
int a[50010][5];
int f[40010];
int p[40010][2];
struct pp
{
  int a,b,c,d;
  bool operator <(pp x) const
  {
   return c < x.c;
  }
};
pp b[50010];
int gf(int i,int & x,int & y)
{
    int z = i;
    int sx = 0,sy = 0;
    while(z != f[z])
    {
     sx += p[z][0];
     sy += p[z][1];
     z = f[z];
    }
    int xx = z;
    z = i;
    while(z != f[z])
    {
     sx -= p[z][0];
     sy -= p[z][1];
     p[z][0] += sx;
     p[z][1] += sy;
     int p = f[z];
     f[z] = xx;
     z = p;
    }
    x = p[i][0];
    y = p[i][1];
    return z;
}
int ans[50010];
int main(int argc, char *argv[])
{
    freopen("navigate.in","r",stdin);
    freopen("navigate.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=n;i++)
     f[i] = i;
    for(int i = 1;i<=q;i++)
    {
     int x,y,z;
     char s[10];
     scanf("%d%d%d%s",&a[i][1],&a[i][2],&a[i][3],&s);
     switch(s[0])
     {
      case 'E':
         a[i][4] = 1;
         break;
      case 'N':
         a[i][4] = 2;
         break;
      case 'W':
         a[i][4] = 3;
         break;
      case 'S':
         a[i][4] = 4;
         break;
     };
    }
    scanf("%d",&m);
    for(int i = 1;i<=m;i++){
     scanf("%d%d%d",&b[i].a,&b[i].b,&b[i].c);
     b[i].d = i;
    }
    sort(b+1,b+1+m);
    int j = 1;
    for(int i = 1;i<=q;i++)
    {
    int tx,ty,mx,my,vx,vy;
    int fx = gf(a[i][1],tx,ty);
    int fy = gf(a[i][2],mx,my);
    vx = a[i][3]*dx[a[i][4]];
    vy = a[i][3]*dy[a[i][4]];
    f[fx] = f[fy];
    p[fx][0] = mx-vx-tx;
    p[fx][1] = my-vy-ty;
     while(b[j].c == i && j<=m)
     {
     
      fx = gf(b[j].a,tx,ty);
      fy = gf(b[j].b,mx,my);
      if(fx != fy)
       ans[b[j].d] = -1;
      else 
       ans[b[j].d] = abs(tx-mx)+abs(ty-my); 
      j++;
     }
    }
    for(int i = 1;i<=m;i++)
     printf("%d\n",ans[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
