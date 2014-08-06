#include <cstdlib>
#include <iostream>

using namespace std;
int n;
struct p
{
 int u,v,len;
 bool operator<(p y) const
 {
  return len < y.len;
 }
};
p k[310*310];
int f[310];
int t;
int gf(int x)
{
    if(f[x] == x)
     return x;
    return (f[x] = gf(f[x]));
}
int uf(int x,int y)
{
    x = gf(x);
    y = gf(y);
    f[x] = f[y];
}
void add(int x,int y,int c)
{
    t++;
    k[t].u = x;
    k[t].v = y;
    k[t].len = c; 
}
int main(int argc, char *argv[])
{
    freopen("water.in","r",stdin);
    freopen("water.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int c = 0;
     scanf("%d",&c);
     add(0,i,c);
    }
    for(int i = 1;i<=n;i++)
     f[i] = i;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
     {
      int u = 0;
      scanf("%d",&u);
      add(i,j,u); 
     }
    int ans = 0;
    sort(k+1,k+1+t);
    for(int i = 1;i<=t;i++)
     if(gf(k[i].u) != gf(k[i].v))
     {
      uf(k[i].u,k[i].v);
      ans += k[i].len;
     }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
