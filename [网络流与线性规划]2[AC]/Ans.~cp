#include "mode.h"
struct edge{int n,v,f,c;};
#undef TRA
#undef INF
#define INF 0x7f7f7f7f
#define MN 110
#define MM 1010
#define TRA(x,y) for(int x = st[y];x;x=lk[x].n)
#define FIND(x,y) for(int x = cur[y];x;x=lk[x].n)
#define PRE(x,y) for(int x = pre[y];x;x = pre[lk[x^1].v])
#define GAP(x) if((--num[d[x]])==0) break;
int e = 1,n,m,ans,node;
edge lk[MM];
int cur[MN],st[MN],pre[MN],d[MN],q[MN],num[MN];
void add(int x,int y,int z)
{++e,lk[e].n = st[x],lk[e].v = y,lk[e].f = 0,lk[e].c = z,st[x]=e;}
void bfs(int t){
     CLEAR(d,0x7f);
     int r = 0;
     d[t] = 0;q[++r] = t;++num[d[t]];
     for(int i = 1;i<=r;)
     {
      int u = q[i];++i;
      TRA(x,u)
       if(d[lk[x].v] >= INF)
       {
        d[lk[x].v] = d[u]+1;
        ++num[d[lk[x].v]];
        q[++r] = lk[x].v;
       }
     }
}
int aug(int t)
{
    int ret = t,mf = INF;
    PRE(u,t)
     if(lk[u].c-lk[u].f<=mf)
     {
      mf = lk[u].c-lk[u].f;
      ret = lk[u^1].v;
     }
    ans += mf;
    PRE(u,t)
     lk[u].f+=mf,lk[u^1].f-=mf;
   return ret;
}
void isap(int s,int t)
{
     bfs(t);
     for(int i = 1;i<=node;++i) cur[i]=st[i];
     int u = s;
     while(d[s] < node){
      if(u == t)
       u = aug(t);
      int adv = 0;
      FIND(x,u)
       if(d[lk[x].v]+1 == d[u] && lk[x].c > lk[x].f)
       {
        cur[u] = x; 
        u = lk[x].v;
        pre[u] = x;
        adv = 1;
        break;
       }
      if(!adv){
       GAP(u);
       int dm = node;
       TRA(x,u)
        if(lk[x].f < lk[x].c)
        dm = min(dm,d[lk[x].v]);
       d[u] = dm+1;
       cur[u] = st[u];
       ++num[d[u]];
       if(u != s) u = lk[pre[u]^1].v;
      }
     }
}

int map[MN][MN],len,pos,val[MN],cost[MN];
char str[MN];
#define EP(x) n+x+1
#define YQ(x) x+1
int gint()
{
    char c = str[pos];++pos;
    int ret = 0,sign = 1;
    while(pos < len && !isdigit(c) && c != '-')
      c = str[pos],++pos; 
    if(pos > len) return -1;
    if(c == '-') sign = -1,c = str[pos],++pos;
    while(isdigit(c) ) 
     ret *= 10,ret += (c-'0'),c =str[pos],++pos;
    return ret*sign;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    m = gi,n = gi;
    
    int tot = 0;
    for(int i = 1;i<=m;++i)
    {
      val[i] = gi;tot+=val[i];
      pos = 0;
      gets(str);
      len = strlen(str);
      while(1)
      {
       ++map[i][0];map[i][map[i][0]] = gint();
       if(map[i][map[i][0]] == -1)
       {--map[i][0];
        break;
       }
      }
    }
    
    for(int i = 1;i<=n;++i)
     cost[i] = gi;
    int s = 1, t = EP(m)+1;
    for(int i = 1;i<=m;++i)
     add(s,EP(i),val[i]),add(EP(i),s,0);
    for(int i = 1;i<=m;++i)
     for(int j = 1;j <= map[i][0];++j)
      add(EP(i),YQ(map[i][j]),INF),add(YQ(map[i][j]),EP(i),0);
    for(int i = 1;i<=n;++i)
     add(YQ(i),t,cost[i]),add(t,YQ(i),0);
    for(int i = 1;i<=t;++i)
     node += (st[i]!=0);
    isap(s,t);
    printf("%d",tot-ans);
    closeIO();
    return EXIT_SUCCESS;
}
