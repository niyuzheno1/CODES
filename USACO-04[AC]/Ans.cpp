#include <cstdlib>
#include <iostream>

using namespace std;
int n,ans,now;
int a[100010];
int main(int argc, char *argv[])
{
    freopen("profits.in","r",stdin);
    freopen("profits.out","w",stdout);
    now = 0;ans = -0x7f7f7f7f;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]),ans = max(ans,a[i]);
    for(int i = 1;i<=n;i++)
    {
            
            
            now += a[i];
            if(now < 0)
             now = 0;
            else
             ans = max(ans,now);
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
