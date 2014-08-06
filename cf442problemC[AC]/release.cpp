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
