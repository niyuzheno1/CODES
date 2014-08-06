#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define rep(i,n) for(int i=1;i<=n;++i)
#define imax(x,y) (x>y?x:y)
#define imin(x,y) (x<y?x:y)
using namespace std;
const int N=15010,BIG=1000000000;
char ch[N];
int nexte[N],L[N];
int n,k,ans=0;
int main()
{
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    scanf("%s",ch+1);
    n=strlen(ch+1);
    scanf("%d",&k);
    for(int t=1;t+k*2<=n;++t)
    {
        nexte[t]=nexte[t+1]=t;
        L[t]=L[t+1]=BIG;
        for(int i=t+1;i<=n;++i)
        {
            int j=nexte[i];
            while(j>t&&ch[i]!=ch[j])j=nexte[j];
            if(ch[i]==ch[j])
                nexte[i+1]=j+1;
            else
                nexte[i+1]=t;
            if(nexte[i+1]-t>=k)
            L[i+1]=imin(nexte[i+1],L[nexte[i+1]]);
            else
            L[i+1]=L[nexte[i+1]];
            if(L[i+1]-t>=k&&i-(L[i+1]-t)>=L[i+1])
                ++ans;
        }
    }
    printf("%d",ans);
    return 0;
}
