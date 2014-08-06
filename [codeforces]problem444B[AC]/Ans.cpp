#include "mode.h"
#define MN 100010
#define BEEP for(int i=0;i<n;++i)
#undef pb
typedef long long LL;
int n,d,a[MN],b[MN],ans[MN]={0},s = 42;
int pa[MN],pb[MN];
LL x;
int get() {return x = (x*37+10007)%1000000007;}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, d = gi, x = gi;
    BEEP a[i]=i+1,b[i]=(i<d);
    BEEP swap(a[i],a[get()%(i+1)]);
    BEEP swap(b[i],b[get()%(i+1)]);
    BEEP {
         pa[a[i]] = i;
         if(b[i]) pb[++pb[0]] = i;
    }
    BEEP {
     for(int j = 0;j<s;++j)
      if(pa[n-j]<=i && b[i-pa[n-j]])
      {ans[i] = n-j;break;}
     if(!ans[i])
      for(int j = 1;j<=d&&pb[j]<=i;++j)
       ans[i] =max(ans[i],a[i-pb[j]]);
    }
    BEEP 
     printf("%d\n",ans[i]);
    closeIO();
    return EXIT_SUCCESS;
}
