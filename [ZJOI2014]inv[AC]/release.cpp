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
typedef pair<double,double> pdd;
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

#define MN 200010
#define ML 18
const double eps  = 1e-6;
struct ct{
       double a[2],b[2],c; // a ->sigma b -> sqr ,c ->x*y
}cnt[MN],now,ccnt[MN];
pdd poi[MN];
ct operator - (const ct & a,const ct & b){
 ct ret; ret = a;
 ret.a[0] -= b.a[0];ret.a[1] -= b.a[1];
 ret.b[0] -= b.b[0];ret.b[1] -= b.b[1];
 ret.c -= b.c;return ret;
}
ct operator + (const ct & a,const ct & b){
 ct ret; ret = a;
 ret.a[0] += b.a[0];ret.a[1] += b.a[1];
 ret.b[0] += b.b[0];ret.b[1] += b.b[1];
 ret.c += b.c;return ret;
}
int n,m,q,m0,st[MN],seed = 2333,fa[MN][ML+2],dep[MN],cou[MN],cir[MN],ctot,to[MN];
bool vis[MN],iscir[MN];
struct _edge{
 int n,v,f;
};
_edge lk[MN*2];
double sinn,coss,oo=1e5,ans;
void add(int a,int b){
 ++m0;lk[m0].v = b;lk[m0].n = st[a];st[a] = m0;
}
void dfs(int now){
 vis[now] = 1;
 TRA(i,now)
  if(!vis[lk[i].v] &&(!iscir[lk[i].v])){
     cnt[lk[i].v] = cnt[lk[i].v]+cnt[now];
     fa[lk[i].v][0] = now;dep[lk[i].v] = dep[now]+1;
     dfs(lk[i].v);
  }
}
void search(int now){
 cir[++ctot] = now;
 to[now] = ctot;
 vis[now] = 1;
 iscir[now] = 1;
 TRA(i,now)
  if(!vis[lk[i].v])
   search(lk[i].v);
}
int que[MN];
void bfs()
{
 int r = 0;
 for(int i = 1;i<=n;++i)
  if(cou[i] == 1)  que[++r]=i;
 for(int i = 1;i<=r;++i){
  vis[que[i]] = 1;
  TRA(j,que[i]){
   --cou[lk[j].v];
   if(cou[lk[j].v] == 1)
    que[++r] = lk[j].v;
  }
 }
 for(int i = 1;i<=n;++i)
  if(!vis[i])
  {
   search(i);break;
  }
 CLEAR(vis,0);
 for(int i = 1;i<=ctot;++i){
  dep[cir[i]] = 1;
  fa[cir[i]][0] = cir[i];
  dfs(cir[i]);
  ccnt[i] = ccnt[i-1]+cnt[cir[i]];
 }
}
int lca(int l,int r){
    if(dep[l] < dep[r]) swap(l,r);
    int d = dep[l]-dep[r];
    for(int i = 0;d;d>>=1,++i)
     if(d & 1)
      l = fa[l][i];
    if(l == r)
     return l;
    for(int i = 19;i>=0;--i)
     if(fa[l][i] != fa[r][i])
      l = fa[l][i],r = fa[r][i];
    return fa[l][0];
}
double calc(double k,double tot){
 return (sqr(k)*(now.b[0]-sqr(now.a[0])/tot)
  -2.0*k*(now.c-now.a[0]*now.a[1]/tot)
  + (now.b[1]-sqr(now.a[1])/tot))/(sqr(k)+1.0);
}
void getans(double tot){
  if(tot<=2){ans = 0;return;}
  double A = (now.b[0]-sqr(now.a[0])/tot),
  B = -2.0*(now.c-now.a[0]*now.a[1]/tot),
  C = (now.b[1]-sqr(now.a[1])/tot);
  double tA = 1,tB = -(A+C),tC = A*C-sqr(B)/4.0;
  ans = min(ans,(-tB-sqrt(sqr(tB)-4.0*tA*tC+3.0*eps))/2.0);
}
int main(int argc, char *argv[])
{
    setIO("sample");CLEAR(st,0xff);
    sinn = sin(seed),coss = cos(seed);
    scanf("%d%d",&n,&m);
    for(int i =1;i<=n;++i){
     scanf("%lf%lf",&poi[i].X,&poi[i].Y);
     double nx = poi[i].X*coss-poi[i].Y*sinn,
     ny = poi[i].X*sinn+poi[i].Y*coss;
     poi[i].X = nx,poi[i].Y = ny;
     cnt[i].a[0] = nx,cnt[i].a[1] = ny;
     cnt[i].b[0] = sqr(nx),cnt[i].b[1] = sqr(ny);
     cnt[i].c = nx*ny;
    }
    for(int i = 1,x,y;i<=m;++i){
     scanf("%d%d",&x,&y);
     add(x,y);add(y,x);++cou[x];++cou[y];
    }
    if(m == n-1){
     dep[1] = 1;
     fa[1][0] = 1;
     dfs(1);
    }
    else  bfs();
     for(int j = 1;j<=19;++j)
      for(int i = 1;i<=n;++i)
       fa[i][j] = fa[fa[i][j-1]][j-1];
     scanf("%d",&q);
     for(int i = 1,x,y;i<=q;++i){
      scanf("%d%d",&x,&y);
      ans = 1e8;
      if(fa[x][19] == fa[y][19]){
       int L = lca(x,y);
       now = cnt[x]+cnt[y]-cnt[L]- (fa[L][0] == L ? cnt[0]:cnt[fa[L][0]]);
       getans(dep[x]+dep[y]-2*dep[L]+1);
       double pA = abs(ans+eps);
       printf("%.5f\n",pA);
      }
      else{
       int ta = fa[x][19],tb = fa[y][19];
       if(to[ta] > to[tb]) swap(ta,tb);
       now = cnt[x]+cnt[y]+ccnt[to[tb]]-ccnt[to[ta]]-cnt[tb];
       getans(dep[x]+dep[y]+to[tb]-to[ta]-1);
       now = cnt[x]+cnt[y]+ccnt[ctot]-ccnt[to[tb]]+ccnt[to[ta]]-cnt[ta];
       getans(dep[x]+dep[y]+ctot-to[tb]+to[ta]-1);
       double pA =abs(ans);
       printf("%.5f\n",pA);
      }
     }
    closeIO();
    return EXIT_SUCCESS;
}
