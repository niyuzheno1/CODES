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

#define MN 50010
struct node{
        int l,r,lp,pos;
        bool operator < (node t) const {
         return lp < t.lp || (lp == t.lp && r < t.r);
        }
}ask[MN];
int num[MN],num2[MN],w[MN],a[MN],key[MN];
int n,q,cnt,ans;
void upd(int x,int v){
 for(int i  =x;i<=cnt;i+=lb(i))
  num[i] += v;
}
int sum(int x){
 int res = 0;
 for(int i = x;i;i-=lb(i))
  res += num[i];
 return res;
}
void upd2(int x,int v){
 for(int i = x;i<=cnt;i+=lb(i))
  num2[i] += v;
}
int sum2(int x){
 int res = 0;
 for(int i = x;i;i-=lb(i))
  res += num2[i];
 return res;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;a[i]=gi,w[i]=a[i],++i);
    sort(w+1,w+n+1);
    cnt = unique(w+1,w+n+1)-w-1;
    for(int i = 1;i<=n;a[i]=lower_bound(w+1,w+cnt+1,a[i])-w,++i);
    q = gi;
    int len = (int)(sqrt(n)+0.5);
    for(int i = 1;i<=q;++i){
     ask[i].l = gi,ask[i].r=  gi;
     ask[i].lp = (ask[i].l-1)/len+1;
     ask[i].pos = i;
    }
    sort(ask+1,ask+q+1);
    int pl = 1,pr = 0;
    for(int i = 1;i<=q;++i){
     if(pr < ask[i].r){
      for(++pr;pr <= ask[i].r;++pr){
       ans += sum(cnt+1-a[pr]);
       upd(cnt+1-a[pr]+1,1);
       upd2(a[pr]+1,1);
      }
      --pr;
     }else if(pr > ask[i].r){
      for(;pr>ask[i].r;--pr){
       ans -= sum(cnt+1-a[pr]);
       upd(cnt+1-a[pr]+1,-1);
       upd2(a[pr]+1,-1);
      }
     }
     if(pl < ask[i].l){
      for(;pl < ask[i].l;++pl){
       ans -=sum2(a[pl]);
       upd(cnt+1-a[pl]+1,-1);
       upd2(a[pl]+1,-1);}
      }
      else if(pl > ask[i].l){
       for(--pl;pl >= ask[i].l;--pl){
        ans += sum2(a[pl]);
        upd(cnt+1-a[pl]+1,1);
        upd2(a[pl]+1,1);
       }
      ++ pl;
      }
      key[ask[i].pos] = ans;
     }
    
    
    for(int i = 1;i<=q;++i) printf("%d\n",key[i]);
    closeIO();
    return EXIT_SUCCESS;
}
