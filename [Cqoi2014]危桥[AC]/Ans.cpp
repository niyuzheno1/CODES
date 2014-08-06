#include "mode.h"
#define MN 55
#define MM 55*55
int S,T,st[MN],tot,d[MN];
struct  edge{
    int f,n,c,v;
};
edge lk[MM];

char p[MN][MN];

void clear()
{
     CLEAR(st,0xff);
     CLEAR(lk,0);++tot;
}
void addedge(int x,int y,int c){
 lk[tot].v = y,lk[tot].n = st[x],lk[tot].f = 0,lk[tot].c = c,st[x] = tot;
 ++tot;
}

void ae(int x,int y,int c){
 addedge(x,y,c);
 addedge(y,x,0);
}

bool bfs(){
 CLEAR(d,0x7f);d[S] = 0;
 queue<int> q; q.push(S);
 while(!q.empty())
 {
  int u = q.front(),v = 0;q.pop();if(u == T) return 1;
  TRA(x,u)
   if(d[v=lk[x].v] > d[u]+1 && lk[x].c)
   {
   d[v] = d[u]+1; q.push(v);
   }
 }
 return 0;
}
int dfs(int x,int flow)
{
     if(x == T) return flow;
     int tmp = 0,v=0,pp;
     if(x == 8) 
      x = 8;
     TRA(u,x)
      if(d[v = lk[u].v] == d[x]+1 && lk[u].c )
      {
       pp = dfs(v,min(flow,lk[u].c));
       if(!pp) continue;
       flow -= pp;
       lk[u].c -= pp;
       lk[u^1].c += pp;
       tmp+= pp;
       if(flow == 0)
        break;
      }
   return tmp;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    int n,a1,a2,an,b1,b2,bn;
    while(~scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&an,&b1,&b2,&bn))
    {
     ++a1,++a2,++b1,++b2,T = n+1,S = 0;an*=2,bn*=2;
     clear();int flag = 1;
     for(int i = 1;i<=n;++i){
      scanf("%s",p[i]+1);
      for(int j = 1;j<=n;++j)
       if(p[i][j] == 'N') ae(i,j,INF);
       else if(p[i][j] == 'O') ae(i,j,2);
     }
     ae(S,a1,an);ae(S,b1,bn);ae(a2,T,an);ae(b2,T,bn);
     int flow = 0;
     while(bfs())
      flow += dfs(0,INF);
     if(flow < an+bn) flag = 0;
     clear();
     if(flag){
     for(int i = 1;i<=n;++i)
      for(int j = 1;j<=n;++j)
       if(p[i][j] == 'N') ae(i,j,INF);
       else if(p[i][j] == 'O') ae(i,j,2);
     ae(S,a1,an);ae(S,b2,bn);ae(a2,T,an);ae(b1,T,bn);
     flow = 0;
     while(bfs())
      flow += dfs(0,INF);
     if(flow < an+bn) flag = 0;
     }
     if(flag ) puts("Yes"); else puts("No");
    }
    closeIO();
    return EXIT_SUCCESS;
}
