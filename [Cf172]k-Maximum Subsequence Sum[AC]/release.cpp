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
#define pb push_back
/*#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif*/
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
#undef L
#undef R
#define tree int t,int l,int r
#define left t*2,l,mid
#define right t*2+1,mid+1,r
#define M int mid = (l+r)/2;
const int N = 400005;
struct Tree{
 struct opt{int L,R,m;}a[2];
 struct note{int m,p;}L[2],R[2];
 int s;
}T[ N ],o[55];
int c [ N ] , n , m , type , x, y , k;
bool cmp(int a,int b,int type) {return type?a>b:a<b;}
void update(Tree & t,Tree & l, Tree & r)
{
 t.s = l.s + r.s;
 for(int i = 0;i<2;++i){
 t.L[i] = l.L[i],t.R[i] = r.R[i];
 if(cmp(l.s + r.L[i].m , t.L[i].m,i))
   t.L[i].m = l.s + r.L[i].m, t.L[i].p = r.L[i].p;
 if(cmp(r.s + l.R[i].m , t.R[i].m , i))
   t.R[i].m = r.s + l.R[i].m, t.R[i].p = l.R[i].p;
 t.a[i].m = l.R[i].m + r.L[i].m;
 t.a[i].L = l.R[i].p,t.a[i].R = r.L[i].p;
 if(cmp(l.a[i].m,t.a[i].m,i))t.a[i] = l.a[i];
 if(cmp(r.a[i].m,t.a[i].m,i))t.a[i] = r.a[i]; 
 }
}
void turn(int t)
{
 c[t]^=1,T[t].s *= -1,swap(T[t].a[0],T[t].a[1]);
 swap(T[t].L[0],T[t].L[1]),swap(T[t].R[0],T[t].R[1]);
 for(int i = 0;i<2;++i) T[t].a[i].m *= -1,T[t].L[i].m *= -1,T[t].R[i].m *= -1;
}
void down(int t){c[t]=0,turn(t*2),turn(t*2+1);}
void renew(int t,int P)
{
     int x = T[t].s;
     for(int i = 0;i<2;++i)
      T[t].a[i].m = T[t].L[i].m = T[t].R[i].m = x,
      T[t].a[i].L = T[t].a[i].R = T[t].L[i].p = T[t].R[i].p = P;
}
void build(tree)
{
     if(l == r ) {T[t].s = gi;renew(t,l);return;}M;
     build(left);build(right);update(T[t],T[t*2],T[t*2+1]);
}
void modify(tree,int x,int y)
{
     if(l == r ) {T[t].s = y;renew(t,l);return;}M;if(c[t]) down(t);
     x <= mid?modify(left,x,y):modify(right,x,y);update(T[t],T[t*2],T[t*2+1]);
}
void rev(tree,int ll,int rr)
{
     if(l == ll && r == rr) {turn(t);return;} M; if(c[t]) down(t);
     if(rr <= mid) rev(left,ll,rr);else if(ll> mid) rev(right,ll,rr);
     else rev(left,ll,mid),rev(right,mid+1,rr);
     update(T[t],T[t*2],T[t*2+1]);
}
void query(tree,int ll,int rr,Tree & res)
{
     if(l == ll && r == rr){res = T[t];return;}M;if(c[t]) down(t);
     if(rr <= mid) query(left,ll,rr,res); else if(ll > mid) query(right,ll,rr,res);
     else {Tree TL,TR; query(left,ll,mid,TL),query(right,mid+1,rr,TR),update(res,TL,TR);}
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,build(1,1,n),m = gi;
    while(m--) {
    type = gi,x = gi,y = gi;
     if(type){
       k = gi; int len = 0,ans = 0;
       while(len < k){
        query(1,1,n,x,y,o[++len]);
        if(o[len].a[1].m <= 0) {--len;break;}
        ans += o[len].a[1].m;
        rev(1,1,n,o[len].a[1].L,o[len].a[1].R);
       }
       printf("%d\n",ans);
       for(int i = len;i;--i)
        rev(1,1,n,o[i].a[1].L,o[i].a[1].R);
     }
     else modify(1,1,n,x,y);
    }  
    closeIO();
    return EXIT_SUCCESS;
}
