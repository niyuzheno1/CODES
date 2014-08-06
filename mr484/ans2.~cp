#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <vector>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n,l;
char m[210][510];
int a[210][4];
bool k[210][210];
vector<string> sl;
char inf[101],ouf[101];
bool s(int x,int y)
{
	for(int i = 1;i<=n;i++)
		if(k[x][i] == 0 && k[y][i] != 0)
			return 0;
	return 1;
}
void p(int x,int y)
{
	for(int i = 1;i<=n;i++)
		if(k[x][i] == 0 && k[y][i] != 0)
			k[x][i] = 1;
}
int main()
{
for(int cani = 0;cani<=4;cani++){
    l = 0;
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr484.in%d",cani);
    sprintf(ouf,"mr484.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	zero(m);
	zero(a);
	zero(k);
	sl.clear();
	scanf("%d\n",&n);
    for(int i = 1;i<=n;i++){
    char chr = 0;
    int tot = 0;
    scanf("%c",&chr);
     while(chr != '\n')
     {
     m[i][tot] = chr;
     tot++;
     scanf("%c",&chr);
     }
	 scanf("%d %d %d\n",&a[i][1],&a[i][2],&a[i][3]);
    }
	for(int i = 1;i<=n;i++)
		k[i][i] = 1;
	bool re = 1;
	while(re)
	{
	re = 0;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			if(i != j)
			{
			 if(a[i][1] > a[j][1] && a[i][2] > a[j][2])
				if(!s(i,j))
				 p(i,j),re = 1;
			 if(a[i][3] > a[j][3] && a[i][2] > a[j][2])
				if(!s(i,j))
				 p(i,j),re = 1;
			  if(a[i][1] > a[j][1] && a[i][3] > a[j][3])
				if(!s(i,j))
				 p(i,j),re = 1;
			}
	}
	for(int i = 1;i<=n;i++){
	int tot = 0;
		for(int j = 1;j<=n;j++)
			if(k[i][j] == 1)
				tot++;
	if(tot == n)
		l++,sl.push_back(string(m[i]));
	}
	printf("%d\n",l);
	sort(sl.begin(),sl.end());
	for(int i = 0;i<l;i++)
		printf("%s\n",sl[i].c_str());
   fclose(stdin);fclose(stdout);
}
	return 0;
}
