#include "mode.h"
pii c[16];

int MUL = 8221;
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

int getrand(int seq)
{
    return (seq = (seq*MUL)+(seq>>16))&15;
}
struct pt
{
 int a[5][5],now;
 int abs(pt & u)
 {
  int ret = 0;
  for(int i = 1;i<=4;++i)
   for(int j = 1;j<=4;++j)
    ret += sqr(a[i][j]-u.a[i][j]);
  return ret;
 }
 void proc()
 {
  now = getrand(now);
  while(a[c[now].X][c[now].Y])
  {now = getrand(now);}
  a[c[now].X][c[now].Y] = 1;
 }
};
pt b;
const string ru = "0LRUD";
bool range(int x,int y){
 return x<=4&&x>=1&&y<=4&&y>=1;
}

void mov(pt * ax,int & u,int v)
{
 ax->proc();
 for(int i = sx[v];i!=ex[v];i+=nx[v])
  for(int j = sy[v];j!=ey[v];j+=ny[v])
   if(ax->a[i][j]){
   int x = i+dx[v],y = j+dy[v];
   while(range(x,y)){
    if(ax->a[x][y] == ax->a[i][j]){
    ax->a[i][j] = 0;++ax->a[x][y];++u;
    }
    if(ax->a[x][y]) break;
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
  
}

int main()
{
    setIO("sample");
    int k = 0;
    for(int i = 1;i<=15;++i)
     fx[1<<i] = i;
    for(int i = 1;i<=4;++i)
     for (int j = 1;j<=4;++j)
      c[k++] = MP(i,j);
    for(int i = 1;i<=4;++i)
     for (int j = 1;j<=4;++j)
      b.a[i][j] = gi;
    k = gi;
    int time = 0;
    mov(&b,time,k);
    printf("%d\n",time);
    for(int i = 1;i<=4;printf("\n"),++i)
     for(int j = 1;j<=4;++j)
      printf("%d ",b.a[i][j]);
    closeIO();
    return EXIT_SUCCESS;
}
