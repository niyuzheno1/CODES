#include "mode.h"
#define MM 200005
#define MN 100005
struct edge{int v,w,f,n;};
int st[MN],tot,d[MN],pos[MM],pe[MM],pre[MM],suf[MM],rt[MM],n,m,l;
int vis[MN],occur[MN],id,stk[MN],val[MN],top;
edge lk[MM];
typedef priority_queue<pii,vector<pii>,greater<pii> > pq;
pq Q;
void add(int x,int y,int z){
 ++tot;lk[tot].v = y;lk[tot].n = st[x];lk[tot].w = z;st[x] = tot;
}
queue<int> q;
void spfa(int ds,int s,int lim){
 CLEAR(vis,0);
 ++id;d[s] = ds;
 q.push(s);vis[s] = 1;
 while(!q.empty()){
  int u = q.front();q.pop();
   TRA(i,u)
   {
    int v = lk[i].v;
    if(v == 112)
     v = 112;
    if(pos[v] > lim){
              if(occur[v] != id){
                 occur[v] = id;
                 stk[++top] = v;
                 val[v] = d[u]+lk[i].w+suf[pos[v]];
              }
              else
               val[v] = min(val[v],d[u]+lk[i].w+suf[pos[v]]);
    }else if(d[u]+lk[i].w<d[v]){
          d[v]= d[u]+lk[i].w;
          if(vis[v]) continue;
          vis[v]=1;q.push(v);
    }
   }
  vis[u] = 0;
 }
 while(top){
 Q.push(MP(val[stk[top]],stk[top]));
 --top;
 }
}
void solve(){
     CLEAR(d,0x7f);
     d[1] = 0;
     for(int i = 1;i<=l;++i){
      lk[rt[i]].f ^= 1;
      spfa(pre[i],pe[i],i);
      lk[rt[i]].f ^= 1;
      int u = 0,v = Q.top().X;
      while(!Q.empty()&&pos[u=Q.top().Y]<=i) {
                                           
                                           Q.pop();
      }
      if(Q.empty()) puts("-1");
      else printf("%d\n",Q.top().X);
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");CLEAR(st,0xff);
    n = gi,m = gi,l = gi;
    for(int i = 1,u,v,w;i<=m;u=gi,v=gi,w=gi,add(u,v,w),++i);
    pos[1]=1,pe[1]=1;
    for(int i = 1;i<=l;rt[i]=gi,pe[i+1]=lk[rt[i]].v,pos[lk[rt[i]].v]=i+1,++i);
    for(int i = 1;i<=l;++i)pre[i+1] = pre[i] + lk[rt[i]].w;
    for(int i = l;i>=1;--i)suf[i] = suf[i+1]+lk[rt[i]].w;
    solve();
    closeIO();
    return EXIT_SUCCESS;
}
