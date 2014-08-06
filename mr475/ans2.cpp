#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define pb push_back
#define zero(x) memset(x,0,sizeof(x))
using namespace std;
map<int,int> b;
int n;
int c(int x,int y)
{
 x ^= 1<<y;
 if(y-5 >= 1)
 x ^= 1<<(y-5);
 if(y+5 <= 25)
 x ^= 1<<(y+5);
 if(y-1 >= 1 && y%5 != 1)
 x ^= 1<<(y-1);
 if(y+1 <= 25 && y%5 != 0)
 x ^= 1<<(y+1);
 return x;
}
int f[60915801];
int tot = 0;
int d[60915801];
char s[10];
char inf[101],ouf[101];
void print(int x)
{
	if(x == 0)
		printf("-1\n");
	else if(x == -1)
		printf("2\n");
	else
		printf("%d\n",x);
}
int main()
{
	f[0] = 67108862;
	d[0] = 0;
	b[f[0]] = -1;
	for(int i = 0;d[i]<=6;i++)
	{
	
	 for(int j = 1;j<=25;j++){
		 tot++;
		 f[tot]=c(f[i],j);
		 if(b[f[tot]]){
			 tot--;
			 break;
		 }
		 d[tot]=d[i]+1;
		 
		 b[f[tot]] = d[tot];
	 }
	}
for(int cani = 0;cani<=9;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr475.in%d",cani);
    sprintf(ouf,"mr475.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	scanf("%d",&n);
	for(int i = 1;i<=n;i++)
	{
		int ans = 0;
		for(int j = 1;j<=5;j++){
		 scanf("%s",&s);
		 for(int k = 0;k<=4;k++)
		   if(s[k] == '1')
			   ans |= 1<<((j-1)*5+k+1);
		}
		print(b[ans]);
	}
	 fclose(stdin);fclose(stdout);
}
	return 0;
}
