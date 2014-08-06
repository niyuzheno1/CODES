#include "mode.h"
int N;
const int MN = 152;
const int dx[] = {0,0,1,0,-1};
const int dy[] = {0,1,0,-1,0};
int f[MN][MN];
bool check(pii u)
{
     for(int i = 1;i<=4;++i)
      if(!f[u.X+dx[i]][u.Y+dy[i]])
       return true;
     return false;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    N = gi;
    N+=2;
    for(int i = 1;i<=N;++i)f[i][N] = 1,f[i][1] = 1;
    for(int i = 1;i<=N;++i)f[N][i] = 1,f[1][i] = 1;
    pii d = MP(2,2);
    int cnt = 1,k = 1;f[2][2] = 1;
    while(check(d))
    {
     int nx = d.X+dx[k];
     int ny = d.Y+dy[k];
     while(f[nx][ny]){
      k++,k%=5,k=k?k:1;
      nx = d.X+dx[k],ny = d.Y+dy[k];
     }
     ++cnt;f[nx][ny] = cnt;d = MP(nx,ny);
    }
    for(int i =2;i<=N-1;printf("\n"),++i)
     for(int j = 2;j<=N-1;++j)
      printf("%6d",f[i][j]);
    closeIO();
    return EXIT_SUCCESS;
}
