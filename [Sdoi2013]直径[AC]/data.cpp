#include "mode.h"

using namespace std;
const int MN = 21, MI = 10000;
int n,f[MN],ec;
int gf(int x)
{
    if(x == f[x])
     return x;
    return (f[x]=gf(f[x]));
}
void uni(int x,int y)
{
     f[gf(x)] = f[gf(y)];
}
int main(int argc, char *argv[])
{
    srand(clock());
    freopen("sample.in","w",stdout);
    n = rand()%MN+1;
    for(int i = 1;i<=n;++i) f[i] = i;
    printf("%d\n",n);
    for(ec = 1;ec<=n-1;)
    {
     int x = rand()%n+1,y = rand()%n+1,z = rand()&MI;
     if(gf(x) != gf(y))
     {
     ec++;
     printf("%d %d %d\n",x,y,z);
     uni(x,y);
     }
    }
    fclose(stdout);
    return EXIT_SUCCESS;
}
