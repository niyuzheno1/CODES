#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
char str[2100];
int costdel[255];
int costins[255];
const int inf = 0x7f7f7f7f;
int N,M;
void dn(int & x,int y)
{
	x = min(x,y);
}
int dfs(int x,int y)
{
	if(x>=y)
		return 0;
	if(str[x] == str[y])
		 return dfs(x+1,y-1);
     if(str[x] != str[y])
	 {
		int ans = inf;
		dn(ans,dfs(x+1,y)+costdel[str[x]]);
		dn(ans,dfs(x,y-1)+costdel[str[y]]);
		dn(ans,dfs(x+1,y)+costins[str[x]]);
		dn(ans,dfs(x,y-1)+costins[str[y]]);
		return ans; 
	 }
}
int main(int argc, char *argv[])
{
	scanf("%d %d",&N,&M);
	for(int i = 1;i<=M;i++)
		 scanf("%c",&str[i]);
	for(int i = 1;i<=N;i++)
	{
	 char re;int ins,del;
	  scanf("%c%d%d",&re,&ins,&del);
	  costins[re] = ins;
	  costdel[re] = del;
	}
	int ans = dfs(1,M);
	printf("%d",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
