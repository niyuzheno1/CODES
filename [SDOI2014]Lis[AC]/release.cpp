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

#undef TRA //undefine TRA in mode.h
#define TRA(x,y) for(int x = st[y];x;x=lk[x].n)
#define FIND(x,y) for(int & x = cur[y];x;x=lk[x].n)
#define PRE(x,y) for(int x = pre[y];x;x=pre[lk[x^1].v])
#define GAP(x) if((--num[d[x]]) == 0) break; 
#define BAL(x) lk[x].c-lk[x].f
#define INC(x) ++num[d[x]]
struct _nedge{int n,f,v,c;};
struct _cedge{int n,f,v,c,w;};

#define MN 710*2
#define MM 500010
typedef _nedge edge;
int n,st[MN],ans,pre[MN],num[MN],d[MN],q[MN],cur[MN],node,e=1,f[MN];
edge lk[MM];
void ad(int x,int y,int z){++e,lk[e].v = y,lk[e].n = st[x],st[x] = e,lk[e].c = z,lk[e].f=0;}
void add(int x,int y,int z){ad(x,y,z),ad(y,x,0);}
void bfs(int t)
{
 CLEAR(d,0x7f);CLEAR(num,0);
 int r=0;q[++r] = t,d[t] = 0,INC(t);
 for(int i = 1;i<=r;++i){
  int u = q[i];
  TRA(x,u)
   if(d[lk[x].v] >= INF && BAL(x^1)>0){
     d[lk[x].v] = d[u]+1;
     INC(lk[x].v);
     q[++r] = lk[x].v;
   }
 }
}
int aug(int t)
{
 int ret = t,mf =  INF;
 PRE(u,t) 
  if(BAL(u) <= mf)
   ret = lk[u^1].v,mf = BAL(u);
 ans += mf;
 PRE(u,t)
   lk[u].f += mf,lk[u^1].f -= mf;
 return ret;
}
void isap(int s,int t)
{
     ans = 0;
     CLEAR(pre,0);
     for(int i = 1;i<=node;++i) cur[i]=st[i];
     bfs(t);
     int u = s;
     while(d[s]<node)
     {
      if(u == t) u = aug(t);
      int adv = 0;
      FIND(x,u)
       if(BAL(x)>0&&d[lk[x].v]+1==d[u]){adv = 1,u = lk[x].v,pre[u] = x;break;}
       if(!adv)
       {
       GAP(u);int md = node;
       TRA(x,u) if(BAL(x)>0) md = min(md,d[lk[x].v]);
       cur[u] =st[u],d[u]=md+1,INC(u);
       if(u != s) u = lk[pre[u]^1].v;
       }
     }
}
struct note
{
 int a,b,c,d;
 bool operator < (note u) const
 {
      return c < u.c;
 }
};
note a[MN];
int ans2[MN];
#define LEF(x) x+1
#define RIG(x) x+n+1
int main(int argc, char *argv[])
{
    setIO("sample");
    int T;
    scanf("%d",&T);
    while(T--){
    CLEAR(st,0);
    e = 1;
    scanf("%d",&n);
    int s = 1,t = RIG(n)+1;
    node = t;
    for(int i = 1;i<=n;a[i].d = i,++i) scanf("%d",&a[i].a);
    for(int i = 1;i<=n;++i) scanf("%d",&a[i].b);
    for(int i = 1;i<=n;++i) scanf("%d",&a[i].c);
    int maxf = 0;
    for(int i = 1;i<=n;++i)
    {
     f[i] = 1;
     for(int j = 1;j<i;++j)
      if(a[i].a > a[j].a && f[i] < f[j]+1)
       f[i]=f[j]+1;
     maxf = max(maxf,f[i]);
    }
    for(int i = 1;i<=n;++i)
    {
     add(LEF(i),RIG(i),a[i].b);
     if(f[i] == 1) add(s,LEF(i),INF);
     if(f[i] == maxf) add(RIG(i),t,INF);
     for(int j  =1;j<i;++j)
      if(a[i].a > a[j].a && f[i] == f[j]+1)
       add(RIG(j),LEF(i),INF);
    }
    isap(s,t);
    sort(a+1,a+1+n);
    printf("%d",ans);
     SIZE(ans2) = 0;
    for(int x = 1;x<=n;++x)
    {
     int i = a[x].d;
     int ne = 0;
     TRA(x,LEF(i))
      if(lk[x].v == RIG(i)) 
      {
       ne = x;
       break;
      }
     if(BAL(ne) == 0)
     {
      bfs(RIG(i));
      if(d[LEF(i)] >= INF)
      {
       ans = 0;
       isap(LEF(i),s);
       isap(t,RIG(i));
       ++SIZE(ans2);
       ans2[SIZE(ans2)] = i;
       lk[ne^1].c = 0;
      }
     }
    }
    sort(ans2+1,ans2+1+SIZE(ans2));
    printf(" %d\n",SIZE(ans2));
    for(int i = 1;i<=SIZE(ans2);printf(i==SIZE(ans2)?"\n":" "),++i)
     printf("%d",ans2[i]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
