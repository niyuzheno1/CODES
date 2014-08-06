#include "mode.h"

using namespace std;
const int MAXN = 1000;
FILE * d;
int main(int argc, char *argv[])
{
    d = fopen("AOMap.in","w");
    srand(clock());
    int n = (rand()%MAXN)+1,m = (rand()%MAXN)+1,q = (rand()%MAXN)+1;
    printf("%d %d\n",n,m);
    ff(d,"%d %d %d\n",n,m,q);
    for(int i = 1;i<=n;i++,ff(d,"\n"))
     for(int j = 1;j<=m;j++)
      ff(d,"%d ",(rand()%MAXN));
    for(int i = 1;i<=q;i++)
    {
     int u = rand()%n+1,v = rand()%n+1;
     if(u > v) swap(u,v);
     int x = rand()%m+1,y = rand()%m+1;
     if(x > y) swap(x,y);
     ff(d,"%d %d %d %d\n",u,x,v,y);
    }
    fclose(stdout);
    return EXIT_SUCCESS;
}
