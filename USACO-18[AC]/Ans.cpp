#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;
const int maxn = 1000010;
int n;
int h[maxn];
int t[maxn];
struct p
{
      int h;
      int n;
      p(int x,int y)
      {
       h = x;n = y;
      }
};
stack<p> u;
int main(int argc, char *argv[])
{
    freopen("lookup.in","r",stdin);
    freopen("lookup.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&h[i]);
    for(int i = n;i>=1;i--)
    {
     while(true)
     {
      if(u.empty())
       break;
      p x = u.top();u.pop();
      if(h[i] < x.h)
      {
       t[i] = x.n;
       u.push(p(x.h,x.n));
       break;
      }
     }
     u.push(p(h[i],i));
    }
    for(int i = 1;i<=n;i++)
     printf("%d\n",t[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
