#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
#define X first
#define Y second
using namespace std;
int n,m,ti;
typedef pair<int,int> p2;
int st[400010],d[400010],t[400010],le[400010],ri[400010];
int f[400010][40];
int qt[400010];
struct p
{
	int t,n;
}lk[400010];
void ae(int x,int y)
{
	m++;
	lk[m].t = y;
	lk[m].n = st[x];
	st[x] = m;
}
void dfs(int x,int y)
{
	d[x] = d[y]+1;
	ti = ti+1;
	t[ti] = x;
	le[x] = ti;
	int e = st[x];
	while(e != 0)
	{
		int v = lk[e].t;
		if(d[v] == 0)
			dfs(v,x);
	    e = lk[e].n;
	}
	f[x][0] = y; 
	ri[x] = ti;
}

void up(int x)
{
 
 for(int k = 1;k<=20;k++)
	f[x][k] = f[f[x][k-1]][k-1];
}
int lca(int x,int y)
{
	if(d[x] > d[y])
		swap(x,y);
	int k = 20;
	while(k >= 0){
		 if(d[y]-d[x] >= (1<<k))
			  y = f[y][k];
		 k = k-1;
	}
	k = 20;
	while(k >= 0){
		if(f[x][k] != f[y][k])
		{
			x = f[x][k];
			y = f[y][k];
		}
	    k--;
	}
	if(x != y)
		 return f[x][0];
	else
		 return x;
}
int lowbit(int  x){return x&(-x);}
void add(int x,int y)
{
	while(x <= n)
	{
	  qt[x] += y;
	  x+= lowbit(x);
	}
}
int sum(int x)
{
	int ans =0;
	while(x>0)
	{
		ans += qt[x];
		x-=lowbit(x);
	}
	return ans;
}
void pl(int x,int y)
{
  int p = lca(x,y);
  add(le[x],1);
  add(le[y],1);
  add(le[p],-2);
}
int q(int u)
{
	int ans = sum(ri[u])-sum(le[u]-1);
    return ans;
}
int Q;
int main()
{
    freopen("grassplant.in","r",stdin);
    freopen("grassplant.out","w",stdout);
    
	scanf("%d%d",&n,&Q);
	for(int i = 1;i<=n-1;i++){
	    int u,v;	
		scanf("%d%d",&u,&v);
		ae(u,v);
		ae(v,u);
	}
	dfs(1,0);
	for(int i =1;i<=ti;i++)
	 up(t[i]);
    for(int i =1;i<=Q;i++)
	{
		char x[100];
		int u,v;
		scanf("%s%d%d",&x,&u,&v);
		if(x[0] == 'P')
			pl(u,v);
		else
		   printf("%d\n",q(d[u]>d[v]?u:v));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}