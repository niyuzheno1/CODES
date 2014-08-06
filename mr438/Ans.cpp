#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
const int dx[] = {0,-2 ,-1,-2 ,-1,1,2,1,2};
const int dy[] = {0,1,   2,-1, -2,2,1,-2,-1};
int n,k;
int x[100],y[100];
int mp[100][100];
int f[100][100];
int pp[100];
queue<p> q;
void bfs(int i)
{
     memset(mp,0x7f,sizeof(mp));
     
     q.push(p(x[i],y[i]));
     mp[x[i]][y[i]] = 0;
     while(!q.empty())
     {
      p px = q.front();q.pop();
      for(int i = 1;i<=8;i++){
       int nx,ny;
       nx = px.X+dx[i];
       ny = px.Y+dy[i];
       if(nx >= 1 && nx <= n && ny >= 1 && ny <= n)
       if(mp[nx][ny] > mp[px.X][px.Y]+1)
       {
        mp[nx][ny] = mp[px.X][px.Y]+1;
        q.push(p(nx,ny));
       }
      }
     }
     for(int j = 1;j<=k;j++)
      f[i][j] = mp[x[j]][y[j]];
}
int ans = 0x7f7f7f7f;
void dfs(int x,int y,int z)
{
 if(z > ans)
  return;
 if(y <= 0){
  ans = min(ans,z+f[x][2]);
  return;
 }
 for(int i = 2;i<=k;i++)
  if(pp[i] == 0)
  {
   pp[i] = 1;
   dfs(i,y-1,z+f[x][i]);
   pp[i] = 0;
  } 
}
char inf[1100],ouf[1100];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){

    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr438.in%d",cani);
    sprintf(ouf,"mr438.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(pp,0,sizeof(pp));
    memset(mp,0,sizeof(mp));
    memset(f,0,sizeof(f));
    ans = 0x7f7f7f7f;
    scanf("%d%d",&n,&k);
    x[1] = y[1] = 1;
    for(int i = 2;i<=k+1;i++)
     scanf("%d%d",&x[i],&y[i]);
    k++;
    for(int i = 1;i<=k;i++)
     bfs(i);
    pp[1] = 1;
    pp[2] = 1;
    dfs(2,k-2,0);
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}   

    return EXIT_SUCCESS;
}
