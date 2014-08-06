#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;
const int maxn = 510,INF = 10000000;
priority_queue<int> null;
//define 
struct Edge
{
 int flow,cap;
 int to/*,from Only for Debug*/;      
};

struct NT{
 int n,m,s,t;
 vector<int> G[maxn];
 vector<Edge> edges;
 bool vis[maxn];
 int cur[maxn];
 int d[maxn];
 
 void addedge(int from,int to,int cap)
 {
  edges.push_back( ((Edge) {0,cap,to}) );
  edges.push_back( ((Edge) {0,0,from}) );
  int m = edges.size();
  G[to].push_back(m-1);
  G[from].push_back(m-2);
  
 }
 
 bool BFS()
 {
 memset(&d,0x7f,sizeof(d));
 memset(&vis,0,sizeof(vis));
 queue<int> Q;
 Q.push(s);d[s] = 0,vis[s] = 1;
 while(!Q.empty())
 {
  int x = Q.front();Q.pop();
  for(int i = 0;i<G[x].size();i++)
  {
   Edge & e = edges[G[x][i]];
   if(!vis[e.to] && e.flow < e.cap)
   {
    d[e.to] = d[x] + 1;
    vis[e.to] = 1;
    Q.push(e.to);
   }
  }
 }
 return vis[t];
 } 
 
 int DFS(int x,int a)
 {
     if(x == t || a == 0)
      return a;
     int flow = 0,f;
     for(int & i = cur[x];i<G[x].size();i++)
     {
      Edge & e = edges[G[x][i]];
      if( (d[e.to] ==  d[x]+1 ) && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
      {
       e.flow += f;
       edges[G[x][i]^1].flow -= f;
       flow += f;
       a-=f;
       if(a == 0)
        break;
      }
     }
     return flow;
 }
 int Flow()
 {
  int ans = 0;
  while(BFS()){
  memset(cur,0,sizeof(cur));
   ans += DFS(s,INF);
  }   
  return ans;
 }
 
};
NT network;
//process
int main(int argc, char *argv[])
{
    network.s = 1;
    network.t = 4;
    network.addedge(1,2,1);
    network.addedge(2,3,1);
    network.addedge(3,4,1);
    network.addedge(1,6,2);
    network.addedge(6,5,2);
    network.addedge(5,4,3);
    printf("%d\n",network.Flow());
    
    system("PAUSE");
    return EXIT_SUCCESS;
}