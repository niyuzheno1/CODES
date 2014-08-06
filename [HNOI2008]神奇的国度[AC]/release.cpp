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

#define MN 10010
#define MM 2000010
int n,m,ans = 0,st[MN],tot;
int hash[MN],color[MN],label[MN],v[MN],a[MN];
struct edge{int v,f,n;};
edge lk[MM];
void add(int x,int y)
{
 ++tot;lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    CLEAR(st,0xff);
    for(int i = 1,x,y;i<=m;++i){
     x = gi;y =gi;add(x,y);add(y,x);
    } 
    label[0] = -1;
    for(int i = n;i>=1;--i){
     int k = 0;
     for(int j = 1;j<=n;++j)
      if(label[j]>label[k] && !v[j]) k = j;
     a[i] = k;v[k] = 1;
     TRA(j,k) ++label[lk[j].v];
    }
    for(int i = n;i>=1;--i)
     {
      TRA(j,a[i]) hash[color[lk[j].v]] = i;
      int j = 0;
      while(hash[++j] == i); color[a[i]] = j;
     }
     for(int i = 1;i<=n;++i) if(color[i]>ans) ans = color[i];
     printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
