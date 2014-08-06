#include "mode.h"
int tttt[5];
#define MM 15*2
#define MN 21*2
#define MD 210*2
#undef INF
#define INF 0x7f7f7f7f
int day,n,m,k,S,T,ans;
int hpi[MM],d[MN*MD],pre[MN*MD];
int r[MM],s[MM][MN];
#define UP(_) (_ + (day-1)*(n+2)+4)
#define DOWN(_) (_ + day*(n+2)+4)
int st[MN*MD];
struct _edge{
 int n,v,f,ud;
};
_edge lk[MN*MD*10];
#define tot tttt[0]
void init(){CLEAR(st,0xff);tot = 1;}
void ad(int x,int y,int z){ ++tot;lk[tot].v = y;lk[tot].n = st[x];lk[tot].f = z;st[x] = tot;}
void add(int x,int y,int z){
     ad(x,y,z);ad(y,x,0);
     }
#undef tot
bool spfa(int s,int t){
 CLEAR(d,0x7f);CLEAR(pre,0);
 d[s] = 0;
 queue<int> q;q.push(s);
 while(!q.empty()){
  int x = q.front();q.pop();
  TRA(i,x)
   if(lk[i].f && d[lk[i].v] > d[x]+1){
   d[lk[i].v] = d[x]+1;
   q.push(lk[i].v);
   pre[lk[i].v] = i;
   }
 }
 return d[t]<INF;
}
void aug(int & ans,int s,int t)
{
     int mf = INF;
     for(int i = pre[t];i;i=pre[lk[i^1].v])
      mf = min(mf,lk[i].f);
     ans += mf;
     for(int i = pre[t];i;i=pre[lk[i^1].v])
      lk[i].f -= mf,lk[i^1].f +=mf;
}
int main(int argc, char *argv[])
{
    setIO("sample");init();
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=m;++i){
     scanf("%d%d",&hpi[i],&r[i]);
     for(int j = 0;j<r[i];++j) scanf("%d",&s[i][j]);
    }
    S = 1,T =2;
    add(S,DOWN(0),INF);add(DOWN(-1),T,INF);
    while(spfa(S,T))
     aug(ans,S,T);
    for(day = 1;;++day){
    if(day > 40){
     puts("0");
     return 0;
    }
    add(S,DOWN(0),INF);add(DOWN(-1),T,INF);
    for(int i = 1;i<=m;++i){
     int last = s[i][(day-1)%r[i]],now = s[i][(day)%r[i]];
     add(UP(last),DOWN(now),hpi[i]);
    }
    for(int i = -1;i<=n;++i) add(UP(i),DOWN(i),INF);
    if(day == 8)
     day = 8;
    while(spfa(S,T))
     aug(ans,S,T);
    if(ans >= k)
      break;
    }
   
    printf("%d\n",day);   
    closeIO();
    return EXIT_SUCCESS;
}
