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

const int MN = 1000010;
int lef[MN*4],rig[MN*4],tot;
int64 cnt[MN*4];
#define LEF(_t) lef[_t]
#define RIG(_t) rig[_t]

int build(TREE)
{
 if(_t == 0 ) _t = ++tot;
 if(_l == _r) return _t;
 M;LEF(_t) = build(LEFT);RIG(_t) = build(RIGHT);
 return _t;
}
void mkc(TREE,int x)
{
 ++cnt[_t];if(_l == _r) return;
 M;
 if(x<=mid) 
 mkc(LEFT,x); 
 else 
 mkc(RIGHT,x);
}
int64 delmin(TREE)
{
  --cnt[_t];
  if(_l == _r) return _l;
  M;
  if(cnt[LEF(_t)]>0)return delmin(LEFT);
  else if(cnt[RIG(_t)]>0)return delmin(RIGHT);
  return 0;
}
int64 delmax(TREE)
{
 --cnt[_t];
 if(_l == _r) return _r;
 M;
 if(cnt[RIG(_t)]>0)return delmax(RIGHT);
 else if(cnt[LEF(_t)]>0)return delmax(LEFT);
 return 0;
}
int main(int argc, char *argv[])
{
    tot = 1;
    setIO("sample");
    int64 n = gi;
    build(1,1,MN-10);
    int64 ans = 0;
    for(int64 i = 1;i<=n;++i)
    {
     int64 k = gi;
     for(int64 j = 1,u=0;j<=k;++j)
      u = gi,mkc(1,1,MN-10,u);
     int64 fx = delmin(1,1,MN-10);
     int64 fy = delmax(1,1,MN-10);
     ans += fy-fx;
    }
    printf(I64D,ans);
    closeIO();
    return EXIT_SUCCESS;
}
