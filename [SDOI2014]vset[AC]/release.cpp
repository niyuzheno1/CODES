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
#include <ctime>
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

#define SGT
#undef INF
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
#define du debug
#define CON rt,1,n
#define MN 400010
typedef long long LL;
const LL INF = ~0ULL>>1;
typedef pair<LL,LL> pLL;
typedef vector<pLL> vp;
pLL operator - (pLL a,pLL b) {return MP(a.X-b.X,a.Y-b.Y);}
pLL operator * (pLL a,pLL b) {return MP(a.X*b.Y-a.Y*b.X,a.X*b.X+a.Y*b.Y);}
LL det(pLL A,pLL B,pLL C) 
{
           LL res = ((B-A)*(C-A)).X;
           return res;
}
pLL a[MN],b[MN];
struct ch
{
 int tot;
 bool close;
 vector<pLL> f;
 void clo(int l,int r)
 {
  close = 1;
  int tot = 0;
  for(int i = l;i<=r;++i) b[++tot] = a[i];
  sort(b+1,b+tot+1);
  tot = unique(b+1,b+tot+1)-b;--tot;
  for(int i = 1;i<=tot;++i)
  {
   pLL now = b[i];
   while(f.size()>1 && det(f[f.size()-2],f[f.size()-1],now)>0) f.pop_back();
   f.pb(now);
  }
 }
 LL ask(pLL vc)
 {
  int _l = 0,_r = f.size()-1;
  LL ans = -INF;
  int times = 0;
  while(_l+2<_r && times <= 10)
  {
  M;int ne = mid+1;++times;
  if(mid == f.size()-1) break;
  if((vc*f[mid]).Y < (vc*f[ne]).Y)_l = mid+1;
  if((vc*f[mid]).Y > (vc*f[ne]).Y)_r = mid;
  }
  if(_l > _r) swap(_l,_r);
  for(int i = _l;i<=_r;++i) ans = max(ans,(vc*f[i]).Y);
  return ans;
 }
};
int o1[MN*4],o2[MN*4],tot;
ch inf[MN*4];
#define LCH(_t) o1[_t]
#define RCH(_t) o2[_t]
void add(TREE2,int x)
{
 if(_t == 0) _t = ++tot;
 ++inf[_t].tot;
 if(inf[_t].tot == _r-_l+1)
  inf[_t].clo(_l,_r);
 if(_l == _r) return;
 M;
 if(x <= mid) add(LEFT,x); else add(RIGHT,x);
}
LL getans(TREE,int l,int r,pLL u)
{
 if(l<=_l && _r <= r && inf[_t].close)
  return inf[_t].ask(u);
 M;
 LL ans = -INF;
 if(l <= mid) ans = max(ans,getans(LEFT,l,r,u));
 if(r > mid) ans = max(ans,getans(RIGHT,l,r,u));
 return ans;
}
LL lastans=0;
char str[10];
int n ,rt,ok=0;
inline int decode(int x,LL lastans){
 return x^(lastans & 0x7fffffff);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d%s",&n,str);
    if(str[0] == 'E') ok = 1;
    int siz = 1;
    for(int i = 1,x,y,z,w;i<=n;++i)
    {
     scanf("%s",str);
     if(str[0] == 'A')
     {
      scanf("%d%d",&x,&y);
      if(!ok){
      x = decode(x,lastans),y = decode(y,lastans);
      }
      a[siz]= MP(x,y);
      add(CON,siz);++siz;
     }
     if(str[0] == 'Q')
     {
      scanf("%d%d%d%d",&x,&y,&z,&w);
      if(!ok){
      x = decode(x,lastans),y = decode(y,lastans);
      z = decode(z,lastans),w = decode(w,lastans);
      }
      printf("%lld\n",lastans=getans(CON,z,w,MP(x,y)));
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
