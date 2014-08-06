#include "mode.h"
#define MN 510
char str[MN];
int k;
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%s",str+1);
    k = gi;
    int len = strlen(str+1),ans = 0;
    for(int i=1;i<=len-k+1;++i)
    {
     int l = len+1;
     for(int j = i;j<=i+k-1;++j) str[l] = str[j],++l;
     --l;
     for(int j = 1;j<=l;++j)
      for(int o = 1;o<=l;++o)
       if(j+o <= l)
       {
        int q = j+o;
        int flag= 1;
        for(int p = j;p<=j+o-1;++q,++p)
         if(str[p] != str[q])
          flag = 0;
        if(flag)
         ans =max(ans,o*2);
       }
    }
     if(len-k+1<=0) ans = ((len+k)/2)*2;
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
