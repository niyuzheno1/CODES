#include "mode.h"
#undef MP
#undef INF
#define MM 800005
#define MN 400005
#define MP 200005
#define TRA1(x,y) for(int x = g.st[y];~x;x = g.lk[x].n) if(!g.lk[x].f)
#define TRA2(x,y) for(int x = rg.st[y];~x;x = rg.lk[x].n) if(!rg.lk[x].f)
const int INF = 0x2f2f2f2f;
struct _Gp{
 struct _edge{
 int n,v,f;
 };
 _edge lk[MM];
 int st[MN],tot;
 void init(){tot=0,CLEAR(st,0xff);}
 void add(int x,int y){
  ++tot;lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;
 }
};
_Gp g,rg;
int n,m;
int sign = 0,scc = 0,top = 0,dfn[MP],low[MP],stk[MP],instk[MP],blk[MP];
int deg[MN],mat[MN],dis[MN],Q[MN];
struct lis{
 int L[MN],R[MN],H[MN];
 void add(int v){
  int idx = deg[v];
  R[v] = H[idx];
  if(R[v]) L[R[v]] = v;
  L[v] = 0;
  H[idx] = v;
 }
 void erase(int v){
  int idx = deg[v];
  if(L[v]) R[L[v]] = R[v];
  else H[idx] = R[v];
  if(R[v])L[R[v]] = L[v];
  L[v] = R[v] = 0;
  }
}T;
void dfs(int u ){
 dfn[u] = low[u] = ++sign;
 stk[++top] = u;instk[u] = 1;
 TRA1(i,u)
 {
 int v = g.lk[i].v;
  if(!dfn[v]) dfs(v),low[u] = min(low[u],low[v]);
  else if(instk[v]) low[u] = min(low[u],dfn[v]);
 }
 if(dfn[u] == low[u])
 {
  ++scc;
  int k;
  do{
       k = stk[top--],instk[k] = 0,blk[k] = scc; 
  }while(k != u);
 }
}
bool bfs(){
 CLEAR(dis,INF);
 int ed = 0;
 for(int i  = 1;i<=scc;++i)
  if(!mat[i]) dis[Q[ed++] = i]=0;
 for(int l = 0;l<ed;++l){
  int u = Q[l];
  TRA2(i,u){
   int v = rg.lk[i].v;
   if(dis[mat[v]] == INF)
   {
    dis[mat[v]] = dis[u]+1;
    Q[ed++] = mat[v];
   }
  }
 }
 return dis[0] < INF;
}
bool find(int u){
 TRA2(i,u){
   int v = rg.lk[i].v;
   if(dis[mat[v]] == dis[u]+1)
    if(!mat[v] || find(mat[v]))
    {
     mat[u] = v;
     mat[v] = u;
     return true;
    }
 }
 dis[u] = INF;
 return false;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    g.init();rg.init();
    scanf("%d%d",&n,&m);
    for(int i = 1,x,y;i<=m;++i){
     scanf("%d%d",&x,&y);g.add(x,y);
    }
    for(int i = 1;i<=n;++i) 
     if(!dfn[i]) dfs(i);
    for(int u = 1;u<=n;++u)
     TRA1(i,u)
     {
      int v = g.lk[i].v;
      if(blk[u] == blk[v]) continue;
      rg.add(blk[u],blk[v]+scc);
      rg.add(blk[v]+scc,blk[u]);
      ++deg[blk[u]];++deg[blk[v]+scc];
     }
    for(int i = 1;i<=(scc<<1);++i) T.add(i);
    int ans = 0;
    for(int k = 1;k<=scc;){
     if(!T.H[k]){++k;continue;}
     int u = T.H[k],minx = 0,mind = INF;
     TRA2(i,u)
     {
              int v = rg.lk[i].v;
              if(mat[v]) continue;
              if(deg[v] < mind) mind=deg[v],minx = v;
              T.erase(v);
              --deg[v];
              T.add(v);
     }
     T.erase(u);
     
     if(minx)
     {
      T.erase(minx);
      mat[u] = minx,mat[minx] = u,++ans;
      TRA2(i,minx){
       int v = rg.lk[i].v;
       if(mat[v]) continue;
       T.erase(v);
       --deg[v];
       T.add(v);
      }
      if(k > 1) --k;
     }
    }
    
    while(bfs()){
     for(int i = 1;i<=scc;++i)
      if(!mat[i] && find(i)) 
      ++ ans;
    }
    printf("%d\n",scc-ans);
    closeIO();
    return EXIT_SUCCESS;
}
