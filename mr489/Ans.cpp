#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n,m,t;
char s[51][51];
int f[51][51][2510];
char inf[101],ouf[101];
int dfs(int x,int y,int q)
{
    if(x > n)
     return 0;
    if(y > m)
     return dfs(x+1,1,q);
    if(q > t)
     return 0;
    int & ans = f[x][y][q];
    if(ans)
     return ans;
    ans = dfs(x,y+1,q);
    int ret = 0;
    for(int i = y;i<=m;i++){
     if(s[x][i] == s[x][y])
      ret++;
     ans =max(ans,dfs(x,i+1,q+1)+ret);
    }
    return ans;
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr489.in%d",cani);
    sprintf(ouf,"mr489.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(&f,0,sizeof(f));
    scanf("%d%d%d",&n,&m,&t);
    for(int i = 1;i<=n;i++)
     scanf("%s",&s[i][1]);
    printf("%d",dfs(1,1,1));
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
