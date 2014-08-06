#include "mode.h"
const int MUL = 8221;
typedef map<int,int> mp;
mp fx;
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
    printf("%d ",a[i][j]);
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
void enter(){
 best = -INF;
}
void dn1(int & u ,int & v,int x,int y)
{
     if(u < x)
      u = x, v = y;
}
#define begin beginx
int begin = 0;
int dep = 4;
const int atbegin = 0;
bool kill1(pt * u)
{
     for(int i = 0;i<=15;++i)
      {
       int ux = u->a[c[i].X][c[i].Y];
       for(int j = i+1;j<=15;++j)
       {
        int uy = u->a[c[j].X][c[j].Y];
        if(uy - ux >= 5 && (ux > 6 || uy > 6))
         return 1;
       }
      }
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
 int ret = -INF,bn = 0;
 pt * nst = new pt;
 memcpy(nst,u,sizeof(pt));
 int uu = 0,vv = 0,pp=0;
 mov(nst,uu,1);if(uu){//dn1(ret,bn,dfs(nst,d+1),1);
                      if(d == 1 && begin<=atbegin)
                      return 1;
                      else{
                      int reta = dfs(nst,d+1);
                      dn1(ret,bn,reta,1);
                      }
 }
 memcpy(nst,u,sizeof(pt));
 mov(nst,vv,3);if(vv){//dn1(ret,bn,dfs(nst,d+1),3);
   if(d == 1 && begin<=atbegin)
   return 3;
   else{
    int reta = dfs(nst,d+1);
   dn1(ret,bn,reta,3);
   }
 }
 /*if(uu == 0 && vv == 0)
 {*/
  memcpy(nst,u,sizeof(pt));
  mov(nst,pp,2);if(pp){
    int reta = dfs(nst,d+1);
                       dn1(ret,bn,reta,2);
                       }
  memcpy(nst,u,sizeof(pt));
  pp =0;mov(nst,pp,4);
  if(pp){
         int reta = dfs(nst,d+1);
         dn1(ret,bn,reta,4);
         }
 //}
 delete nst;
 if(d == 1)
  return bn;
 return ret;
}
map<char,int> pq;
char str3[5];
bool check()
{
     for(int i = 1;i<=4;++i)
      for(int j = 1;j<=4;++j)
       if(uv.a[i][j] == 15)
        return 1;
     return 0;
}
int main(int argc, char *argv[])
{
    pq['w'] = 3;pq['s'] = 4;pq['a'] = 1;pq['d'] = 2;
    inp = fopen("sample.in","r");
    //setIO("sample");
    debug = fopen("debug.txt","w");
    FILE *deb = fopen("debug3.txt","w");
    for(int i = 1;i<=15;++i)
     fx[1<<i] = i;
    int k =0;
    for(int i = 1;i<=4;++i)
     for (int j = 1;j<=4;++j)
      c[k++] = MP(i,j);
    init(12);
    /*for(int i = 1;i<=4;printf("\n"),++i)
     for(int j = 1;j<=4;++j)
      printf("%d ",tag.a[i][j]);*/
    puts("please enter a number (in 1 ~ 20):");
    scanf("%d",&uv.now);
    ff(debug,"%d\n",uv.now);
    int o = 1;
    uv.proc();uv.proc();
    uv.pf();
    int bk;
    while(1){
     if(check()) break;
   // ff(deb,"%d\n",uv.now);
    enter();
	if(o <= 100 && o >= 1)
		 dep = 4;
    if(o >= 101 && o <= 1001)
		 dep = 5;
	if(o >= 1002 && o <= 10001)
		 dep = 7;
	if(o >= 10002 && o <= 12000)
		 dep = 8;
    if(o >= 12001)
         dep = 7;
    if(o >= 15000)
         dep = 10;
	if(o == 4||o==5)
     bk  = 1;
    int u = 0;
    /*while(((o  == 15631)&& u <= 29 )){
    int tt = 0;
    uv.pf();
    scanf("%s",str3);
    if(str3[0] == '-') break;
    int d = pq[str3[0]];
    ff(debug,"%c",ru[d]);
    mov(&uv,tt,d);
    ++u;
    }*/
    ++begin;
    int x = dfs(&uv,1);
    ff(debug,"%c",ru[x]);
    if(x == 0){
     x = 0;
      break;
    }
    int t = 0;
    mov(&uv,t,x);
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
