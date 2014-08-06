#include "mode.h"
#define MN 110
#undef INF 
#define INF 0x7f7f7f7f
int tttt[5];
int n;
int a[MN];
int st[MN*4],pre[MN*4],d[MN*4];
struct _edge{int n,v,c,f,udd;};
_edge lk[MN*MN*5];
#define tot tttt[0]
void init(){CLEAR(st,0xff);tot = 1;}
void ad(int x,int y,int v,int c){
     ++tot;lk[tot].v = y;lk[tot].n =st[x];lk[tot].c = c;lk[tot].f = v;lk[tot].udd = 0;st[x] = tot;}
void add(int x,int y,int v,int c){ad(x,y,v,c);ad(y,x,0,-c);}
#undef tot
int docir(int x,int y){if(x > y ) swap(x,y);return min(y-x,n-(y-x));}
#define LEF(_) _+1
#define RIG(_) _+n+1
bool spfa(int s,int t){
 CLEAR(d,0x7f);CLEAR(pre,0);
 queue<int> q;
 q.push(s);d[s] = 0;
 while(!q.empty()){
  int x = q.front();q.pop();
  TRA(i,x)
   if(lk[i].f > 0 && d[x]+ lk[i].c < d[lk[i].v]){
    d[lk[i].v] = d[x]+ lk[i].c;
    pre[lk[i].v] = i;
    q.push(lk[i].v);
   }
 }
 return d[t] < INF;
}
void aug(int & ans ,int s,int t){
 int mf = INF ,cost = 0;
 for(int i = pre[t];i;i=pre[lk[i^1].v])
  mf = min(lk[i].f,mf),cost += lk[i].c;
 ans += mf * cost;
 for(int i = pre[t];i;i=pre[lk[i^1].v])
  lk[i].f -= mf,lk[i^1].f += mf;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d",&n);init();
    int ava= 0;
    for(int i = 1;i<=n;++i) scanf("%d",&a[i]),ava+=a[i];
    ava /= n;
    int S = LEF(0),T = RIG(n+1);
    for(int i = 1;i<=n;++i) a[i] -= ava;
    for(int i = 1;i<=n;++i)
    {
     if(a[i] < 0)
      add(RIG(i),T,-a[i],0);
     if(a[i] > 0)
      add(S,LEF(i),a[i],0);
    }
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
      if(i != j)
      {
       int cost = docir(i,j);
       add(LEF(i),RIG(j),INF,cost);
      }
    int ans = 0;
    while(spfa(S,T))
      aug(ans,S,T);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
