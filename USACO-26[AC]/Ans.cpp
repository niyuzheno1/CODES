#include <cstdlib>
#include <iostream>

using namespace std;
long long c = 100000000;
long long f1[2510],f2[2510],a[2510];
long long n,f;
int main(int argc, char *argv[])
{
    freopen("fristeam.in","r",stdin);
    freopen("fristeam.out","w",stdout);
    scanf("%d%d",&n,&f);
    for(long long i = 1;i<=n;i++){
     scanf("%d",&a[i]);
     a[i] %= f;
    }
    for(long long i = 1;i<=n;i++)
    {
     memcpy(f2,f1,sizeof(f1));
     for(long long j = 0;j<f;j++)
      f2[(a[i]+j)%f] = (f2[(a[i]+j)%f]%c+f1[j]%c)%c;
     f2[a[i]] = (f2[a[i]]+1)%c;
     memcpy(f1,f2,sizeof(f1));
    }
    printf("%d",f1[0]%c);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
