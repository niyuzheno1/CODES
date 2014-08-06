#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
int n,x,y,z;
int m[71][71];
typedef pair<int,int> p;
typedef pair<int,p> p1;
map<p1,int> mp;
int dfs(int k,int x,int u)
{
    int ans = 0,ansa=0;
    p1 s = p1(k,p(x,u));
    if(mp[s])
     return mp[s];
    if(k-x > n || k-x < 1)
     return 0;
    if(x > n || x < 1)
     return 0; 
    if(k-u > n || k-u < 1)
     return 0;
    if(u > n || u < 1)
     return 0; 
    ans = m[x][k-x];
    if(x != u)
     ans +=  m[u][k-u];
    for(int i = 0;i<=1;i++)
     for(int j = 0;j<=1;j++)
      ansa = max(ansa,dfs(k+1,x+i,u+j));
     mp[s] = ans+ansa;
     return ans+ansa;
    
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
 for(int cani = 0;cani<=9;cani++){
    mp.clear();
    memset(m,0,sizeof(m));
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr450.in%d",cani);
    sprintf(ouf,"mr450.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d",&n);
    x=y=z=-1;
    while(!(x==0&&y==0&&z==0))
    {
     scanf("%d%d%d",&x,&y,&z);
     m[x][y] = z;
    }
    printf("%d",dfs(2,1,1));
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
