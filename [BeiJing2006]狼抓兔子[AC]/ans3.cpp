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
int N,M;
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

#define MN  1000*1000
int st[2*MN+10],dis[2*MN+10],q[2*MN+10],tot;
struct edge
{
 int n,f,v,w;
};
edge lk[5*MN];
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
int go1()
{
	int kcase = 1;setIO("sample");
	int n,m;
	n = N,m= M;
    {
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
    printf("%d\n",kcase++,dis[T]);
	}
	closeIO();
    return EXIT_SUCCESS;
}

#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define tr(e,x) for(eit e=x.begin();e!=x.end();e++)

const int maxn=1000,maxv=maxn*maxn*2,inf=~0U>>2;
int n,m,vs,vt,v;
int Node[maxn][maxn][2];
int Dist[maxv];
struct Edge
{
int t,c;
Edge(int _t,int _c):t(_t),c(_c){}
};
struct State
{
int p,c;
State(int _p,int _c):p(_p),c(_c){}
bool operator<(const State&o)const
{
return c>o.c;
}
};
vector<Edge> E[maxv];
priority_queue<State> Q;
typedef vector<Edge>::iterator eit;
int Dijstra()
{
rep(i,v)Dist[i]=inf;Q.push(State(vs,0));
while(Q.size())
{
State t=Q.top();Q.pop();if(t.c>Dist[t.p])continue;
if(t.p==vt)return t.c;
tr(e,E[t.p])
{
int ncost=t.c+e->c;
if(ncost<Dist[e->t])
{
Dist[e->t]=ncost;
Q.push(State(e->t,ncost));
}
}
}
}
void AddEdge(int s,int t,int c)
{
E[s].pb(Edge(t,c));
E[t].pb(Edge(s,c));
}
int go2()
{
setIO("sample");
n = N,m= M;v=0;
rep(i,n-1)rep(j,m-1)rep(k,2)Node[i][j][k]=v++;
vs=v++;vt=v++;int c;
rep(j,m-1)scanf("%d",&c),AddEdge(vs,Node[0][j][0],c);
rep(i,n-2)rep(j,m-1)
{
scanf("%d",&c);AddEdge(Node[i][j][1],Node[i+1][j][0],c);
}
rep(j,m-1)scanf("%d",&c),AddEdge(Node[n-2][j][1],vt,c);
rep(i,n-1)
{
scanf("%d",&c);AddEdge(Node[i][0][1],vt,c);
rep(j,m-2)
{
scanf("%d",&c);AddEdge(Node[i][j+1][1],Node[i][j][0],c);
}
scanf("%d",&c);AddEdge(vs,Node[i][m-2][0],c);
}
rep(i,n-1)
rep(j,m-1)
{
scanf("%d",&c);
AddEdge(Node[i][j][0],Node[i][j][1],c);
}
printf("%d\n",Dijstra());
closeIO();
}

int main(int argc, char *argv[])
{
    N=gi,M= gi;
    if(N<=500&&M<=500)
     go1();
    else
     go2();
    return EXIT_SUCCESS;
}
