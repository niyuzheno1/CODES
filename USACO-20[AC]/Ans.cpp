#include <cstdlib>
#include <iostream>
#include <cmath>
#define sqr(x) (x)*(x)
using namespace std;
struct e
{
  double len;
  int u,v;
  bool operator <(e x) const
  {
   return len < x.len;
  }
};
e ed[1000*1000];
int t;
void a(int x,int y,double c)
{
     t++;
     ed[t].u = x, ed[t].v = y;
     ed[t].len = c;
}
int f[1010];
double u[1010][2];
int gf(int x)
{
    if(f[x] == x)
     return x;
    return (f[x] = gf(f[x]));
}
void uf(int x,int y)
{
    x = gf(x);
    y = gf(y);
    f[x] = f[y];
}
double dis(int x,int y)
{
       return sqrt(sqr(u[x][0]-u[y][0])+sqr(u[x][1]-u[y][1]));
}
int n,m;
int main(int argc, char *argv[])
{
    freopen("roads.in","r",stdin);
    freopen("roads.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
     scanf("%lf%lf",&u[i][0],&u[i][1]);
     f[i] = i;
    }
    for(int i = 1;i<=n;i++)
     for(int j = i+1;j<=n;j++)
      a(i,j,dis(i,j));
    for(int i = 1;i<=m;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     uf(x,y);
    }
    sort(ed+1,ed+1+t);
    double ans = 0;
    for(int i = 1;i<=t;i++)
     if(gf(ed[i].u) != gf(ed[i].v))
     {
      uf(ed[i].u,ed[i].v);
      ans += ed[i].len;
     }
    printf("%.2lf",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
