#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#define X first
#define Y second
using namespace std;
int n,s[100010],b[100010];
char inf[101],ouf[101];
void f(int x)
{
    int l = 0,m = 0;
    for(int i = 2;i<=x;i++){
     if(x % i == 0)
     {
      l++;
      s[l] = i;
      m = max(m,b[i]);
     }
     while(x % i == 0)
      x /=i;
    }
    for(int i = 1;i<=l;i++)
     b[s[i]] = m+1;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    memset(s,0,sizeof(s));
    memset(b,0,sizeof(b));
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr457.in%d",cani);
    sprintf(ouf,"mr457.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = 0;
    
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int b;
     scanf("%d",&b);
     f(b);
    }
    int ans = 0;
    for(int i = 1;i<=100000;i++)
     ans = max(ans,b[i]);
    printf("%d",ans);
	fclose(stdin);fclose(stdout);
}
   
    return EXIT_SUCCESS;
}
