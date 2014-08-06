#include "mode.h"
using namespace std;
const int MN = 10,MC = 10;
int p;
int main(int argc, char *argv[])
{
    freopen("sample.in","w",stdout);
    srand(clock());
    int n = rand()%MN+1,m = rand()%MC+1;
    printf("%d %d\n",n,m);
    for(int i = 1;i<=n-1;++i) printf("%d ",rand()%MN);
    printf("%d\n",rand()%MN);
    for(int i = 1;i<=m;++i)
    {
     int u = rand()%2;
     if(u == 1) ++p;
     if(p>= 1000 || u == 0)
      u = 2;
     printf("%d %d ",u,rand()%n+1);
     if(u == 1)
      printf("%d",rand()%MN);
     puts("");
    }fclose(stdout);
    return EXIT_SUCCESS;
}
