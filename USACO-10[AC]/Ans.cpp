#include <cstdlib>
#include <iostream>

using namespace std;
long long n;
long long a[100010],b[100010];
long long c[100010];
int main(int argc, char *argv[])
{
    freopen("restack.in","r",stdin);
    freopen("restack.out","w",stdout);
    scanf("%I64d",&n);
    for(long long i = 1;i<=n;i++)
     scanf("%I64d%I64d",&a[i],&b[i]);
    c[1] = a[1]-b[1];
    for(long long i = 2;i<=n;i++)
     c[i] = c[i-1]+a[i]-b[i];
    sort(c+1,c+1+n);
    long long m = c[n/2+1];
    long long ans = 0;
    for(long long i = 1;i<=n;i++)
     ans += abs(c[i]-m);
    printf("%I64d",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
