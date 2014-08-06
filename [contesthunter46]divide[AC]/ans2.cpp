#include "mode.h"
#undef INF
const int INF=0x2f2f2f2f;
struct Graph
{
	struct Edge {int to,next;} E[800005];
	int H[400005],Cnt;
	void AddEdge(int x,int y)
	{
		Cnt++;
		E[Cnt].to=y;
		E[Cnt].next=H[x];
		H[x]=Cnt;
	}
}G,RG;
int N,M;
int Sign=0,Scc=0,Top=0,Dfn[200005]={0},Low[200005]={0},Stk[200005]={0},InStk[200005]={0},Block[200005]={0};
int Ans=0,Degree[400005]={0},Match[400005]={0},Dis[400005]={0},Q[400005]={0};
struct Buckets
{
	int L[400005],R[400005],H[400005];
	void Add(int v)
	{
		int idx=Degree[v];
		R[v]=H[idx];
		if(R[v]) L[R[v]]=v;
		L[v]=0;
		H[idx]=v;
	}
	void Erase(int v)
	{
		int idx=Degree[v];
		if(L[v]) R[L[v]]=R[v];
		else H[idx]=R[v];
		if(R[v]) L[R[v]]=L[v];
		L[v]=R[v]=0;
	}
}T;
void Read()
{
	int i,x,y;
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d%d",&x,&y);
		G.AddEdge(x,y);
	}
}
void DFS(int u)
{
	int i,v,k;
	Dfn[u]=Low[u]=++Sign;
	Stk[++Top]=u;
	InStk[u]=true;
	for(i=G.H[u];i;i=G.E[i].next)
	{
		v=G.E[i].to;
		if(!Dfn[v])
		{
			DFS(v);
			Low[u]=min(Low[u],Low[v]);
		}
		else if(InStk[v]) Low[u]=min(Low[u],Dfn[v]);
	}
	if(Dfn[u]==Low[u])
	{
		Scc++;
		do
		{
			k=Stk[Top--];
			InStk[k]=false;
			Block[k]=Scc;
		}while(k!=u);
	}
}
void Tarjan()
{
	int i;
	for(i=1;i<=N;i++)
		if(!Dfn[i]) DFS(i);
}
void BuildBip()
{
	int i,u,v;
	for(u=1;u<=N;u++)
		for(i=G.H[u];i;i=G.E[i].next)
		{
			v=G.E[i].to;
			if(Block[u]==Block[v]) continue;
			RG.AddEdge(Block[u],Block[v]+Scc);
			RG.AddEdge(Block[v]+Scc,Block[u]);
			Degree[Block[u]]++,Degree[Block[v]+Scc]++;
		}
}
void Greedy()
{
	int i,k,u,v,Minx,Mind;
	for(i=1;i<=(Scc<<1);i++) T.Add(i);
	for(k=1;k<=Scc;)
	{
		if(!T.H[k]) {k++; continue;}
		u=T.H[k],Minx=0,Mind=INF;
		for(i=RG.H[u];i;i=RG.E[i].next)
		{
			v=RG.E[i].to;
			if(Match[v]) continue;
			if(Degree[v]<Mind) Minx=v,Mind=Degree[v];
			T.Erase(v);
			Degree[v]--;
			T.Add(v);
		}
		T.Erase(u);
		if(Minx)
		{
			T.Erase(Minx);
			Match[u]=Minx,Match[Minx]=u,Ans++;
			for(i=RG.H[Minx];i;i=RG.E[i].next)
			{
				v=RG.E[i].to;
				if(Match[v]) continue;
				T.Erase(v);
				Degree[v]--;
				T.Add(v);
			}
			if(k>1) k--;
		}
	}
}
bool BFS()
{
	int i,u,v,st=0,ed=0;
	memset(Dis,INF,sizeof(Dis));
	for(i=1;i<=Scc;i++)
		if(!Match[i]) Dis[Q[ed++]=i]=0;
	while(st!=ed)
	{
		u=Q[st++];
		for(i=RG.H[u];i;i=RG.E[i].next)
		{
			v=RG.E[i].to;
			if(Dis[Match[v]]==INF)
			{
				Dis[Match[v]]=Dis[u]+1;
				Q[ed++]=Match[v];
			}
		}
	}
	return Dis[0]<INF;
}
bool Find(int u)
{
	int i,v;
	for(i=RG.H[u];i;i=RG.E[i].next)
	{
		v=RG.E[i].to;
		if(Dis[Match[v]]==Dis[u]+1)
			if(!Match[v]||Find(Match[v]))
			{
				Match[u]=v;
				Match[v]=u;
				return true;
			}
	}
	Dis[u]=INF;
	return false;
}
void MaxMatch()
{
	int i;
	while(BFS())
	{
		for(i=1;i<=Scc;i++)
			if(!Match[i]&&Find(i)) 
            Ans++;
	}
	printf("%d\n",Scc-Ans);
}
int main()
{
    setIO();
	Read();
	Tarjan();
	BuildBip();
	Greedy();
	MaxMatch();
	return 0;
}
