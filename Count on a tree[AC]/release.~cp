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

void endline()
{
     ff(debug,"\n");
}

#define L C[0]
#define R C[1]
#define F C[2]
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LEF(_t),_l,mid
#define RIGHT RIG(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}

#define TRA(x,y) for(int x = st[y];~x;x=lk[x].n) if(~lk[x].f)
const int MN  = 100010*2,ML = 17,MV = 100010*20;
int o1[MV*2],o2[MV*2],cnt[MV*2],tot,low;
#define LEF(_t) o1[_t]
#define RIG(_t) o2[_t]
#define S(_t) cnt[_t]
int n,m,a[MN],t[MN],b[MN],len,st[MN],ltot,d[MN],dep[MN];
int f[MN][ML+5];
struct ed{int v,n,f;};
ed lk[MN*2];
void addedge(int x,int y)
{
 lk[ltot].v = y;lk[ltot].n = st[x];st[x] = ltot;++ltot;
}
int mkc(TREE,int x,int c)
{
     int p = 0 ;
     if(_t == 0) p = _t = ++tot;
     else p = ++tot,LEF(p) = LEF(_t),RIG(p) = RIG(_t),S(p) = S(_t);
     if(_l == _r){S(p)+=c; return p;}
     M;_t = p;if(mid >= x) LEF(p) = mkc(LEFT,x,c); else RIG(p) = mkc(RIGHT,x,c);
     S(p)+=c;return p;
}
void dfs(int x,int y)
{
     int tmp = 1,k=0;
     while(len-tmp> 0)
     {
      f[x][k] = d[len-tmp];
      ++k,tmp *= 2;
     }
     t[x] = mkc(t[y],1,low,a[x],1);
     TRA(i,x)
     {
     ++len;lk[i^1].f = -1;int v = lk[i].v;dep[v] = dep[x]+1;d[len] = v;dfs(v,x);--len;
     }
}
int lca(int x,int y)
{
    if(dep[x]>dep[y]) swap(x,y);
    for(int i = ML;i>=0;--i)
     if(dep[x] <= dep[f[y][i]]) 
      y = f[y][i];
    if(y == x) return x;
    for(int i = ML;i>=0;--i)
     if(f[x][i] != f[y][i])
      x = f[x][i],y = f[y][i];
    if(x != y)
      x = f[x][0],y = f[y][0];
    return x;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi; m = gi;
    CLEAR(st,0xff);
    for(int i = 1;i<=n;++i) a[i] = gi,b[i]=a[i];
    sort(b+1,b+1+n);
    low = unique(b+1,b+1+n)-b;
    for(int i = 1;i<=n;++i) a[i] = lower_bound(b+1,b+low,a[i])-b;
    for(int i = 1;i<n;++i)
    {
     int x = gi,y = gi;addedge(x,y);addedge(y,x);
    }
    ++len;d[len] = 1;
    dep[1] = 1;
    dfs(1,0);
    for(int i = 1,x,y,k;i<=m;++i)
    {
     x= gi;y=gi;k=gi;
     int z = lca(x,y);
     int _l = 1,_r = low;
     int a = t[x],_b=t[y],c=t[z],d=t[f[z][0]];
     while(_l<_r)
     {
      M;
      int d1 = S(LEF(a))+S(LEF(_b))-S(LEF(c))-S(LEF(d));
      if(d1 >= k)
       a = LEF(a),_b=LEF(_b),c = LEF(c),d =LEF(d),_r = mid;
      else
       k -= d1,a = RIG(a),_b=RIG(_b),c = RIG(c),d=RIG(d),_l=mid+1;
     }
     if(((_l+_r)>>1)==low) 
     printf("%d\n",b[low-1]);
     else
     printf("%d\n",b[(_l+_r)>>1]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
