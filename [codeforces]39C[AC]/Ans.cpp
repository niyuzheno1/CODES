#include "mode.h"
const int u = 4010;
struct rec{int x,l,r;}a[u];
int f[u][u],d[u][u],v[u][u],b[u],n,m;
vector<int> c[u];
int dp(int l,int r)
{
    if(l>r) return 0;
    if(f[l][r] != -1) return f[l][r];
    f[l][r] = dp(l+1,r);
    for(int i = 0,j;i<c[l].size();i++)
     if(a[j=c[l][i]].r < r && dp(l,a[j].r)+dp(a[j].r,r) > f[l][r])
      f[l][r] = dp(l,a[j].r)+dp(a[j].r,r),d[l][r] = j;
    return f[l][r]+=(v[l][r]>0);  
}
void print(int l,int r)
{
     if(l>r) return;
     if(v[l][r]) printf("%d ",v[l][r]);
     if(d[l][r]) print(l,a[d[l][r]].r),print(a[d[l][r]].r,r);
     else return print(l+1,r);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i)
    {
     a[i].x = gi,a[i].r = gi;
     a[i].l = a[i].x-a[i].r;a[i].r += a[i].x;
     b[++m] = a[i].l,b[++m] = a[i].r;
    }
    sort(b+1,b+1+m);
    m = unique(b+1,b+1+m)-b-1;
    for(int i = 1;i<=n;i++)
    {
     a[i].l = lower_bound(b+1,b+1+m,a[i].l)-b;
     a[i].r = lower_bound(b+1,b+1+m,a[i].r)-b;
     c[a[i].l].push_back(i);
     v[a[i].l][a[i].r] = i;
    }
    CLEAR(f,0xff);
    printf("%d\n",dp(1,m));
    print(1,m);
    closeIO();
    return EXIT_SUCCESS;
}
