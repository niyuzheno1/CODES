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


#define MN 10010
#define MK 6000
#define MKK 610
int a[MN];
int n,k;
int f[MN][MKK];
int sum[MK][MKK];
void modify(int x,int y,int z)
{
     ++x,++y;
     for(int i = x;i<MK;i+=lb(i))
      for(int j = y;j<MKK;j+=lb(j))
       sum[i][j] = max(sum[i][j],z);
}

int Sum(int x,int y)
{
    ++x,++y;
    int ret = 0;
     for(int i = x;i;i-=lb(i))
      for(int j = y;j;j-=lb(j))
       ret = max(sum[i][j],ret);
    return ret;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi,k = gi;
    for(int i = 1;i<=n;a[i]=gi,++i);
    for(int i = 1;i<=n;++i)
    {
     for(int j = 0;j<=k;++j)
      f[i][j] = Sum(a[i]+j,j)+1;
     for(int j = 0;j<=k;++j)
      modify(a[i]+j,j,f[i][j]);
    }
    int ans = 0;
    for(int i = 1;i<=n;++i)
     for(int j = 0;j<=k;++j)
      ans = max(ans,f[i][j]);
    printf("%d",ans);
    closeIO();
    return EXIT_SUCCESS;
}
