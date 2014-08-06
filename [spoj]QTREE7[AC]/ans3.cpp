#include <cstdio>
#include <algorithm>
#include <set>
using std::multiset;
const int N = 100000 + 9;
int col[N],n,son[N],lnk[N * 2],nxt[N * 2],fa[N],ec;
struct info
{
	int l[N],r[N],p[N],max[N],v[N];
	multiset<int>s[N];
	void reset(int n)
	{
		for (int i = 1; i <= n + 1; ++i) l[i] = r[i] = p[i] = max[i] = v[i] = 0,s[i].clear();
	}
	void update(int x)
	{
		max[x] = v[x];
		if (s[x].size()) max[x] = std::max(max[x],*s[x].rbegin());
		if (l[x]) max[x] = std::max(max[x],max[l[x]]);
		if (r[x]) max[x] = std::max(max[x],max[r[x]]);
	}
	bool isrt(int x){return !p[x] || l[p[x]] != x && r[p[x]] != x;}
	void rig(int x)
	{
		int y = l[x];
		p[y] = p[x];
		if (l[p[x]] == x) l[p[x]] = y;
		if (r[p[x]] == x) r[p[x]] = y;
		p[r[y]] = x;
		l[x] = r[y];
		p[x] = y;
		r[y] = x;
		update(x);
	}
	void lef(int x)
	{
		int y = r[x];
		p[y] = p[x];
		if (l[p[x]] == x) l[p[x]] = y;
		if (r[p[x]] == x) r[p[x]] = y;
		p[l[y]] = x;
		r[x] = l[y];
		p[x] = y;
		l[y] = x;
		update(x);
	}
	void splay(int x)
	{
		while (!isrt(x)) {
			int y = p[x],z = p[y];
			if (!isrt(y) && l[z] == y && l[y] == x) rig(z),rig(y);
			else if (!isrt(y) && r[z] == y && r[y] == x) lef(z),lef(y);
			else if (l[y] == x) rig(y);
			else lef(y);
		}
		update(x);
	}
	void access(int rt)
	{
		for (int x = 0,y = rt; y; y = p[y]) {
			splay(y);
			if (r[y]) s[y].insert(max[r[y]]);
			if ((r[y] = x)) s[y].erase(s[y].find(max[x]));
			update(x = y);
		}
		splay(rt);
	}
	int findrt(int x)
	{
		access(x);
		while (l[x]) x = l[x];
		return x;
	}
	void cut(int x)
	{
		access(x);
		p[l[x]] = 0; l[x] = 0;
		update(x);
	}
	void modify(int x,int y)
	{
		access(x);
		v[x] = y;
		update(x);
	}
	void link(int x)
	{
		access(fa[x]);
		splay(x);
		r[fa[x]] = x;
		update(p[x] = fa[x]);
	}
	int query(int x)
	{
		x = findrt(x); splay(x);
		return max[r[x]];
	}
}t[2];
void cut(int x)
{
	t[col[x]].cut(x);
}
void link(int x)
{
	t[col[x]].link(x);
}
void modify(int x,int y)
{
	t[0].modify(x,y);
	t[1].modify(x,y);
}
void toggle(int x)
{
	cut(x);
	col[x] ^= 1;
	link(x);
}
inline void addedge(const int x,const int y)
{
	nxt[++ec] = son[x];
	lnk[son[x] = ec] = y;
}
void dfs(const int x)
{
	for (int i = son[x]; i; i = nxt[i])
		if (fa[x] != lnk[i]) {
			fa[lnk[i]] = t[col[lnk[i]]].p[lnk[i]] = x;
			dfs(lnk[i]);
			t[col[lnk[i]]].s[x].insert(t[col[lnk[i]]].max[lnk[i]]);
		}
	t[col[x]].update(x);
	t[col[x]^1].update(x);
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("QTREE7.in","r",stdin);
	freopen("QTREE7.out","w",stdout);
	#endif
	while (~scanf("%d",&n)) {
		for (int i = 1,x,y; i < n; ++i) {
			scanf("%d%d",&x,&y);
			addedge(x,y);
			addedge(y,x);
		}
		for (int i = 1; i <= n; ++i) scanf("%d",col + i);
		for (int i = 1; i <= n; ++i) {scanf("%d",&t[0].v[i]);t[1].v[i] = t[0].v[i];}
		fa[1] = t[col[1]].p[1] = n + 1;
		dfs(1);
		t[col[1]].s[n + 1].insert(t[col[1]].max[1]);
		int m = 0;
		scanf("%d",&m);
		for (int opt,x,y; m--; ) {
			scanf("%d%d",&opt,&x);
			if (opt == 2) {
				scanf("%d",&y);
				modify(x,y);
			}else if (!opt) printf("%d\n",t[col[x]].query(x));
			else toggle(x);
		}
		ec = 0;
		for (int i = 1; i <= n; ++i) son[i] = 0;
		t[0].reset(n); t[1].reset(n);
	}
}