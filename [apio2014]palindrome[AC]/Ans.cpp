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

inline int get(int * h,int * p,int i,int len){
 int res = h[i+len-1];
 if(i > 0) res -= h[i-1]*p[len];
 return res;
}
inline int lcp(char * s,int * hl,int * p,const pii & a,const pii & b){
 int l = 0,r = min(a.Y,b.Y)+1;//[,)
 if(get(hl,p,a.X,r-1) == get(hl,p,b.X,r-1)) return r-1;
 if(s[a.X] != s[a.X]) return 0;
 while(r-l > 1){
  int mid = ((l+r)>>1);
  if(get(hl,p,a.X,mid) == get(hl,p,b.X,mid))
   l = mid;
  else
   r = mid;
 }
 return l;
}
struct cmpSA{
        int * hl,*p;
        char * s;
        bool operator() (const pii & a,const pii & b)
        {
         int mlen = min(a.Y,b.Y);
         int l = lcp(s,hl,p,a,b);
         if(l == mlen) return a.Y < b.Y;
         return s[a.X+l] < s[b.X + l];
        }
        int slcp(const pii & a,const pii & b){return lcp(s,hl,p,a,b);}
};

#define MN 300003
#define MC 600006
typedef pii pi;
typedef long long ll;
const int ba = 233;
char s[MN],t[MC];
int n,tn,d[MC];
pi d1[MN],d2[MN];
int b[MN],bn,L[MN],R[MN],st[MN],stn;
int h[MN],p[MN];
void pre() {
      p[0] = 1;
      for(int i  =1;i<=n;++i)
       p[i] = p[i-1]*ba;
      int hh = 0;
      for(int i = 0;i<n;++i){
       hh = hh*ba+s[i]-'a'+1;
       h[i] = hh;
      }
}
inline void manachers(){
       tn = 0;
       t[tn++] = '*';
       for(int i = 0 ;i<n;++i)
        t[tn++] = s[i],t[tn++] = '*';
       int j = 0;
       for(int i = 0;i<tn;++i){
         d[i] = 0;
         if(j + d[j] > i)
          d[i] = min(j+d[j]-i,d[2*j-i]);
         while(i + d[i] < tn && i - d[i] >= 0 && t[i+d[i]] == t[i-d[i]])
          ++d[i];
         if(i + d[i] > j + d[j])
          j = i;
       }
       for(int i = 0;i<n;++i){
        int j = 2*i+1;
        d1[i].X = i,d1[i].Y = d[j]/2;
        d2[i].X = i,d2[i].Y = d[j-1]/2;
       }
}
inline ll calc(int odd,pi a[]){
   ll res = 0;
   cmpSA comp;
   comp.hl = h;comp.p = p;comp.s = s;
   sort(a,a+n,comp);
   bn = 0;
   for(int i = 0;i<n;++i){
     res = max(res,(2ll*a[i].Y-odd));
     if(i < n-1)
      b[bn++] = comp.slcp(a[i],a[i+1]);
   }
   stn = 0;
   for(int i = 0;i<bn;++i){
    while(stn > 0 && b[st[stn-1]] >= b[i])
     --stn;
    L[i] = stn > 0 ? st[stn-1] : -1;
    st[stn++] = i;
   }
   stn = 0;
   for(int i = bn-1;i>=0;--i){
    while(stn > 0 && b[st[stn-1]]>=b[i])
     --stn;
    R[i] = stn > 0 ?st[stn-1] : bn;
    st[stn++] = i;
   }
   for(int i = 0;i<bn;++i)
    res = max(res,(2ll*b[i]-odd)*(R[i]-L[i]));
   return res;
}
int main(int argc, char *argv[])
{
    setIO();
    gets(s);
    n = strlen(s);
    pre();
    manachers();
    ll res = max(0ll,calc(1,d1));
    res = max(res,calc(0,d2));
    printf("%d\n",res);
    closeIO();
    return EXIT_SUCCESS;
}
