#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#define pb push_back
#define X first
#define Y second
#define zero(x) memset(x,0,sizeof(x))
using namespace std;
int n;
char inf[101],ouf[101];
typedef pair<int,int> p;
typedef pair<int,p> t;
int f[310];
vector<t> v;
int g(int x)
{
    if(x == f[x])
     return x;
    return f[x] = g(f[x]);
}
void u(int x,int y)
{
     x = g(x);y=g(y);
     f[x] = y;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr469.in%d",cani);
    sprintf(ouf,"mr469.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n;
    zero(f);
    v.clear();
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     f[i] = i;
     scanf("%d",&f[301]);
     v.pb(t(f[301],p(0,i)));
     v.pb(t(f[301],p(i,0)));
    }
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
     {
     scanf("%d",&f[301]);
     v.pb(t(f[301],p(i,j)));
     v.pb(t(f[301],p(j,i)));
     }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i = 0;i<v.size();i++)
    {
     t m = v[i];
     if(g(m.Y.X) != g(m.Y.Y))
     {
      u(m.Y.X,m.Y.Y);
      ans += m.X;
     }
    }
    printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
