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


#define MN 100010
#define MM 500010

typedef long long ll;
ll ran,p1,p2,p3,P = ~0U>>1;

struct edge{
 int x,y,next;
} e[MM << 1] ;

int len,pt[MM],aa[MM],last[MN],fa[MN],na[MN],q[MN],dep[MN],c1[16],lastans;
int flag,n,m,r,l;

inline void add(int x,int y){
 e[++len].y = y;e[len].x = x;e[len].next = last[x];last[x] = len;
}

int a[16],g[32][16];
inline int Gauss(int n){
 int cnt;
 for(int c = cnt = 0;c<n;++c){
  int r = cnt;
  for(;r<31;++r) if(g[r][c]) break;
  if(r < 31) {
  if(r != cnt) for(int i = 0;i<n;++i) swap(g[r][i],g[cnt][i]);
  for(int i = cnt+1;i<31;++i) if(g[i][c]) for(int j = 0;j<n;++j) g[i][j] ^= g[cnt][j];
  ++cnt;
  }
 }
 return n-cnt;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;for(int i = 1;i<=n;++i) dep[i] = P>>1;
    for(int i = 1,x,y;i<=m;++i) x = gi,y =gi,add(x,y),add(y,x);
    q[r=1] = 1;dep[1] = 0;
    while(l<r) {int x;
               for(int i = last[x=q[++l]];i;i=e[i].next)
     if(dep[e[i].y] > dep[x] + 1)
      fa[e[i].y] = x , na[e[i].y] = (i+1)>>1,dep[e[i].y] = dep[x]+1,q[++r] = e[i].y;
     else if((i & 1) == 0 && fa[x] != e[i].y){
      ran *= 13;ran += 237;ran%=P;
      pt[(i+1)>>1] = ran;
      aa[e[i].x] ^= pt[(i+1)>>1];
      aa[e[i].y] ^= pt[(i+1)>>1];
     }
  }
    for(int i = r,x;i;--i)
     for(int j = last[x=q[i]];j;j=e[j].next)
      if(fa[e[j].y] == x) aa[x] ^= aa[e[j].y];
    for(int i = 1;i<=n;++i) pt[na[i]] = aa[i];
    int k = gi;
    while(k--){
     int c = gi;
     for(int i = 0;i<c;++i){
      int u = gi;a[i] = pt[u^lastans];
     }
     for(int i = 0;i<31;++i) 
      for(int j = 0;j<c;++j)
       g[i][j] = (a[j]>>i)&1;
     if(flag = (Gauss(c) == 0)) ++lastans;
     puts(flag ? "Connected" : "Disconnected");
    }
    closeIO();
    return EXIT_SUCCESS;
}
