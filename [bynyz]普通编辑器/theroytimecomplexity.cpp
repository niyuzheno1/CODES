#include "mode.h"
int n,m;
double timesum;
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;m = gi;
    for(int i = 1;i<=n;++i) {int x = gi;}
    int u = 0;
    for(int i = 1;i<=m;++i){
     char o[10];
     scanf("%s",o);
     if(o[0] == 'I')
     {
      ++u;
      int x = gi,len = gi;
      for(int i = 1;i<=len;++i){
       int z = gi;
       
      }
      timesum += (double(len)+3.0)*sqr(log(double(n+len))/log(2.0));
      n+=len;
     }
     if(o[0] == 'D')
     {
      int x = gi,y = gi;
      timesum += sqr(log(double(n))/log(2.0))*3.0;
      n-=y-x+1;
     }
     if(o[0] == 'C')
     {
      int x = gi,y = gi,z = gi;
      timesum += sqr(log(double(n))/log(2.0))*6.0;
     }
     if(o[0] == 'P')
     {
      int x = gi;
      timesum += sqr(log(double(n))/log(2.0));
     }
    }
    printf("%.7f",timesum);

    closeIO();
    return EXIT_SUCCESS;
}
