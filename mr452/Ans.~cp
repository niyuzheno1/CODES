#include <cstdlib>
#include <iostream>
#include <queue>
#include <map>
#define X first
#define Y second
using namespace std;

long long h[4][400010],n;
long long bin[400010];
int l,r;
int s(int v)
{
    
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
  for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr452.in%d",cani);
    sprintf(ouf,"mr452.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
	long long ans =0;
	memset(h,0,sizeof(h));
	memset(bin,0,sizeof(bin));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%I64d",&h[1][i]);
    for(int i = 1;i<=n;i++)
    {
		while(r > 0 && h[1][bin[r]] > h[1][i])
			r--;
		 h[2][i] = bin[r]+1;
		 r++;
		 bin[r] = i;
	}
	bin[0]=n+1;
	for(int i = n;i>=1;i--)
    {
		while(r > 0 && h[1][bin[r]] > h[1][i])
			r--;
		 h[3][i] = bin[r]-1;
		 r++;
		 bin[r] = i;
	}
	for(int i = 1;i<=n;i++)
		ans = max(ans,h[1][i]*(h[3][i]-h[2][i]+1));
	printf("%I64d",ans);
	  fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
