#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#define pb push_back
#define X first
#define Y second
using namespace std;
const int maxn = 200010,maxm = 400010;
typedef pair<int,int> p;
int n,m;
int a[maxn][3];
int b[maxm][3];
int t[maxn];
vector<p> v;
int f[maxn];
int gf(int x)
{
    if(x == f[x])
     return x;
    int y = gf(f[x]);
    f[x] = y;
    if(t[f[x]] < t[x] )
     t[x] = t[f[x]];
     return y;
}
void u(int x,int y,int T)
{
     if(gf(x) != gf(y)){
     if(x == 1)
      f[gf(y)] = x ,t[y] = T;
     if(y == 1)
      f[gf(x)] = y ,t[x] = T;
     else
     f[gf(x)]= f[gf(y)];
    }
}
int main(int argc, char *argv[])
{
    memset(t,0x7f,sizeof(t));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
     scanf("%d%d",&a[i][1],&a[i][2]);
     v.pb(p(i,1)),v.pb(p(i,2));
     f[i] = i;
    }
    for(int i = 1;i<=m;i++)
    {
     scanf("%d%d",&b[i][1],&b[i][2]);
     v.erase(find(v.begin(),v.end(),p(b[i][1],b[i][2])));
    }
    for(int i = 0;i<v.size();i++)
     u(v[i].X,a[v[i].X][v[i].Y],m);

    for(int i = m;i>=1;i--)
    if(a[b[i][1]][b[i][2]] != -1)
    u(b[i][1],a[b[i][1]][b[i][2]],i);
    for(int i = 1;i<=n;i++)
     {
      gf(i);
     printf("%d\n",t[i] >= m ? -1 : t[i]);
     }
    system("PAUSE");
    return EXIT_SUCCESS;
}
