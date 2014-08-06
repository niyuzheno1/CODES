#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
int T;
int n;
struct p
{
 int r,d,w;
 bool operator <(p b) const
 {
     return d<b.d;
 }
};
p h[10010];
p m[10010];
bool cmp1(p a, p  b)
{
     return a.r<b.r;
}
void clean(priority_queue<p> & x ,int su)
{
  while(!x.empty() && su != 0){
   p y = x.top();
   y.w -= su;
   if(y.w < 0)
     su = abs(y.w);
   else
   {
    su = 0;
    x.push(y);
   }
  }
}
bool ok(int v)
{
 memcpy(m,h,sizeof(m));
 sort(m+1,m+1+n,cmp1);
 priority_queue<p> q;
 int w = 0;
 for(int i = 1;i<=n;i++)
 {
  int su = (m[i].r-w)*v;
  clean(q,su);
 }
}
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d%d",&h[i].r,&h[i].d,&h[i].w);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
