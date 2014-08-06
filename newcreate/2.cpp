#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#define ze(x) x.clear()
#define zero(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;
int n,k,b;
char h[110];
vector<string> a;
map<string,int> m;
vector<int> s;
bool cmp(int a,int b)
{
	return a > b;
}
char inf[101],ouf[101];
int main()
{
for(int cani = 0;cani<=5;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr293.in%d",cani);
    sprintf(ouf,"mr293.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	n=k=b=0;
	zero(h);
	ze(a);ze(m);ze(s);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		scanf("%s",h);
		a.push_back(string(h));
	}
	scanf("%d",&k);
	for(int i = 1;i<=k;i++){
		s.clear();
		for(int j = 1;j<=n;j++)
		{
			scanf("%d%s",&b,h);
			m[string(h)]+=b;
		}
		for(int j = 1;j<=n;j++)
			s.pb(m[a[j-1]]);
		sort(s.begin(),s.end(),cmp);
		for(int j = 1;j<=n;j++)
			if(s[j-1] == m["JLY"])
			{
				printf("%d\n",j);
				break;
			}
	}
    fclose(stdin);fclose(stdout);
}
	return 0;
}
