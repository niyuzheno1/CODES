#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
int n,b,k;
int a[251][251];
int c[251][251];
int u;
bool cmp(int x,int y){
 if(u)
  return x>y;
 else
  return x<y;
}
struct px
{
 int key;
 int x;
 bool operator <(px p) const
 {
      return cmp(key,p.key);
 }
};
priority_queue<px> q;
int main(int argc, char *argv[])
{
    scanf("%d%d%d",&n,&b,&k);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
      scanf("%d",&a[i][j]);
    for(int i = 1;i<=n;i++){
     for(int j = 1;j<=n;j++){
     {
      while(!q.empty() && (q.top().x < j-b+1 || q.top().x > j+b-1) )
       q.pop();
      if(!q.empty()){
      c[i][j-b+1<1?1:j-b+1]=max(c[i][j-b+1<1?1:j-b+1],q.top().key);
      c[i][j+b-1>n?n:j+b-1]=max(c[i][j+b-1>n?n:j+b-1],q.top().key);
      }
      px nq;
      nq.key = a[i][j];
      nq.x  = j;
      q.push(nq);
      }
    }
     while(!q.empty())
      q.pop();
    }
    for(int i = 1;i<=n;i++){
     for(int j = 1;j<=n;j++)
      printf("%d ",c[i][j]);
     printf("\n");
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
