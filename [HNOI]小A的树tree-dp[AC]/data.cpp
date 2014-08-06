#include "mode.h"

using namespace std;
const int MN = 100010;
int f[MN];
int gf(int x)
{
    if(x == f[x])
     return x;
    return (f[x] = gf(f[x]));
}
int main(int argc, char *argv[])
{
    srand(clock());
    freopen("sample.in","w",stdout);
    printf("1\n");
    int n = rand()%MN+1;
    printf("%d\n",n);
    for(int i = 1;i<=n;++i) f[i] = i;
    int m = 0;
    for(int i = 1;i<=n;++i) printf("%d ",rand()%MN);
    puts("");
    while(m<n-1)
    {
     int u = rand()%n+1,v= rand()%n+1;
     if(gf(u) != gf(v)){
      f[f[u]] = f[f[v]];++m;
      printf("%d %d\n",u,v);
     }
    }
    return EXIT_SUCCESS;
}
