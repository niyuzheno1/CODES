#include "mode.h"
#include "ptr.h"
#include "debug.h"
#define MN 510
struct sbt;
typedef ptr<sbt> pt;
struct sbt{
  int ref,size,key,time;
  pt lc,rc;
}None;
int gcnt,gtime;
pt none(&None);
pt newnode(int key){
 sbt * nd = new sbt;
 nd->ref = 0;nd->size = 1;nd->key = key;nd->lc = none;nd->rc = none;
 return pt(nd);
}
pt newnode(pt sou){
 if(sou->key == 0)
  return none;
 if(sou->time == gtime)
  return sou;
 return sou;
  ++gcnt;
 sbt * nd = new sbt;nd->time = gtime;
 nd->ref = 1;nd->size = sou->size;nd->key = sou->key;nd->lc = sou->lc;nd->rc = sou->rc;
 return pt(nd);
}
int rotime = 0,oprs = 0;
void rr(pt & u){
 ++rotime;
 pt newu = newnode(u);
 pt newk = newnode(u->lc);
 newu->lc = newk->rc;newk->rc = newu;
 newk->size = newu->size;newu->size = newu->lc->size+newu->rc->size+1;
 u = newk;
}
void lr(pt & u){
 ++rotime;
 pt newu = newnode(u);
 pt newk = newnode(u->rc);
 newu->rc = newk->lc;newk->lc = newu;
 newk->size = newu->size;newu->size = newu->lc->size+newu->rc->size+1;
 u = newk;
}
void mt(pt & t,bool flag){
 
 if(flag == false)
 {
  if(t->lc->lc->size > t->rc->size)
   rr(t);
  else{
   if(t->lc->rc->size > t->rc->size)
   {
    t = newnode(t);
    lr(t->lc);++oprs;
    rr(t);
   }
   else
    return ;
  }
 }
 else{
  if(t->rc->rc->size > t->lc->size)
   lr(t);
  else{
   if(t->rc->lc->size > t->lc->size)
   {
    t = newnode(t);
    rr(t->rc);++oprs;
    lr(t);
   }
   else
    return;
  }
 }
 ++oprs;
 mt(t->lc,true);
 mt(t->rc,true);
 mt(t,true);
 mt(t,false);
}
int d= 0;
void insert(pt & t,int v,int dd){
 if(t == none)
 {
  t = newnode(v);
  d = dd;
  return;
 }else{
  pt  newt = newnode(t);
  ++newt->size;
  if(v < newt->key) insert(newt->lc,v,dd+1);
  else insert(newt->rc,v,dd+1);
  if(d >= 1)
   mt(newt,v>=newt->key);
  t = newt;
 }
}
void pri(pt u){
 if(u == none)
  return;
 pri(u->lc);
 ff(debug,"size:%d key:%d lkey:%d rkey:%d\n",u->size,u->key,u->lc->key,u->rc->key);
 pri(u->rc);
}
void dpri(pt u){
 pri(u);
ff(debug,"global property : rotate times:%d  persistent times:%d",rotime,gcnt);
}
pt hto[MN];
int main(int argc, char *argv[])
{
    srand(clock());
    setIO("sample");
    None.size = 0,None.lc = none;None.rc = none;none->ref = 10;
    pt rt = none;gtime = 1;
    int lastgcnt = 0;
    DEG_PIN_1_BEGIN
    for(int i = 1; i<=1000;++i){
     oprs = 0;
     //++gtime;
    // hto[i] = rt;
     /*if(i==3)
      i = 3;*/
     //rt = newnode(rt);
     //int u = rand()%129+1;
     oprs = 0;
     insert(rt,i,1);
     if(oprs >= 2)
      BREAKPOINT;
     //ff(debug,"%d\n",gcnt-lastgcnt);
     lastgcnt = gcnt;
    }
    DEG_PIN_1_END
    ff(debug,"%d",rotime);
    /*for(int i = 1;i<=100;++i){
     ff(debug,"when %d:\n",i);
     pri(hto[i]);
    }
    ff(debug,"now:\n");*/

    closeIO();
    return EXIT_SUCCESS;
}
