#include<cstdio>
#include<vector>
#include<queue>
#include<iostream>
#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define tr(e,x) for(eit e=x.begin();e!=x.end();e++)
using namespace std;
const int maxn=1000,maxv=maxn*maxn*2,inf=~0U>>2;
int n,m,vs,vt,v;
int Node[maxn][maxn][2];
int Dist[maxv];
struct Edge
{
int t,c;
Edge(int _t,int _c):t(_t),c(_c){}
};
struct State
{
int p,c;
State(int _p,int _c):p(_p),c(_c){}
bool operator<(const State&o)const
{
return c>o.c;
}
};
vector<Edge> E[maxv];
priority_queue<State> Q;
typedef vector<Edge>::iterator eit;
int Dijstra()
{
rep(i,v)Dist[i]=inf;Q.push(State(vs,0));
while(Q.size())
{
State t=Q.top();Q.pop();if(t.c>Dist[t.p])continue;
if(t.p==vt)return t.c;
tr(e,E[t.p])
{
int ncost=t.c+e->c;
if(ncost<Dist[e->t])
{
Dist[e->t]=ncost;
Q.push(State(e->t,ncost));
}
}
}
}
void AddEdge(int s,int t,int c)
{
E[s].pb(Edge(t,c));
E[t].pb(Edge(s,c));
}
int main()
{
freopen("sample.in","r",stdin);
freopen("sample.out","w",stdout);
scanf("%d%d",&n,&m);v=0;
rep(i,n-1)rep(j,m-1)rep(k,2)Node[i][j][k]=v++;
vs=v++;vt=v++;int c;
rep(j,m-1)scanf("%d",&c),AddEdge(vs,Node[0][j][0],c);
rep(i,n-2)rep(j,m-1)
{
scanf("%d",&c);AddEdge(Node[i][j][1],Node[i+1][j][0],c);
}
rep(j,m-1)scanf("%d",&c),AddEdge(Node[n-2][j][1],vt,c);
rep(i,n-1)
{
scanf("%d",&c);AddEdge(Node[i][0][1],vt,c);
rep(j,m-2)
{
scanf("%d",&c);AddEdge(Node[i][j+1][1],Node[i][j][0],c);
}
scanf("%d",&c);AddEdge(vs,Node[i][m-2][0],c);
}
rep(i,n-1)
rep(j,m-1)
{
scanf("%d",&c);
AddEdge(Node[i][j][0],Node[i][j][1],c);
}
printf("%d\n",Dijstra());
fclose(stdin);fclose(stdout);
}
