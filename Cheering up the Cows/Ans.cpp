#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn = 10100,maxe = 100010;
struct Edge
{
	 int from,to,dis;
	 bool operator < (Edge x) const
	 {
		 return dis<x.dis;
	 }
};
struct Set 
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
	   return f[x];
	 return (f[x] = dfs(f[x]));
	}
	bool in(int x,int y)
   {
	 dfs(x);dfs(y);
	 return (f[x] == f[y]);
   }
	void unions(int x,int y)
	{
	  	dfs(x);dfs(y);
	     f[f[x]] = f[y];
	}
};
struct Kruscal
{
  Edge lk[maxe];
  int tot;
  int st[maxn];
  Set S;
  void AE(int x,int y,int dis)
  {
	 tot++;
	 lk[tot].from = x;
	 lk[tot].to = y;
	 lk[tot].dis = dis;
  }
   void sort()
   {
	 std::sort(lk+1,lk+tot+1);
   }
   void init(int n)
   {
	 S.init(n);
   }
   int solve()
   {
	 sort();
	 int ans  = 0;
	 for(int i = 1;i<= tot;i++)
	 {
		 Edge & e = lk[i];
		 if(!S.in(e.from,e.to))
		 {
			ans += e.dis;
			 S.unions(e.from,e.to);
		 }
	 }
	 return ans;
   }
};
Kruscal kru;
int N,P;
int a[maxn];
int main(int argc, char *argv[])
{
	int minval = 0x7f7f7f7f;
	freopen("in.txt","r",stdin);
	scanf("%d%d",&N,&P);
	for(int i = 1;i<=N;i++)
	  scanf("%d",&a[i]),minval = min(minval,a[i]);
	kru.init(N);
	for(int i = 1;i<=P;i++)
	{
	  int x,y,z;
	  scanf("%d %d %d",&x,&y,&z);
	  kru.AE(x,y,z*2+a[x]+a[y]);
	}
	printf("%d",kru.solve()+minval);
    
    return EXIT_SUCCESS;
}
