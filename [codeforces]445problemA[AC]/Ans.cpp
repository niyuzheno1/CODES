#include "mode.h"
#define MN 1100
int n,m;
char s[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    for(int i = 0;i<n;++i){
     gets(s);
     for(int j = 0;j<m;++j)
      if(s[j] == '.'){
       if((i+j)&1) s[j] = 'W';
       else s[j] = 'B';
      }
      puts(s);
    }
    closeIO();
    return EXIT_SUCCESS;
}
