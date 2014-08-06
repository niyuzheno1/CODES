#include <cstdlib>
#include <iostream>

using namespace std;
const int mm = 10010;
int f[mm],g[mm],k[mm];
int n;
int main(int argc, char *argv[])
{
 
    f[1] = 0;   
    f[2] = 1;
    g[1] = 1;
    g[2] = 1;
    k[2] = 1;
    for(int i = 3;i<=mm-10;i++)
    {
     f[i] = f[i-1]+g[i-1];
     k[i] = f[i-2]*2+k[i-1];
     g[i] = g[i-2]+f[i-1]*2+k[i];
     
    }
    scanf("%d",&n);
    printf("%d\n",f[n]);
    printf("%d",f[4]);
    system("PAUSE");
    return EXIT_SUCCESS;
}
