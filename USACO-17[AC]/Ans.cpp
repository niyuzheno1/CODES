#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;
typedef long long int64;
int64 n;
long long v = 123456789;
void a(int64 & x,int64 y)
{
  x = (x+y)%(v);
}
void b(int64 & x,int64 y)
{
 x = (x%v)*(y%v);
 x %=v;
}
struct c
{
 bool k;
 int64 s;
 c(bool x,int64 y)
 {
  k = x;
  s = y;
 }
};
stack<c> s;
int p[100010];
int main(int argc, char *argv[])
{
    freopen("paren.in","r",stdin);
    freopen("paren.out","w",stdout);
    v *=100;
    v += 10;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&p[i]);
    for(int i = 1;i<=n;i++)
     if(p[i] == 0)
      s.push(c(true,0));
     else
     {
      int64 ret = 0;
      while(true)
      {
       c u  = s.top();s.pop();
       if(u.k == true)
        break;
       a(ret, u.s);
      }
      if(ret == 0)
       ret = 1;
      else
       b(ret,2);
      s.push(c(false,ret));
     }
    int64 ans = 0;
    while(!s.empty()){
     a(ans, s.top().s);s.pop();
    }
    printf("%I64d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
