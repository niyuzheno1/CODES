#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
struct st
{
 int i,n;
 int key;
 bool operator < (st x) const
 {
  if(i == x.i)
   return key>x.key;
  else
   return i > x.i;
 }
};
priority_queue<st> q;
int n,e,k;
struct p
{
 int x,f,c;
 bool operator < (p px) const
 {
  return x < px.x;
 }
};
p h[10010];
int main(int argc, char *argv[])
{
    scanf("%d%d%d",&n,&e,&k);
    for(int i = 1;i<=k;i++)
     scanf("%d%d%d",&h[i].x,&h[i].f,&h[i].c);
    sort(h+1,h+k+1);
    st s;
    s.i = 0;s.key = 0;s.n = 0;
    q.push(s);
    for(int i = 1;i<=k;i++)
    {
     while(!q.empty() && q.top().i < i-1)
      q.pop();
     
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
