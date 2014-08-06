#include "mode.h"
const int MN = 200010;
int n,dfs[MN],bfs[MN],Max[MN],Min[MN],rk[MN];
void build(int idx,int l,int r)
{
     if(l == r)
     {
      Min[idx] = dfs[l];
      return;
     }
     int mid = (l+r)>>1;
     build(idx*2,l,mid);
     build(idx*2+1,mid+1,r);
     Min[idx] = min(Min[idx*2],Min[idx*2+1]);
}
int getmin(int idx,int l,int r,int ll,int rr)
{
    if(ll<= l && r<=rr)
     return Min[idx];
    int ret = INF;
    int mid = (l+r)>>1;
    if(ll <= mid)
    ret = min(ret,getmin(idx*2,l,mid,ll,rr));
    if(rr > mid)
    ret = min(ret,getmin(idx*2+1,mid+1,r,ll,rr));
    return ret;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i  = 1;i<=n;++i)
    {
     dfs[i] = gi;
     rk[dfs[i]]= i;
    }
    for(int i  =1;i<=n;++i)
    {
     bfs[i] = gi;
     dfs[rk[bfs[i]]]= i;
    }
    for(int i = 1;i<=n;++i)
     rk[dfs[i]]= i;
    for(int i = 1;i<=n;++i)
     Max[i] = max(Max[i-1],dfs[i]);
    build(1,1,n);
    int ans = 2,tmp = 0;
    for(int i = 1;i<n;++i)
    {
     if(i == 1 || rk[i+1]<rk[i]) ans += tmp+2,tmp = 0;
     else if(rk[i]+1 == rk[i+1] && Max[rk[i]]<i+1) ++tmp;
     else if(getmin(1,1,n,rk[i]+1,rk[i+1]-1)<i) tmp = 0; 
    }
    ans += tmp;
    printf("%.3f\n%.3f\n%.3f\n",ans/2.0-0.001,ans/2.0,ans/2.0+0.001);
    closeIO();
    return EXIT_SUCCESS;
}
