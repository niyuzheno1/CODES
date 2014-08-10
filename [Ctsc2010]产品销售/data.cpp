#include "mode.h"
#include "iodata.h"

using namespace std;
#define MN 100010
int n;
#define mk 11
int a[MN],b[MN];
int c[MN];
void swap(int a[],int b[])
{
     for(int i = 1;i<=n;++i)
      c[i] = a[i];
     for(int i = 1;i<=n;++i)
       a[i] = b[i];
     for(int i = 1;i<=n;++i)
       b[i] = c[i];

}
int main(int argc, char *argv[])
{
    init("sample.in");
    n = 5;
    pli(n);
    for(int i  =1;i<=n;++i) 
     a[i] = rand()%mk+1,b[i] = rand()%mk+1;
    int tmp1=0,tmp2=0;
    for(int i  =1;i<=n;++i)
     tmp1 += a[i],tmp2 += b[i];
    if(tmp1 > tmp2) swap(a,b);
    for(int i = 1;i<=n;++i)
     pin_(a[i]);
    nl();
    for(int i = 1;i<=n;++i)
     pin_(b[i]);
    nl();
    for(int i = 1;i<=n;++i)
     pin_(rand()%mk+1);
    nl();
    for(int i = 1;i<=n-1;++i)
     pin_(rand()%mk+1);
    nl();
    for(int i = 1;i<=n-1;++i)
     pin_(rand()%mk+1);
    nl();
    
    closeIO();
    return EXIT_SUCCESS;
}
