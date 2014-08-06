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
const int INF =  100001000;
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

const int MN = 20010,MM = 50010,MQ = 50010,offset = 10;
struct e {int flag,a,tmp;long long b,c;};
e ed[MM],qu[MQ];
int n,m,q;
int a[MM],f[MN],t[MM],t2[MM];
long long res[MQ];
bool cmp(int  a,int  b){ return ed[a].c < ed[b].c; }
int gf(int x)
{
 if(x == f[x]) return x;
 return f[x] = gf(f[x]);
}
inline void merge(int x,int y)
{
 f[gf(x)] = f[gf(y)];
}
void reduce1(int l,int r,int nn,int al,int & ar)
{
     int to = 0;
     for(int i = 1;i<=nn;++i) f[i] = i;
     for(int i = l;i<=r;++i)
       if(ed[qu[i].a].c != INF)
        ed[qu[i].a].tmp = ed[qu[i].a].c,ed[qu[i].a].c = INF;
     sort(a+al,a+ar+1,cmp);
     for(int i = al;i<=ar;++i)
      if((gf(ed[a[i]].a) != gf(ed[a[i]].b)) || (ed[a[i]].c == INF))
      {
       merge(ed[a[i]].a,ed[a[i]].b);
       ++to;t[to] = a[i];
      }
    int x = al;
    for(int i = 1;i<=to;i++)
     a[x] = t[i],++x;
    for(int i = l;i<=r;++i) ed[qu[i].a].c = ed[qu[i].a].tmp;
    --x;ar = x;
}
void reduce2(int l,int r,int & nn,int al,int ar,long long & ans)
{
    int to = 0,to2 = 1,to3 = 0;
    for(int i = 1;i<=nn;++i) f[i] = i;
    for(int i = l;i<=r;++i) 
     if(ed[qu[i].a].c != -INF)
     ed[qu[i].a].tmp = ed[qu[i].a].c,ed[qu[i].a].c = -INF;
    sort(a+al,a+ar+1,cmp);
    for(int i = al;i<=ar;++i)
     if((gf(ed[a[i]].a) != gf(ed[a[i]].b)))
     {
       merge(ed[a[i]].a,ed[a[i]].b);
       if(ed[a[i]].c != -INF)
        to3++,t2[to3] = a[i];
     }
    for(int i = 1;i<=nn;++i) f[i] = i;
    for(int i = 1;i<=to3;++i)
     merge(ed[t2[i]].a,ed[t2[i]].b),ans+=ed[t2[i]].c;
    for(int i = 1;i<=nn;++i)
     ++to,t[i]=f[gf(i)];
    sort(t+1,t+1+to);
    for(int i = 2;i<=to;++i)
     if(t[i] != t[i-1])
      ++to2,t[to2] = t[i];
    to = to2;
    for(int i = al;i<=ar;i++)
    {
     ed[a[i]].a = lower_bound(t+1,t+1+to,gf(ed[a[i]].a))-t;
     ed[a[i]].b = lower_bound(t+1,t+1+to,gf(ed[a[i]].b))-t;
    }
   for(int i = l;i<=r;++i)
     ed[qu[i].a].c = ed[qu[i].a].tmp;
   nn = to;
}
void sol(int l,int r,int nn,int al,int ar,long long ans)
{
     if(l == r)
     {
      for(int i = 1;i<=nn;++i) f[i] = i;
      ed[qu[l].a].c = qu[l].b;
      sort(a+al,a+ar+1,cmp);
      for(int i = al;i<=ar;++i)
       if(gf(ed[a[i]].a) != gf(ed[a[i]].b))
       {
        merge(ed[a[i]].a,ed[a[i]].b);
        ans += ed[a[i]].c;
       }
      res[l] = ans;
      return;
     } 
     reduce1(l,r,nn,al,ar);
     reduce2(l,r,nn,al,ar,ans);
     int * cpa = new int[ar-al+offset];
     int * cpb = new int[ar-al+offset];
     int * cpc = new int[ar-al+offset];
     for(int i = al;i<=ar;++i)
      cpa[i-al+1] = a[i];
     for(int i = al;i<=ar;++i)
      cpb[i-al+1] = ed[a[i]].a;
     for(int i = al;i<=ar;++i)
      cpc[i-al+1] = ed[a[i]].b;
     int m = (l+r)>>1;
     sol(l,m,nn,al,ar,ans);
     for(int i = al;i<=ar;++i)
      a[i] = cpa[i-al+1];
     for(int i = al;i<=ar;++i)
      ed[a[i]].a = cpb[i-al+1];
     for(int i = al;i<=ar;++i)
      ed[a[i]].b = cpc[i-al+1];
     sol(m+1,r,nn,al,ar,ans);
     /*delete[] cpa;
     delete[] cpb;
     delete[] cpc;*/
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi,q=gi;
    for(int i = 1;i<=m;i++)
     ed[i].a = gi,ed[i].b = gi ,ed[i].c = gi;
    for(int i = 1;i<=m;i++)
     a[i] = i;
    for(int i = 1;i<=q;i++)
     qu[i].a = gi,qu[i].b= gi;
    sort(a+1,a+1+m,cmp);
    sol(1,q,n,1,m,0);
    for(int i = 1;i<=q;i++)
     printf("%lld\n",res[i]);
    closeIO();
    exit(0);
    return EXIT_SUCCESS;
}
