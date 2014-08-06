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

#define MN 100010
#define MM MN*2
int n,k,p,e = 1;
int a[MN],b[MN],Ind;
int st[MN],con[MN],v[MM],ne[MM];
bool cmp(int x,int y)
{
     return a[x] < a[y];
}
void ad(int x,int y)
{
     ++e;v[e] = y;ne[e] = st[x];st[x] = e;
}
void add(int x,int y)
{
     ad(x,y);ad(y,x);
}
void dfs(int x)
{
     if(con[x])return;
     con[x] = Ind;
     for(int i = st[x];i;i=ne[i])
     if(!con[v[i]]) dfs(v[i]);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, k = gi,p = gi;
    for(int i = 1;i<=n;++i) a[i] = gi,b[i] = i;
    sort(b+1,b+1+n,cmp);
    for(int i = 1;i<n;++i)
     if(abs(a[b[i]]-a[b[i+1]]) <= k)
      add(b[i],b[i+1]);
    for(int i = 1;i<=n;++i)
     if(!con[i])
      ++Ind,dfs(1);
    for(int i = 1;i<=p;++i)
    {
            int u,v;
            scanf("%d%d",&u,&v);
            if(con[u] != con[v])
             puts("No");
            else
             puts("Yes");
    }
    closeIO();
    return EXIT_SUCCESS;
}
