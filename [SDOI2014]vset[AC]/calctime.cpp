#include "mode.h"
#include "data.h"
typedef long long LL;
int u[200010];
int main(int argc, char *argv[])
{
    srand(time(0));
     double ans = 0 ;
    for(LL i = 1;i<=200000;u[i] = lb(i),++i)
     ans += double(lb(i))+double(lb(i))*log(double(lb(i)))/log(2.0);
    for(LL i = 1;i<=200000;++i)
    {
           int x = rand()%200000;
           int y = rand()%200000;
           for(LL j = y;j>=x;--j)
           {
            if(j-u[j]< x)
             --j,++ans;
            else
             j = j-u[j],++ans;
           }
    }
    printf("%f",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
