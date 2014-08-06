#include "mode.h"
#include "data.h"
#define DISCRETE(u) for(int i = 1;i<=n;++i)t[i] = a[i].u;sort(t+1,t+1+n);for(int i = 1;i<=n;++i) b[i].u = lower_bound(t+1,t+1+n,a[i].u)-t;
struct p { double x,y,z,w,p;};
struct q { int x,y,z,w,p;};
#define MN  30000
p a[MN];
q b[MN];
double t[MN];
int n,m,c[MN],ans[MN],d1[MN],d2[MN];;
struct spl{ int C[3]; };
spl tr[MN];int sum[MN],cnt[MN];
#define S(_x) sum[_x]
#define C(_x) cnt[_x]
inline void upd(int x){if(!x)return;S(x) = S(tr[x].L)+S(tr[x].R)+1;}
void rotate(int x)
{
 int y = tr[x].F,z = tr[y].F,d1 = (tr[y].L==x),d2 = (tr[z].R==y);
 tr[y].C[!d1] = tr[x].C[d1],tr[tr[y].C[!d1]].F = y,tr[x].C[d1] = y,tr[y].F = x,tr[z].C[d2] = x,tr[x].F = z;
 upd(y);upd(x);upd(z);
}
void splay(int x,int rt)
{
     while(tr[x].F != rt){
      int y = tr[x].F,z = tr[y].F;
      if(z!= rt && ((y == tr[z].L)==(tr[y].L == x))) rotate(y);
      rotate(x);
     }
}
void ins(int & x,int y)
{
 ++SIZE(cnt);sum[SIZE(cnt)] = 1,cnt[SIZE(cnt)] = y;
 if(x == 0) x = SIZE(cnt);
 else{
 int u = x,v = 0;
  while(u != 0)
  {
   ++S(u);
   if(y <= C(u))v = u,u = tr[u].L;else v = u,u = tr[u].R;
  }
 tr[SIZE(cnt)].F = v;
 tr[v].C[y > C(v)] = SIZE(cnt);
 splay(SIZE(cnt),0),x = SIZE(cnt);
 }
}
int find(int & x,int y)
{
 ++y;
 if(x == 0) return 0;
 else
 {
  int u = x,v = 0;
  while(u != 0){
   if(y <= C(u)) v = u,u = tr[u].L;  else v = u,u = tr[u].R;
  }
  splay(v,0);x = v;
  return S(tr[v].L)+(C(v)<y)?1:0;
 }
}
struct fenwick{
 int rt[MN];
 fenwick()
 {
  CLEAR(rt,0);
 }
 void insert(int x,int y)
 {
  while(x <=n) ins(rt[x],y),x+= lb(x);
 }
 int updata(int x,int y)
 {
  int ret = 0;
  while(x > 0) ret += find(rt[x],y),x-= lb(x);
  return ret;
 }
};
bool cmp(int x,int y){return b[x].x < b[y].x;}
fenwick* solve(int l,int r,int _l,int _r)
{
 if(r < l) 
  return (fenwick*)NULL;
 if(l == r || _l == _r){
  fenwick * ret = new fenwick;
  for(int i = l;i<=r;++i)
   if(!b[c[i]].p) 
    ret->insert(b[c[i]].z,b[c[i]].w);
  for(int i = l;i<=r;++i)
   if(b[c[i]].p) 
   ans[b[c[i]].p] += ret->updata(b[c[i]].z,b[c[i]].w);
  return ret;
 }
 int mid = (_l+_r)/2;
 SIZE(d1)=SIZE(d2)=0;
 for(int i = l;i<=r;++i) 
  if(b[c[i]].y <= mid) ++SIZE(d1),d1[SIZE(d1)]=c[i];
  else ++SIZE(d2),d2[SIZE(d2)]=c[i];
 int nmid = l+SIZE(d1)-1;
 for(int i = l;i<=nmid;++i) c[i] = d1[i-l+1];
 for(int i = nmid+1;i<=r;++i) c[i] = d2[i-nmid];
 fenwick * fl = solve(l,nmid,_l,mid);
 fenwick * fr = solve(nmid+1,r,mid+1,_r);
 if(fl != NULL)
 {
  for(int i = nmid+1;i<=r;++i) 
   if(b[c[i]].p) 
   ans[b[c[i]].p] += fl->updata(b[c[i]].z,b[c[i]].w);
  for(int i = nmid+1;i<=r;++i) 
   if(b[c[i]].p == 0) 
    fl->insert(b[c[i]].z,b[c[i]].w);
  if(fr != NULL) delete fr;
  return fl;
 }
 else return fr;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d",&n);
    for(int i = 1;i<=n;++i) scanf("%lf %lf %lf %lf",&a[i].x,&a[i].y,&a[i].z,&a[i].w),b[i].p = 0;
    scanf("%d",&m);
    ++n;
    for(int i = 1;i<=m;++n,++i) scanf("%lf %lf %lf %lf",&a[n].x,&a[n].y,&a[n].z,&a[n].w),b[n].p = i;
    --n;
    DISCRETE(x);DISCRETE(y);DISCRETE(z);DISCRETE(w);
    for(int i = 1;i<=n;++i) c[i] = i;
    sort(c+1,c+1+n,cmp);
    solve(1,n,1,n);
    for(int i = 1;i<=m;++i) printf("%d\n",ans[i]);
    closeIO();
    return EXIT_SUCCESS;
}
