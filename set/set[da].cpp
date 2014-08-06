#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    freopen("set.in","w",stdout);
    srand(time(0));
    int x = rand()%1000;
    int y = rand()%1000;
    if(x>y)
     swap(x,y);
    int z = rand()%y;
    printf("%d %d %d \n",x,y,z);
    fclose(stdout);
  
    return EXIT_SUCCESS;
}
