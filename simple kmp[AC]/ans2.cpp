#include "mode.h"
using namespace std;
const int MN = 1010;
char a[MN],b[MN];

int main(int argc, char *argv[])
{
    setIO("sample");
    gets(a+1);
    gets(b+1);
    int n = strlen(a+1),m = strlen(b+1),ans = 0;
    for(int i = 1;i<=n;++i)
    {
      bool flag = 1;
     for(int j = 1;j<=m;++j)
      if(a[i+j-1] != b[j]){
       flag = 0;
       break;
      }
     if(flag){ printf("%d",i);ans = 1;break;}
    }
    if(!ans) puts("-1");
    closeIO();
    return EXIT_SUCCESS;
}
