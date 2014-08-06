#include "mode.h"

using namespace std;

#define N 10000010
typedef long long ll;
int fl[N]={0},prime[N/10],tot=0;
ll miu[N];
void sieve(int n){
        miu[1]=0;
        for(int i=2;i<=n;i++){
                if(!fl[i])  prime[++tot]=i,miu[i]=1;
                for(int j=1;j<=tot && i*prime[j]<=n;j++){
                        fl[i*prime[j]]=1;
                        if(i%prime[j]==0){
                                miu[i*prime[j]]=0;
                                break;
                        }
                        miu[i*prime[j]]=-miu[i];
                }
        }
        for(long long i=2;i*i<=n;i++)
                if(miu[i]!=0)
                        for(long long j=i;j<=n;j*=i) miu[j]=miu[i];
        for(int i=2;i<=n;i++)    miu[i]+=miu[i-1];
}
ll work(int n,int m){
        ll ans=0;
        for(int i=1;i<=n;i++){
                int j=min(n/(n/i),m/(m/i))-i;
                ans+=1ll*(n/i)*(m/i)*(miu[i+j]-miu[i-1]);
                i+=j;
        }
        return ans;
}
int main(){
        setIO("sample");
        sieve(10000000);
        int tc,n,m;
        scanf("%d",&tc);
        while(tc--){
                scanf("%d%d",&n,&m);
                if(n>m)  swap(n,m);
                printf("%lld\n",work(n,m));
        }
        closeIO();
        return 0;
}
