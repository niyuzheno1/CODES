#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define dprint(x,y) fprintf(debug,x,y)
using namespace std;
const int maxn = 1010;
typedef int mat[maxn][maxn];
FILE * debug;
int m,n,b,a,d,c;
mat e;
mat f;
mat g;
mat h;
mat k;
mat u;
struct p
{
 int x,y;
 int v;
 p()
 {
  x = y = v = 0;
 }
 p(int x,int y,int v)
 {
  this->x = x;
  this->y = y;
  this->v = v;
 }
 bool operator < (p  a) const 
 {
  return v > a.v;
 }
};
priority_queue<p> q[maxn];
priority_queue<p> qmin;
void print(mat x)
{
     for(int i = 1;i<=n;i++){
      for(int j = 1;j<=m;j++)
       dprint("%d ",x[i][j]);
      dprint("\n",0);
      }
}
int main(int argc, char *argv[])
{
    freopen("pyramid.in","r",stdin);
    freopen("pyramid.out","w",stdout);
    debug = fopen("debug","w");
    scanf("%d%d%d%d%d%d",&m,&n,&b,&a,&d,&c);
    a--;b--;c--;d--;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      scanf("%d",&e[i][j]);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      f[i][j] = f[i][j-1]+e[i][j];
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
      h[i][j] = h[i-1][j]+f[i][j];

    for(int i = 1;i<=n-a;i++)
     for(int j = 1;j<=m-b;j++)
      g[i][j] = h[i+a][j+b]-h[i+a][j-1]-h[i-1][j+b]+h[i-1][j-1];
    
    for(int i = n-c;i>=1;i--){
     while(!qmin.empty())
      qmin.pop();
     for(int j = m-d;j>=1;j--)
     {
      while(!q[j].empty() && q[j].top().x+c>=i+a)
       q[j].pop();
      while(!qmin.empty()){
       p ux = qmin.top();
       if(ux.y + d >= j + b)
        qmin.pop();
       else
        break;
      }
      if(!qmin.empty())u[i][j] = qmin.top().v;
      if(!q[j].empty())qmin.push(q[j].top());
      q[j].push(p(i,j,h[i+c][j+d]-h[i+c][j-1]-h[i-1][j+d]+h[i-1][j-1]));
     }
    }
    print(u);
    int ans = 0;
    for(int i = 1;i<=n-a;i++)
     for(int j = 1;j<=m-b;j++)
      ans = max(ans,g[i][j]-u[i][j]);
     
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    fclose(debug);
    return EXIT_SUCCESS;
}
