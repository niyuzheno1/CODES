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

#define MN 3010
typedef pair<int,pii> piii;
piii v[MN];
int n ,times[MN],x[MN],fa[MN],xsum;
int gf(int x)
{
    if(x == fa[x]) return x;
    return gf(fa[x]);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int i = 1;n = gi;
    for( i = 1;i<=n-1;++i) v[i].Y.X = gi,v[i].Y.Y = gi,v[i].X = gi;
    sort(v+1,v+n);
    for( i = 1;i<=n;fa[i]=i,++i){
     times[i] = x[i] = gi;xsum+=x[i];++times[i];
    }
    for(i =1;i<=n-1;++i){
     times[gf(v[i].Y.Y)] += times[gf(v[i].Y.X)];
     fa[gf(v[i].Y.X)] = fa[gf(v[i].Y.Y)];
     if(times[gf(v[i].Y.Y)] > xsum)
      break;
    }
    printf("%d",v[i].X);
    closeIO();
    return EXIT_SUCCESS;
}
