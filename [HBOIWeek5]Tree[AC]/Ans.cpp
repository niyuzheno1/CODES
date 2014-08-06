#include "mode.h"

const int64 mod = 99990001;
#define MM 200010*2
#define MN 200010

typedef vector<int> vi;
typedef queue<int> qi;

struct edge {int64 v,n,f;};
//a -> mut,b->add
int64 w[MM],c[MM],tot,n,x,st[MN],a[MM],b[MM],lastans,vis[MN],cpN;edge lk[MM];

inline void decode(int64 & u) {u = ((lastans*x)%(n-1)+u)%(n-1)+1;}
void add(int64 x,int64 y,int64 c) {lk[tot].v = y,lk[tot].f=0,lk[tot].n = st[x],st[x] = tot,w[tot] = c,++tot;}
inline void am(int64 & x,int64 y,int64 c) {x = y+c;while(x < 0) x += mod;while(x > mod) x -= mod;}
inline void mm(int64 & x,int64 y,int64 c) {x = (y*c)%mod;}
inline void ccp(int64 x) {c[x] = cpN;c[x^1] = cpN;}
// pu is a list
int64 d[2][MM],o[2][MM];
void proc(int64 x,int64 y,int64 z)
{
      ++SIZE(vis);
      d[0][SIZE(d[0]) = 1]= x;d[1][SIZE(d[1]) = 1]= y;
      SIZE(o[1]) = SIZE(o[0]) = 0;
      int p[] = {1,1};
      vis[x] = vis[y] = SIZE(vis);
      int64 f[2] = {0,1},g[2] = {x,y},s[2] = {0,0};
      //process of bfs
      int64 flag = 1;
      while(flag)
      {
       for(int64 i = 0;i<=1;++i){
       if(p[i] <= d[i][0] /*!d[i].empty()*/){
        int64 x = d[i][p[i]],v=0;++p[i];vis[x] = vis[0];
        TRA(u,x) if(vis[v=lk[u].v] != SIZE(vis)){vis[v] = SIZE(vis);d[i][++SIZE(d[i])] = v;o[i][++SIZE(o[i])] = u;}
        }
       }
       for(int64 i = 0;i<=1;++i)
       if(p[i] <= d[i][0]/*!d[i].empty()*/){
       int64 x = d[i][p[i]];
       g[i] = min(g[i],x);
       }
       for(int64 i = 0;i<=1;++i)
        if(p[i] > d[i][0]){
         flag = 0;
         ++s[i^1];
        }
      }
      //done 
      if(s[0] > s[1] ||(s[0] == s[1] && g[0] > g[1])) swap(f[0],f[1]);
      ++cpN;
      for(int64 i = 1;i<=SIZE(o[f[0]]);++i) 
       ccp(o[f[0]][i]);
      b[cpN] = b[z];
      a[cpN] = a[z];
      mm(b[cpN],b[cpN],lastans);
      mm(a[cpN],a[cpN],lastans);
      am(b[z],b[z],lastans);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    CLEAR(st,0xff);
    n = gi,x = gi;
    for(int64 i = 1;i<n;++i)
    {
     int64 u=gi,v=gi,w=gi;
     add(u,v,w);add(v,u,w);
    }
    a[0] = 1,b[0] = 0;
    for(int64 i = 1;i<n;++i)
    {
     int64 op = gi;decode(op),lk[(op-1)*2].f = 1,lk[(op-1)*2+1].f = 1;
     mm(lastans,w[(op-1)*2],a[c[(op-1)*2]]);
     am(lastans,lastans,b[c[(op-1)*2]]);
     proc(lk[(op-1)*2+1].v,lk[(op-1)*2].v,c[(op-1)*2]);
     printf(I64D,lastans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
