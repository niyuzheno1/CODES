#include "mode.h"
#define Maxn 1000005
int p[Maxn],c[Maxn],t[Maxn],bo[Maxn],tot,ca,n;
long long cnt[Maxn],ans;
int bk;
void Prime()
{
    int i,j,maxi=Maxn-5;
    for (i=2;i<=maxi;i++)
    {
        if (!bo[i]) {p[++tot]=i; bo[i]=i; cnt[i]=i-1;}
        for (j=1;j<=tot&&p[j]*i<=maxi;j++)
        {
            bo[i*p[j]]=p[j];
            if(i*p[j] == 4) 
             bk = 1;
            if (i%p[j]==0)
            {
                cnt[p[j]*i]=cnt[i]*p[j];
                break;
            }else
                cnt[p[j]*i]=cnt[i]*(p[j]-1);
        }
    }
    cnt[1]=1;
    for (i=3;i<=maxi;i++)
        cnt[i]=cnt[i]*i>>1;
    //show1D(int,cnt);
}

void dfs(int k,int now)
{
    if (k>t[0])
    {
        ans+=n*cnt[n/now];
        return;
    }
    dfs(k+1,now);
    int i;
    for (i=1;i<=c[k];i++)
    {
        now*=t[k];
        dfs(k+1,now);
    }
}

void Work()
{
    int i,k=n,maxi=int(sqrt(n));
    ans=0;
    t[0]=0;
    while (k!=1)
    {
        i=bo[k];
        if (t[t[0]]!=i) {t[++t[0]]=i; c[t[0]]=0;}
        c[t[0]]++;
        k/=i;
    }
    dfs(1,1);
    printf("%lld\n",ans);
}

int main()
{
    setIO("sample");
    Prime();
    for (scanf("%d",&ca);ca--;)
    {
        scanf("%d",&n);
        Work();
    }
    closeIO();
    return 0;
} 
