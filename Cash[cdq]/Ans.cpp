#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn = 1010;
double a[maxn],b[maxn],c[maxn];
double f[maxn];
int main(int argc, char *argv[])
{
    freopen("cash.in","r",stdin);
    freopen("cash.out","w",stdout);
    int n;double x;
    scanf("%d%lf",&n,&x);
    for(int i = 1;i<=n;i++)
     scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
    f[1] = x*c[1]/(a[1]*c[1]+b[1]);
    double ans = x;
    for(int i = 2;i<=n;i++){
     for(int j = 1;j<=i-1;j++)
       ans = max(ans,f[j]*a[i]+f[j]/c[j]*b[i]);
     f[i] = ans*c[i]/(a[i]*c[i]+b[i]); 
    }
    printf("%lf",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
