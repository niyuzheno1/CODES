#include <cstdlib>
#include <iostream>
#include <vector>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
const int u = -20000;
char inf[101],ouf[101];
int n,c;
vector<int> p[50010][2];
vector<int> q[10010];
int f[10010][101][101];
void init()
{
     for(int i = 0;i<=50000;i++)
      p[i][0].clear(),p[i][1].clear();
     for(int i = 0;i<=10000;i++)
      q[i].clear();
     memset(f,0,sizeof(f));
}
int mod(int x)
{
    return (x%n)==0?n:(x%n);
}
int e(int x,int y)
{
    if( x%16 == y/2)
     return 0;
    else
     return 1;
}
int g(int x,int y)
{
 if(x-y >= 0)
  return x-y;
 else
  return 4-(y-(n-(4-x)));
}
int cal(int x,int y)
{
    int ans = 0;
    for(int i = 0;i<q[x].size();i++){
     for(int j = 0;j<=1;j++){
      int f = 0;
      for(int k = 0;k<p[q[x][i]][j].size();k++)
      if((y/(1<<g(x,p[q[x][i]][j][k])))%2 == j)
      {
       ans++;
       f = 1;
       break;
      }
      if(f)
       break;
     }
    }
    return ans;
}
int dfs(int x,int y,int z)
{
    if(x == n){
     if(e(y,z) == 0)
      return cal(x,y);
     else
      return u;
    }
    if(f[x][y][z])
     return f[x][y][z];
    int ans = cal(x,y);
    int ans1 = u;
    for(int i = 0;i<=1;i++)
     ans1 = max(ans1,dfs(x+1,(y*2+i)%32,z));
    
    return f[x][y][z] = (ans + ans1);
}
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=19;cani++){
    
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr487.in%d",cani);
    sprintf(ouf,"mr487.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    init();
    scanf("%d%d",&n,&c);
   
    for(int i = 1;i<=c;i++)
    {
    int e,f,l;
    scanf("%d%d%d",&e,&f,&l);
    q[mod(e+4)].push_back(i);
     for(int j = 1;j<=f;j++)
     {
         int x;
         scanf("%d",&x);
         p[i][0].push_back(x);
     }
     for(int j = 1;j<=l;j++)
     {
         int x;
         scanf("%d",&x);
         p[i][1].push_back(x);
     }
    }
    int ans = 0;
    for(int i = 0;i<=31;i++)
     ans = max(ans,dfs(1,i,i));
    printf("%d\n",ans);
    
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
