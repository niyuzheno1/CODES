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

#undef INF
#define INF 0x7f7f7f7f
const int MN = 510;
int f[MN][MN],rs[MN],b[MN],a[MN],n;
inline void dn(int & x,int y)
{
       x = min(x,y);
}
int solve(int x,int y)
{
 if(x > y) return INF;
 if(x == y) return f[x][x];
 if(f[x][y] != INF) return f[x][y];
 int res;
 if(a[x] == a[y]){
 res = solve(x+1,y-1); 
 dn(f[x][y],max(3-b[x]-b[y],0)+res);
 }
 for(int i = x;i<y;++i) dn(f[x][y],solve(x,i)+solve(i+1,y));
 return f[x][y];
}
int main(int argc, char *argv[])
{
    CLEAR(f,0x7f);
    setIO("sample");
    n = gi;
    int cnt = 0;
    a[0] = -INF;
    for(int i = 1,x;i<=n;++i){
     x = gi;
     if(a[cnt] != x){
      ++cnt;
      a[cnt] = x;
      b[cnt] = 1;
     }
     else ++b[cnt];
     f[cnt][cnt] = max(1,3-b[cnt]);
    }
    solve(1,cnt);
    printf("%d",f[1][cnt]);
    closeIO();
    return EXIT_SUCCESS;
}
