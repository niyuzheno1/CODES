#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
long long c[1001*1001+1][4],ans,tmp;
int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
void calc(){
	c[0][0]=1;
	for(int i=1;i<=n*m;i++){
		c[i][0]=1;
		for(int j=1;j<=3;j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}
void solve(){
	ans=c[n*m][3];
	ans-=n*c[m][3];
	ans-=m*c[n][3];
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++){
			tmp=gcd(i,j)+1;
			if(tmp>2)ans-=(tmp-2)*2*(n-i)*(m-j);
		}
	printf("%lld",ans);		
}
int main(){
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
	n=read();m=read();
	n++;m++;
	calc();solve();
	fclose(stdin);fclose(stdout);
	return 0;
}
