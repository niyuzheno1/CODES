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
typedef pair<int,int> _reserve_type_1;
typedef pair<int64,int64> pll;
#define pii _reserve_type_1
FILE * debug;
#define setIO _func_2_
void _func_2_(string file = "sample")
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

int n,m;
#define MN 50010
#define MM 100010
#define L a.ch[0]
#define R a.ch[1]
#define F a.ch[2]
#define GF a.ch[2]->a.ch[2]
#define have(x) (x!=(node*)NULL)
#define nil ((node*)NULL)
struct _edge{
       int a,b,x,y;
       bool operator < (_edge c) const {return a<c.a || (a == c.a && b < c.b);}
};
_edge a[MM];
struct node;
struct _down{
 int rev;
 node* ch[4];
};
void operator >> ( const _down & a,_down & b){
 if(a.rev) b.rev ^= 1;
}
void operator -- (_down & a){
 if(a.rev) swap(a.ch[0],a.ch[1]);
 a.rev = 0;
}
struct _up{
 int a;
 node * b;
 node * c,*d,*e;
 bool operator < (_up d) const 
 {
       return a > d.a || (a == d.a && b > d.b);
 }
};
_up empup;
void operator ++ (_up & a){
 a . a =  -INF;a.b = nil;
}
void operator << (_up & a,const _up & b){
 if(a.a <= b.a)
  a.a = b.a,a.b = b.b;
}
struct node{
 _down a;
 _up b,sf;
 //set<_up> im;
 node () {
  sf.a = -INF;sf.b = this; 
  upd();
 }
 void pd(){
      if(!have(this)) return;
       if(have(L)) a >> L->a; if(have(R)) a >> R->a;--a;
      
 }
 void upd(){
     if(!have(this)) return;
     ++b;if(have(L)) b << L->b; if(have(R)) b << R->b;b << sf;
     /*if(im.size() >= 1){
       b << *im.begin();
     }*/
 }
 int fd(node * x){
     if(!have(this)) return -1;
    int ret = -1;
    if(x == L) ret = 0; if(x == R) ret = 1;
    return ret;
 }
 bool isrt(){
    if(!have(this)) return true;
    return  (!have(F))|| (F->fd(this) == -1);
 }
 void setw(node * x){
  if(!have(this)) return;
  this->a.ch[2] = x;
 }
 void mkrt(){
  if(!have(this)) return;
  this->a.rev ^= 1;pd();
 }
};
node c[MN+MM];
node * newnode(node * a,node * b,int val)
{
     ++n;
     node * ret = c+n; ret->sf.a = val;ret->sf.d = a;ret->sf.e = b;
     return ret;
}
void rotate(node * x){
 node * y = x->F,*z = x->GF;
 z->pd();y->pd();x->pd();
 int d1 = y->fd(x),d2 = z->fd(y);
 if(d1 != -1){
 y->a.ch[d1] = x->a.ch[!d1];y->a.ch[d1]->setw(y);
 x->a.ch[!d1] = y;y->setw(x);
 }
 if(d2 != -1) z->a.ch[d2] = x;  x->setw(z);
 y->upd();x->upd();y->upd();
}
void splay(node * x){
 while(!x->isrt()){
   node * y = x->F,*z = x->GF;
   if((!y->isrt()) &&  ((y->L == x)==(z->L==y)))
    rotate(y);
   rotate(x);
 }
}
void splay(node * x,node * w){
  while(x->F != w){
   node * y = x->F,*z = x->GF;
   if((!(y->F==w)) &&  ((y->L == x)==(z->L==y)) )
    rotate(y);
   rotate(x);
  }
}
node * lm(node * x){
 while(x->L) x = x->L;
 return x;
}
node* access(node * x){
  for(node * pre = 0,* now = x;now;){
  splay(now);now->pd();
  //if(have(now->R))now->im.insert(now->R->b);
  //if(have(pre))now->im.erase(pre->b);
  now->R = pre;
  pre = now;pre->upd();now = now->F;
  }
  splay(x);
  return lm(x);
}
void link2(node * a,node * b){
 access(a);
 a->mkrt();
 a->F = b;
 a->upd();
 //a->F->im.insert(a->b);
 access(a);
 a->sf.c = b;
}
void cut2(node * a,node * b){
 access(a);
 a->mkrt(); 
 access(b); 
 b->L->F = nil;
 b->L = nil;
 b->upd();
}
void link(node * a,node * b,int val){
 node * c = newnode(a,b,val);
 link2(a,c);link2(b,c); 
}
void cut(node * a,node * b,node * c){
 cut2(a,c);
 cut2(b,c);
}
bool same(node * a,node * b){
 a = access(a); 
 b = access(b);
 
 return a==b;
}
bool q1(node * a,node * b,int val){
 if(!same(a,b))
 {
	 link(a,b,val); 
	 return 1;
 }
 access(a);
 a->mkrt();
 access(b);
 b->pd();
 splay(a,b);a->pd();
  _up msg = empup;
 if(have(a->R)) msg = a->R->b;
 if(msg.a > val){
  cut(msg.b->sf.d,msg.b->sf.e,msg.b);
  node * c = newnode(a,b,val);
 link2(a,c);
 link2(b,c); 
  return 1;
 }
 return 0;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    empup.a = -INF;
    for(int i = 1; i<= m;++i){
     a[i].x = gi;a[i].y = gi; a[i].a = gi,a[i].b = gi;
    }
    sort(a+1,a+1+m);
    int ans1 = INF;
    int ln =  n;
    for(int i = 1;i<=m;++i){
	 if(i == 223)
		  i = 223;
     if(a[i].x == a[i].y) continue;
     int res = q1(c+a[i].x,c+a[i].y,a[i].b);
     access(c+ln); (c+ln)->mkrt();node * res1  = lm(c+ln);
     node * res2 = access(c+1); 
     if(res1 == res2 && res){
     splay(c+ln,c+1);
     ans1 = min(ans1,a[i].a+(c+ln)->b.a);
     }
    }
    if(ans1 == INF)
     puts("-1");
    else
     printf("%d",ans1);
    closeIO();
    return EXIT_SUCCESS;
}
