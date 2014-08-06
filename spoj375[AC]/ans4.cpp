#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN=10010,MAXE = 2*MAXN,INF = 0x7f7f7f7f;
int head[MAXN],cost[MAXN],id[MAXN];
int weight[MAXE],to[MAXE],next[MAXE];
int n,ecnt;
void init(){
 memset(head,0,sizeof(head));
 ecnt = 2;
}
void add_edge(int u,int v,int c){
 to[ecnt] = v;weight[ecnt] = c;next[ecnt] = head[u];head[u] = ecnt++;
 to[ecnt] = u;weight[ecnt] = c;next[ecnt] = head[v];head[v] = ecnt++;
}
int maxt[MAXN*4];
void modify(int x,int left,int right,int a,int b,int val){
 if(a <= left && right <= b) maxt[x] = val;
 else{
  int ll = x<<1,rr = ll^1;
  int mid = (left+right)>>1;
  if(a<=mid) modify(ll,left,mid,a,b,val);
  if(mid < b)modify(rr,mid+1,right,a,b,val);
  maxt[x] = max(maxt[ll],maxt[rr]);
 }
}
int query(int x,int left,int right,int a,int b){
 if(a <= left && right <= b) return maxt[x];
 else
 {
  int ll = x<<1,rr=ll^1;
  int mid = (left+right)>>1,ret = 0;
  if(a<=mid) ret = max(ret,query(ll,left,mid,a,b));
  if(mid < b) ret = max(ret,query(rr,mid+1,right,a,b));
  return ret;
 }
}
int size[MAXN],fa[MAXN],dep[MAXN],son[MAXN];
int tid[MAXN],top[MAXN],dfs_clock;
void dfs_size(int u,int f,int depth){
 fa[u] = f;dep[u] = depth;
 size[u] = 1;son[u] = 0;
 int maxsize = 0;
 for(int p = head[u];p;p=next[p]){
  int & v= to[p];
  if(v == f) continue;
  cost[v] = weight[p];
  dfs_size(v,u,depth+1);
  size[u] += size[v];
  if(size[v] > maxsize){
   maxsize = size[v];
   son[u] = v;
  }
 }
}
void dfs_heavy_edge(int u,int ancestor){
 tid[u] = ++dfs_clock;top[u] = ancestor;
 modify(1,1,n,tid[u],tid[u],cost[u]);
 if(son[u]) dfs_heavy_edge(son[u],ancestor);
 for(int p = head[u];p;p=next[p]){
  int & v = to[p];
  if(v == fa[u] || v == son[u]) continue;
  dfs_heavy_edge(v,v);
 }
}
int query(int x,int y){
 int ret = 0;
 while(top[x] != top[y]){
  if(dep[top[x]] < dep[top[y]]) swap(x,y);
  ret = max(ret,query(1,1,n,tid[top[x]],tid[x]));
  x = fa[top[x]];
 }
 if(dep[x] > dep[y])swap(x,y);
 ret = max(ret,query(1,1,n,tid[x]+1,tid[y]));
 return ret;
}
void change(int x,int y){
 int u = to[x],v = to[x^1];
 if(fa[u] == v) swap(u,v);
 modify(1,1,n,tid[v],tid[v],y);
}
char str[15];
int main(int argc, char *argv[])
{
    int T;scanf("%d",&T);
    while(T--){
     scanf("%d",&n);
     init();
     for(int i = 1;i<n;i++){
      int u,v,c;scanf("%d%d%d",&u,&v,&c);
      id[i] = ecnt;
      add_edge(u,v,c);
     }
     memset(maxt,0,sizeof(maxt));
     dfs_size(1,0,0);cost[1] = -INF;
     dfs_clock = 0;
     dfs_heavy_edge(1,1);
     while(scanf("%s",str) && *str != 'D'){
      int x,y;
      scanf("%d%d",&x,&y);
      if(*str == 'C') change(id[x],y);
      else printf("%d\n",query(x,y)); 
     }
    }
    return EXIT_SUCCESS;
}
