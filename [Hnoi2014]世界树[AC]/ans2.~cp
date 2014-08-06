#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 300010
using namespace std;
void Read(int &digit)
{
	digit=0;
	char c;
	for(c=getchar();c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';digit=digit*10+c-'0',c=getchar());
}
int occur[maxn],seq[maxn],top;
int n,father[maxn],dep[maxn],F[maxn][20],size[maxn];
int nEdge=1,to[maxn*2],next[maxn*2],start[maxn];
void make(int a,int b)
{
	++nEdge,to[nEdge]=b,next[nEdge]=start[a],start[a]=nEdge;
}
void read()
{
	Read(n);
	for(int i=2,a,b;i<=n;++i)
	{
		Read(a),Read(b);
		make(a,b),make(b,a);
	}
	dep[1]=1;
}
int LCA(int a,int b)
{
	if(dep[a]<dep[b])
		swap(a,b);
	for(int i=18;i>=0;--i)
		if(dep[F[a][i]]>=dep[b])
			a=F[a][i];
	if(a==b)
		return a;
	for(int i=18;i>=0;--i)
		if(F[a][i]!=F[b][i])
			a=F[a][i],b=F[b][i];
	return F[a][0];
}
int Find(int p,int d)
{
	for(int i=18;i>=0&&dep[p]>d;--i)
		if(dep[F[p][i]]>=d)
			p=F[p][i];
	return p;
}
void DFS(int p)
{
	seq[++top]=p,occur[p]=top,size[p]=1;
	for(int i=start[p];i;i=next[i])
		if(to[i]!=father[p])
		{
			int q=to[i];
			dep[q]=dep[p]+1;
			father[q]=p,F[q][0]=p;
			for(int j=0;F[F[q][j]][j];++j)
				F[q][j+1]=F[F[q][j]][j];
			DFS(q);
			size[p]+=size[q];
		}
}
int cmp(int a,int b)
{
	return occur[a]<occur[b];
}
void Query()
{
	static int stack[maxn];
	static int ask[maxn],tree[maxn],val[maxn],ans[maxn],in[maxn],tmp[maxn];
	static pair<int,int> near[maxn];
	int m;
	Read(m);
	for(int T=1;T<=m;++T)
	{
		int tn,tot=0,top=0;
		Read(tn);
		for(int i=1;i<=tn;++i)
		{
			Read(ask[i]);
			near[ask[i]]=make_pair(0,ask[i]);
			ans[ask[i]]=0;
			tmp[i]=ask[i];
			tree[i]=ask[i];
		}
		sort(ask+1,ask+tn+1,cmp);
		tot=tn;
		for(int j=1;j<=tn;++j)
		{
			int p=ask[j];
			if(top==0)
				stack[++top]=p,father[p]=0;
			else
			{
				int x=LCA(stack[top],p);
				father[p]=x;
				while(dep[stack[top]]>dep[x])
				{
					if(dep[stack[top-1]]<=dep[x])
						father[stack[top]]=x;
					--top;
				}
				if(stack[top]!=x)
				{
					father[x]=stack[top];
					stack[++top]=x,near[x]=make_pair(1<<30,0);
					tree[++tot]=x;
				}
				stack[++top]=p;
			}
		}
		sort(tree+1,tree+tot+1,cmp);
		for(int i=1;i<=tot;++i)
		{
			int p=tree[i];
			val[p]=size[p];
			if(i>1)
				in[p]=dep[p]-dep[father[p]];
		}
		for(int i=tot;i>1;--i)
		{
			int p=tree[i],fa=father[p];
			near[fa]=min(near[fa],make_pair(near[p].first+in[p],near[p].second));
		}
		for(int i=2;i<=tot;++i)
		{
			int p=tree[i],fa=father[p];
			near[p]=min(near[p],make_pair(near[fa].first+in[p],near[fa].second));
		}
		for(int i=1;i<=tot;++i)
		{
			int p=tree[i],fa=father[p],sum=size[Find(p,dep[fa]+1)]-size[p];
			if(fa==0)
				ans[near[p].second]+=n-size[p];
			else
			{
				val[fa]-=sum+size[p];
				if(near[p].second==near[fa].second)
					ans[near[p].second]+=sum;
				else
				{
					int dis=(dep[p]-dep[fa]+near[fa].first-near[p].first)/2,x;
					if(dis+near[p].first==dep[p]-dep[fa]-dis+near[fa].first&&near[fa].second<near[p].second)
						--dis;
					x=Find(p,dep[p]-dis);
					ans[near[p].second]+=size[x]-size[p];
					ans[near[fa].second]+=sum-size[x]+size[p];
				}
			}
		}
		for(int i=1;i<=tot;++i)
			ans[near[tree[i]].second]+=val[tree[i]];
		for(int i=1;i<=tn;++i)
			printf("%d ",ans[tmp[i]]);
		printf("\n");
	}
}
int main()
{
	freopen("sample.in","r",stdin);
	freopen("sample.out","w",stdout);
	read();
	DFS(1);
	Query();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
