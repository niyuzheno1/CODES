#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;
ifstream re("jpol.in");
ifstream ou("jpol.out");
ofstream dat("result");
int a[61*3];
int b[61*3];
int main(int argc, char *argv[])
{
    int n;
    re>>n;
    for(int i = 1;i<=3*n;i++)
     re>>a[i];
    for(int i = 1;i<=3*n;i++)
     ou>>b[i];
    int p = 0,x = 0;
    for(int i = 1;i<=n;i++)
     x += a[b[i]];
    if(x>500*n)
     p++;
    x = 0;
    for(int i = n+1;i<=2*n;i++)
     x += a[b[i]];
    if(x>500*n)
     p++;
    x = 0;
    for(int i = n*2+1;i<=3*n;i++)
     x += a[b[i]];
    if(x>500*n)
     p++;
    x = 0;
    if(p >= 2)
     dat<<"AC"<<endl;
    else
     dat<<"WA"<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
