#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define X first
#define Y second
using namespace std;
int n,b,k;
typedef pair<int,int> p2;
typedef pair<int,p2> p;
priority_queue<p,vector<p>,greater<p> > q;
priority_queue<p,vector<p>,less<p> > q2;
int a[251][251];
int ans[251][251];
bool del(int i,int j,p2 t)
{
      if(i+b <= t.X || i > t.X)
       return 1;
      else if(j+b <= t.Y || j > t.Y)
       return 1;
      return 0;
}
void down(int x,int y)
{
     for(int i = y;i<=min(n,y+b-1);i++){
      q.push(p(a[x][i],p2(x,i)));
      q2.push(p(a[x][i],p2(x,i)));
     }
}
void tr(int x,int y)
{
 if(y+b > n)
  return;
 for(int i = x;i<=x+b-1;i++)
  if(i <= n){
  q.push(p(a[i][y+b],p2(i,y+b)));
  q2.push(p(a[i][y+b],p2(i,y+b)));
 }
}
void tl(int x,int y)
{
 if(y-1 <= 0)
  return;
 for(int i = x;i<=x+b-1;i++)
  if(i <= n)
  {
  q.push(p(a[i][y-1],p2(i,y-1)));
  q2.push(p(a[i][y-1],p2(i,y-1)));
  }
}
int main(int argc, char *argv[])
{
    freopen("cornfld.in","r",stdin);
    freopen("cornfld.out","w",stdout);
    scanf("%d%d%d",&n,&b,&k);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      scanf("%d",&a[i][j]);
    for(int i = 1;i<=b;i++)
     for(int j = 1;j<=b;j++)
      q.push(p(a[i][j],p2(i,j))),q2.push(p(a[i][j],p2(i,j)));
    int d = 1,j=0;
    for(int i = 1;i<=n;i++)
    {
     for(int k = 1;k<=n;k++)
     {
      j+=d;
      while(!q.empty()){
       p2 t = q.top().Y;
       if(del(i,j,t))
        q.pop();
       else
        break;
      }
      while(!q2.empty()){
       p2 t = q2.top().Y;
       if(del(i,j,t))
        q2.pop();
       else
        break;
      }
      ans[i][j] = abs(q.top().X-q2.top().X);
      if(d > 0)
       tr(i,j);
      else
       tl(i,j);
      
     }
     down(i+b,j);
     j+=d;
     d = -d;
    }
    for(int i = 1;i<=k;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     printf("%d\n",ans[x][y]);
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
