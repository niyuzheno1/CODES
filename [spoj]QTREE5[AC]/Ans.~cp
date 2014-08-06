#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int N = 100010,INF = 0x3f3f3f3f;
bool iscenter[N];
int n,son[N],lnk[N*2],nxt[N*2],ec,cnt,times[N],col[N];
struct info
{
 int u,dis;
 info(const int _u=0,const int _dis = 0):
  u(_u),dis(_dis){}
 bool operator<(const info & a)const
 {return dis>a.dis;}
};
priority_queue<info> sq[N*3];
int sqa[N*3],dis[20][N];
struct Center
{
 int fa,fa_son;
 priority_queue<info> q;
}c[N];
inline bool check(const info & a)
{
 return sqa[a.u] != a.dis;
}
void maintain(priority_queue<info> & q)
{
 while(!q.empty() && check(q.top())) q.pop();
}
int FC(const int s)
{
 static int q[N],f[N],g[N],fa[N],h,t;
 int res = 0; g[0] = INF;
 fa[s] = f[s] = g[s] = 0;
 for(q[t=h=1]=s;h<=t;++h)
  for(int i = son[q[h]],v;i;i=nxt[i]){
    if(iscenter[v = lnk[i]] || fa[q[h]] == v) continue;        
    fa[v] = q[h];
    q[++t] = v;
    f[v] = g[v] = 0;
  }
 for(int i = t;i;--i){
  f[fa[q[i]]] += (++f[q[i]]);
  g[fa[q[i]]] = max(g[fa[q[i]]],f[q[i]]);
  g[q[i]] = max(g[q[i]],t-g[q[i]]);
  if(g[res] > g[q[i]]) res = q[i];
 }
 iscenter[res] = true;
 return res;
}
void update(const int s)
{
 static int q[N],h,t,fa[N];
 fa[s] = dis[++times[s]][s] = 0;
 for(q[h=t=1]=s;h<=t;++h)
  for(int v,i=son[q[h]];i;i=nxt[i]){
   if(iscenter[v=lnk[i]] || fa[q[h]] == v) continue;
   fa[v] = q[h];
   q[++t] = v;
   dis[++times[v]][v] = dis[times[q[h]]][q[h]]+1;
  }
}
void init()
{
 static int q[N];
 int h,t;
 h = t = 1;
 for(q[t] = FC(1);h<=t;++h){
  update(q[h]);
  for(int i = son[q[h]];i;i=nxt[i])
   if(!iscenter[lnk[i]]){
    q[++t] = FC(lnk[i]);
    c[q[t]].fa = q[h];
    c[q[t]].fa_son = i;
   }
 }
}
int query(int x)
{
 if(!cnt) return -1;
 if(!col[x]) return 0;
 int s = x,ans,y=c[x].fa_son,t=times[s]-1;
 maintain(c[x].q);
 if(c[x].q.empty()) ans = INF;
 else ans = c[x].q.top().dis;
 for(x = c[x].fa;x && ans >1;y = c[x].fa_son,x = c[x].fa,--t){
  priority_queue<info> & q = c[x].q;
  maintain(q);
  if(q.empty()) continue;
  info  tmp = q.top(),tt;q.pop();
  if(tmp.u != y) ans = min(ans,dis[t][s] + tmp.dis);
  else
  {
   while(!q.empty() && (check(tt = q.top()) || tt.u == tmp.u)) q.pop();
   if(!q.empty()) ans = min(ans,dis[t][s] + q.top().dis);
  }
  q.push(tmp);
 }
 return ans;
}
void modify(int x)
{
 cnt += ((col[x]^=1)?-1:1);
 int s = x,y = c[x].fa_son,t = times[s]-1;
 if(col[x]) sqa[x+2*n] = INF;
 else{
  sqa[x+2*n] = 0;
  sq[x+2*n].push(info(x,0));
  c[x].q.push(info(x+2*n,0));
 }
 for(x = c[x].fa;x;y=c[x].fa_son,x = c[x].fa,--t){
  priority_queue<info> & q = sq[y];
  while(!q.empty() && col[q.top().u]) q.pop();
  if(!col[s]) q.push(info(s,dis[t][s]));
  int mem = sqa[y];
  if(q.empty()) sqa[y] = INF;
  else sqa[y] = q.top().dis;
  maintain(c[x].q);
  if(sqa[y] != mem)c[x].q.push(info(y,sqa[y]));
 }
}
inline void addedge(const int x,const int y)
{
 nxt[++ec] = son[x];son[x] = ec;lnk[ec] = y;
}
FILE * d;
void setIO(string file)
{
 #ifndef ONLINE_JUDGE
 string input = file+".in",output = file+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);d = fopen("debug.txt","w");
 #endif
}
void closeIO()
{
 #ifndef ONLINE_JUDGE
 fclose(stdin);fclose(stdout);fclose(d);
 #endif
}
int main(int argc, char *argv[])
{
    setIO("Qtree5");
    scanf("%d",&n);
    for(int i = 1;i<=n;++i) col[i] = 1;
    for(int i = 1;i<=n*3;++i) sqa[i] = INF;
    for(int i = 1,x,y;i<n;++i){
     scanf("%d%d",&x,&y);
     addedge(x,y);addedge(y,x);
    }
    init();
    int q = 0;
    scanf("%d",&q);
    for(int opt,x;q--;){
     scanf("%d%d",&opt,&x);
     if(!opt) modify(x);
     else printf("%d\n",query(x));
    }
    closeIO();
    return EXIT_SUCCESS;
}
