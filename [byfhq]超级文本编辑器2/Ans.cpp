#include "mode.h"
#include "ptr.h"
#include "debug.h"
#define MM 1010*2
#define MC 100010
struct sbt;
typedef ptr<sbt> pt;
struct sbt{
  int ref,size,key,time;
  pt lc,rc;
}None;
int gcnt,gtime;
pt none(&None);
pt newnode(int key){
 sbt * nd = new sbt;nd->time = 0;
 nd->ref = 0;nd->size = 1;nd->key = key;nd->lc = none;nd->rc = none;
 return pt(nd);
}
pt newnode(pt a){
++gcnt;
 if(a->key == 0) return none;
 if(a->time == gtime)
  return a;
 sbt * nd = new sbt;nd->time = gtime;
 nd->ref = 0;nd->size = a->size;nd->key = a->key;nd->lc = a->lc;nd->rc = a->rc;
 return pt(nd);
}
int norm;
void rr(pt & newu){
 pt newk = none;
 if(!norm){
 newu = newnode(newu);
 newk = newnode(newu->lc);
 }else
  newk = newu->lc;
 newu->lc = newk->rc;newk->rc = newu;
 newk->size = newu->size;newu->size = newu->lc->size+newu->rc->size+1;
 newu = newk;
}
void lr(pt & newu){
 pt newk = none;
 if(!norm){
 newu = newnode(newu);
 newk = newnode(newu->rc);
 }else
  newk = newu->rc;
 newu->rc = newk->lc;newk->lc = newu;
 newk->size = newu->size;newu->size = newu->lc->size+newu->rc->size+1;
 newu = newk;
}
void mt(pt & t,bool flag){
 if(flag == false)
 {
  if(t->lc->lc->size > t->rc->size)
   rr(t);
  else{
   if(t->lc->rc->size > t->rc->size){if(!norm)t=newnode(t);lr(t->lc);rr(t);}
   else
    return ;
  }
 }
 else{
  if(t->rc->rc->size > t->lc->size) lr(t);
  else{
   if(t->rc->lc->size > t->lc->size) {if(!norm)t=newnode(t);rr(t->rc);lr(t);}
   else
    return;
  }
 }
 if(!norm)
 t = newnode(t);
 mt(t->lc,true);
 mt(t->rc,true);
 mt(t,true);
 mt(t,false);
}
void init()
{
     None.size = 0,None.lc = none;None.rc = none;none->ref = 10;
}
void upd(pt & a){
 a->size = a->lc->size+a->rc->size+1;
}
pt merge(pt & a,pt & b){
 if(a == none ) return b;
 if(b == none ) return a;
 if(a->rc->size + b->size < a->lc->size)
 {
  a = newnode(a);
  a->rc = merge(a->rc,b);
  upd(a->rc);upd(a);
  mt(a,1);
  return a;
 }
 else{
  b = newnode(b);
  b->lc = merge(a,b->lc);
  upd(b->lc);upd(b);
  mt(b,0);
  return b;
 }
}
void split(pt a,pt & b,pt & c,int x){
 if(x == 0)
  b = none,c = a;
 else if(x == a->size)
  b = a,c = none;
 else{
  if(a->lc->size >= x){
   c = newnode(a);
   split(a->lc,b,c->lc,x);
   mt(c,0);
   upd(c);
  }
  else{
   b = newnode(a);
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
 printf("%c",u->key);
 pri(u->rc);
}
vector<pt> ll;
pt subtack(pt rt,int x,int a){
 pt rt1 = none,rt2=none,rt3 = none;
 split(rt,rt1,rt2,x);
 ll.pb(newnode(a));
 rt3 = merge(rt1,ll.back());
 return merge(rt3,rt2);
}
pt subtack2(pt rt,int x,int y){
 --x;--y;
 pt rt1 = none,rt2 = none,rt3 = none,rt4=none;
 split(rt,rt1,rt2,x);
 split(rt2,rt3,rt4,y-x+1);
 return merge(rt1,rt4);
}
pt subtack3(pt a,int x,int y,int z){
 --x;--y;
 pt rt[9];
 for(int i =1;i<=8;++i)
  rt[i] = none;
 split(a,rt[1],rt[2],x);
 split(rt[2],rt[3],rt[4],y-x+1);
 split(a,rt[5],rt[6],z);
 rt[7] = merge(rt[5],rt[3]);
 rt[8] = merge(rt[7],rt[6]);
 return rt[8];
}
pt h[MM];
int sum,m;
void hcal(pt a){
 if(sum == 2*m)
 {
  for(int i = 1;i<=m;++i) h[i] = h[i+m];
  for(int i = 1;i<=m;++i) h[i+m] = none;
  sum -= m;
 }
 h[++sum] = a;
}
void subtack4(pt a,int x,int y){
 --x;--y;
 pt rt[9];
 for(int i =1;i<=8;++i)
  rt[i] = none;
 split(a,rt[1],rt[2],x);
 split(rt[2],rt[3],rt[4],y-x+1);
 pri(rt[3]);puts("");
}
char str [MC];
pt now;
char opt[6];
int main(int argc, char *argv[])
{
    setIO("sample");
    init();
    now = none;
    gtime = 0;
    m = gi;
    gets(str);
    for(int i = 0;i<strlen(str);++i){
     ll.pb(newnode(str[i]));
     now = merge(now,ll.back());
    }
    while(~scanf("%s",opt)){
     ++gtime;
     if(opt[0] == 'I')
     {
      int x = gi; scanf("%s",opt);
      now=subtack(now,x,opt[0]);
      hcal(now);
     }
     if(opt[0] == 'D')
     {
      int x = gi,y = gi;
      now=subtack2(now,x,y);
      hcal(now);
     }
     if(opt[0] == 'C')
     {
      int x = gi,y = gi,z=gi;
      now=subtack3(now,x,y,z);
      hcal(now);
     }
     if(opt[0] == 'P')
     {
      int x = gi, y = gi , z = gi;
      int t = sum-x;ff(debug,"%d\n",sum-x);
      subtack4(h[t],y,z);
     }
    }
    ff(debug,"%d\n",gcnt);
    closeIO();
    return EXIT_SUCCESS;
}
