#include "mode.h"
#define MN 184775
#define MH 15
#define ML 25
#define MF 1010
typedef long long LL;
/*typedef map<LL,LL> mLL;
typedef mLL::iterator Lit;*/
const LL mod = 15;
LL stk[MN],cost[MN],m;
int n,h,ans,a[MH],b[ML];
/*All means all set*/
LL top,All,maxlen;
int dp[2][1001][MN];
char fom[2][1001][MN];
bool ok1(LL x)
{
     while(x > 0)
	 {
		 LL y = (x&mod);
		 if(y >= 11)return 0; 
		 x>>=4;
	 }
     return 1;
}
bool ok2(LL x)
{
     for(LL i = 2;i<=m;++i)
     {
      LL a1 = ((x>>(4*(i-1)))&mod);
      LL a2 = ((x>>(4*(i-2)))&mod);
      if(a2 < a1)
       return 0;
     }return 1;
}
LL getlen(LL x)
{
	LL ret = 0;
	while(x>0) x>>=4,++ret;
	return ret;
}
LL dis(LL x)
{
 return lower_bound(stk+1,stk+top+1,x)-stk;
}
LL gety(LL x)
{
 LL ret = 0;
 while(x > 0) ret = (x&mod),x>>=4;
 return ret;
}
void emu(LL l,LL x,LL y)
{
	if(y >m)
	{
		x>>=4;
		maxlen = max(maxlen,getlen(x));
		if(ok2(x) && x != 0){
			++top;
			stk[top] = x;
		}
		return ;
	}
	for(LL i = 0;i<=10;++i)
	{
		if(i < l) continue;
		LL tmp = x|i;
		emu(i,tmp<<4,y+1);
	}
}
inline void init() {
       emu(-1,0,1);
       for(int i = 1;i<=top;++i)
        cost[i] = gety(stk[i]);
}
int main()
{
    setIO();
    n = gi, h = gi;n/=4;
    for(int  i = 1;i<=h;++i) a[i] = gi,a[i]/=2,m=max(m,LL(a[i]));
    a[0] = m+1;
    for(int  i = 1;i<=h;++i)
     for(int j = 1;j<=a[i];++j)
      b[j] = i;
    LL st = 0;
    for(int i = m;i>=1;--i)
     st<<=4,st|=b[i],n-=b[i];
    init();st = dis(st);
    dp[0][st][n] = 1;
    char op =0;
    int u = 0;
    for(int i = 1;i<=n;u^=1,++i){
     for(int j = )
     ++op;
    }
    closeIO();
    return 0;
}
