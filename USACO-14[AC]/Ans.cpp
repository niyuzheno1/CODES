#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
int64 n;
struct p
{
      int64 a,b;
      bool operator < (p x) const
      {
           
           return a * x.b < b * x.a ;
      }
};
p q[100010];
int main(int argc, char *argv[])
{
    freopen("flowers.in","r",stdin);
    freopen("flowers.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&q[i].a,&q[i].b);
    sort(q+1,q+1+n);
    int64 t = 0,ans = 0;
   
    for(int64 i = 1;i<=n;i++)
    {
     ans += q[i].b*(t);
     t += 2*q[i].a;
    }
    printf("%I64d",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
