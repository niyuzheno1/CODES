#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define F ch[2]
#define L ch[0]
#define R ch[1]
using namespace std;
const int MAXN  = 100000;
const int MAXBLOCK = 10100;
template <class T>
class mem
{
 public:
 int used,m;
 T p[MAXBLOCK];
 T * u[MAXBLOCK];
 T * add(){ }
 void dec(T * v){ }
};
struct edge{ int v,u,w,l;};
struct lct_edge{ int w; edge * cir;};
struct lct_msg
{ int p[3]; lct_edge *q[2]; bool cir;
  void rev(){}
  void co(edge * e,bool is){}
  friend inline lct_msg operator+(const lct_msg & l,const lct_msg & r){
   lct_msg ret;
   return ret; 
  }
};
struct linkcut{
 linkcut*ch[3];
 lct_edge * pre,*nex;
 lct_msg msg;
 bool rev,Cir;
 edge * cir;
 bool isRoot(){}
 void rotate(){}
 void passdown(){}
 void splay(){}
 void splayto(linkcut * t){}
 linkcut * lmost(){}
 void access(){}
 void downrev(){}
 void downcir(edge * e){}
 void down(){ }
 void makeRoot(){ }
 linkcut * findRoot(){ }
 void updata(){ }
};
linkcut t[MAXN + 1];
mem<edge> Edglis;
mem<lct_edge> lctlis;
int n;
void cactus_init()
{
 for(int v = 1;v<=n;v++)
 {
  linkcut*p = t+v;
  p->F = p->L = p->R = NULL;
  p->pre = p->nex = NULL;
  p->rev = false;
  p->Cir = false;
  p->updata();
 }
}
bool cactus_link(int v,int u,int w)
{
 if(v == u)
  return false;
 if(v > u)
  swap(v,u);
 linkcut * x = t+v,*y = t+u;
 x->makeRoot();y->makeRoot();
 if(x->F)
 {
   x->access();
   y->splayto(x);
   if(x->msg.cir)
    return false;
   edge * cirE = Edglis.add();
   cirE->v = v,cirE->u = u,cirE->w = w;
   cirE->l = w + x->msg.p[1];
   x->nex->cir = cirE;
   x->pre->cir = cirE;
   if(y->R)
    y->R->downcir(cirE);
   y->updata();x->updata();
 }else {
    x->F = y;
    lct_edge * e = lctlis.add();
    e->w = w,e->cir = NULL;
    x->pre = e;
    x->updata();
 }
 return true;
}
bool cactus_cut(int v,int u,int w)
{
  if(v == u)
   return false;
  if(v > u)
   swap(v,u);
  linkcut * x = t+v,*y = t+u;
  if(x->findRoot() != y->findRoot())
   return false;
  y->makeRoot();
  x->access();
  y->splayto(x);
  lct_edge * e = y->nex;
  edge * cirE = e->cir;
  
}
int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
