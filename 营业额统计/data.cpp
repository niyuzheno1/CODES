#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1000000,inf = 0x7f7f7f7f;
int main(int argc, char *argv[])
{
    srand(clock());
    freopen("splay1.in","w",stdout);
    int n = rand()%maxn+1;
    printf("%d\n",n);
    for(int i =1;i<=n;i++)
     printf("%d\n",abs(rand()%inf));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
