#include <cstdlib>
#include <iostream>

using namespace std;
int N;
int x,y;
int main(int argc, char *argv[])
{
	scanf("%d",&N);
	for(int i = 1;i<=N-1;i++){
		scanf("%d%d",&x,&y)
		g.add(x,y);
	}
	g.dfs(1);
	system("PAUSE");
	return EXIT_SUCCESS;
}
