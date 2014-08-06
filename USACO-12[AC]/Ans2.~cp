#include <cstdlib>
#include <iostream>

using namespace std;
int n;
struct p
{
      int v,x;
      bool operator <(p x) const 
      {
           return v < x.v;
      }
};
p q[20010];
int s[20010];
int s1[20010];
int maxx;
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&q[i].v,&q[i].x),maxx = max(maxx,q[i].x);
    sort(q+1,q+1+n);
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
     int x = q[i].x;
     int y = 0;
     int z = 0;
     for(int j = 1;j<x;j++)
     {
     z += s1[j];y += s[j];
     }
     ans += (y*x-z)*q[i].v;
     y = z = 0;
     for(int j = x;j<=maxx;j++)
     {
     z += s1[j];y += s[j];
     }
     ans += (z-y*x)*q[i].v;
     y = z = 0;
     s[x] = 1;
     s1[x] = x;
    }
    printf("%d\n",ans);
    
    return EXIT_SUCCESS;
}
