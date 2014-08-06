#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;

struct m
{
 int h,c,a;
 bool operator < (m x) const
 {
  if(a == x.a)
   return h > x.h;
  return a < x.a;
 }
};
int n;
m a[410];
int f[410][40010];
typedef pair<int,int> p;

int dfs(int x,int y)
{
    if(x > n)
     return 0;
   
    if(f[x][y])
     return f[x][y];
    int ans = 0;
    for(int i = 0;i<=a[x].c;i++)
     if(y+a[x].h*i <= a[x].a)
      ans = max(ans,dfs(x+1,y+a[x].h*i)+a[x].h*i);
    return f[x][y]=ans;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr460.in%d",cani);
    sprintf(ouf,"mr460.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);  
    n = 0;
    memset(&a,0,sizeof(a));
    memset(&f,0,sizeof(f));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%d%d%d",&a[i].h,&a[i].a,&a[i].c);
     a[i].c = min(a[i].c,a[i].a/a[i].h);
    }
    sort(a+1,a+1+n);
    printf("%d",dfs(1,0));
	fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
