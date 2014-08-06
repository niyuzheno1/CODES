#include <cstdlib>
#include <iostream>
#define rep(i,k,n) for(int i = k;i<=n;i++)
using namespace std;
int m[1000010][5];
int f[1<<5];
int n,d;
int main(int argc, char *argv[])
{
    freopen("jail1.in","r",stdin);
    freopen("jail.out","w",stdout);
    int s = 0;
    scanf("%d%d",&n,&d);
    memset(f,0xab,sizeof(f));
    s = (1<<d)-1;
    for(int i = 1;i<=n;i++)
      for(int j = 0;j<d;j++)
       scanf("%d",&m[i][j]);
    rep(i,0,s)
     rep(j,1,n)
     {
      int cnt = 0;
      rep(k,0,d-1)
       if(i & (1<<(k))!= 0)
        cnt += m[j][k];
       else
        cnt -= m[j][k];
      f[i] = max(f[i],cnt);
     }
    int ans = 0;
    rep(i,0,s)
    {
     ans = max(ans,f[i] + f[s & (~i)]);
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
