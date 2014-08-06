#include "mode.h"
#include <fstream>
ifstream knl("2048.txt"); //kownledgelibrary
char opr[20010][20];
int toto;
const int MUL = 8221;
typedef map<int,int> mp;
const int sx[] = {0,1,1,1,4};
const int ex[] = {0,5,5,5,0};
const int sy[] = {0,1,4,1,1};
const int ey[] = {0,5,0,5,5};
const int nx[] = {0,1,1,1,-1};
const int ny[] = {0,1,-1,1,1};
const int dx[] = {0,0,0,-1,1};
const int dy[] = {0,-1,1,0,0};
const string ru = "0LRUD";
int getrand(int & seq)
{
    return (seq = ((seq*MUL)+(seq>>16)))&15;
}
void initknow(){
 int len;
 knl>>len;
 for(int i = 1;i<=len;++i){
 ++toto;
 knl>>(opr[toto]+1);
 }
}
pii c[16];
//int f[5][5];
struct pt
{
 int a[5][5],now;
 int abs(pt & u)
 {
  int ret = 0;
  for(int i = 1;i<=4;++i)
   for(int j = 1;j<=4;++j)
    ret += (1<<a[i][j])*u.a[i][j];
  return ret;
 }
 void proc()
 {
  bool full = 1;
  for(int i = 1;i<=4;++i)
   for(int j = 1;j<=4;++j)
    if(a[i][j] == 0)
     full = 0;
  if(full) 
   return;
  int fv;
  fv = getrand(now);
  while(a[c[fv].X][c[fv].Y])
        fv = getrand(now);
  a[c[fv].X][c[fv].Y] = 1;
 }
 void pf()
 {
  for(int i = 1;i<=4;printf("\n"),++i)
   for(int j = 1;j<=4;++j)
    printf("%8d ",1<<a[i][j]);
 }
};
pt tag,uv;
int f[5][5];
bool range(int x,int y){return x<=4&&x>=1&&y<=4&&y>=1;}
void mov(pt * ax,int & u,int v)
{
 CLEAR(f,0);
 /*CLEAR(f,0,sizeof(f));
 for(int i = 1;i<=4;++i)
  for(int j = 1;j<=4;++j)
   f[i][j] = ax->a[i][j];*/
 for(int i = sx[v];i!=ex[v];i+=nx[v])
  for(int j = sy[v];j!=ey[v];j+=ny[v])
   if(ax->a[i][j]){
   int x = i+dx[v],y = j+dy[v];
   while(range(x,y)){
    if(ax->a[x][y] == ax->a[i][j] && f[x][y] == 0){
    ax->a[i][j] = 0;++ax->a[x][y];
    f[x][y] = 1;
    ++u;
    }
    if(ax->a[x][y] || f[x][y] == 1) break;
    x += dx[v],y += dy[v];
   }
  }
  for(int i = sx[v];i!=ex[v];i+=nx[v])
   for(int j = sy[v];j!=ey[v];j+=ny[v])
    if(ax->a[i][j]){
    int mi=i,mj=j;
    int x = i+dx[v],y = j + dy[v];
    while(range(x,y)){
     if(ax->a[x][y]) break;
     ++u;
     swap(ax->a[x][y],ax->a[i][j]);
     i += dx[v],j+=dy[v];
     x += dx[v],y+=dy[v];
    }
    i = mi,j = mj;
   }
  ax->proc();
}
int tabx[5][5];
#define inp inputx
FILE * inp;
void init(int x)
{
    for(int i = 1;i<=4;++i)
     for(int j = 1;j<=4;++j)
      fscanf(inp,"%d",&tag.a[i][j]);
}
int best = 0;
void dn1(int & u ,int & v,int x,int y)
{
     if(u < x)
      u = x, v = y;
}
#define begin beginx
int begin = 0;
int dep = 4;
map<char,int> pq;
const int maxl = 16;
bool check()
{
     for(int i = 1;i<=4;++i)
      for(int j = 1;j<=4;++j)
       if(uv.a[i][j] == maxl)
        return 1;
     return 0;
}
bool check(pt * u){
  for(int i = 1;i<=4;++i)
    for(int j = 1;j<=4;++j)
      if(u->a[i][j] == maxl)
        return 1;
     return 0;

}
int dfs(pt * u,int d)
{
 //if(d != 1&&kill1(u)) return -INF;
 //if(double(u->abs(tag)) < double(best)*0.6) return -INF;
 if(d > dep) {
      int rval = u->abs(tag);
      best = max(best,rval);
      return rval;
 }
 int ret=-INF,best=0;
 pt * nst = new pt;
 for(int i = 1;i<=toto;++i){
  int comp = INF;
  if(i == 79)
   i = 79;
  memcpy(nst,u,sizeof(pt));
  int len = strlen(opr[i]+1);
  int j = 1;
  for( j = 1;j<=len&&opr[i][j] != '\n';++j)
  {
   if(check(nst)) break;
   int qq = 0;
   int dir = pq[opr[i][j]];
   mov(nst,qq,dir);
   if(qq == 0) {/*comp = -INF;*/break;}
  }
  if(comp >= INF && j > 1) comp = nst->abs(tag);
  else comp = -INF;
  if(check(nst)) comp = INF;
  dn1(ret,best,comp,pq[opr[i][1]]);
 }
 delete nst;
 return best;
}

int main(int argc, char *argv[])
{
    pq['U'] = 3;pq['D'] = 4;pq['L'] = 1;pq['R'] = 2;
    inp = fopen("sample.in","r");
    //setIO("sample");
    debug = fopen("debug.txt","w");
    FILE *deb = fopen("debug3.txt","w");
    int k =0;
    for(int i = 1;i<=4;++i)
     for (int j = 1;j<=4;++j)
      c[k++] = MP(i,j);
    init(12);
    initknow();
    puts("please enter a number (in 1 ~ 20):");
    scanf("%d",&uv.now);
    ff(debug,"%d\n",uv.now);
    int o = 1;
    uv.proc();uv.proc();
    uv.pf();
    int bk;
    while(1){
    if(check()) 
     break;
    int u = 0;
    ++begin;
    dep = 1;
    int x = dfs(&uv,1);
    ff(debug,"%c",ru[x]);
    if(x == 0){
     x = 0;
      break;
    }
    int t = 0;
    mov(&uv,t,x);
    uv.pf();
    if(!t) 
    {
      t= 0;
     break;}
    printf("%d\n",o);
    o++;
    }
    ff(debug,"\n");
    closeIO();
    return EXIT_SUCCESS;
}
