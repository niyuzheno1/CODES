#include <cstdlib>
#include <iostream>

using namespace std;

typedef long long int64;
const int64 inf = 0x7f7f7f7f;
int64 n;
struct q
{
       int64 a,b,c;
       bool operator <(q x) const
       {
            return c < x.c;
       }
};
q p[25010];

int main(int argc, char *argv[])
{
    freopen("mqueue.in","r",stdin);
    freopen("mqueue.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++){
     scanf("%I64d%I64d",&p[i].a,&p[i].b);
     if(p[i].a > p[i].b)
      p[i].c = inf-p[i].b;
     else
      p[i].c = p[i].a;
    }
    sort(p+1,p+1+n);
    int64 b = 0,a =0;
    for(int64 i = 1;i<=n;i++)
     b+=p[i].b;
    int64 ans= -inf;
    for(int64 i = 1;i<=n;i++)
    {
     a+=p[i].a;
     ans = max(ans,a+b);
     b-=p[i].b;
    }
    printf("%I64d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
