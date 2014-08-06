#include "mode.h"

const int MN = 15100;

int n,k;
char str[MN];
int nex[MN],f[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    int K,ans = 0;
    gets(str+1);
    n=strlen(str+1); K = gi;
    for(int i = 1;i<=n;++i)
    {
     CLEAR(f,0x7f);
     nex[i] = nex[i+1] = i;f[i] = f[i+1] = INF;
     for(int j = i+1;j<=n;++j)
     {
     int k = nex[j];
     while(k != i && str[j] != str[k]) k = nex[k];
     if(str[j] == str[k]) nex[j+1] = k+1;
     else nex[j+1] = i;
     if(nex[j+1]-i >= K) f[j+1] = min(f[nex[j+1]],nex[j+1]);
     else f[j+1] = f[nex[j+1]];
     if(f[j+1]-i >= K && j-(f[j+1]-i)>=f[j+1]) ++ans;
     }
    }
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
