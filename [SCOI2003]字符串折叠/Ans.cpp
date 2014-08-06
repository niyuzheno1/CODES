#include "mode.h"
#include "algo.h"
#define MN 105
char str[MN];
int f[MN][MN];
int bit[4] = {0,100,10,1};

bool check(int l,int mid,int r){
 int lens,lent;
 if((lent = r-l+1)%(lens=mid-l+1) != 0) return 0;
 for(int i = l+lens;i<=r;i+=lens)
  for(int j = 0;j<=lens-1;++j)
   if(str[l+j-1] != str[i+j-1])
    return 0;
 return 1;
}

int calc(int num)
{
    for(int i = 1;i<=3;++i)
     if(num >= bit[i]) return 3-i+1;
    return 0;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    gets(str);int len = strlen(str);
    CLEAR(f,1);
    for(int i = 1;i<=len;f[i][i]=1,++i);
    for(int k = 1;k<=len;++k)
     for(int i = 1;i+k<=len;++i)
      for(int j = i,g=  0;j+1<=i+k;++j){
       dn(f[i][i+k],f[i][j]+f[j+1][i+k]);
       if(check(i,j,i+k))
        dn(f[i][i+k],min(calc((k+1)/(j-i+1))+2+f[i][j],k+1));
      }
    printf("%d",f[1][len]);
    closeIO();
    return EXIT_SUCCESS;
}
