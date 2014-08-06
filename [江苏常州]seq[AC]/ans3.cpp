#include "mode.h"
#include "data.h"
using namespace std;
const int MN = 200010;
int n,b[MN],c[MN],s[MN],d,k,e[MN],mu,f[MN],p[MN];
pii a[MN];
vector<int> l;

bool cmp(int x,int y)
{
 return a[x] < a[y];
}

int get(int x)
{
 int ans = 0;
 for(;x;x-=lb(x))
  ans = max(ans,e[x]);
 return ans;
}

void ins(int x,int y)
{
 for(;x<=mu;x+=lb(x))
  e[x] = max(e[x],y);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i)
    {
     p[i] = i;
     char c = 0;while(c != 'N' && c != 'K') c = getchar();
     if(c == 'N') ++k;
     else{++d;a[d].X = gi;a[d].Y = i;s[d]= k;l.pb(-s[d]+a[d].X); l.pb(-s[d]+a[d].X+1);}
    }
    sort(p+1,p+d+1,cmp);
    sort(l.begin(),l.end());
    for(int i = 1;i<=d;mu=max(mu,b[i]),++i)
     b[i] = lower_bound(l.begin(),l.end(),-s[i]+a[i].X)-l.begin()+1;
    for(int i = 1;i<=d;mu=max(mu,c[i]),++i)
     c[i] = lower_bound(l.begin(),l.end(),-s[i]+a[i].X+1)-l.begin()+1;
	++mu;
    int ans = 0;
    int  u = 0;
    for(int i = 1;i<=d;ans = max(ans,f[u]),++i)
    {
    u = p[i];
    f[u] = get(b[u])+1;ins(c[u],f[u]);
    }
    printf("%d\n",ans+k);
    closeIO();
    return EXIT_SUCCESS;
}
