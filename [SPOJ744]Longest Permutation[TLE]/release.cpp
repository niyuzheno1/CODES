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

const int MN = 100010,PINF = 0x7f7f7f7f;

int n,a[MN],b[MN],c[MN],d[MN],s[MN],tot,ans;

int ltr[MN*4],rtr[MN*4],inf1[MN*4],inf2[MN*4];

#define LEF(_t) ltr[_t]

#define RIG(_t) rtr[_t]

void rev()
{
 reverse(a+1,a+1+n);
}
void initsgt()
{
     CLEAR(b,0x7f);CLEAR(d,0x7f);
     tot = 1;
     CLEAR(ltr,0);CLEAR(rtr,0);CLEAR(inf1,0);CLEAR(inf2,0);
}

int build(TREE)
{
 if(!_t) _t = ++tot;
 if(_l == _r)
 {inf1[_t] = a[_l];inf2[_t] = c[_l];return _t;}
 M;
 LEF(_t) = build(LEFT);
 RIG(_t) = build(RIGHT);
 inf1[_t] = max(inf1[LEF(_t)],inf1[RIG(_t)]);
 inf2[_t] = min(inf2[LEF(_t)],inf2[RIG(_t)]);
 return _t;
}

int gmax(TREE,int l,int r)
{
 if(_l == l && _r == r)
  return inf1[_t];
 M;
 if(l> mid)
  return gmax(RIGHT,l,r);
 else if(r <= mid)
  return gmax(LEFT,l,r);
 else 
  return max(gmax(LEFT,l,mid),gmax(RIGHT,mid+1,r));
}

int gmin(TREE,int l,int r)
{
 if(_l == l && _r == r)
  return inf2[_t];
 M;
 if(l> mid)
  return gmin(RIGHT,l,r);
 else if(r <= mid)
  return gmin(LEFT,l,r);
 else 
  return min(gmin(LEFT,l,mid),gmin(RIGHT,mid+1,r));

}

void work()
{
    initsgt();
    for(int i = n;i>=1;--i)
     if(a[i] == 1) b[i] = i;
     else b[i] = b[i+1];
    for(int i = 1;i<=n;++i) s[i] = s[i-1]+a[i];
    for(int i = n;i>=1;--i)
     c[i] = d[a[i]],d[a[i]] = i;
    
    build(1,1,n);
    for(int i = 1;i<=n;++i)
     if(b[i] != PINF)
     {
      int len = gmax(1,1,n,i,b[i]);
      int k = i+len-1;
      int uu = gmin(1,1,n,i,k);
      if(uu > k)
       if((s[k]-s[i-1]) == (len*(len+1))/2)
        ans = max(ans,len);
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i)
     a[i] = gi;
    work();
    rev();work();
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
