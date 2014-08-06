#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
const int maxm = 310, maxf = 30;
const int dx[] = {0,0,0,-1,1};
const int dy[] = {0,1,-1,0,0};
int N,M;
char MA[maxm][maxm];
int Ma[maxm][maxm];
int vis[maxm][maxm];
int P[maxf][6];
int st[3],ed[3];
struct Qtype
{
  int x,y,dis;
  bool operator < (Qtype X) const
  {
   return X.dis < dis;
  }
  void calc()
  {
   dis = abs(x-ed[0])+abs(y-ed[1]);
  }
  void operator = (Qtype X)
  {
    x = X.x; y = X.y; dis = X.dis; 
  }
};
queue<Qtype> q;
void Add(int x,int y,int step)
{
 Qtype qx;
 qx.x = x;
 qx.y = y;
 vis[x][y] = step;
 qx.calc();
 q.push(qx);
}
int main(int argc, char *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    scanf("%d%d",&N,&M);
    memset(&vis, 0x7f ,sizeof( vis ));
    for(int i = 1;i<=N;i++){
	scanf("%s",&MA[i][1]);
	for(int j = 1;j<=M;j++){
	  switch(MA[i][j])
	  {
	   case '#':
		Ma[i][j] = 0;
		break;
	   case '=':
		Ma[i][j] = 1;
		ed[0] = i;ed[1] = j;
		break;
	   case '.':
		Ma[i][j] = 1;
		break;
	   case '@':
		Ma[i][j] = 1;
		st[0] = i;st[1] = j;
		break;
	  }
	 if(MA[i][j]>='A' && MA[i][j] <= 'Z')
	  {
	   Ma[i][j] = 1+MA[i][j]-'A'+1;
	   P[1+MA[i][j]-'A'+1][P[1+MA[i][j]-'A'+1][0]+1] = i;
	   P[1+MA[i][j]-'A'+1][P[1+MA[i][j]-'A'+1][0]+2] = j;
	   P[1+MA[i][j]-'A'+1][0]+=2;
	  }       
	}
    }
    Add(st[0],st[1],0);
    while(!q.empty())
    {
     Qtype X = q.front();q.pop();
	if(vis[X.x][X.y] > vis[ed[0]][ed[1]])
		  continue;
    
     for(int i = 1;i<=4;i++)
     {
      int nx = dx[i]+X.x;
      int ny = dy[i]+X.y;
      if(Ma[nx][ny] != 0 && vis[nx][ny] > vis[X.x][X.y]+1)
	 if(Ma[nx][ny] >= 2 && Ma[nx][ny] <= 27)
	 { if( P[Ma[nx][ny]][2] == ny && P[Ma[nx][ny]][1] == nx){
	                   Add(P[Ma[nx][ny]][3],P[Ma[nx][ny]][4],vis[X.x][X.y]+1);
		 }
          else{
	       
			  Add(P[Ma[nx][ny]][1],P[Ma[nx][ny]][2],vis[X.x][X.y]+1);
		}
	 }else{
	   Add(nx,ny,vis[X.x][X.y]+1);
	 }
	} 
     }
    
    printf("%d",vis[ed[0]][ed[1]]);

    return EXIT_SUCCESS;
}
