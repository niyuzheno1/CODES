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
#include <bitset>
#define ff fprintf
#define RENEW(x) if(x) delete[] x
#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define gi getint()
#define CLEAR(x,y) memset(x,y,sizeof(x))
#define MP make_pair
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

const int N = 10000010;
bitset<N> pr;
int64 p[N];
int64 phi[N];
int64 f[N],k;
void ip()
{
 pr.set();
 for(int i = 2;i<=N;++i)
  if(pr[i])
  {
   p[++k] = i;
   for(int j = i+i;j<N;j+=i)
    pr[j] = false;
  }
}
void init()
{
  for(int i = 1;i<N;++i) phi[i] = i-1;
  phi[0] = 0;
  for(int i = 2;i<N;i+=2) phi[i] /= 2;
  for(int i = 3;i<N;i+=2)
   if(phi[i] == i-1)
   {
    for(int j = i;j<N;j+=i)
     phi[j] /= i,phi[j]*=i-1;
   }
 f[1] = 0;
 for(int i = 2;i<N;++i)
  f[i] = f[i-1]+phi[i];
}
int64 n ;
void solve()
{
 int64 ans = 0;
 for(int i = 1;i<=k;++i)
  if(p[i] > n)
   break;
  else
   ans += f[n/p[i]]*2;
 printf("%I64d\n",ans);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    ip();init();
    n = gi;
    solve();
    closeIO();
    return EXIT_SUCCESS;
}
