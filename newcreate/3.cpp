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
#include <queue>
#define ze(x) x.clear()
#define zero(x) memset(x,0,sizeof(x))
#define pb push_back
using namespace std;

long long s;
queue<long long> t;
long long A(long long x)
{
	char n[110];
	zero(n);
	sprintf(n,"%I64d",x);
	x = 0;
	for(int i = strlen(n)-1;i>=0;i--)
	{
		x*=10;
		x += (n[i]-'0');
	}
	return x;
}
long long B(long long x)
{
	char n[110];
	zero(n);
	sprintf(n,"%I64d",x);
	x = 0;
	long long y = 0;
	for(int i = 0;i<=2;i++)
	{
		x*=10;
		x += (n[i]-'0');
	}
	x*=10000;
	x += (n[3]-'0')*10000000;
	x += (n[4]-'0');
	for(unsigned int i = 5;i<=strlen(n)-1;i++)
	{
		y*=10;
		y += (n[i]-'0');
	}
	y*=10;
	x+=y;
	return x;
}
long long C(long long x)
{
	char n[110];
	zero(n);
	sprintf(n,"%I64d",x);
	x = 0;
	x = (n[0]-'0')*10000000;
	x += (n[6]-'0')*1000000;
	x += (n[1]-'0')*100000;
	x += (n[3]-'0')*10000;
	x += (n[4]-'0')*1000;
	x += (n[2]-'0')*100;
	x += (n[5]-'0')*10;
	x += (n[7]-'0')*1;
	return x;
}
long long k[99999999];
map<long long,string> u;
char inf[101],ouf[101];
int main()
{
	memset(k,0x7f,sizeof(k));
	s =12345678;
	k[s] = 0;
	t.push(s);
	while(!t.empty())
	{
		long long p = t.front();
		t.pop();
		s = A(p);
		if(k[p]+1 < k[s] || (k[p]+1 == k[s] && u[p]+'A' < u[s]))
		{
		 k[s]=k[p]+1;
		 u[s] =u[p]+'A';
		 t.push(s);
		}
		
		s = B(p);
		if(k[p]+1 < k[s] || (k[p]+1 == k[s] && u[p]+'B' < u[s]))
		{
		 k[s]=k[p]+1;
		 u[s] =u[p]+'B';
		 t.push(s);
		}
		
		s = C(p);
		if(k[p]+1 < k[s] || (k[p]+1 == k[s] && u[p]+'C' < u[s]))
		{
		 k[s]=k[p]+1;
		 u[s] =u[p]+'C';
		 t.push(s);
		}
	}
for(int cani = 0;cani<=9;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr288.in%d",cani);
    sprintf(ouf,"mr288.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	int j = 0,o = 0;
	for(int i = 1;i<=8;i++)
	{scanf("%d",&j);
		o*=10;
		o+=j;
	}
	printf("%I64d\n",k[o]);
	printf("%s\n",u[o].c_str());
    fclose(stdin);fclose(stdout);
}
	return 0;
}
