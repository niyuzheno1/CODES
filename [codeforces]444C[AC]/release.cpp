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

typedef int64 LL;
const LL li = 320;
#define MQ 325 
#define MN 200010
LL st[MQ],ty[MQ],ct[MQ],tg[MQ],a[MN],cg[MN];
int n,m,l,r,x;
void work1(){
 l = gi,r = gi,x = gi;
 for(int i = 1;i<=li;++i){
   int L=li*(i-1)+1,R=li*i;
   if(l <= L && R <= r){
        if(st[i] == 0){
        for(int j = L;j<=R;++j) ct[i] += abs(a[j]-x),cg[j] += abs(a[j]-x);
        ty[i] = x;
        st[i] = 1;
        }else {
        tg[i] += abs(x-ty[i]);
        ct[i] += li*abs(x-ty[i]);
        ty[i] = x;
        }
   }else if(!((l>R||r<L))){
    if(st[i] == 1){
     for(int j = L;j<=R;++j) a[j] = ty[i];
     st[i] = 0;
    }
    if(l > L) L = l;
    if(r < R) R = r;
    for(int j = L;j<=R;++j){
     ct[i] += abs(a[j]-x);
     cg[j] += abs(a[j]-x);
     a[j] = x;
    }
   }
 }
}

void work2(){
 l = gi,r = gi;
 LL ans = 0;
 for(int i = 1;i<=li;++i)
 {
  int L = li*(i-1)+1,R = li*i;
  if(l <= L && R <= r)
   ans+=ct[i];
  else if(!(l>R ||r < L)){
   if(l > L) L = l;
   if(r < R) R = r;
   for(int j = L;j<=R;++j)
    ans += tg[i]+cg[j];
  }
 }
 
 printf(I64D,ans);puts("");
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    for(int i = 1;i<=170000;a[i] = i,++i);
    for(int h = 1;h<=m;++h){
     int tp = gi;
     if(tp == 1) work1();
     else work2();
    } 
    closeIO();
    return EXIT_SUCCESS;
}
