#include "mode.h"
#include "iodata.h"

using namespace std;
const int MN = 11,MX = 2010;
int main(int argc, char *argv[])
{
    init("sample.in");
    int n = rand()%MN+1;
    pli(n);
    for(int i = 1;i<=n;++i)
     pin_(rand()%MX);
    nl();
    for(int i = 1;i<=n;++i)
     pin_(rand()%MX);
    closeIO();
    return EXIT_SUCCESS;
}
