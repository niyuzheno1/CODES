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
typedef  double ld;
typedef long long int64;
typedef unsigned long long uint64;
typedef pair<int,int> pii;
typedef pair<int64,int64> pll;
FILE * debug;
void setIO(string file = "sample")
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
