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
#define show1D(_type,_array) for(int i = 0;i<=sizeof(_array)/sizeof(_type);++i)\
ff(debug,"%d ",_array[i]);\
ff(debug,"\n");\
\


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
const int INF =  1000000010;
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

typedef double ld;
const ld eps = 1e-15; 
ld a[21][21];
inline int dcmp(double p){
 if(fabs(p) < eps) return 0;return p>eps ? 1 : -1;
}
inline void gauss(int n){
 double tmp = 1.0,an = 1.0,p;
 for(int i = 1,pos;i<=n;++i){
  for(pos = i;(!dcmp(a[pos][i]))&&pos<=n;++pos);
  if(pos > n) continue;
  for(int j = i;j<=n;++j) swap(a[pos][j],a[i][j]);
  for(int j = i+1;j<=n;++j)
   if(dcmp(a[j][i])){
    if(dcmp(a[i][i])== 0 || dcmp(a[j][i])==0){ printf("0\n");return;}
    tmp *= (p = a[i][i]/a[j][i]);
    for(int k = i;k<=n;++k) a[j][k] = a[i][k]-a[j][k]*p;
   }
 }for(int i = 1;i<=n;++i) an = an*a[i][i];
 if(n & 1) an *= -1;
 printf("%.0lf\n",fabs(an/tmp));
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n,m,x,y,tc;tc = gi;
    while(tc--){
    n = gi;m=gi;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j)
      a[i][j] = 0;
    for(int i = 1;i<=m;++i){
     scanf("%d%d",&x,&y);
     a[x][y] = a[y][x] = -1;
     a[x][x] +=1 ; a[y][y] += 1;
    }
    gauss(n-1);
    }
    
    closeIO();
    return EXIT_SUCCESS;
}
