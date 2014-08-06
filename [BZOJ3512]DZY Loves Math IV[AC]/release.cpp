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




#define pb push_back
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

const int Mod = (int)1e9+7,N = 1000010,MN=1000000;
int n,m;
int phi[N],K[N],mm[N];
int q[N],top;
vector<int> yueshu[N];
map<int,int> S[N/10];
void update(int & a,int b)
{
 a+=b;
 if(a>=Mod)a-= Mod;
}
int64 calc(int n,int m)
{
   int t =  K[n];
   if(m == 0) return 0;
   if(t != n && n != 1) return (n/t)*calc(t,m)%Mod;
   if(S[n].find(m) != S[n].end()) return S[n][m];
   int & ans = S[n][m];
   if(n == 1)
   {
    int now = m,next,t;
    for(;now>=2;now=next){
     t = m/now;
     next = m/(t+1);
     update(ans,(now-next)*calc(1,t)%Mod);
    }
    return (ans = (((int64)m*(m+1)/2-ans+Mod)%Mod));
   }
   for(int i = 0;i<yueshu[n].size();++i){
    int d = yueshu[n][i];
    update(ans,(phi[n/d]*calc(d,m/d))%Mod);
   }
   return ans;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi,m = gi;
    mm[1] = phi[1] = K[1] = 1;
    for(int i = 2;i<=MN;++i){
     if(!mm[i])
     {
      mm[i] = i;phi[i] = i-1;
      K[i] = i;q[++top] = i;
     }
     for(int j = 1;j<=top && q[j]*i<=MN;++j)
     {
      int u = q[j]*i;
      mm[u] = q[j];
      phi[u] = phi[i];
      K[u] = K[i];
      if(i%q[j] == 0) {phi[u]*=q[j];break;}
      phi[u]*=(q[j]-1);
      K[u]*=q[j];
     }
    }
  
    for(int i = 1;i<=n;++i)
     for(int j = i;j<=n;j+=i)
      yueshu[j].pb(i);
    int now = 0;
    for(int i = 1;i<=MN;++i)
    {
     update(now,phi[i]);
     S[1][i] = now;
    }
    int ans = 0;
    for(int i = 1;i<=n;++i)
     update(ans,calc(i,m));
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
