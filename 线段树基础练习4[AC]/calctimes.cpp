#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    freopen("debug.txt","r",stdin);
    
    double sum = 0.0,tmp = 0.0;
    while(~scanf("%lf",&tmp))
    {
     sum += tmp;
    }
    return EXIT_SUCCESS;
}
