#include "mode.h"

int main(int argc, char *argv[])
{
    freopen("debug.txt","r",stdin);
    freopen("result.txt","w",stdout);
    double total = 0,x = 0;
    while(~scanf("%lf",&x))
    {
     total +=x;
    }   
    printf("%.7f",total);
    return EXIT_SUCCESS;
}
