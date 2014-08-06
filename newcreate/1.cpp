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
typedef pair<int,string> p;
int n,m;
char name[100];
map<string,int> s;
set<p> e;
char inf[101],ouf[101];
int main()
{
for(int cani = 0;cani<=9;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"star.in%d",cani);
    sprintf(ouf,"star.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	n = m = 0;
	ze(s);
	ze(e);
	zero(name);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
	scanf("%s",name);
	s[string(name)] = 0;
	}
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
	scanf("%s%d",name,&m);
	s[string(name)] +=  m;
	}
	for(map<string,int>::iterator it = s.begin();it !=  s.end();it++)
	{
		e.insert(p((*it).second,(*it).first));
	}
	set<p>::iterator it  = e.end();
	it--;
	set<p>::iterator it2 =  e.begin();
	it2--;
	for(;it != it2;it--)
		printf("%s\n%d\n",(*it).second.c_str(),(*it).first);
    fclose(stdin);fclose(stdout);
}
	return 0;
}
