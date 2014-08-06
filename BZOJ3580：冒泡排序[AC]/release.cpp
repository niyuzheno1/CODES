#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


#define TRA(x,y) for(int x = st[y];~x;x = lk[x].n) if(!lk[x].f)
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
#define pb push_back
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
#define SIZE(a) a[0]
#define INF  1000000010
using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);debug = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(debug);
 #endif
}
template <class T>
void read(T & x)
{
 char tmp = 0; T flag = 1,ret = 0;while(tmp != '-' && !isdigit(tmp))tmp = getchar();
 if(tmp == '-') flag = -1,tmp=getchar();while(isdigit(tmp)) ret*=10,ret += tmp-'0',tmp = getchar();
 x = flag *ret;
}

int64 getint()
{
     int64 ret;read<int64>(ret);
     return ret;
}

void endline()
{
     ff(debug,"\n");
}

#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LEF(_t),_l,mid
#define RIGHT RIG(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}


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
