#include "mode.h"
#include "data.h"

#define MN 10010
#define MK 6000
#define MKK 610
int a[MN];
int n,k;
int f[MN][MKK];
int sum[MK][MKK];
void modify(int x,int y,int z)
{
     ++x,++y;
     for(int i = x;i<MK;i+=lb(i))
      for(int j = y;j<MKK;j+=lb(j))
       sum[i][j] = max(sum[i][j],z);
}

int Sum(int x,int y)
{
    ++x,++y;
    int ret = 0;
     for(int i = x;i;i-=lb(i))
      for(int j = y;j;j-=lb(j))
       ret = max(sum[i][j],ret);
    return ret;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi,k = gi;
    for(int i = 1;i<=n;a[i]=gi,++i);
    for(int i = 1;i<=n;++i)
    {
     for(int j = 0;j<=k;++j)
      f[i][j] = Sum(a[i]+j,j)+1;
     for(int j = 0;j<=k;++j)
      modify(a[i]+j,j,f[i][j]);
    }
    int ans = 0;
    for(int i = 1;i<=n;++i)
     for(int j = 0;j<=k;++j)
      ans = max(ans,f[i][j]);
    printf("%d",ans);
    closeIO();
    return EXIT_SUCCESS;
}
