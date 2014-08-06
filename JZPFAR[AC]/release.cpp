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

const int MN = 210000;

struct node {
        node * l,*r;int bh,kind,xx,xd,yx,yd;
} g[MN] , * root;
struct poin{int x,y;} a[MN];
int tot,n,bh[MN],px,py,pk,pbh[MN],m;
int64 d[25];
int comy(int p,int q){return a[p].y < a[q].y;}
int comx(int p,int q){return a[p].x < a[q].x;}
void up(int & a,int b) {if(b > a) a = b;}
void dw(int & a,int b) {if(a > b) a = b;}

node * build (int l,int r,int k)
{
 node * p = &g[++tot];
 sort(bh+l,bh+r+1,k?comy:comx);
 int mid = (l+r)>>1;
 p->bh = bh[mid],p->kind = k;
 p->xx = p->xd = a[bh[mid]].x;
 p->yx = p->yd = a[bh[mid]].y;
 if(l < mid)
 {
 p->l = build(l,mid-1,!k);
 up(p->xd,p->l->xd);dw(p->xx,p->l->xx);
 up(p->yd,p->l->yd);dw(p->yx,p->l->yx);
 }
 if(r > mid)
 {
 p->r = build(mid+1,r,!k);
 up(p->xd,p->r->xd);dw(p->xx,p->r->xx);
 up(p->yd,p->r->yd);dw(p->yx,p->r->yx);
 }
 return p;
}
int64 dist(int x,int y){
 return  1LL*x*x+1LL*y*y;
}
void updata(int x)
{
    int64 mid = dist(px-a[x].x,py-a[x].y);
    for(int j = 1;j<=pk;++j)
     if(mid > d[j] || (mid == d[j] && pbh[j] > x )) 
      {
      for(int k = pk;k>j;--k)
       d[k] =  d[k-1],pbh[k] = pbh[k-1];
      d[j] = mid,pbh[j] = x;
      return;
      }
}
void answer(node * p ,int k)
{
 if(!p || dist(max(abs(px-p->xx),abs(px-p->xd)),max(abs(py-p->yx),abs(py-p->yd)))<d[pk])
  return;
 updata(p->bh);
 if(k ? (a[p->bh].y < py || (a[p->bh].y == py && a[p->bh].x < px)) : (a[p->bh].x < px || (a[p->bh].x == px && a[p->bh].y < py)))
  answer(p->l,!k),answer(p->r,!k);
 else answer(p->r,!k),answer(p->l,!k);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;bh[i] = i,++i)a[i].x  = gi,a[i].y = gi;
    root = build(1,n,0);
    
    for(m = gi;m;--m)
    {
     px = gi,py = gi,pk = gi;
     CLEAR(d,0xff);
     answer(root,0);
     printf("%d\n",pbh[pk]);
    }closeIO();
    return EXIT_SUCCESS;
}
