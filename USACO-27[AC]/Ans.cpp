#include <cstdlib>
#include <iostream>

using namespace std;
int n,k;
long long h[5010];
long long f[5010];
int main(int argc, char *argv[])
{
    freopen("skilift.in","r",stdin);
    freopen("skilift.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     scanf("%d",&h[i]);
    memset(f,0x7f,sizeof(f));
    f[1] = 1;
    for(int i = 1;i<=n;i++)
    {
     long long ky,kx;
     ky = h[i+1]-h[i];
     kx = 1;
     for(int j = 1;j<=k;j++)
      if(i+j <= n)
      if(kx*(h[i+j]-h[i]) >=ky*(j))
      {
       ky = (h[i+j]-h[i]);
       kx = j;
       f[i+j] = min(f[i+j],f[i]+1);
      }
    }
    printf("%d",f[n]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
