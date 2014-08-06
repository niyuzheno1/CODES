#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;
const int maxn = 100000;
int main(int argc, char *argv[])
{
    srand(clock());
    freopen("treap.in","w",stdout);
    int n = rand()%maxn;
    for(int i = 1;i<=n;i++)
    {
     if(rand()%2)
      printf("I %d\n",rand()%maxn);
     else
      printf("F %d\n",rand()%maxn);
    }
    fclose(stdout);
    return EXIT_SUCCESS;
}
