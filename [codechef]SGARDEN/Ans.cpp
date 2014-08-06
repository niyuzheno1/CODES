#include "mode.h"
typedef long long LL;
const LL mod  = 1000000007;
int gcd(int x,int y)
{
    if(y == 0) return x;
    return gcd(y,x%y);
}
void mutmod(LL & u,LL v,LL w)
{
     u = ((v%mod)*(w%mod))%mod;
}
#define MN 100010
int a[MN],vis[MN];

int main(int argc, char *argv[])
{
    setIO("sample");
    int T;
    scanf("%d",&T);
    while(T--)
    {
     vector<int> o;
     int n;scanf("%d",&n);CLEAR(vis,0);
     for(int i =1;i<=n;++i) scanf("%d",&a[i]);
     LL ret = 1;
     for(int i =1;i<=n;++i)
     if(!vis[i]){
             vis[i] = 1;
             int s = 1;
             int u = a[i];
             while(!vis[u])
             {
              vis[u] = 1;
              ++s;u = a[u];
             }
     o.pb(s);
     }
     int u = o[0];
     for(int i = 1;i<o.size();++i)
      u = gcd(u,o[i]);
     ret = o[0];
     for(int i = 1;i<o.size();++i)
     {
      mutmod(ret,ret,o[i]/u);
     }
     printf(I64D,ret);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
