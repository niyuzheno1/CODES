#include "mode.h"
#undef INF
#define INF 10000
#define MN 1005
#define MM 10000000
const int dr[] = {0,-1,0,1,0};
const int dc[] = {0,0,1,0,-1};
struct rec{ pii d;int dist,next;};
int r,c;
char a[MN][MN];
inline bool IN(int nx,int ny) {
   return 1<=nx && nx <= r && 1<=ny &&ny<=c&&a[nx][ny] == '.';
}
pii sta,end;
int dtw[MN][MN],sc[5][MN][MN],tt[MN][MN],nft[MM];
rec ll[MM];
pii q[(MM)*2];
void cdtw()
{
     int qs=1,qe=1;
     for(int i = 1;i<=r;++i)
      for(int j = 1;j<=c;++j)
       if(a[i][j] == '#')
        q[qe] = MP(i,j),++qe,dtw[i][j] = 0;
       else
        dtw[i][j] = INF;
     while(qs != qe)
     {
      pii u = q[qs];++qs;
      for(int i = 1;i<=4;++i)
      {
       int nx = u.X+dr[i];
       int ny = u.Y+dc[i];
       if(1<=nx && nx <= r && 1<=ny &&ny<=c && dtw[nx][ny] == INF)
       {
       dtw[nx][ny] = 1+dtw[u.X][u.Y];
       q[qe] = MP(nx,ny);++qe;
       }
      }
     }
}
void csc()
{
 for(int i = 1;i<=r;++i)
  for(int j = 1;j<=c;++j)
   {
    if(a[i][j] == '#') sc[1][i][j] = i,sc[4][i][j] = j;
    else sc[1][i][j] = sc[1][i-1][j],sc[4][i][j] = sc[4][i][j-1];
    int ii = r-i+1,ij = c-j+1;
    if(a[ii][ij] == '#') sc[2][ii][ij] = ij,sc[3][ii][ij] = ii;
    else sc[2][ii][ij] = sc[2][ii][ij+1],sc[3][ii][ij] = sc[3][ii+1][ij];
   }
}
int nc;
void upd(pii u,int nd)
{
     if(tt[u.X][u.Y] <= nd) return;
     tt[u.X][u.Y] = nd,ll[nc].d = u,ll[nc].dist = nd,ll[nc].next = nft[nd],nft[nd] = nc;
     ++nc;
}
void process(int id)
{
 pii dcc = ll[id].d;
 int dist = ll[id].dist;
 if(dist != tt[dcc.X][dcc.Y]) return;
 for(int i = 1;i<=4;++i){
  int nx = dcc.X + dr[i];
  int ny = dcc.Y + dc[i];
  if(IN(nx,ny))
   upd(MP(nx,ny),dist+1);
 }
 upd(MP(sc[1][dcc.X][dcc.Y]+1,dcc.Y),dist+dtw[dcc.X][dcc.Y]);
 upd(MP(sc[3][dcc.X][dcc.Y]-1,dcc.Y),dist+dtw[dcc.X][dcc.Y]);
 upd(MP(dcc.X,sc[2][dcc.X][dcc.Y]-1),dist+dtw[dcc.X][dcc.Y]);
 upd(MP(dcc.X,sc[4][dcc.X][dcc.Y]+1),dist+dtw[dcc.X][dcc.Y]);
}
int wintime()
{
 nc = 1;
 for(int i = 1;i<=r;++i)
  for(int j = 1;j<=c;++j) tt[i][j] = INF;
 for(int i = 0;i<=MM/10;++i)nft[i] = 0;
 tt[sta.X][sta.Y] = 0;
 ll[nc].d = sta;
 ll[nc].dist = 0;
 ll[nc].next = 0 ;
 nft[0] = nc;
 ++nc; 
 for(int i = 0;i<=MM/10;++i)
 {
  int u = nft[i];
  while(u != 0)
  {
   if(ll[u].d == end)
    return i;
   process(u);
   u = ll[u].next;
  }
 }
 return -INF;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    r = gi,c = gi;
    for(int i = 2;i<=r+1;++i)
     for(int j = 2;j<=c+1;++j){
      a[i][j] = getchar();
      while(a[i][j] != '#' && a[i][j] != '.' && a[i][j] != 'S' && a[i][j] != 'C')a[i][j] = getchar();
      if(a[i][j] == 'S')
       sta = MP(i,j),a[i][j] = '.';
      else if(a[i][j] == 'C')
       end = MP(i,j),a[i][j] = '.';
     }
    r = r+2;c = c+2;
    for(int i = 1;i<=c;++i) a[r][i] = a[1][i] = '#';
    for(int i = 1;i<=r;++i) a[i][c] = a[i][1] = '#';
    cdtw();
    csc();
    
    printf("%d\n",wintime());
    closeIO();
    return EXIT_SUCCESS;
}
