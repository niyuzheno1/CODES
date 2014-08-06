/**************************************************************
    Problem: 3244
    User: lazycal
    Language: C++
    Result: Accepted
    Time:292 ms
    Memory:7056 kb
****************************************************************/
  
#include <cstdio>
#include <algorithm>
const int N = 200000 + 9;
int Max[N],Min[N*4],rk[N],dfs[N],bfs[N],n;
void build(const int idx,const int l,const int r)
{
    if (l == r) return (void)(Min[idx] = dfs[l]);
    build(idx * 2,l,(l+r)/2);
    build(idx*2+1,(l+r)/2+1,r);
    Min[idx] = std::min(Min[idx*2],Min[idx*2+1]);
}
int MIN(const int idx,const int l,const int r,const int L,const int R)
{
    if (L <= l && r <= R) return Min[idx];
    int mid = (l + r)/2,res = 0x7fffffff;
    if (L <= mid) res = std::min(res,MIN(idx * 2,l,mid,L,R));
    if (mid < R) res = std::min(res,MIN(idx*2+1,mid+1,r,L,R));
    return res;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    #endif
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",dfs + i);
        rk[dfs[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d",bfs + i);
        dfs[rk[bfs[i]]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        Max[i] = std::max(Max[i - 1],dfs[i]);
        rk[dfs[i]] = i;
    }
    build(1,1,n);
    int ans = 2,tmp = 0;
    for (int i = 1; i < n; ++i) {
        if (i == 1 || rk[i + 1] < rk[i]) ans += tmp + 2,tmp = 0;
        else if (rk[i] + 1 == rk[i + 1] && Max[rk[i]] < i + 1) ++tmp;
        else if (MIN(1,1,n,rk[i] + 1,rk[i + 1] - 1) < i) tmp = 0;
    }
    ans += tmp;
    printf("%.3f\n%.3f\n%.3f\n",ans/2.0-0.001,ans/2.0,ans/2.0+0.001);
}
