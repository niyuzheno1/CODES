#include "mode.h"
#include "iodata.h"

using namespace std;
#define MV 51
#define MC 110
#define MN 5
int main(int argc, char *argv[])
{
    init("sample.in");
    int n = rand()%MN+1,V=rand()%MV+1;
    if(n == 1) ++n; 
    printf("%d 1 %d\n",n,V);
    for(int i = 1;i<=n;++i)
    {
     int x = rand()%MV+1,y = rand()%MC+1;
     printf("%d %d \n",x,y);
    }
    printf("%d\n",rand()%n+1);
    closeIO();
    return EXIT_SUCCESS;
}
