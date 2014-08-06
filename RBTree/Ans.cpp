#include "mode.h"
#include "mathlab.h"
#include "data.h"
struct RBT
{
 struct node
 {
  node *  C[3];
  int val,color;
  node operator = (node x) { val =  x.val; }
 };
 node*root,*nil;
 int h;
 void update(node * u)
 {
 }
 void passtoleft(node * u)
 {
 }
 RBT()
 {
  nil = new node;
  memset(nil,0,sizeof(node));
  root = nil;
 }
 void dpr(node * u,int dep)
 {
  if(u == nil)
   return;
  h = max(dep,h);
  dpr(u->L,dep+1);
  ff(debug,"now:%d L:%d R:%d color:%d val:%d\n",u->val,u->L->val,u->R->val,u->color,u->val);
  dpr(u->R,dep+1);
 }
 void getd(node * u,int dep)
 {
  if(u == nil)
   return;
  h = max(dep,h);
  getd(u->L,dep+1);
  getd(u->R,dep+1);
 }
};
int _insert(RBT * u,RNode * & x,RNode * y)
{
 if(x == u->nil) { x = y ; return 1; }
 int ret = 0;
 if(y->val > x->val) ret = _insert(u, x->R , y);
 else ret = _insert(u , x->L , y);
 if(ret) y->F = x;
 return 0;
}
void LR(RBT * T,RNode * x)
{
     RNode * y = x->R;
     x->R = y->L;
     if(y->L != T->nil) y->L->F = x;
     y->F = x->F;
     if(x->F == T->nil) T->root = y;
     else if(x == x->F->L) x->F->L = y;
     else x->F->R = y;
     y->L = x;
     x->F = y;
}
void RR(RBT * T,RNode * x)
{
   RNode * y = x->L;
   x->L = y->R;
   if(y->R != T->nil) y->R->F = x;
   y->F = x->F;
   if(x->F == T->nil) T->root = y;
   else if(x->F->L == x) x->F->L = y;
   else x->F->R = y;
   y->R = x;
   x->F = y;
}
void insert(RBT * T,int x)
{
 RNode * y = new RNode;
 y->val = x;
 y->L = y->R = y->F = T->nil;
 _insert(T,T->root,y);
 y->color = RED;
 while((y != T->root) && (y->F->color == RED))
 {
  if(y->F == y->F->F->L)
  {
   RNode * u = y->F->F->R;
   if(u->color == RED)
   {
    y->F->color = u->color = BLACK;
    u->F->color = RED;
    y = u->F;
   }
   else 
   {
    if(y == y->F->R) y=y->F,LR(T,y); // 定义|x|为x的黑高度,则|y->F->L| == |y->F->R| => |y->F->L| = |y->L| =>足够对于y->F左旋
    //假设修改,并且|y->F->F->R| == |y->R| 足够使y->F->F右旋 
    y->F->color = BLACK;
    y->F->F->color = RED;
    RR(T,y->F->F);
   }
  }else{
    RNode * u = y->F->F->L;
    if(u->color == RED)
    {
     y->F->color = u->color = BLACK;
     u->F->color = RED;
     y = u->F;
    }else {
     if(y == y->F->L) y = y->F,RR(T,y);  
     y->F->color = BLACK;
     y->F->F->color = RED;
     LR(T,y->F->F);
    }
  }
 }
 T->root->color = BLACK;
}
RNode * find(RBT * T, RNode * x,int y)
{
 if(x == T->nil) return x;
 RNode*ret = T->nil;
 if( y > x->val ) ret = find(T,x->L,y);
 if( y == x->val ) ret = x;
 else ret = find(T,x->R,y);
 if(ret == T->nil) ret = x;
 return ret;
}
RNode * succ(RBT * T ,RNode * x)
{
 if(x == T->nil) return x;
 RNode * ret = T->nil;
 ret = succ(T,x->L);
 if(ret == T->nil) ret = x;
 return ret;
}
void RB_Fix(RBT * T,RNode * x)
{
     while(x != T->root && x->color == BLACK)
     {
      if(x == x->P->L){
       RNode * w = x->p->R;
       
      }else{
      }
     }
}
void del(RBT * T,RNode * z)
{
     RNode * y,*x;
     if((z->L == T->nil)||(z->R == T->nil)) y = z; else y = succ(T,z->R);
     if(y->L != T->nil) x = y->L; else x = y->R;
     x->F = y->F;
     if(y->F == T->nil)T -> root = x; else if(y == y->F->L ) y->F->L = x; else y->F->R = x;
     if(y != z) (*z) = (*y);
     if(y->color == BLACK) RB_Fix(T,x);
     T->nil->F = 0;
}
RBT u;
int main(int argc, char *argv[])
{
    setIO("sample");
    for(int i = 1;i<=10000;++i)
     insert(&u,i);
    //u.dpr(u.root,1);
    u.getd(u.root,1);
    ff(debug,"%d\n",u.h);
    closeIO();
    return EXIT_SUCCESS;
}
