#include "mode.h"
typedef vector<int64> vi;
vi anslist;
const int64 MN =  5*100000+10;
int64 a[MN];
int64 hi[MN], p[MN],n[MN],ans;
inline bool cmp(int64 l,int64 r)
{
return a[l]<a[r];
}
void solve(int64 st,int64 ed)
{
     if(st == ed) return;
     vi ind;
     for(int64 i = st;i<ed;++i) ind.pb(i);
     for(int64 i = st;i<=ed;++i) n[i-1] = i,p[i] = i-1;
     sort(ind.begin(),ind.end(),cmp);
     for(int64 i = 0;i<ind.size();++i)
     {
      int64 u = ind[i];
      ans += min(a[p[u]],a[n[u]]);
      n[p[u]] = n[u];
      p[n[u]] = p[u];
     }
}
int main(int argc, char *argv[])
{
    int64 n;
    setIO("sample");
    n = gi;
    if(n <= 2){ puts("0");return 0;}
    for(int64 i = 1;i<=n;++i) a[i] = gi;
    int64 cmax = -1;
    for(int64 i = 1;i<=n;++i)
     if(a[i] > cmax) hi[i] = 1,cmax = a[i];
    cmax = -1;
    for(int64 i = n;i>=1;--i)
     if(a[i] > cmax) hi[i] = 1,cmax = a[i];
    int64 lval = -1;
    for(int64 i = 1;i<=n;++i)
     if(hi[i])
     {
      if(lval != -1)
       solve(lval+1,i);
      lval = i;
      anslist.pb(a[i]);
     }
    sort(anslist.begin(),anslist.end());
    for(int64 i = 0;i<anslist.size()-2;++i) 
     ans += anslist[i];
    printf(I64D,ans);
    closeIO();
    return EXIT_SUCCESS;
}
