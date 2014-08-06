#include "mode.h"
const int N  = 100100;
bool a[N*2+1],aa[N+1];
int b[N*2+1],c[N*2+1],h[N+1],n,m,i,x,y;
int go(int k)
{
 aa[k] = 1;
 int x = 0;
 for(int i=h[k],t;i;i=b[i])
  if(!a[i])
  {
   a[i>m ? i-m:i+m] = 1;
   if(t = (aa[c[i]] ? 0 : go(c[i])))
    printf("%d %d %d\n",k,c[i],t);
   else
    if(x)
     printf("%d %d %d\n",x,k,c[i]),x = 0;
    else
     x = c[i];
  }
 return x;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    if(m&1)
    {
     puts("No solution");
     return 0;
    }
    for(int i = 1;i<=m;++i)
    {
     x = gi,y=gi;
     b[i] = h[x];c[i] = y;h[x] = i;
     b[i+m] = h[y];c[i+m] = x;h[y] = i+m;
    }
    go(1);
    closeIO();
    return EXIT_SUCCESS;
}
