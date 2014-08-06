#include "mode.h"
/*
标记下放时注意关系 
*/
#undef INF 
#define MN 1005
#define MM 100005
#define T1 int k,int l,int r
#define M int mid = (l+r)>>1;
#define gol (k<<1),l,mid
#define gor (k<<1)+1,mid+1,r
#define con 1,1,n
#define sampar1 int x,y,w,v,p,q;\
     scanf("%d%d%d%d%d%d",&x,&y,&w,&v,&p,&q);\
addedge(x,y,w,v,p,q);\
\


const int INF = 0x2f2f2f2f;
struct _edge{int x,to,n,w,v,p,q;};
_edge lk[MM];
struct info{
       int w,add;
};
info T[MM];
struct fe{int v,n,f,c;};
fe e[MM];
int n,m,q;
int cnt = 0,h[MN],ct= 0,r[2*MN],pos[MM];
int num = 0,size[MN],dep[MN],top[MN],prt[MN*2],son[MN],Pos[MM],rank[MN],val[MN];
int s=1,vst[MN*2],Prt[MN*2],to[MN*2],dis[MN*2];
int sum = 0;
void operator >> (const info & a,info & b){b.add += a.add;b.w += a.add;}
void addedge(int x,int y,int w,int v,int p,int q){
 lk[++cnt] = (_edge){x,y,h[x],w,v,p,q};
 h[x] = cnt;
}
void addflow(int x,int y,int c,int v,int k){
 e[++ct] = (fe) {y,r[x],c,v};
 r[x] = ct,Pos[ct] = ct+k;
}
void add(int x,int y,_edge e){
 addflow(x,y,e.w,-e.p+e.v,1);
 addflow(y,x,0,e.p-e.v,-1);
 addflow(x,y,INF,e.q+e.v,1);
 addflow(y,x,0,-e.q-e.v,-1);
}
void dfs1(int x,int f){
 size[x] = 1;dep[x] = dep[f]+1;prt[x] = f;
 for(int i = h[x];i;i=lk[i].n){
  int y = lk[i].to;
  val[y] = lk[i].w;
  dfs1(y,x);
  size[x] += size[y];
  if(size[y] > size[son[x]]) son[x] = y;
 }
}
void dfs2(int x,int f){
 pos[x] = ++num;
 rank[num] = x;
 top[x] = (son[f] == x)?top[f]:x;
 if(son[x]) dfs2(son[x],x);
 for(int i = h[x];i;i=lk[i].n){
  int y = lk[i].to;
  if(y == son[x]) continue;
  dfs2(y,x);
 }
}
void bdsg(T1){
 M;
 if( l== r) return (void)(T[k].w=val[rank[l]]);
 bdsg(gol);bdsg(gor);
}
void down(int k){
 if(!T[k].add) return;
 T[k]>>T[k<<1];
 T[k]>>T[(k<<1)+1];
 T[k].add = 0;
}
void upd(T1,int L,int R,int c){
 M;
 if(L <= l && r <= R){
  ((info){c,c})>>T[k];
  return;
 }
 down(k);
 if(mid >= L) upd(gol,L,R,c);
 if(mid < R) upd(gor,L,R,c);
}
void modify(int x,int y,int c){
 while(top[x] != top[y]){
  if(dep[top[x]] > dep[top[y]]) swap(x,y);
  upd(con,pos[top[y]],pos[y],c);
  y = prt[top[y]];
 }
 if(x == y) return;
 if(dep[x] > dep[y]) swap(x,y);
 upd(con,pos[x]+1,pos[y],c);
}
void refresh(T1){
 M;
 if(l==r) return (void)(val[rank[l]] = T[k].w);
 down(k);
 refresh(gol);
 refresh(gor);
}
#define pos Pos
#define prt Prt
void bfs()
{
     queue<int> Q;
     ct = 0;
     CLEAR(r,0);
     Q.push(1);
     while(!Q.empty())
     {
      int x = Q.front();Q.pop();
      for(int i = h[x];i;i=lk[i].n)
       if(i <= n-1)
       {
        int y = lk[i].to;
        lk[i].w= max(0,val[y]);
        sum += lk[i].w*lk[i].p;
        add(lk[i].x,lk[i].to,lk[i]);
        Q.push(y);
       }
     }
     for(int i = n;i<=m;++i)
      sum += lk[i].w*lk[i].p,add(lk[i].x,lk[i].to,lk[i]);
}
void spfa()
{
     deque<int> Q;
     CLEAR(vst,0);CLEAR(Prt,0);CLEAR(to,0);
     for(int i = 1;i<=n;++i)dis[i] = INF;
     dis[s] = 0,vst[s] = 1;
     Q.pb(s);
     while(!Q.empty()){
      int x = Q.front();Q.pop_front();
      vst[x] = 0;
      for(int i = r[x];i;i=e[i].n){
       int y = e[i].v;
       if(e[i].f && dis[y] > dis[x]+e[i].c)
       {
        dis[y] = dis[x]+e[i].c;
        prt[y] = x;
        to[y] = i;
        if(!vst[y]){
         vst[y] = 1;
         if(!Q.empty()){
          if(dis[y] > dis[Q.front()]) Q.pb(y);
          else Q.push_front(y);
         }
         else Q.pb(y);
        }
       }
      }
     }
}
int costflow(int s,int t,int rate){
  if(s == t) return 0;
  int cost =0,delta;
  while(rate){
   spfa();
   if(dis[t] >= INF) break;
   delta = INF;
   for(int x=t;x!=s;x=prt[x]) delta =min(delta,e[to[x]].f);
   if(delta > rate) delta = rate;
   cost += dis[t]*delta;
   rate -= delta;
   for(int x=t;x!=s;x=prt[x]){
   e[to[x]].f -=delta;
   e[pos[to[x]]].f += delta;
   }
  }
  return cost;
}
void query(int t,int rate){
 sum = 0;
 refresh(con);
 bfs();
 printf("%d\n",sum+costflow(s,t,rate));
}
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n-1;++i){
     sampar1;
     
    }
    dfs1(1,1);
    dfs2(1,1);
    bdsg(con);
    for(int i = 1;i<=m;++i){
     sampar1;
    }
    m+=n-1;
    int Q;scanf("%d",&Q);
    for(int i = 1;i<=Q;++i){
     char o;
     while(o =getchar()) if(o == 'C' || o == 'Q') break;
     int x,y,w;
     if(o == 'C') scanf("%d%d%d",&x,&y,&w),modify(x,y,w);
     else scanf("%d%d",&x,&w),query(x,w);
    }
    closeIO();
    return EXIT_SUCCESS;
}
