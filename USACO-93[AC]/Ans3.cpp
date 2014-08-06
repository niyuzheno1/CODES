/*#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#define X first
#define Y second

using namespace std;
typedef pair<int,int> p;
set<int> all;
typedef set<int>::iterator it;
int n,m;
p a[100010];
p b[100010];
int main(int argc, char *argv[])
{
    freopen("gourmet.in","r",stdin);
    freopen("gourmet.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+1+n);
    for(int i = 1;i<=m;i++)
     scanf("%d%d",&b[i].X,&b[i].Y);
    sort(b+1,b+1+m);
    int j = 1,ans = 0;
    for(int i = 1;i<=m;i++)
    {
     while(j <= n && a[j].X <= b[i].X)
      all.insert(a[j].Y),j++;
     if(all.size() == 0)
      continue;
     it k = all.begin();
     if(*k <= b[i].Y){
      ans += b[i].X;
      all.erase(k);
     }
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}*/
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> Pair;

int main()
{
	assert(freopen("gourmet.in", "r", stdin) != NULL);
	assert(freopen("gourmet.out", "w", stdout) != NULL);

	int N, M;
	scanf("%d %d", &N, &M);

	vector<Pair> cows(N), grass(M);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &cows[i].first, &cows[i].second);

	for (int i = 0; i < M; i++)
		scanf("%d %d", &grass[i].first, &grass[i].second);

	// sort everything by price
	sort(cows.begin(), cows.end());
	sort(grass.begin(), grass.end());

	int i = 0, j = 0;
	long long res = 0;
	set<Pair> cset;

	// greedily match grass packages with cows in order of increasing cost
	for (; i < (int)grass.size(); i++) {
		int curCost = grass[i].first;
		int curGreen = grass[i].second;

		while (j < (int)cows.size() && cows[j].first <= curCost) {
			cset.insert(Pair(cows[j].second, j));
			j++;
		}

		if (cset.size() != 0) {
			int g = cset.begin()->first;
			if (g <= curGreen) {
				cset.erase(cset.begin());
				res += curCost;
			}
		}
	}

	if (j != (int)cows.size() || cset.size() != 0) {
		printf("IMPOSSIBLE\n");
	} else {
		printf("%lld\n", res);
	}
}
