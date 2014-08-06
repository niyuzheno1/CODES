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

const ld PI = acos(-1.0);
struct cx{
       ld a,b;
       cx(ld _a=0.0,ld _b = 0.0):a(_a),b(_b){}
       friend cx operator + (const cx & x, const cx & y){
        return cx(x.a+y.a,x.b+y.b);
       }
       friend cx operator - (const cx & x, const cx & y){
        return cx(x.a-y.a,x.b-y.b);
       }
       friend cx operator * (const cx & x, const cx & y){
        return cx(x.a*y.a-x.b*y.b,x.a*y.b+x.b*y.a);
       }
};
void fft(cx p[],int n,int oper){
  for(int i = 1,j=0;i<n-1;++i){
    for(int s = n;j^=s>>=1,~j & s;);
    if(i < j) swap(p[i],p[j]);
  }
  cx up0;
  for(int d = 0;(1<<d)<n;++d){
   int m = 1<<d,m2 = m*2;
   double p0 = PI/m*oper;
   up0 = cx(cos(p0),sin(p0));
    for(int i = 0 ;i<n;i+=m2){
     cx u = 1;
     for(int j = 0;j<m;++j){
      cx & p1 = p[i+j+m],&p2 = p[i+j];
      cx t = u * p1;p1 = p2 - t;p2 = p2 + t;
      u = u * up0;
     }
    }
  }
}
template <class T>
bool isprime(T x)
{
     if(x == 1) return false;
     for(T i = 2;i*i<=x;i++) if(x % i == 0) return false;
     return true;
}

template <class T>
T gcd(T a,T b)
{
       if(b == 0) return a;
       return gcd(b,a%b);
}

#define MN 30010
#define MM MN*2
#define MK (1 << 16) + 10
int tttt[6];
int n,st[MN],f[MN],g[MN],fa[MN],dep[MN],blk[MN],sz[MN],mx[MN];
cx A[MK],B[MK],C[MK];
struct _edge {
 int v,n,f;
};
_edge lk[MM];
#define tot tttt[0]
void add(int x,int y){
 lk[tot].v = y,lk[tot].n = st[x],st[x] = tot,++tot;
}
#undef tot
double ans;
int q[MN],r;
int findg(int x)
{
    r = 1;q[0] = x;fa[x] = -1;
    for(int i = 0;i<r;++i){
     int x = q[i];
     sz[x] = 1,mx[x] = -1;
     TRA(u,x){
      int y = lk[u].v;
      if(blk[y] || fa[x] == y) continue;
      q[r++] = y,fa[y] = x;
     }
    }
    for(int i = r-1;i>=0;--i){
     int x = q[i];
     if(fa[x] != -1){
      sz[fa[x]] += sz[x];
      mx[fa[x]] = max(mx[fa[x]],sz[x]);
     }
     mx[x] = max(mx[x],r-sz[x]);
    }
    int G = x;
    for(int i = 0;i<r;++i){
     int x = q[i];
     if(mx[x] < mx[G]) G =x;
    }
    stack<int> stk;
    while(!stk.empty()) stk.pop();
    dep[G] = 0,fa[G] = -1,r = 0;
    for(stk.push(G);!stk.empty();){
     int x = stk.top();stk.pop();q[r++] = x;
     TRA(u,x){
      int y= lk[u].v;
      if(blk[y] || fa[x] == y) continue;
      fa[y] = x,stk.push(y),dep[y] = dep[x] +1;
     }
    }
    return G;
}
void solve(int x){
  int G = findg(x);
  if(r == 1) return;
  for(int i = 0;i<r;++i) f[i] = 0;f[0] = 1;
  int l = 1;
  for(int i = 1;i<=r-1;++i){
    int x = q[i];
    if(fa[x] != G) continue;
    for(int j = i+1;j<=r-1;++j){
     int nowx = q[j];
     if(fa[nowx] == G) break;
     ++g[dep[nowx]],l = max(l,dep[nowx]);
    }
    int length = l<<1;
    ++g[1];
    int m;
    for(m = 1;m<(length<<1);m<<=1);
    for(int j = 0;j<m;++j) A[j] = B[j] = cx(0,0);
    for(int j = 0;j<length;++j) B[j].a = g[j],A[j].a = f[j];
    fft(A,m,1),fft(B,m,1);
    for(int j = 0;j<m;++j) C[j] = A[j]*B[j];
    fft(C,m,-1);
    for(int j = 1;j<=m-1;++j) 
     ans += (1.0/(j+1)) * ((int)(C[j].a/m+0.5));
    for(int j = 0;j<length;++j) f[j] += g[j];
    for(int j = i+1;j<=r-1;++j){
     int nowx = q[j];
     if(fa[nowx] == G) break;
     g[dep[nowx]] = 0;
    }
    g[1] = 0;
  }
  blk[G] = 1;
  TRA(u,G){
   int y = lk[u].v;
   if(blk[y]) continue;
   solve(y);
  }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d",&n);CLEAR(st,0xff);
    for(int i = 1;i<n;++i){
     int u,v;
     scanf("%d%d",&u,&v);
     add(u,v);add(v,u);
    }
    solve(0);
    ans = ans*2+n;
    printf("%.4f\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
