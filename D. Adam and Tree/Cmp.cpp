#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int n;
int dp[1100000], ma[1100000], fa[1100000], ma2[1100000];

int main() {
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
	scanf("%d", &n);
	for (int i = 2; i <= n + 1; i++) {
		scanf("%d", &fa[i]);
		dp[i] = 1;
		int t = i;
		while (t != 1) {
			if (dp[t] > ma[fa[t]])	ma2[fa[t]] = ma[fa[t]], ma[fa[t]] = dp[t];
			else	ma2[fa[t]] = max(ma2[fa[t]], dp[t]);
			t = fa[t];
			if (max(ma[t], ma2[t] + 1) == dp[t])	break;
			dp[t] = max(ma[t], ma2[t] + 1);
		}
		printf("%d ", ma[1]);
	}
	fclose(stdin);fclose(stdout);
}
