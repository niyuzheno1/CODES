#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>   
#include<queue>
#include<cstdlib>
#include<vector>
using namespace std; 

#define N 10001
vector<int> v[N];
int n,m;

void dfs(int k)
{
	int i,j;
	
	while (v[k].size())
	{
		j=v[k][v[k].size()-1];
		v[k].pop_back();
		dfs(j);
	}printf("%d\n",k);   
}

int main()
{
	
	freopen("watchcow.in","r",stdin);
	freopen("watchcow.out","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++)
		v[i].clear();
	while (m--)
	{
		scanf("%d%d",&i,&j);
		v[i].push_back(j);
		v[j].push_back(i);

	}
	
	dfs(1);
    fclose(stdin);
    fclose(stdout);
	return 0;
}
