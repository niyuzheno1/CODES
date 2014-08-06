#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 1000;
const int maxm = 10,maxd = 100000;
int n,m;
int main(int argc, char *argv[])
{
    srand(time(0));
    freopen("tsinsenD5530.in","w",stdout);
    n = 100000;
    m = 100000;
    printf("%d %d\n",n,m);
    for(int i = 1;i<=n;i++)
    {
     int x = rand()%maxd;
     int y = rand()%maxd;
     printf("%d %d\n",x,y);
    }
    for(int i = 1;i<=m;i++)
    {
     int u = abs(rand()%3)+1;
     int v = abs(rand()%n)+1;
     int z = abs(rand()%n)+1;
     if(v>z) swap(v,z);
     printf("%d %d %d\n",u,v,z);
    }
    fclose(stdout);
    return EXIT_SUCCESS;
}
