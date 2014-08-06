#include "mode.h"
typedef long long LL;
#undef INF
const LL INF= ~0ULL>>1;
#define MN 1010
typedef vector<LL> vL;
typedef vector<int> vi;
typedef priority_queue<LL> pqL;
int n,m,k,p,c[MN][MN];
vL solve(vi a,LL v){ 
 pqL Q;
 for(int i = 0;i<a.size();++i)Q.push(a[i]);
 vL re;
 LL s = 0;
 re.pb(0);
 for(int i = 0;i<k;++i){
  LL x = Q.top();
  Q.pop();
  s+=x;
  re.pb(s);
  Q.push(x-v);
 }
 return re;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi, k = gi, p = gi;
    for(int i = 0;i<n;++i)for(int j = 0;j<m;++j)c[i][j] = gi;
    vi a,b;
    for(int i = 0;i<n;++i){
    int s = 0;
    for(int j = 0;j<m;++j) s += c[i][j];
    a.pb(s);
    }
    for(int j = 0;j<m;++j){
    int s = 0; 
    for(int i = 0;i<n;++i) s += c[i][j];
    b.pb(s);
    }
    vL sa = solve(a,p*m);
    vL sb = solve(b,p*n);
    LL ans = -INF;
    for(int i = 0;i<=k;++i) 
    ans = max(ans,sa[i]+sb[k-i]-i*(1LL)*(k-i)*p);
    printf("%I64d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
