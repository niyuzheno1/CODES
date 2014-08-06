#include "mode.h"
#define mod 1000000007
using namespace std;
typedef long long LL;
LL n;
int T,S,dp[14000010],d[10],tot;
bool mark;
void Prepare(int n)
{
	for(int i=2;i*i<=n;++i)
		if(n%i==0)
		{
			int s=0;
			while(n%i==0)
				n/=i,++s,d[++tot]=i;
			if(s>1)
				mark=true;
		}
	if(n!=1)
		d[++tot]=n;
	if(mark==false)
	{
		int sum=0;
		for(int i=1;i<=tot;++i)
			sum+=d[i];
		dp[sum]=1;
		for(int i=1;i<=tot;++i)
			for(int j=d[i];j<=tot*S;++j)
			{
				dp[j]+=dp[j-d[i]];
				if(dp[j]>=mod)
					dp[j]-=mod;
			}
	}
	dp[0]=1;
}
int orzvfk(LL N)
{
	static int y[10];
	static LL x[10];
	LL n=N/S,m=N%S;
	for(int i=0;i<tot;++i)
		y[i]=dp[i*S+m];
	int sum=0;
	for(int i=0;i<tot;++i)
	{
		int sum1=y[i],s=0,sign=1;
		for(int j=0;j<tot;++j)
			if(i!=j)
			{
				if(n<j)
					sign*=-1;
				x[++s]=abs(n-j);
			}
		for(int j=0;j<tot;++j)
			if(i!=j)
			{
				if(i<j)
					sign*=-1;
				int val=abs(i-j);
				for(int k=1;k<=s;++k)
					if(x[k]%val==0)
					{
						x[k]/=val;
						break;
					}
			}
		for(int j=1;j<=s;++j)
			sum1=x[j]%mod*sum1%mod;
		if(sign==1)
			sum=(sum+sum1)%mod;
		else
			sum=(sum-sum1+mod)%mod;
	}
	return sum;
}
int main()
{
    setIO("sample");
	scanf("%d",&S);
	Prepare(S);
	for(scanf("%d",&T);T;--T)
	{
		scanf("%lld",&n);
		if(mark)
			printf("0\n");
		else
			printf("%d\n",orzvfk(n));
	}
	closeIO();
	return 0;
}
