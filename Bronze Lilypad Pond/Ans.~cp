#include <cstdlib>
#include <iostream>

using namespace std;
const int dx[] = {0,1,-1,-1,1};
const int dy[] = {0,1,-1,1,-1};
int M,N,M1,M2;
int pos[30*30*30][2];
int map[31][31];
int vis[31][31];
int front,top;
int main(int argc, char *argv[])
{
    memset(&vis,0x7f,sizeof(vis));
    scanf("%d %d %d %d",&N,&M,&M1,&M2);
    for(int i = 1;i<=N;i++)
     for(int j = 1;j<=M;j++)
     {
      scanf("%d",&map[i][j]);
      if(map[i][j] == 3){
       map[i][j] = 1;
       top++;pos[top][0] = i;pos[top][1] = j;
       vis[i][j] = 0;
       }
     }
    
    while(true)
    {
     int x,y;
     x = pos[front][0];y = pos[front][1];front++;
     for(int i = 1;i<=4;i++)
     {
      int nx,ny;
      nx = dx[i]*M1+x;
      ny = dy[i]*M2+y;
      if(nx > 0 && nx <= N)
       if(ny > 0 && ny <= M)
        if(vis[nx][ny] > vis[x][y] + 1){
        vis[nx][ny] = vis[x][y] + 1;
        top++;
        pos[top][0] = nx;pos[top][1] = ny;
       }
     }
     for(int i = 1;i<=4;i++)
     {
      int nx,ny;
      nx = dx[i]*M2+x;
      ny = dy[i]*M1+y;
      if(nx > 0 && nx <= N)
       if(ny > 0 && ny <= M)
        if(vis[nx][ny] > vis[x][y] + 1){
        vis[nx][ny] = vis[x][y] + 1;
        top++;
        pos[top][0] = nx;pos[top][1] = ny;
       }
     }
     if(vis[N][M] != 0x7f7f7f7f)
      break;
    }
    printf("%d",vis[N][M]);    
    system("PAUSE");
    return EXIT_SUCCESS;
}
