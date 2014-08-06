#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#define pb push_back
#define zero(x) memset(x,0,sizeof(x))
using namespace std;
const int inf = 0x7f7f7f7f;
typedef vector<int> v;
typedef pair<int,v> p;
int n,k;
int a[110];
int N[110][11];
map<p,int> f;
char info[101],ouf[101];
int dfs(int x,v y)
{
    if(x == n+1)
     return inf;
    if(f[p(x,y)] != 0)
     return f[p(x,y)];
    bool u = true;
    for(int i = 1;i<=k;i++)
     if(y[i] == 0)
     u = false;
    int ans = inf;
    if(u)
     ans = min(ans,n-x);
    for(int i = 1;i<=k;i++)
     if(a[x] == i)
          ans = min(ans,dfs(N[x][i],y)+N[x][i]-x-1);
     else if(y[i] == 0)
     {
          v t;
          t = y;
          t[i] = 1;
          ans = min(ans,dfs(N[x][i],t)+N[x][i]-x-1);
     }
     return f[p(x,y)] = ans;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(info);
    zero(ouf);
    
    sprintf(info,"mr473.in%d",cani);
    sprintf(ouf,"mr473.ou%d",cani);
    freopen(info,"r",stdin);
    freopen(ouf,"w",stdout);
    n = k = 0;
    zero(a);
    zero(N);
    f.clear();
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++){
     for(int j = i+1;j<=n;j++)
      if(N[i][a[j]] == 0)
       N[i][a[j]] = j;
     for(int j = 1;j<=k;j++)
      if(N[i][j] == 0)
       N[i][j] = n+1;
    }
    v v1;
    for(int i = 0;i<=k;i++)
     v1.pb(0);
    int ans = 0x7f7f7f7f;
    for(int i = 1;i<=n;i++){
     v t;
     t = v1;
     t[a[i]] = 1;
     ans = min(ans,dfs(i,t)+i-1);
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
