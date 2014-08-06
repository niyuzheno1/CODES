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

int n , m ;
long long c[1001*1001+1][4],ans,tmp;
int gcd(int a,int b){
 return b==0?a:gcd(b,a%b);
}
void calc(){
 c[0][0] = 1;
 for(int i = 1;i<=n*m;++i) c[i][0] = 1;
 for(int i = 1;i<=n*m;++i){
  for(int j = 1;j<=3;++j) c[i][j] = c[i-1][j]+c[i-1][j-1];
 }
}
void solve(){
 ans = c[n*m][3];
 ans -= n*c[m][3];
 ans -= m*c[n][3];
 for(int i = 1;i<n;++i)
  for(int j = 1;j<m;++j){
   int tmp = gcd(i,j)+1;
   if(tmp > 2) ans -= (tmp-2)*2*(n-i)*(m-j);
  }
 printf(I64D,ans);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m= gi;++n,++m;
    calc();solve();
    closeIO();
    return EXIT_SUCCESS;
}
