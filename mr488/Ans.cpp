#include <cstdlib>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#define X first
#define Y second
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
typedef pair<int,int> p;
const int INF = 0x7f7f7f7f;
const int dx[] = {0,0,0,1,-1};
const int dy[] = {0,1,-1,0,0};
char l[31][31];
int f[910][910];
char inf[101],ouf[101];
int n,m,t;
int cal(int x,int y)
{
 return ((x-1)*(m)+y > 0 && (x-1)*(m)+y <= n*m) ?(x-1)*(m)+y : 0 ;
}
double dis(double x1,double y1,double x2,double y2)
{
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void bfs(int x,int y)
{
 int c = cal(x,y);
 queue<p> q;
 q.push(p(x,y));
 while(!q.empty())
 {
  p to = q.front();q.pop();
  int d = f[c][cal(to.X,to.Y)];
  for(int i = 1;i<=4;i++)
  if(to.X+dx[i] <= n && to.X+dx[i] >= 1)
  if(to.Y+dy[i] <= m && to.Y+dy[i] >= 1)
  if(f[c][cal(to.X+dx[i],to.Y+dy[i])] > d+(l[to.X+dx[i]][to.Y+dy[i]]-'0')){
   f[cal(to.X+dx[i],to.Y+dy[i])][c] = f[c][cal(to.X+dx[i],to.Y+dy[i])] = d+(l[to.X+dx[i]][to.Y+dy[i]]-'0');
   q.push(p(to.X+dx[i],to.Y+dy[i]));
  }
 }
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr488.in%d",cani);
    sprintf(ouf,"mr488.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    zero(l);zero(f);
    scanf("%d%d%d",&n,&m,&t);
    for(int i = 1;i<=n;i++)
    {
    scanf("%s",&l[i][1]); 
    }
    memset(f,0x7f,sizeof(f));
    for(int x = 1;x<=n;x++)
     for(int y = 1;y<=m;y++)
     if(l[x][y] == '1')
      f[cal(x,y)][cal(x,y)] = 1;
     else
      f[cal(x,y)][cal(x,y)] = 0;
    for(int x = 1;x<=n;x++)
     for(int y = 1;y<=m;y++)
      bfs(x,y);
      
    double ans = 0;
    
    for(int x = 1;x<=n;x++)
     for(int y = 1;y<=m;y++)
      for(int k = 1;k<=n;k++)
       for(int h = 1;h<=m;h++)
        if(f[cal(x,y)][cal(k,h)] <= t)
        if(ans < dis(x,y,k,h)){
        
         ans = max(ans,dis(x,y,k,h));
        }
      
    printf("%.6f",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
