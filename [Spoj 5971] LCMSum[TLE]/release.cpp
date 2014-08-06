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

#define MN 1000005
int p[MN],f[MN];
int64 phi[MN],ans;
int o1[MN],o2[MN];
void init(int n)
{
 f[1] = 1;
 for(int i = 2;i<=n;++i)
 {
  if(!f[i]) ++SIZE(p),p[SIZE(p)] = i,phi[i] = i-1; 
  for(int j = 1;i*p[j]<MN&& j<=SIZE(p);++j)
  {
   f[i*p[j]] = 1;
   
   if(i % p[j] == 0)
   {
    phi[i*p[j]] =phi[i]*p[j]; 
    break;
   }
   else
    phi[i*p[j]] = phi[i]*(p[j]-1); 
  }
 }
 phi[1] = 1;
 for(int i = 3;i<=n;++i)
  phi[i] = (i*phi[i])>>1;
 //show1D(int,phi);
}
int N;
void dfs(int x,int y)
{
     if(x > SIZE(o1))
     {
      if(y != 0) ans += N*phi[N/y];
      return ;
     }
     for(int i = 0;i<=o2[x];++i)
     {
             dfs(x+1,y);
             y *= o1[x];
     }
}
void solve(int x)
{
 SIZE(o1) =0 ;
 for(int i = 2;i*i<=x;++i)
 {
  if(x % i == 0){++SIZE(o1);o1[SIZE(o1)] = i;}
  while(x%i==0){++o2[SIZE(o1)];x/=i;}
 }
 if(x && x!=1){++SIZE(o1);o1[SIZE(o1)]=x;++o2[SIZE(o1)];}
 ans = 0;
 dfs(1,1);
 printf(I64D,ans);puts("");
}
int main(int argc, char *argv[])
{
    setIO("sample");
    init(MN-5);
    int T = gi;
    while(T--)
    {
     int n = gi;N = n;
     solve(n);
    }
    closeIO();
    return EXIT_SUCCESS;
}
