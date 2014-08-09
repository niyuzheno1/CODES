#include "mode.h"
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
 node * c;
 bool operator < (_up d) const 
 {
       return a > d.a;
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
 set<_up> im;
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
     if(im.size() >= 1){
       b << *im.begin();
     }
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
node c[MN];
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
  if(have(now->R))now->im.insert(now->R->b);
  if(have(pre))now->im.erase(pre->b);now->R = pre;
  pre = now;pre->upd();now = now->F;
  }
  splay(x);
  return lm(x);
}
void link(node * a,node * b,int val){
 access(a);
 a->mkrt();
 a->F = b;
 a->sf.a = val;
 a->upd();
 a->F->im.insert(a->b);
 access(a);
 a->sf.c = b;
}
void cut(node * a,node * b){
 access(a);
 a->mkrt(); 
 access(b); 
 b->L->F = nil;
  b->L = nil;
  b->upd();
}
bool same(node * a,node * b){
 a = access(a); b = access(b);
 return a==b;
}
bool q1(node * a,node * b,int val){
 if(!same(a,b)){link(a,b,val); return 1;}
 access(a);
 a->mkrt();
 access(b);
 b->pd();
 splay(a,b);a->pd();
 _up msg = empup;
 if(have(a->R)) msg = a->R->b;
 msg << a->sf; msg << b->sf;
 if(msg.a > val ){
  access(msg.b);
  node * pre = msg.b->sf.c;
  cut(msg.b,pre);
  if(have(msg.b->F) && msg.b->F->fd(msg.b) == -1)
   msg.b->F->im.erase(msg.b->b);
  msg.b->sf.a = -INF;
  msg.b->sf.b = msg.b;
  msg.b->sf.c = (node*)NULL;
  msg.b->upd();
  if(have(msg.b->F) && msg.b->F->fd(msg.b) == -1)
   msg.b->F->im.insert(msg.b->b);
  access(msg.b);
  link(a,b,val);
  return 2;
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
    int ans1 = 0,ans2 = 0;
    for(int i = 1;i<=m;++i){
            if(i == 5)
             i = 5;
     int res = q1(c+a[i].x,c+a[i].y,a[i].b);
     if(res) ans1 = a[i].a;
    }
    access(c+1);
    ans2 =  c[1].b.a;
    printf("%d",ans1+ans2);
    closeIO();
    return EXIT_SUCCESS;
}
