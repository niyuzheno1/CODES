#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <utility>
#include <queue>
#include <functional>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
void gpi(int &x){
	int c;
	while (!isdigit(c=getchar()));
	x=c-48;
	while ( isdigit(c=getchar())) x=x*10+(c-48);
}
const int maxn=100000+10,maxm=500000*2+10;//! *2!
const int inf=1000000000;//ll->inf's calc!!!!!!!!!!!!!!!
struct edge{
	int u,v,w,ne;
	bool fl;
}e[maxm];
int hd[maxn],tot;
void addedge(int u,int v,int w){
	e[++tot].u=u;e[tot].v=v;e[tot].w=w;e[tot].ne=hd[u];hd[u]=tot;
	e[++tot].u=v;e[tot].v=u;e[tot].w=w;e[tot].ne=hd[v];hd[v]=tot;
}
int ds[maxn],dt[maxn];
bool ss[maxn],st[maxn];
typedef priority_queue<pii,vector<pii>,greater<pii> > pq;
pq qs,qt;
struct data{
	int v,ne;
}e2[maxn];//n fei m!
int tot2,hd2[maxn];
void addedge2(int u,int v){
	e2[++tot2].v=v;e2[tot2].ne=hd2[u];hd2[u]=tot2;
}
int fa[maxn],prt[maxn];//0?????????????
int n;
void dj(int p,int *d,bool *s,pq q){
	for (int i=1;i<=n;i++)
		d[i]=inf;
	d[p]=0;
	q.push(make_pair(0,p));
	// wu s[1]!!
	for (int z=1;z<=n;z++){
		/*pii tmp=q.top();q.pop();//pop!
		while (!q.empty() && s[tmp.se]){
			tmp=q.top();q.pop();
		}
		if (s[tmp.se])//not q.empty()!!!!!!!!!!!!!!!!!!!!!!! abnormal stop!*/
		if (q.empty()) break;//!!!!!!!!!!!!!!
		pii tmp=q.top();q.pop();
		while (!q.empty() && s[tmp.se]){//!!!!!!!
			tmp=q.top();q.pop();
		}
		int x=tmp.se;
		if (s[x]) break;
		s[x]=true;
		for (int i=hd[x];i;i=e[i].ne){
			int y=e[i].v;//y not j!
			if (!s[y] && d[x]+e[i].w<d[y]){//!s!
				d[y]=d[x]+e[i].w;
				q.push(make_pair(d[y],y));
			}
		}
	}
}
int main(){
	freopen("sample.in","r",stdin);
	freopen("sample.out","w",stdout);
	int m;
	gpi(n);gpi(m);
	for (int i=1;i<=m;i++){
		int u,v,w;
		gpi(u);gpi(v);gpi(w);
		addedge(u,v,w);
	}
	dj(1,ds,ss,qs);
	dj(n,dt,st,qt);
	/*for (int i=2;i<=n;i++)
		ds[i]=inf;
	ds[1]=0;
	qs.push(make_pair(0,1));
	// wu s[1]!!
	for (int z=1;z<=n;z++){
		/*pii tmp=q.top();q.pop();//pop!
		while (!q.empty() && s[tmp.se]){
			tmp=q.top();q.pop();
		}
		if (s[tmp.se])//not q.empty()!!!!!!!!!!!!!!!!!!!!!!! abnormal stop!
		if (qs.empty()) break;//!!!!!!!!!!!!!!
		pii tmp=qs.top();qs.pop();
		while (!qs.empty() && ss[tmp.se]){//!!!!!!!
			tmp=qs.top();qs.pop();
		}
		int x=tmp.se;
		if (ss[x]) break;
		ss[x]=true;
		for (int i=hd[x];i;i=e[i].ne){
			int y=e[i].v;//y not j!
			if (!ss[y] && ds[x]+e[i].w<ds[y]){//!s!
				ds[y]=ds[x]+e[i].w;
				qs.push(make_pair(ds[y],y));
			}
		}
	}
	printf("%d\n",ds[n]);
	
	//memset(s,0,sizeof(s));
	//while (!s.empty()) s.pop(); //C!!!!!!
	
	for (int i=1;i<n;i++)//not 2-n!
		dt[i]=inf;
	dt[n]=0;//n not 1!
	qt.push(make_pair(0,n));//up
	// wu s[1]!!
	for (int z=1;z<=n;z++){
		/*pii tmp=q.top();q.pop();//pop!
		while (!q.empty() && s[tmp.se]){
			tmp=q.top();q.pop();
		}
		if (s[tmp.se])//not q.empty()!!!!!!!!!!!!!!!!!!!!!!! abnormal stop!
		if (qt.empty()) break;//!!!!!!!!!!!!!!
		pii tmp=qt.top();qt.pop();
		while (!qt.empty() && st[tmp.se]){//!!!!!!!
			tmp=qt.top();qt.pop();
		}
		int x=tmp.se;
		if (st[x]) break;
		st[x]=true;
		for (int i=hd[x];i;i=e[i].ne){
			int y=e[i].v;//y not j!
			if (!st[y] && dt[x]+e[i].w<dt[y]){//!s!
				dt[y]=dt[x]+e[i].w;
				qt.push(make_pair(dt[y],y));
			}
		}
	}
	printf("%d\n",dt[1]);*/
	//printf("%d\n",ds[n]);
	for (int i=1;i<n;i++){
		for (int j=hd[i];j;j=e[j].ne){
			int k=e[j].v;
			if (dt[k]+e[j].w==dt[i]){
				fa[i]=k;//not j!
				e[j].fl=true;
				addedge2(k,i);
				break;//!!!
			}
		}
	}
	
	static int qu[maxn],bot;
	qu[bot=1]=n;//n not 1!
	for (int i=1;i<=bot;i++){
		int x=qu[i];//!!
		for (int j=hd2[x];j;j=e2[j].ne)
			qu[++bot]=e2[j].v;//not j!
	}
	for (int i=1;i<=bot;i++){
		int x=qu[i];
		if (ds[x]+dt[x]==ds[n]) prt[x]=x;
		else prt[x]=prt[fa[x]];
	}
	int ans=inf;
	for (int i=1;i<=tot;i++){//not +=2!
		if (e[i].fl || ds[e[i].u]+e[i].w+dt[e[i].v]==ds[n]) continue;//not break!
		int u=prt[e[i].u],v=prt[e[i].v];
		if (!u || !v || u==v || ds[u]>ds[v]) continue;//!u !
		int tmp=ds[e[i].u]+e[i].w+dt[e[i].v];//not u v!
		if (tmp<ans) ans=tmp;
	}
	if (ans==inf) puts("-1");
	else printf("%d\n",ans);
	return 0;
}
