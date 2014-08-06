#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 510;
struct Edge{
 int from,to,cap,flow,cost;
};
struct MCMF
{
 int s,t,m,n;
 
 vector<int> G[maxn];
 vector<Edge> edges;
 int inq[maxn];
 int p[maxn];
 int d[maxn];
 int a[maxn];
 
 bool Bell(int s,int t,int & flow,int & cost)
 {
      memset(&d,0x7f,sizeof(d));
      memset(&a,0,sizeof(a));
      memset(&inq,0,sizeof(inq));
      queue<int> Q;
      Q.push(s);d[s] = 0;inq[s] = 1;a[s] = 0x7f7f7f7f;
      while(!Q.empty()){
       int x = Q.front();Q.pop();
       inq[x] = 0;
       for(int i = 0;i<G[x].size();i++)
       {
        Edge & e = edges[G[x][i]];
        if(d[e.to] > d[x] + e.cost && e.cap>e.flow)
        {
         d[e.to] = d[x] + e.cost;
         a[e.to] = min(d[x],e.cap-e.flow);
         p[e.to] = G[x][i];
        }
        if(!inq[e.to])
        {
        Q.push(e.to);
        inq[e.to] = 1;
        }
       }
       
      }
      if(d[t] = 0x7f7f7f7f)
       return false;
      flow += a[t];
      cost += a[t]*d[t];
      for(int u = t;u != s;u = edges[p[u]].from)
      {
       edges[p[u]].flow += a[t];
       edges[p[u]^1].flow -= a[t];
      }
      
 }
};
int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
