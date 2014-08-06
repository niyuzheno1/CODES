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

#define MN  1010*1010
int st[3*MN],dis[3*MN],q[3*MN],tot;
struct edge
{
 int n,f,v,w;
};
edge lk[6*MN];
inline void addedge(int x,int y,int z)
{
 lk[tot].w = z,lk[tot].v = y,lk[tot].n = st[x],st[x] = tot;lk[tot].f=  0;
 ++tot;
}
inline void ae(int x,int y,int z)
{
 addedge(x,y,z);
 addedge(y,x,z);
}
void spfa()
{
 int r = 1;q[r] = 0;
 for(int i = 1;i<=r;++i)
 {
  int u = q[i];
  TRA(x,u)
  {
   int v = lk[x].v;
   if(dis[v] > dis[u]+lk[x].w)
   {
    dis[v] = dis[u]+lk[x].w;
    lk[x^1].f = 1;
    lk[x].f = 1;
    ++r;q[r] = v;
   }
  }
 }
}
int main(int argc, char *argv[])
{
	int kcase = 1;setIO("sample");
	int n,m;
    while(~scanf("%d%d",&n,&m) && !(n==0&&m==0)){
	CLEAR(st,0xff);tot = 0;
    CLEAR(dis,0x7f);
    int S = 0,T = 2*(n-1)*(m-1)+1,last,now;
    dis[S] = 0;
    for(int i = 1,w;i<=m-1;++i)
    {
     w = gi;
     ae(T,i*2,w);
    }
    last = 2*(m-1),now = 2*(m-1)+2;
    for(int i = 2;i<=n-1;++i)
     for(int j = 1,w;j<=m-1;++j)
     {
      w = gi;
      int v = now,u = v-last-1;
      ae(u,v,w);
      now+=2;
     }
    for(int j = 1,w;j<=m-1;++j)
     {
      w = gi;
      int v = now,u = v-last-1;
      ae(u,S,w);
      now+=2;
     }
    now = 1;
    for(int i = 1,w;i<=n-1;++i)
    {
     w = gi;
     ae(now,S,w);now+=2;
     for(int j = 2;j<=m-1;++j)
     {
      w = gi;
      ae(now,now-1,w);
      now+=2;
     }
     w = gi;
     ae(T,now-1,w);
    }
    now = 1;
    for(int i=1,w;i<=n-1;++i)
     for(int j = 1;j<=m-1;++j)
     {
     w = gi;
     ae(now,now+1,w);
     now += 2;
     }
    spfa();
    printf("Case %d: Minimum = %d\n",kcase++,dis[T]);
	}
	closeIO();
    return EXIT_SUCCESS;
}

