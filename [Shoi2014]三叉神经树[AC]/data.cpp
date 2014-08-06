#include "mode.h"
#include "iodata.h"

using namespace std;
const int MN = 4,MM=3;
int u;
int son[MN][4];
int main(int argc, char *argv[])
{
    init("sample.in");
    int n = MN;u=2;
    pli(n);
    for(int i = 1;i<=n && u <= n;++i)
    {
     ++son[i][0];
     son[i][son[i][0]] = u;
     ++u;
     if(i == n && u <= n)
      i = 0;
    }
    for(int i = 1;i<=n;nl(),++i)
     for(int j = 1;j<=3;++j)
      if(son[i][j] == 0)
       pin_(u),++u;
      else
       pin_(son[i][j]);
    --u;
    for(int i = 1;i<=2*n+1;++i)
     pin_(rand()%2);
    nl();
    int m = rand()%MM+1;
    pli(m);
    for(int i = 1;i<=m;++i){
      int gu = rand()%u+1;
      while(gu <= n)gu = rand()%u+1;
      pli(gu);
    }
    closeIO();
    return EXIT_SUCCESS;
}
