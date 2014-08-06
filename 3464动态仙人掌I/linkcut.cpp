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
 bool isRoot()
 {
  return !F||(F->L != this && F->R != this);
 }
 void rotate()
 {
  linkcut * x = this,*y = x->F,*z = y->F;
  bool d1 = (y->L==x);
  bool d2 = (z->R == y);
  y->ch[!d1] = x->ch[d1];y->ch[!d1]->F = y;
  x->ch[d1] = y;y->F = x;z->ch[d2] = x;x->F = z;
  y->updata();
 }
 void passdown()
 {
  int anc_n = 0;
  static linkcut * anc[MAXN];
  anc[anc_n++] = this;
  for(int i = 0;!anc[i]->isRoot();i++)
   anc[anc_n++] = anc[i]->F;
  for(int i = anc_n-1;i>=0;i--)
   anc[i]->down();
 }
 void splay()
 {
  passdown();
  while(!this->isRoot())
  {
   if(!F->isRoot())
    if((F->F->L == F)==(F->L == this))
     F->rotate();
    else
     this->rotate();
   this->rotate();
  }
  this->updata();
 }
 void splayto(linkcut * t)
 {
  passdown();
  while(this->F != t)
  {
   if(!(F->F == t))
    if((F->F->L == F)==(F->L == this))
     F->rotate();
    else
     this->rotate();
   this->rotate();
  }
  linkcut * y = this;
  while(!y->isRoot())
   y->updata(),y = y->F;
  y->updata();
 }
 linkcut * lmost()
 {
  linkcut * x = this;
  while(x->down(),x->L)
   x = x->L;
  return x;
 }
 void access()
 {
  for(linkcut* p = this,*q = NULL;p;q = p,p=p->F)
  {
   p->splay();
   p->nex = q ? q->msg.q[0]:NULL;
   p->R = q;
  }
  this->splay();
 }
 void downrev()
 {
  rev ^= rev;
  msg.rev();
 }
 void downcir(edge * e)
 {
  Cir = true,cir = e;
  msg.co(e,!L&&!R);
 }
 void down()
 {
  if(rev)
  {
  linkcut* mid = L;L=R;R =mid;
  lct_edge * mid1 = pre;pre = nex;nex = mid1;
  if(L) L->downrev();
  if(R) R->downrev();
  rev = false;
  }
  if(Cir)
  {
  if(L)
  {
   pre->cir = cir;
   L->downcir(cir);
  }
  if(R)
  {
   nex->cir = cir;
   R->downcir(cir);
  }
  Cir = false;
  }
 }
 void makeRoot()
 {
       this->access();
       this->downrev();
       this->down();
 }
 linkcut * findRoot()
 {
       this->access();
       linkcut * root = this->lmost();
       root->splay();
       return root;
 }
 void updata()
 {
  if(pre->cir == nex->cir)
   msg.p[0] = msg.p[2] = -1;
  else
  {
   msg.p[0] = pre->cir?0:-1;
   msg.p[2] = pre->cir?0:-1;
  }
  msg.p[1] = 0;
  msg.cir = false;
  msg.q[0] = pre,msg.q[1] = nex;
  if(L)
   this->msg = L->msg + this->msg;
  if(R)
   this->msg = this->msg + R->msg;
 }
};
int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
