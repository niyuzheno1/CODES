#include "mode.h"
#include "ptr.h"
#include "debug.h"
#define MN 10010
struct sbt;
typedef ptr<sbt> pt;
struct sbt{
  int ref,size,key;
  pt lc,rc;
}None;
int gcnt;
pt none(&None);
pt newnode(int key){
 sbt * nd = new sbt;
 nd->ref = 0;nd->size = 1;nd->key = key;nd->lc = none;nd->rc = none;
 return pt(nd);
}
void rr(pt & newu){
 pt newk = newu->lc;
 newu->lc = newk->rc;newk->rc = newu;
 newk->size = newu->size;newu->size = newu->lc->size+newu->rc->size+1;
 newu = newk;
}
void lr(pt & newu){
 pt newk = newu->rc;
 newu->rc = newk->lc;newk->lc = newu;
 newk->size = newu->size;newu->size = newu->lc->size+newu->rc->size+1;
 newu = newk;
}
int opt = 0;
void mt(pt & t,bool flag){
 
 if(flag == false)
 {
  if(t->lc->lc->size > t->rc->size)
   rr(t);
  else{
   if(t->lc->rc->size > t->rc->size){++opt;lr(t->lc);rr(t);}
   else
    return ;
  }
 }
 else{
  if(t->rc->rc->size > t->lc->size) lr(t);
  else{
   if(t->rc->lc->size > t->lc->size) {++opt;rr(t->rc);lr(t);}
   else
    return;
  }
 }
++opt;
 mt(t->lc,true);
 mt(t->rc,true);
 mt(t,true);
 mt(t,false);
}
void insert(pt & newt,int v){
 if(newt == none)
 {
  newt = newnode(v);
  return;
 }else{
  ++newt->size;
  insert(newt->rc,v);
  mt(newt,1);
 }
}
void init()
{
     None.size = 0,None.lc = none;None.rc = none;none->ref = 10;
}
void upd(pt & a){
 a->size = a->lc->size+a->rc->size+1;
}

pt merge(pt & a,pt & b){
 if(a == none ) 
  return b;
 if(b == none ) 
  return a;
 if(a->rc->size + b->size < a->lc->size)
 {
  a->rc = merge(a->rc,b);
  upd(a->rc);upd(a);
  mt(a,1);
  return a;
 }
 else{
  b->lc = merge(a,b->lc);
  upd(b->lc);upd(b);
  mt(b,0);
  return b;
 }
}
int blog(int x)
{
     int ret = 0;
     while(x != 0)
       x>>=1,++ret;
      return ret;
}
bool cmp(pt & a,pt & b,int x)
{
 return max(blog(a->size),max(blog(b->lc->size),blog(b->rc->size)))  >= max(blog(b->size),max(blog(a->lc->size),blog(a->rc->size))) ;
}

/*pt merge(pt & a,pt & b){
 int u = 0;
 return merge(a,b,u,0);
}*/
void split(pt a,pt & b,pt & c,int x){
 if(x == 0)
  b = none,c = a;
 else if(x == a->size)
  b = a,c = none;
 else{
  if(a->lc->size >= x){
   c = a;
   split(a->lc,b,c->lc,x);
   mt(c,0);
   upd(c);
  }
  else{
   b = a;
   split(a->rc,b->rc,c,x-a->lc->size-1);
   mt(b,1);
   upd(b);
  }
 }
}
void pri(pt & u){
 if(u == none)
  return;
 pri(u->lc);
 printf("%d ",u->key);
 pri(u->rc);
}
int dpt;
void checkd(pt & u,int v){
 if(u == none)
 {
  dpt =max(dpt,v);
  return;
 }
 checkd(u->lc,v+1);
 checkd(u->rc,v+1);
}
pt subtack(pt a,int x,int y,int pos){
 pt rt1 = none,rt2 = none,rt3=none,rt4=none,rt5 = none,rt6 = none,rt7=none,rt8 = none,rt9 = none;
 split(a,rt1,rt2,x);
 split(rt2,rt3,rt4,y-x+1);
 rt5 = merge(rt1,rt4);
 split(rt5,rt7,rt8,pos);
 rt9 = merge(rt7,rt3);
 opt = 0;
 rt6 = merge(rt9,rt8);
 if(opt >= 2)
  BREAKPOINT;
 return rt6;
}
pt subtack2(pt a,int x,int y){
 pt rt1 = none,rt2 = none,rt3 = none,rt4=none;
 split(a,rt1,rt2,x);
 split(rt2,rt3,rt4,y-x+1);
 pt ret =  none; ret = merge(rt1,rt4);
 return ret;
}
pt subtack3(pt a,pt b,int x){
 pt rt1 = none,rt2 = none,rt3 = none;
 split(a,rt1,rt2,x);
 rt3 = merge(rt1,b);
 pt ret= none;ret = merge(rt3,rt2);
 return ret;
}
void trace(pt a,int x){
 if(a->lc->size >= x)
  trace(a->lc,x);
 if(x == a->lc->size+1)
  printf("%d\n",a->key);
 if(x > a->lc->size+1)
  trace(a->rc,x-a->lc->size-1);
}
char str[MN];
int main(int argc, char *argv[])
{
    srand(clock());
    setIO("sample");
    init();
    pt rt1=none,rt2 = none;
    int n = gi,m=  gi;
    
    for(int i = 1;i<=n;++i) insert(rt1,gi);
    
    for(int i = 1;i<=m;++i)
    {
     if(i == 5000)
      i = 5000;
     scanf("%s",str);
     if(str[0] == 'E')
      break;
     if(str[0] == 'D')
     {
      int x = gi,y = gi;--x;--y;
      rt1 = subtack2(rt1,x,y);
     }
     if(str[0] == 'P'){
      int u = gi;
      trace(rt1,u); 
     }
     if(str[0] == 'I')
     {
      rt2 = none;
      int pos = gi,len = gi;
      //DEG_PIN_1_BEGIN
      for(int i = 1;i<=len;++i)
       insert(rt2,gi);
      //DEG_PIN_1_END
      rt1 = subtack3(rt1,rt2,pos);
     }
     if(str[0] == 'C')
     {
      //DEG_PIN_1_BEGIN
      int x = gi-1,y=  gi-1,z = gi;
      rt1 = subtack(rt1,x,y,z);
      //DEG_PIN_1_END
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
