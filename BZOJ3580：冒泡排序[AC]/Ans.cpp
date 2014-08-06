#include "mode.h"
#include "data.h"

typedef long long LL;
const int MN = 1000010;
int a[MN],f[MN],num[MN],ans[MN],pos[MN];
set<int > s;
LL n,k;

void update(int x){
 while(x <= n){++num[x];x += lb(x);}
}
int sum(int x){
 int res = 0;
 while(x){
  res += num[x];
  x-=lb(x);
 }
 return res;
}
LL solve(int x){
 LL res = 0;
 for(int i = 1;i<=n;++i) res += (LL)min(x,f[i]);
 return res;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;k=gi;
    for(int i = 1;i<=n;++i) a[i] = gi, pos[a[i]] = i;
    for(int i = 1;i<=n;++i){
     f[a[i]] = sum(n+1-a[i]);
     update(n+1-a[i]);
    }
    if(solve(n-1) < k){
     puts("Impossible!");
     closeIO();
     return 0;
    }
    int l= 0,r = n-1;
    while(l < r){
     int mid = (l+r+1)>>1;
     if(solve(mid) <= k) l = mid;
     else r = mid-1;
    }
    ff(debug,"%d\n",l);
    k -= solve(l);
    for(int i = 1;i<=n;++i){
     f[i] -=l;
     if(f[i] < 0) f[i] = 0;
    }
    for(int i = 1;i<=n;++i) s.insert(i);
    for(int i = 1;i<=n;++i){
     set<int>::iterator p = s.lower_bound(pos[i]-l);
     ans[*p] = i;
     s.erase(p);
    }
    for(int i = 1;i<n;++i){
     if(!k) break;
     if(ans[i] > ans[i+1])
      swap(ans[i],ans[i+1]),--k;
    }
    for(int i = 1;i<n;++i) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    closeIO();
    return EXIT_SUCCESS;
}
