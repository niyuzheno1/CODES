#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn=1000;
const char lis[]="IAFS";
int n;
int main(int argc, char *argv[])
{
    srand(clock());
    freopen("splay2.in","w",stdout);
    n = rand()%maxn+1;int m = rand()%maxn+1;
    printf("%d %d\n",n,m);
    for(int i = 1;i<=n;i++)
    {
     int x = rand()%4,y = rand()%maxn+1;
     printf("%c %d\n",lis[x],y);
    }
    fclose(stdin);
    return EXIT_SUCCESS;
}
