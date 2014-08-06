#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

#define maxn 200010
#define INF 1000000000

	struct node
	{
		int left, right, mid;
		pair<int,int> val;
	};
	node a[524288];
	
	void update(int i)
	{
		a[i].val=min(a[i*2].val,a[i*2+1].val);
	}
	
	void build(int i, int bg, int ed, pair<int,int> *d)
	{
		a[i].left=bg; a[i].right=ed; a[i].mid=(bg+ed)/2;
		if (bg==ed) { a[i].val=d[bg]; return; }
		build(i*2,bg,a[i].mid,d); build(i*2+1,a[i].mid+1,ed,d);
		update(i);
	}
	
	pair<int,int> query(int i, int bg, int ed)
	{
		if (bg<=a[i].left && a[i].right<=ed) return a[i].val;
		if (ed<=a[i].mid) return query(i*2,bg,ed);
		if (a[i].mid<bg) return query(i*2+1,bg,ed);
		return min(query(i*2,bg,ed),query(i*2+1,bg,ed));
	}
	
	void serere(int i, int pl, pair<int,int> val)
	{
		if (a[i].left==a[i].right) { 
                                   a[i].val=val; 
                                   return; 
  }
		if (pl<=a[i].mid) serere(i*2,pl,val); else serere(i*2+1,pl,val);
		update(i);
	}


vector< pair<int,int> > qlist[maxn];
vector<int> lis[maxn];
int bk;
int len[maxn], cur[maxn], dl[maxn], final[maxn];


	pair<int,int> d[maxn];
	
	void init(int n)
	{
		rep(i,1,n) if (cur[i]==len[i]) d[i]=make_pair(INF,0); else d[i]=qlist[i][cur[i]];
		build(1,1,n,d);
	}
	
	void query2(int l, int r, int rval)
	{
		if (l>r) return;
		while (1)
		{
			pair<int,int> val=query(1,l,r);
			if(val.first == 49)
			 val.first = 49;
			if (val.first>r) break;
			int i=dl[val.second];
			if(i == 18) 
            i =18;
			while (cur[i]<len[i] && qlist[i][cur[i]].first<=r)
			{
                if(qlist[i][cur[i]].second == 2)
                   bk = 2;
				final[qlist[i][cur[i]].second]=rval;
				cur[i]++;
			}
			if (cur[i]==len[i]) 
            serere(1,i,make_pair(INF,0)); else serere(1,i,qlist[i][cur[i]]);
		}
	}


void lemon()
{
	int n,qa; scanf("%d%d",&n,&qa);
	rep(i,0,200001) lis[i].push_back(0);
	rep(i,1,n)
	{
		int x; scanf("%d",&x);
		lis[x].push_back(i);
	}
	rep(i,0,200001) lis[i].push_back(n+1);

	rep(i,1,qa)
	{
		int l,r; scanf("%d%d",&l,&r); dl[i]=l;
		qlist[l].push_back(make_pair(r,i));
	}
	rep(i,1,n) sort(qlist[i].begin(),qlist[i].end());
	rep(i,1,n) len[i]=qlist[i].size(), cur[i]=0;
	
	init(n);
	rep(i,0,200001)
		rep(k,0,lis[i].size()-2)
			query2(lis[i][k]+1,lis[i][k+1]-1,i);
	
	rep(i,1,qa) printf("%d\n",final[i]);
}

int main()
{
	ios::sync_with_stdio(true);
	freopen("sample.in","r",stdin);
	freopen("sample.out","w",stdout);
    lemon();
	return 0;
}
