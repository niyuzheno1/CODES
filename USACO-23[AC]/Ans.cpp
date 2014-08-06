#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#include <vector>
#define pb push_back
using namespace std;
typedef vector<int> v;
const int dx[]= {0,1,-1,0,0};
const int dy[]= {0,0,0,1,-1};
v d;
map<int,v> w;
map<int,int> pp;
queue<int> q;

int m,n;
bool operator< (v x,v y)
{
     for(int i = 1;i<=m*n;i++)
      if(x[i] > y[i])
       return false;
      else if(x[i] < y[i])
       return true;
     return false;
}
int a(int x,int y)
{
    if(x < 1 || x > m)
     return -1;
    if(y < 1 || y > n)
     return -1;
    return (x-1)*n+y;
}
int p(int x)
{
    for(int i = 1;i<=m;i++){
     for(int j = 1;j<=n;j++)
      if((x & (1<<a(i,j))) != 0)
       printf("1 ");
      else
       printf("0 ");
     printf("\n");  
    }
}
void s()
{
     if(pp[0] == 0)
      printf("IMPOSSIBLE\n");
     else
     for(int i = 1;i<=m;i++){
      for(int j = 1;j<=n-1;j++)
       printf("%d ",w[0][a(i,j)]);
      printf("%d\n",w[0][a(i,n)]);
      
     }
}
int main(int argc, char *argv[])
{
    freopen("fliptile.in","r",stdin);
    freopen("fliptile.out","w",stdout);
    scanf("%d%d",&m,&n);
    int y = 0;
    for(int i = 1;i<=m;i++)
     for(int j = 1;j<=n;j++)
     {
      int x = 0;
      scanf("%d",&x);
      y = y^(x<<(a(i,j)));
     }
    d.pb(0);
    for(int i = 1;i<=m;i++)
     for(int j = 1;j<=n;j++)
      d.pb(0);
    w[y] = d;
    q.push(y);
    pp[y] = 0;
    while(!q.empty() && (pp[0]== 0||pp[0]>=pp[q.front()]+1))
    {
     int t = q.front();q.pop();
     for(int i = 1;i<=m;i++)
      for(int j = 1;j<=n;j++)
      {
       int ot = t;
       v tmp = w[t];
       for(int k = 0;k<=4;k++)
       {
        int y = a(i+dx[k],j+dy[k]);
        if(y != -1)
         ot = ot ^ (1<<(y));
       }
       tmp[a(i,j)]++;
       if(pp[ot] == 0 || (pp[ot] > pp[t]+1)){
        pp[ot] = pp[t]+1;
        w[ot] = tmp;
        q.push(ot);
       }
       else if(pp[t]+1 == pp[ot] && tmp < w[ot] ){
        pp[ot] = pp[t]+1;
        w[ot] = tmp;
        q.push(ot);
       }
      }
    }
    s();
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
