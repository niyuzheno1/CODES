#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    freopen("bs.in","w",stdout);
    srand(time(0));
    for(int i = 1;i<=1000;i++)
     printf("%d %d %d %d\n",rand()%1000000,rand()%1000000,rand()%1000000,rand()%1000000);
    fclose(stdout);
    return EXIT_SUCCESS;
}
