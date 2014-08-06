#include "mode.h"
#include "iodata.h"

using namespace std;

const int MN=1000,MM=10;

int main(int argc, char *argv[])
{
    init("sample.in");
    int n = rand()%MN+1,m = 10;
    if(n < m) swap(n,m);
    int u = rand()%n+1;
    for(int i = 1;i<=n;++i){
      printf("%c",rand()%10+'0');
      if(i == u) printf("15153157215");
    }
    nl();
    /*for(int i = 1;i<=m;++i)
     printf("%c",rand()%10+'0');*/
    printf("15153157215");
    closeIO();
    return EXIT_SUCCESS;
}
