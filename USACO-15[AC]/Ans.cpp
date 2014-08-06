#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
const int64 inf = 0x7f7f7f7f;
int64 n;
struct p
{
      int64 w,s;
      bool operator <(p x) const 
      {
       return w+s < x.w+x.s;
      }
};
p q[50010];
int main(int argc, char *argv[])
{
    freopen("acrobat.in","r",stdin);
    freopen("acrobat.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&q[i].w,&q[i].s);
    sort(q+1,q+1+n);
    int64 ans = -inf;
    int64 sum = 0;
    for(int64 i = 1;i<=n;i++){
     ans = max(ans,sum - q[i].s);
     sum += q[i].w;
    }
    printf("%I64d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
