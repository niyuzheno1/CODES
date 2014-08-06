#include "mode.h"

using namespace std;

const int MN = 1010;

int a[MN],f[MN],s[MN],n,k,d;

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i)
    {
     char c = 0;while(c != 'N' && c != 'K') c = getchar();
     if(c == 'N') ++k;
     else
     {++d;a[d] = gi;s[d] = k;}
    }
    int ans = 0;
    for(int i = 1;i<=d;ans=max(f[i],ans),++i)
     for(int j = 1;j<=d;++j)
     f[i] = max(f[i],f[j]+1+min(a[i]-a[j]-1,s[i]-s[j]));
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
