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
#include <iomanip>
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

#define MN 52
#undef ff
#define ff
typedef double ld;
const ld eps = 1e-4;
int dcmp(ld x)
{
    if(fabs(x) < eps)
     return 0;
    if(x > eps)
     return 1;
    return -1;
}
typedef ld mx[MN][MN];
mx a;
int n,f[MN],g[MN];
int gf(int x)
{
    if(x == f[x]) return x;
    return (f[x]=gf(f[x]));
}
void mg(int x,int y)
{
     f[gf(x)] = f[gf(y)];
}
vector<ld> c[MN][MN];
mx b;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;f[i]=i,++i);
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j){
      scanf("%lf",&a[i][j]);
      if(dcmp(a[i][j]-1.0)==0){
       if(i<=j&&gf(i) == gf(j))
       {
        puts("0");
        closeIO();
        return 0;
       }
       else if(i<=j)
        mg(i,j);
      }
     }
    int tot = 0;
    for(int i = 1;i<=n;++i)
     if(f[i] == i)
      g[i] = ++tot;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
      if(dcmp(1-a[i][j])!=0 && ( gf(i) != gf(j)|| i < j))
      c[g[gf(i)]][g[gf(j)]].pb(a[i][j]);
    double allcut = 1.0;
    for(int i = 1;i<=tot;++i)
     for(int j = 1;j<=tot;++j)
     {
      double cut=1.0,notcut=0.0;
      for(int k = 0;k<c[i][j].size();++k)
       cut *= (1.0-c[i][j][k]);
      for(int k = 0;k<c[i][j].size();++k)
       notcut += ((c[i][j][k])/(1.0-c[i][j][k]))*cut;
      ff(debug,"%lf %lf\n",cut,notcut);
      if(i<=j) allcut *= cut;
      if(i != j)
      b[i][j] = notcut/cut;
     }
    
     
    for(int i = 1;i<=tot;++i)
     for(int j = 1;j<=tot;++j)
      if(i != j)
      {
       b[i][i] += b[i][j];
       b[i][j] = -b[i][j]; 
      }
    --tot;
    for(int i = 1;i<=tot;++i){
     int j = i;
     for(;j<=tot;++j)
      if(dcmp(b[i][j])!= 0)
       break;
     if(j > tot) continue;
     for(int k = 1;k<=tot;++k) swap(b[i][k],b[j][k]);
     for(j = i+1;j<=tot;++j)
      if(dcmp(b[j][i])!=0){
       double t = b[j][i]/b[i][i];
       for(int k = 1;k<=tot;++k)
        b[j][k] -= b[i][k]*t; 
      }
    }
   
    double det = 1.0;
    for(int i = 1;i<=tot;++i)
     det *= b[i][i];
    printf("%.20f",det*allcut);
    closeIO();
    return EXIT_SUCCESS;
}
