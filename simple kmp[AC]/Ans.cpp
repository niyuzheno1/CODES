#include "mode.h"

const int MN = 1010;

char a[MN],b[MN];
int f[MN],n,m;

int main(int argc, char *argv[])
{
    setIO("sample");
    gets(a+1);
    n = strlen(a+1);
    gets(b+1);
    m = strlen(b+1);
    //mk fail
    f[1] = 1,f[2] = 1;
    for(int i = 2;i<=m;++i)
    {
     int j = f[i];
     while(j != 1 && b[i] != b[j]) j = f[j];
     f[i+1] = (b[i]==b[j])?j+1:1;
    }
    int j = 1,flag = 0;
    for(int i = 1;i<=n;++i)
    {
     while(j != 1 && a[i] != b[j]) j = f[j];
     if(a[i] == b[j]) ++j;
     if(j == m+1){
      flag = 1;
      printf("%d\n",i-m+1);
      break;
     }
    }
    if(!flag) printf("-1");
    closeIO();
    return EXIT_SUCCESS;
}
