#include "mode.h"
#include "iodata.h"

using namespace std;

const int MN = 100,MM = 11,ML = 10;

int main(int argc, char *argv[])
{
    init("sample.in");
    int n = rand()%MN+1,m = rand()%MM+1;
    pin_(n);pli(m);
    for(int i = 1;i<=n;++i)
      pin_(rand()%ML);
    nl();
    for(int i = 1,x,y,z;i<=m;nl(),++i)
    {
     int opt = rand()%2+1;
     pin_(opt);
     switch(opt){
      case 1:
           x = rand()%n+1, y = rand()%n+1;
           if(x>y) swap(x,y);
           z = rand()%(y-x+1)+1;
           pin_(x);pin_(y);pin_(z);
           break;
      case 2:
           x = rand()%n+1, y = rand()%ML;
           pin_(x);pin_(y);
           break;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
