#include <cstdlib>
#include <queue>
#include <iostream>
#define X first
#define Y second
using namespace std;
int w,h;
const int dx[] = {0,0,0,2,-2};
const int dy[] = {0,2,-2,0,0};
int ans;
char mapx[39*2+1][101*2+1];
int mapy[39*2+1][101*2+1];
int anm[39*2+1][101*2+1];
typedef pair<int,int> PIII;
typedef pair<pair<int,int>,int> PII;

void BFS(PII x)
{
     
     for(int i = 1;i<=2*h+1;i++)
             for(int j = 1;j<=2*w+1;j++)
              if(mapx[i][j] != ' ')
               mapy[i][j] = 1;
               else
               mapy[i][j] = 0x7f7f7f7f;
     int sans = 0;
     queue<PII> Q;
     Q.push(x);
     for(;!Q.empty();)
     {
       PII nx = Q.front();
       Q.pop();
       for(int i = 1;i<=4;i++)
       {
        PII nu = PII(PIII(nx.X.X+dx[i],nx.X.Y+dy[i]),nx.Y+1);
        
        if(mapx[nu.X.X-(dx[i]/2)][nu.X.Y-(dy[i]/2)] != ' '  )
         continue;
        if(nu.X.X < 1 || nu.X.X >2*h+1 || nu.X.Y < 1 || nu.X.Y > 2*w+1 ) 
         continue;
        if(mapy[nu.X.X][nu.X.Y] != 0x7f7f7f7f)
          continue;
        Q.push(nu);
        mapy[nu.X.X][nu.X.Y] = nu.Y;
        sans = max(sans,nu.Y);
       }
     }
     for(int i = 1;i<=2*h+1;i++)
             for(int j = 1;j<=2*w+1;j++)
              anm[i][j] = min(anm[i][j],mapy[i][j]);

}
int main(int argc, char *argv[])
{
    freopen("mr400.in4","r",stdin);
    freopen("mr400.ou4","w",stdout);
    memset(&anm,0x7f,sizeof(anm));
    scanf("%d%d",&w,&h);
   ans = 0;
    for(int i = 0;i<=2*h+1;i++)
    {
            gets(&mapx[i][1]);
    }
    for(int i = 1;i<=2*h+1;i++)
             for(int j = 1;j<=2*w+1;j++)
              if(i % 2 != 0 || j % 2 != 0 )
               anm[i][j] = 0;
    for(int i = 1;i<=2*h+1;i++)
      if(mapx[i][1] == ' ')
       BFS(PII(pair<int,int>(i,2),0));
    for(int i = 1;i<=2*h+1;i++)
      if(mapx[i][2*w+1] == ' ')
       BFS(PII(pair<int,int>(i,2*w),0));
    
    for(int i = 1;i<=2*w+1;i++)
      if(mapx[1][i] == ' ')
       BFS(PII(pair<int,int>(2,i),0));
    for(int i = 1;i<=2*w+1;i++)
      if(mapx[2*h+1][i] == ' ')
       BFS(PII(pair<int,int>(2*h,i),0));
    
    
    for(int i = 1;i<=2*h+1;i++)
             for(int j = 1;j<=2*w+1;j++)
              ans = max(ans,anm[i][j]);
     printf("%d",ans+1);
     fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
