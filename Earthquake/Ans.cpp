/*
sum(T)*ans+sum(C)
*/
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const double eps = 10e-5;
const int maxm = 10010,maxn = 410;
double l,mid,r;
struct edge
{
	int fr,to,ne;
	double Cos,Ti;
	bool operator < (edge c) const
	{
	return ((this->Cos + this->Ti*mid) < (c.Cos + c.Ti*mid));
	}
};
struct BinSet
{
	int f[maxn];
	void init(int n)
	{
		for(int i = 1;i<=n;i++)
			f[i] = i;
	}	
	int dfs(int x)
	{
	if(f[x] == x)
		return x;
	return (f[x]=dfs(x));
	}
	void unions(int x,int y)
	{
	dfs(x);dfs(y);
	f[f[x]] = f[y];
	}
};
int N,M;double F;
struct Krus
{
	edge lk[maxm];
	int tot,st[maxn];
	BinSet bs;	
	void adde(int f,int to,double v,double t)
	{
	tot++;lk[tot].fr = f;lk[tot].to = to;lk[tot].Cos = v;lk[tot].Ti =t;
	lk[tot].ne = st[f];st[f] = tot;
	}
	void sort()
	{
	std::sort(lk+1,lk+tot);
	}
	bool check()
	{
	double ans = 0;
	sort();
	bs.init(N);
	for(int i = 1;i<=tot;i++)
		if(bs.dfs(lk[tot].fr) != bs.dfs(lk[tot].to))
			ans += (lk[tot].Cos+lk[tot].Ti*mid);
	return F>=ans;
	}
	double Search()
	{
	l = 0;r = F;
	 while( abs(r-l) > eps && r > l)
	 {
	 mid = (l+r)/2;
		if(check())
		 l = mid;
		else
		 r = mid;
	 }
	 return (l+r)/2;
	}
};
Krus kru;
int U,V;
double C,T;
int main(int argc, char *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("ou.txt","w",stdout);
	scanf("%d%d%lf",&N,&M,&F);
	for(int i = 1;i<=M;i++)
		scanf("%d%d%lf%lf",&U,&V,&C,&T),kru.adde(U,V,C,T);
	printf("%.4f",kru.Search());
	fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
