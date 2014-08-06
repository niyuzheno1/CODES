#include "mode.h"
#undef INF 
#define MN 2010
#define MM 10010
const double eps = 1e-8;
const double INF = 100000000.0;
int n,m,k,p,Ans=0,deg;
double sum = 0.0;
struct _edge
{
 int u,v;double p,c,w;
}e[MM],_e[MM];

int node[MN],top;
struct Edge
{
 int from,to,next;
 double w;
}edge[MM];
int fa[MM];
bool vis[MN],flag[MM],Out_ans;
vector<int> adj;
inline void add(int x,int y,double w){edge[top].from =x,edge[top].to = y,edge[top].w = w,edge[top].next = node[x],node[x] = top++;}

inline void build_map(double x)
{
       sum = 0.0,deg = 0;
       CLEAR(node,0xff);CLEAR(flag,0);
       top = 0;
       for(int i = 1;i<=m;++i)
        _e[i].u = e[i].u,_e[i].v = e[i].v,_e[i].w = x*e[i].c-e[i].p;
}

inline bool cmp(_edge x,_edge y)
{
       return x.w < y.w;
}
int findfa(int x)
{
    if(fa[x] == x)
     return x;
    else
     return fa[x] = findfa(fa[x]);
}
inline void Kruskal()
{
       adj.clear();
       sort(_e+1,_e+m+1,cmp);
       for(int i = 1;i<=m;++i)
        if(_e[i].u == p || _e[i].v == p) adj.pb(i);
       for(int i = 1;i<=n;++i)
        fa[i] = i;
       for(int i = 1;i<=m;++i){
        if(_e[i].u == p || _e[i].v == p) continue;
        if(findfa(_e[i].u) == findfa(_e[i].v)) continue;
        fa[findfa(_e[i].v)]=fa[findfa(_e[i].u)];
        sum += _e[i].w;
        add(_e[i].u,_e[i].v,_e[i].w);add(_e[i].v,_e[i].u,_e[i].w);
       }
}
int Maxe[MN];
inline bool link_Forest()
{
       for(int i = 0;i<(int)adj.size();++i)
       {
        int x = adj[i];
        if(findfa(_e[x].u) == findfa(_e[x].v)) continue;
        fa[findfa(_e[x].v)] = fa[findfa(_e[x].u)];
        ++deg;
        if(deg > k) return 0;
        sum += _e[x].w;
        add(_e[x].u,_e[x].v,_e[x].w);
        add(_e[x].v,_e[x].u,_e[x].w);
       }
       return 1;
}

inline void get_Maxedge()
{
       CLEAR(vis,0);CLEAR(Maxe,0xff);
       queue<int> Q;
       vis[p] = 1;
       for(int i = node[p];~i;i=edge[i].next)
       {
        Q.push(edge[i].to);
        vis[edge[i].to] = 1;
       }
       while(!Q.empty())
       {
        int u = Q.front();Q.pop();
        vis[u] =  1;
        for(int i = node[u];~i;i=edge[i].next){
         int v = edge[i].to;
         if(vis[v] || flag[i] == 1)
          continue;
         vis[v]=1;
         if(Maxe[u]== -1 || edge[i].w > edge[Maxe[u]].w)
          Maxe[v] = i;
         else
          Maxe[v] = Maxe[u];
         Q.push(v);
        }
       }
}

inline void Replace()
{
       for(int i = deg+1;i<=k;++i)
       {
               get_Maxedge();
               int tmp,now;
               double Max_ch = 0;
               for(int j = 0;j<adj.size();++j)
               {
                now =  adj[j];
                int u = (_e[now].u == p)?(_e[now].v):(_e[now].u);
                if( Maxe[u] != -1 && edge[Maxe[u]].w - _e[now].w > Max_ch )
                  Max_ch = edge[Maxe[u]].w-_e[tmp = now].w ;
               }
               if(Max_ch == 0)
                break;
               int u = _e[tmp].u == p ? _e[tmp].v:_e[tmp].u;
               add(p,u,_e[tmp].w);
               add(u,p,_e[tmp].w);
               sum += _e[tmp].w-edge[Maxe[u]].w;
               flag[Maxe[u]] = flag[Maxe[u]^1] = 1;
       }
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi,p= gi,k = gi;
    CLEAR(node,0xff);
    top = 0;
    Out_ans = 1;
    for(int i = 1;i<=m;++i){
     e[i].u= gi,e[i].v = gi;
     scanf("%lf%lf",&e[i].p,&e[i].c);
    }
    double L = 0,R = 10000000,mid;
    while(L+eps < R)
    {
     mid = (L+R)/2;
     build_map(mid);
     Kruskal();
     if(link_Forest() == 0)
     {
      Out_ans = 0;
      break;
     }
     Replace();
     if(sum < 0)
      L = mid;
     else
      R = mid;
    }
    if(Out_ans)
     printf("%.3lf\n",L);
    else
     printf("Ni Zai Dou Wo Xiao?\n");
    closeIO();
    return EXIT_SUCCESS;
}
