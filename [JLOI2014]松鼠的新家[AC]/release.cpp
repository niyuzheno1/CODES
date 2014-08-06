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

#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LCH(_t),_l,mid
#define RIGHT RCH(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}

#define CON rt,1,n
#define MN 300000*2+10
int o1[MN],o2[MN],o3[MN],to;
#define LCH(_t) o1[_t]
#define RCH(_t) o2[_t]
#define S(_t) o3[_t]
void show1d(int * u,int st,int ed){
 for(int i = st;i<=ed;++i)
  ff(debug,"%d ",u[i]);
 ff(debug,"\n");
}
void build(TREE2)
{
 if(!_t) _t = ++to;
 if(_l == _r) return;
 M;build(LEFT);build(RIGHT);
}

inline void pd(int x)
{
 if(o3[x] != 0){
  o3[LCH(x)]+=o3[x];
  o3[RCH(x)]+=o3[x];
  o3[x] = 0;
 } 
}
inline void up(int x){
 //no updata
}
void modify(TREE,int x,int d){
 if(_l == _r) { o3[_t]+=d;return;}
 pd(_t);M;
 if(x <= mid) modify(LEFT,x,d);else modify(RIGHT,x,d);
 return;
}
void modify(TREE,int l,int r,int d){
 if(l <= _l && _r <= r) {o3[_t] += d; return ;}
 pd(_t);M;
 if(l <= mid) modify(LEFT,l,r,d);
 if(r >  mid) modify(RIGHT,l,r,d);
 return;
}
int query(TREE,int x){
 if(_l== _r) {return o3[_t];}
 pd(_t);M;
 if(x <= mid) return query(LEFT,x);
 else return query(RIGHT,x);
}
#undef MN
#define MN 300000+10
#define MM 300000*2+10
struct edge{
 int n,f,v;
};
int st[MN],tot,n,q[MN],Ind,id[MN],f[MN],p[MN],hz[MN],sz[MN],dep[MN];
edge lk[MM];
int tab[MN],tab2[MN],ans[MN],rt;
void go(int s)
{
 int x = s;
 while(x != 0){
  id[x] = ++Ind; 
  p[x] = s;
  x = hz[x];
 }
}
void ae(int x,int y){
 lk[tot].f = 0,lk[tot].v = y,lk[tot].n = st[x],st[x] = tot;
 tot++;
}
void addedge(int x,int y){ ae(x,y);ae(y,x);}
int mkc(int x,int y)
{
 while(p[x] != p[y])
 {
  if(dep[p[x]] < dep[p[y]]) swap(x,y);
  if(p[x] == x){
   modify(CON,id[p[x]],1);
   x = f[x];
  }else{
   modify(CON,id[p[x]]+1,id[x],1);
   x = p[x];
  }
 }
 modify(CON,min(id[x],id[y]),max(id[x],id[y]),1);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;CLEAR(st,0xff);
    for(int i = 1;i<=n;++i) tab[i] = gi;
    for(int i = 1,x,y;i<=n-1;++i) x = gi,y = gi,addedge(x,y);
    //bfs
    int r = 1;q[r] = 1;
    dep[1] = 1;
    for(int i = 1;i<=r;++i)
     TRA(j,q[i])
     {
      int u = lk[j].v;
      lk[j^1].f = 1;
      ++r,q[r] = u;
      f[u] = q[i];
      dep[u] = dep[q[i]]+1;
     }
    //done
    for(int i = r,u;i>=1;--i){
     u = q[i];sz[u] = 1;
     TRA(j,u) sz[u] += sz[lk[j].v];
     if(f[u] && sz[hz[f[u]]] < sz[u])
      hz[f[u]] = u;
    }
    for(int i = 1;i<=r;++i)
     if(!id[q[i]])
      go(q[i]);
    for(int i = 1;i<=r;++i)
     tab2[id[q[i]]] = q[i];
    build(CON);
    for(int i = 1;i<=n-1;++i){
     int u = tab[i],v = tab[i+1];
     mkc(u,v);
     modify(CON,id[u],-1);
    }
    modify(CON,id[tab[1]],1);
    modify(CON,id[tab[n]],-1);
    for(int i = 1;i<=n;++i)
     ans[tab2[i]] = query(CON,i);
    for(int i = 1;i<=n;++i)
     printf("%d\n",ans[i]);
    closeIO();
    return EXIT_SUCCESS;
}
