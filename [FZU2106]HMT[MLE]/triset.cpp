#include "mode.h"

using namespace std;
int64 bl[3125001];
int geta(int x)
{
 int u = x%32;
 int v = x/32;
 int ff = bl[v]>>(2*u);
 return (ff&3);
}
int seta(int x,int y)
{
 int u = x%32;
 int v = x/32;
 int nf = bl[v] | (1<<(2*u));
 bl[v] = nf;
}
int main(int argc, char *argv[])
{
    
    return EXIT_SUCCESS;
}
