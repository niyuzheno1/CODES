#include <cstdlib>
#include <iostream>

using namespace std;
const int dx[] = {0,0,0,1,-1};
const int dy[] = {0,-1,1,0,0};
int n;
int a[110][110];
int b[110][110];
int p = 0x7f7f7f7f,t = 0;
void dfs(int x,int y,int ax,int bx)
{
 b[x][y] = 1;
 for(int i = 1;i<=4;i++)
 {
  int nx = x+dx[i];
  int ny = y+dy[i];
  if(a[nx][ny]<=bx&&a[nx][ny] >= ax)
   if(!b[nx][ny])
   dfs(nx,ny,ax,bx);
 } 
}
bool ok(int x)
{
 for(int i = p;i<=t-x;i++)
 {
  memset(&b,0,sizeof(b));
  if(a[1][1]<=i+x && a[1][1]>=i)
  dfs(1,1,i,i+x);
  if(b[n][n] == true)
   return true;
 }
 return false;
}
int main(int argc, char *argv[])
{
    memset(a,0x7f,sizeof(a));
    int l,r;
    l = r = 0;
     
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++){
      scanf("%d",&a[i][j]);
      p = min(p,a[i][j]);
      t = max(t,a[i][j]);
     }
    r = t-p+1;
    while(l < r)
    {
     int mid = (l+r)/2;
     if(ok(mid))
      r = mid;
     else
      l = mid+1;
    }
    printf("%d",(l+r)/2);
  
    return EXIT_SUCCESS;
}
