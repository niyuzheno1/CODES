#include "mode.h"
typedef long long LL;
#define MN 100010
char s[MN];
int T;
int main(int argc, char *argv[])
{
    setIO("sample");
    T = gi;
    while(T--)
    {
     int len = gi;
     gets(s+1);
     LL one = 0,ans = 0;
     for(int i = 1;i<=len;++i)
     if(s[i]=='1'){
      ans += one+1;
      ++one;
     }
     printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
