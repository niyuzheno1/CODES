#include "mode.h"
#define MN 200010
#define mod 99990001
typedef int64 LL;
struct edge{
       int u,v,w,id;
       edge(){}
       edge(int to,int i):v(to),id(i){}
}edges[MN+1];
int n;
list<edge> G[MN];
int comp[MN],add[MN*2],mul[MN*2];
int visflag = 0,vis[MN],lst[2][MN],len[2],isdel[MN],totN;
void calc(int id){
 isdel[id] = 1;
 int cmp = comp[edges[id].u];
 int weight = (LL(mul[cmp])*edges[id].w + add[cmp])%mod;
 queue<int> Q[2];
 Q[0].push(edges[id].u);Q[1].push(edges[id].v);
 vis[edges[id].u] = vis[edges[id].v] = ++visflag;
 len[0] = len[1] = 1;
 lst[0][0] = edges[id].u,lst[1][0] = edges[id].v;
 int Min[2];Min[0] = edges[id].u,Min[1] = edges[id].v;
 int u[2];u[0] = u[1] = -1;
 bool isfin = 0;
 list<edge>::iterator it[2];
 for(int i = 0;!isfin;i^=1){
  bool isupd = 0;
  while(!isupd){
   if(u[i] == -1){
    if(Q[i].empty())
    {
     if(u[i^1] == -1 && Q[i^1].empty() ||len[i^1] > len[i])
     isfin = 1;
    break;
    }else {
     u[i] = Q[i].front();Q[i].pop();it[i] = G[u[i]].begin();
    }
   }
   while(it[i] != G[u[i]].end()){
       if(isdel[it[i]->id]) {
        list<edge>::iterator it1 = it[i];
        ++it[i];G[u[i]].erase(it1);continue;
       }
       int v = it[i]->v;
       if(vis[v] != visflag){
       vis[v] = visflag;Q[i].push(v);
       lst[i][len[i]++] = v;
       Min[i] = min(Min[i],v);
       isupd = 1;
       ++it[i];
       break;
      }
      ++it[i];
   }
   if(it[i] == G[u[i]].end()) u[i] = -1;
   if(isupd) break;
  }
 }
 for(int i = 0;i<2;++i)
  if(len[i] < len[i^1] || (len[i] == len[i^1] && Min[i] < Min[i^1])){
   for(int j = 0;j<len[i];++j)
    comp[lst[i][j]] = totN;
   mul[totN] = (LL(mul[cmp])*weight)%mod;
   add[totN] = (LL(add[cmp])*weight)%mod;
   ++totN;
   add[cmp] = (add[cmp]+weight)%mod;
   break;
  }
}
int main()
{
    setIO("sample");
    int x = 0;
    n = gi,x = gi;
    for(int i = 1;i<n;++i){
     edges[i].u = gi,edges[i].v = gi,edges[i].w=gi;
     --edges[i].v,--edges[i].u;
     G[edges[i].v].pb(edge(edges[i].u,i));
     G[edges[i].u].pb(edge(edges[i].v,i));
    }
    mul[0] = 1,add[0] = 0;
    totN = 1;
    int lastans = 0;
    for(int i = 1;i<n;++i){
     int id =gi;
     id = (LL(lastans)*x+id)%(n-1)+1;
     lastans = int((LL(edges[id].w)*mul[comp[edges[id].u]]+add[comp[edges[id].u]])%mod);
     printf("%d\n",lastans);
     calc(id);
    }
    closeIO();
    return EXIT_SUCCESS;
}
