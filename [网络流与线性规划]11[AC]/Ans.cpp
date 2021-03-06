#include "mode.h"
#undef INF
#define INF 0x7f7f7f7f
#define MN 110*2
#define MM 1100*2
int tttt[4];
int st[MN];
struct _edge{
 int n,f,v,c,d;
};
_edge lk[MM];
#define tot tttt[0]
void init()
{
 tot = 1;CLEAR(st,0xff);
}
void ad(int x,int y,int v,int w){
 ++tot;lk[tot].v = y,lk[tot].c = w,lk[tot].f = v,lk[tot].n = st[x],st[x] = tot;
}
#undef tot
void add(int x,int y,int v,int w){
 ad(x,y,v,w);ad(y,x,0,w);
}
typedef map<string,int> msi;
msi rd;
string rp[MN];
int n,v,d[MN],pre[MN];
#define LEF(_) _
#define RIG(_) _+n
bool spfa(int s,int t){
 CLEAR(d,0x7f);CLEAR(pre,0);
 queue<int> q;
 q.push(s);d[s] = 0;
 while(!q.empty()){
  int x = q.front();q.pop();
  TRA(i,x)
  if(lk[i].f>0 && d[lk[i].v]>d[x]+lk[x].c)
  {
   d[lk[i].v]=d[x]+lk[x].c;
   pre[lk[i].v] = i;
   q.push(lk[i].v);
  }
 }
 return  d[t] < INF;
}
void aug(int & ans,int s,int t){
 int cost = 0,mf = INF;
 for(int i = pre[t];i;i=pre[lk[i^1].v])
   mf = min(lk[i].f,mf),cost += lk[i].c;
 ans += mf*cost;
 for(int i = pre[t];i;i=pre[lk[i^1].v])
  lk[i].f-=mf,lk[i^1].f += mf;
}
int term;
string ans1,ans2;
void solve(int x)
{
  ans1 += rp[x];
  ans1 += '\n';
  TRA(i,RIG(x))
   if(lk[i^1].f && lk[i].v != LEF(x)){
    lk[i].d = lk[i^1].d = 1;
    solve(lk[i].v);
    break;
   }
}
void solve2(int x){
  if(x == term) return ;
  TRA(i,RIG(x))
   if(lk[i^1].f && lk[i].v != LEF(x)){
    solve2(lk[i].v);
    break;
   }
  ans2 += rp[x];
  ans2 += '\n';
}
int main(int argc, char *argv[])
{
    setIO("sample");
    cin>>n>>v;
    init();
    for(int i = 1;i<=n;++i){
     string tmp;
     cin>>tmp;
     rd[tmp] = i;
     rp[i] = tmp;
    }
    int s = LEF(1),t = RIG(n);
    for(int i = 2;i<=n-1;++i){
     add(LEF(i),RIG(i),1,1);
    }
    add(LEF(1),RIG(1),2,1);
    add(LEF(n),RIG(n),2,1);
    for(int i = 1;i<=v;++i){
     string a,b;
     cin>>a>>b;
     add(RIG(rd[a]),LEF(rd[b]),INF,0);
    }
    int ans = 0;
    while(spfa(s,t))
     aug(ans,s,t);
    term = n;
    printf("%d",ans-2);
    solve(1);
    solve2(1);
    ans1 += ans2;
    printf("\n%s",ans1.c_str());
    closeIO();
    return EXIT_SUCCESS;
}
