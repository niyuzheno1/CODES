#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
const int inf = 0x7f7f7f7f;
int l,n;
struct p
{
      int t,s;
      bool operator < (p a) const
      {
           return t<a.t;
      }
};
p mp[100010];
int f[100010];
int m[100010];
int solve(int a,int b,int c)
{
    return (a+b+c)/2;
}
void print(int * x,int y)
{
     printf("\n");
     for(int i = 1;i<=y;i++)
      printf("%d ",x[i]);
     printf("\n");
}
int main(int argc, char *argv[])
{
    freopen("bobsled.in","r",stdin);
    freopen("bobsled.out","w",stdout);
    scanf("%d%d",&l,&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&mp[i].t,&mp[i].s);
    mp[n+1].t = 0;mp[n+1].s = 1;
    mp[n+2].s = inf;mp[n+2].t = l;
    n+=2;
    sort(mp+1,mp+n+1);
    m[n] = inf;
    for(int i = n-1;i>=1;i--)
     m[i] = min(m[i+1]+mp[i+1].t-mp[i].t,mp[i].s);
    //print(m,n);
    f[1] = 1;
    int ans = 0;
    for(int i = 2;i<=n;i++){
     f[i] = min(f[i-1]+mp[i].t-mp[i-1].t,m[i]);
     ans = max(ans,solve(f[i-1],f[i],mp[i].t-mp[i-1].t));
    }
    //print(f,n);
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
