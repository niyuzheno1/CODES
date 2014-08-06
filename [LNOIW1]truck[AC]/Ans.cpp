#include "mode.h"
#include "data.h"
int tttt[5];
typedef pair<double,double> pdd;
#define MN 500010*4
#define MV 500010
const double dinf = ~0ULL>>1;
struct info{
       double s[4];
       info() {CLEAR(s,0);}
};
info sgt[MN];
int o1[MN],o2[MN];
#define tot tttt[0] //segment tree tot
#define LCH(_t) o1[_t]
#define RCH(_t) o2[_t]
#define con(i) rt[i],1,MV
info operator + (const info & a,const info & b){
 info tmp;   
 for(int i = 0;i<=3;++i)
 tmp.s[i] = a.s[i]+b.s[i];    
 return tmp;
}
void add(TREE2,int x,double v){
 M;
 ++tot;
 o1[tot] = o1[_t];o2[tot] = o2[_t];sgt[tot] = sgt[_t];
 _t = tot;
 if(_l == _r) {
        sgt[_t].s[1] += v/double(x),sgt[_t].s[2] += v; 
 return;}
 if(x <= mid) add(LEFT,x,v);else add(RIGHT,x,v);
 sgt[_t] = sgt[LCH(_t)] + sgt[RCH(_t)];
}
double query(TREE,int l,int r,int flag){
 M;
 if(_t == 0) return 0.0;
 if(l<=_l && _r <= r) return sgt[_t].s[flag];
 double ans = 0.0;
 if(l <= mid) ans += query(LEFT,l,r,flag);
 if(r > mid) ans += query(RIGHT,l,r,flag);
 return ans;
}
#undef tot
#undef MN
#define MM 100010*2
#define MN 100010
#define ML 20
int rt[MN],f[MN][ML+1],stk[MN],st[MN],n,m,q,vst[MN],fa[MN],dep[MN];
struct _edge{
 int n,v,f,len,x;
 bool cir;
};
struct lv{ 
 int v,w;
}a[MN];
_edge lk[MM];
#define tot tttt[1]
void ad(int x,int y,int z,int w){
     lk[tot].v = y;lk[tot].len = z,lk[tot].x = w;lk[tot].n = st[x];st[x] = tot;
     ++tot;
}
#undef tot
void addedge(int x,int y,int z,int w){
   ad(x,y,z,w);ad(y,x,z,w);
}
void mkcir(int x,int y)
{
 while(lk[x^1].v != y){
  lk[x^1].cir = lk[x].cir = 1;
  x = fa[lk[x^1].v];
 }
 lk[x^1].cir = lk[x].cir = 1;
}
int fd = 0;
int aa,bb,de;
void dfs(int x,int u){
 vst[x] = 1;
 TRA(i,x){
  if(vst[lk[i].v]  && !fd)
   mkcir(u,lk[i].v),lk[i].cir=lk[i^1].cir=1,lk[i].f =lk[i^1].f=1,de= i,aa = lk[i].v,bb = lk[i^1].v,fd = 1;
  if(!fd){
   fa[lk[i].v] = i;
   lk[i^1].f = 1;
   dfs(lk[i].v,i);
  }
 }
}
#define top tttt[4]
void dfs(int x){
 if(x == 3) 
  x = 3;
 int u = 0;
 ++top;stk[top] = x;
 while(top - (1<<u) > 0) {f[x][u] = stk[top-(1<<u)]; ++u; }
 rt[x] = rt[f[x][0]];
 add(con(x),a[lk[fa[x]].x].v,double(a[lk[fa[x]].x].w)*double(lk[fa[x]].len));
 TRA(i,x){
   lk[i^1].f = 1;
   fa[lk[i].v] = i;
   dep[lk[i].v] = dep[x]+1;
   dfs(lk[i].v);
 }
 --top;
}
#undef top
int lca(int x,int y){
 if(dep[x] > dep[y]) swap(x,y);
 for(int i = ML;i>=0;--i)
  if(dep[x] <= dep[f[y][i]])
   y = f[y][i];
 while(dep[f[y][0]] > dep[x]) y = f[y][0];
 if(y == x) return x;
 for(int i = ML;i>=0;--i)
  if(f[x][i] != f[y][i])
   x = f[x][i],y = f[y][i];
 while(x != y) x=f[x][0],y = f[y][0];
 return x;
}
void query(int x,int y,int u){
 double ans = dinf;
 double r3 = double(lk[de].len)*double(a[lk[de].x].w)/min(double(u),double(a[lk[de].x].v));
 //case 1
  int z = lca(x,y);
  double r1 = query(con(x),1,u,1)+query(con(y),1,u,1)-query(con(z),1,u,1)*2/*-query(con(f[y][0]),1,u,1)*/;
  double r2 = query(con(x),u+1,MV,2)+query(con(y),u+1,MV,2)-query(con(z),u+1,MV,2)*2;
  r2 /= double(u);
  ans = min(r1+r2,ans);
 //case 2
  z = lca(x,aa);
  int w = lca(y,bb);
  r1 = query(con(x),1,u,1)+query(con(aa),1,u,1)+query(con(bb),1,u,1)
   +query(con(y),1,u,1)-query(con(z),1,u,1)*2-query(con(w),1,u,1)*2;
  r2 = query(con(x),u+1,MV,2)+query(con(aa),u+1,MV,2)+query(con(bb),u+1,MV,2)
   +query(con(y),u+1,MV,2)-query(con(z),u+1,MV,2)*2-query(con(w),u+1,MV,2)*2;
  r2 /= double(u);
  ans =min(r1+r2+r3,ans);
 //case 3
 z = lca(y,aa);
 w = lca(x,bb);
  r1 = query(con(x),1,u,1)+query(con(aa),1,u,1)+query(con(bb),1,u,1)
   +query(con(y),1,u,1)-query(con(z),1,u,1)*2-query(con(w),1,u,1)*2;
  r2 = query(con(x),u+1,MV,2)+query(con(aa),u+1,MV,2)+query(con(bb),u+1,MV,2)
   +query(con(y),u+1,MV,2)-query(con(z),u+1,MV,2)*2-query(con(w),u+1,MV,2)*2;
 r2 /= double(u);
 ans =min(r1+r2+r3,ans);
 printf("%.7f\n",ans);
}
int main(int argc, char *argv[])
{
    setIO("sample");CLEAR(st,0xff);
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1;i<=n;++i){
    int x,y,z,w;
    scanf("%d%d%d%d",&x,&y,&z,&w);
    addedge(x,y,z,w);
    }
    for(int i = 1;i<=m;++i)
     scanf("%d%d",&a[i].v,&a[i].w);
    dfs(1,-1);
    dep[1] = 1;
    dfs(1);
    #define de debug
    for(int i = 1;i<=n;++i){
     ff(de,"%.8f %.8f\n",sgt[rt[i]].s[1],sgt[rt[i]].s[2]);
    }
    for(int i = 1;i<=q;++i){
     int s,t,u;
     scanf("%d%d%d",&s,&t,&u);
     query(s,t,u);
    }
    closeIO();
    return EXIT_SUCCESS;
}
