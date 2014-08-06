#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 20010;
int N,ans;
int V[maxn],X[maxn];
int main(int argc, char *argv[])
{
    ans = 0;
    scanf("%d",&N);
    for(int i = 1;i<=N;i++)
    {
	int v,x;
	scanf("%d%d",&v,&x);
	for(int j = 1;j<i;j++)
	 ans += max(V[j],v)*abs(x-X[j]);
	V[i] = v;X[i] = x;
    }
    printf("%d",ans);
    return EXIT_SUCCESS;
}
