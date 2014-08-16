#include "mode.h"
#define MN 1000010
int n,m;
int a[MN],b[MN];
char str[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;++i)
     a[i] = gi;
    for(int i = 1;i<=m;++i)
    {
     scanf("%s",str);
     if(str[0] == 'D')
     {
      int x=gi,y=gi;
      for(int i = x;i<=y;++i) a[i] = 0;
      for(int i = 1;i<=n;++i) 
       if(a[i] ==0)
        for(int j = i;j<=n;++j)
         if(a[j] != 0)
         {
          a[i] = a[j];a[j] = 0;
          break;
         }
      n-=y-x+1;
     }
     if(str[0] == 'P')
     {
      int x = gi;
      printf("%d\n",a[x]);
     }
     if(str[0] == 'I')
     {
      int pos = gi,len = gi;
      for(int i = 1;i<=len;++i)
       b[i] = gi;
      for(int i = n+len;i>pos;--i)
       a[i] = a[i-len];
      for(int i = 1;i<=len;++i)
       a[i+pos] = b[i];
      n = n+len;
     }
     if(str[0] == 'C')
     {
      int x=gi,y=gi;
      for(int i = x;i<=y;++i) b[i-x+1] = a[i],a[i] = 0;
      for(int i = 1;i<=n;++i) 
       if(a[i] ==0)
        for(int j = i;j<=n;++j)
         if(a[j] != 0)
         {
          a[i] = a[j];a[j] = 0;
          break;
         }
      n-=y-x+1;
      int pos = gi,len = y-x+1;
    
      for(int i = n+len;i>pos;--i)
       a[i] = a[i-len];
      for(int i = 1;i<=len;++i)
       a[i+pos] = b[i];
      n = n+len;
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
