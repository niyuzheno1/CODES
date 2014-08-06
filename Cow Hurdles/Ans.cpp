#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 310,maxm = 25000;
int N,M,T;
struct edge
{
	int from,to,h,ne;
};
struct runner
{
	int v,len;
	runner(int v,int l)
	{
	this->v = v;
	this->len = l;
	}
};
struct MinPath
{
	edge lk[maxm];int tot;
	int st[maxn];
	int dis[maxn];
	void adde(int f,int t,int h)
	{
	tot++;
	lk[tot].from = f;lk[tot].to = t,lk[tot].h = h;
	lk[tot].ne = st[f];st[f] = tot;
	}
	int run(int s,int t)
	{
	memset(dis,0x7f,sizeof(dis));
	dis[s] = 0;
	queue<runner> Q;
	Q.push(runner(s,0));
	while(!Q.empty())
	{
	
	runner rr = Q.front();Q.pop();
		for(int i = st[rr.v];i!= 0; i = lk[i].ne)
		{
		edge & E = lk[i];
			if(dis[E.to] > max(rr.len,E.h))
			{
			dis[E.to] = max(rr.len,E.h);
			Q.push(runner(E.to,max(rr.len,E.h)));
			}
		}
	}
	return dis[t]==0x7f7f7f7f?-1:dis[t];
	}
};
MinPath mp;
int S,E,H,A,B;
int main(int argc, char *argv[])
{
	freopen("in.txt","r",stdin);
	freopen("ou.txt","w",stdout);
	scanf("%d%d%d",&N,&M,&T);
	for(int i = 1;i<=M;i++)
		scanf("%d%d%d",&S,&E,&H),mp.adde(S,E,H);	
	for(int i = 1;i<=T;i++)
		scanf("%d%d",&A,&B),printf("%d\n",mp.run(A,B));
	fclose(stdin);fclose(stdout);
	return EXIT_SUCCESS;
}
