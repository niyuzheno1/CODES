#include "mode.h"
typedef long long ll;
const ll MR  = ~0ULL>>1;
#define MN 100000
#define MM 500000
struct number{
  ll id;
  number * lx , * rx;
  int pri;
  number * lc , * rc;
};
number np[MM],*nt = np;
template<class T>
int cmpT(const T & a,const T & b){
  if(a < b)
   return -1;
  else if(a > b)
   return 1;
  else 
   return 0;
}
int ncmp(const number * lhs ,const number * rhs){
 return cmpT(lhs?lhs->id:0,rhs?rhs->id:0);
}
int numxcmp(const number * lhs,const number * rhs){
  if(!lhs && !rhs) return 0;
  if(!lhs) return -1;
  if(!rhs) return 1;
  int c = ncmp(lhs->lx,rhs->lx);
  if(c == 0)  c = ncmp(lhs->rx,rhs->rx);
  return c;
}
number * rt;
number * tisp;
ll tispl,tispr;
#include "data.h"

void treapins(number * & p,ll pl,ll pr,number * np){
   if(!p )
   {
    tisp = p = np;
    np->lc = np->rc = NULL;
   }
   else{
     int c = numxcmp(np,p);
     if(c < 0){
      treapins(p->lc,pl,p->id-1,np);
      if(p->lc->pri < p->pri) zig(p);
     }
     else if(c > 0)
     {
      treapins(p->rc,p->id+1,pr,np);
      if(p->rc->pri < p->pri)
       zag(p);
     }
     else
      tisp = p;
   }
   if(p == np)
    tispl = pl,tispr = pr;
}
void relabl(number * p,ll pL,ll pR)
{
      p->id = pL+(pR-pL)/2;
      if(p->lc)
       relabl(p->lc,pL,p->id-1);
      if(p->rc)
       relabl(p->rc,p->id+1,pR);
}
number * tins(number * np)
{
       treapins(rt,1,MR,np);
       if(np == tisp)
        relabl(np,tispl,tispr);
       return tisp;
}
int n,m;
number * a[MN+1];
int seg[MN*4+1];
int a_max(int i,int j){
 return ncmp(a[i],a[j]) >= 0?i:j;
}
void upd(int p)
{
 seg[p] = a_max(seg[p<<1],seg[(p<<1)+1]);
}
void build(int t,int l,int r){
 if(l == r)
  seg[t] = l;
 else
 {
  int mid = (l+r)/2;
  build(t*2,l,mid);
  build(t*2+1,mid+1,r);
  upd(t);
 }
}
void change(int t,int l,int r,int q)
{
     if(l == r)
     {
      seg[t] = l;
      return;
     }
     int mid = (l+r)/2;
     if(q <= mid )
      change(t*2,l,mid,q);
     else
      change(t*2+1,mid+1,r,q);
     upd(t);
}
int query(int p,int l,int r,int ql,int qr){
 if(ql <= l && r <= qr)
  return seg[p];
 int mid = (r+l)/2;
 bool nul = 1;
 int res = 0,tmp = 0;
 if(ql <= mid)
  res = query(2*p,l,mid,ql,qr),nul = 0;
 if(mid < qr){
  tmp = query(2*p+1,mid+1,r,ql,qr);
  if(!nul)
   res = a_max(res,tmp);
  else
   res = tmp;
 }
 return res;
}
void init()
{
 build(1,1,n);
 rt = NULL;
}
void change(int l,int r,int k){
  if(k == 3)
   k =3;
  nt->lx = a[l],nt->rx = a[r];
  nt->pri = rand();
  a[k] = tins(nt);
  if(a[k] == nt) ++nt;
  change(1,1,n,k);
}
int query(int l,int r){
 return query(1,1,n,l,r);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    srand(19961028);
    n = gi,m = gi;
    for(int i = 1;i<=n;++i) a[i] = NULL;
    init();
    while(m--){
     char tp = getchar();
     while(tp != 'C' && tp != 'Q') tp = getchar();
     if(tp == 'C')
     {
      int l= gi,r = gi,k = gi;
      change(l,r,k);
     }
     else if(tp == 'Q')
     {
      int l = gi,r = gi;
      printf("%d\n",query(l,r));
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
