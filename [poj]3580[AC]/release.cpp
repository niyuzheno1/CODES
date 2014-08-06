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

//for splay
#define L C[0]
#define R C[1]
#define F C[2]
//for fenwick tree
#define lb(x) ((x)&(-x))
#define TREE int _t,int _l,int _r
#define TREE2 int & _t,int _l,int _r
#define M int mid = (_l+_r)>>1;
#define LEFT LCH(_t),_l,mid
#define RIGHT RCH(_t),mid+1,_r
inline int getID(int l,int r){
 return l+r|l!=r;
}
//for treap
template<class _type>
void zig(_type * & y)
{
  _type * x = y->lc;
  y->lc = x->rc;
  x->rc = y;
  y = x;
}

template<class _type>
void zag(_type * & y){
  _type * x = y->rc;
  y->rc = x->lc;
  x->lc = y;
  y = x;
}

#undef INF
const int INF = ~0U>>1;
#define rand ran()
int ran(){
 static int x = 1364684679;
 x += (x<<2)+1;
 return x;
}
#define MX 10010
struct info{
  int mn,k,mark,delta,sz;
  void clr()
  {
   mark = delta = 0;
  }
};
void operator >> (const info & a,info & b)
{
     if(a.mark) b.mark ^= 1;
     if(a.delta) b.mn += a.delta,b.delta += a.delta,b.k += a.delta;
}
void operator << ( info & a,const info & b)
{
    int delta = a.delta;
    if(a.mn > b.mn + delta) a.mn = b.mn+delta;
    a.sz += b.sz;
}
struct node {
   int w;
   info in;
   node * lc,*rc;
   static node * getnew(node * w = NULL){
          static node * list = NULL;
          if(w){
           w->rc = list;list = w;
           return NULL;
          }
          if(!list){
               node * q = new node[MX];
               for(int i = 0;i<MX;++i){
                q[i].w = rand;
                q[i].rc = list;list = q+i;
               }
          }
          node * p = list ;list = list->rc;
          p->lc = p->rc = NULL;
          p->in.delta = p->in.mark = 0;
          return p;     
   }
   void down(){
    if(in.mark){
      if(lc) swap(lc->lc,lc->rc);
      if(rc) swap(rc->lc,rc->rc);
    }
    if(lc) in>>lc->in;
    if(rc) in>>rc->in;
    in.clr();
   }
   void upd(){
    in.mn = in.k;
    in.sz = 1;
    if(lc) in<<lc->in;
    if(rc) in<<rc->in;
   }
};
#undef SIZE
#define SIZE(_) ((_)?(_)->in.sz:0)
struct treap{
   node * rt;
   treap(){rt = NULL;}
   void ins(node *& p,int a,int k){
     if(!p){
       p = node::getnew();
       p->in.k = p->in.mn = k;p->in.sz = 1;
     }else{
       p->down();
       if(SIZE(p->lc) >= a){
        ins(p->lc,a,k);
        node * q = p->lc;
        if(q->w < p->w)
        {
         q->down();
         zig(p);
         p->rc->upd();
        }
       }else {
         ins(p->rc,a-SIZE(p->lc)-1,k);
         node * q = p->rc;
         if(q->w < p->w)
         {
          q->down();
          zag(p);
          p->lc->upd();
         }
       }
       p->upd();
     }
   }
   void ins(int a,int k){ins(rt,a,k);}
   static void merge(node *&p,node * x,node * y){
     if(!x || !y){p=(x?x:y);}
     else if(x->w < y->w){
      x->down();
      merge(x->rc,x->rc,y);
      x->upd();
      p = x;
     }else{
      y->down();
      merge(y->lc,x,y->lc);
      y->upd();
      p = y;
     }
   }
   void del(node * & p ,int a){
    p->down();
    if(SIZE(p->lc) == a){
     node * q = p;
     merge(p,p->lc,p->rc);
     node::getnew(q);
    }else if(SIZE(p->lc) > a){
     del(p->lc,a);
     p->upd();
    }
    else{
     del(p->rc,a-SIZE(p->lc)-1);
     p->upd();
    }
   }
   void del(int a){del(rt,a);}
   static void cut(node * p,node *&x,node *&y,int a){
     if(a == 0){
      x = NULL;y=p;
     }else if(a == SIZE(p)){
      x = p;y=NULL;
     }else{
       p->down();
       if(SIZE(p->lc) >= a ){
        y = p;
        cut(p->lc,x,y->lc,a);
        y->upd();
       }else {
        x = p;
        cut(p->rc,x->rc,y,a-SIZE(p->lc)-1);
        x->upd();
       }
     }
   }
   int ask(node * p ,int a,int b){
    if(a == 0 && b== SIZE(p)-1) return p->in.mn;
    p->down();
    int u = SIZE(p->lc);
    int r = (a<=u && u <= b ? p->in.k:INF);
    if(a < u) r = min(r,ask(p->lc,a,b>=u?u-1:b));
    if(b > u) r = min(r,ask(p->rc,a<=u?0:a-u-1,b-u-1));
    return r;
   }
   int ask(int a,int b){ return ask(rt,a,b); }
}T;
void ins(int a,int k){T.ins(a,k); }
void del(int a){T.del(a);}
void revolve(int a,int b,int c){
 node * p,*q,*r,*s;
 treap::cut(T.rt,p,q,a);
 treap::cut(q,q,r,b-a+1);
 treap::cut(r,r,s,c-b);
 treap::merge(p,p,r);
 treap::merge(p,p,q);
 treap::merge(T.rt,p,s);
}
void reverse(int a,int b){
 node *p,*q,*r;
 treap::cut(T.rt,p,q,a);
 treap::cut(q,q,r,b-a+1);
 q->in.mark ^= 1,swap(q->lc,q->rc);
 treap::merge(p,p,q);
 treap::merge(T.rt,p,r);
}
void add(int a,int b,int c){
 node *p,*q,*r;
 treap::cut(T.rt,p,q,a);
 treap::cut(q,q,r,b-a+1);
 q->in.k += c;q->in.mn += c;q->in.delta +=c;
 treap::merge(p,p,q);
 treap::merge(T.rt,p,r);
}
int ask(int a,int b){
 return T.ask(a,b);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi;
    for(int i = 0,x;i<n;++i){
     x = gi;
     ins(i,x);
    }
    int m = gi;
    char buf[100];
    while(m--){
      scanf("%s",&buf);
      int x=gi,y,d;
      if(buf[0] == 'A'){
       y = gi,d = gi;
       --x;--y;
       add(x,y,d);
      }
      else if(buf[0] == 'I'){
       y = gi;
       ins(x,y);
      }else if(buf[0] == 'D')
       {--x;del(x);}
      else if(buf[0] == 'M'){
       y = gi;--x;--y;
       printf("%d\n",ask(x,y));
      }
      else if(buf[3] == 'E'){
       y = gi;--x;--y;
       reverse(x,y);
      }else{
       y = gi,d = gi;--x;--y;
       d %= (y-x+1);
       d += (y-x+1);
       d %= (y-x+1);
       if(d)
        revolve(x,y-d,y);
      }
    }
    closeIO();
    return EXIT_SUCCESS;
}
