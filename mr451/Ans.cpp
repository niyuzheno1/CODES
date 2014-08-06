#include <cstdlib>
#include <vector>
#include <iostream>
#include <map>
#define X first
#define Y second
using namespace std;
char inf[101],ouf[101];
int M[51][51],N;
typedef pair<int,int> p;
typedef pair<p,p> p1;
typedef pair<p1,p> p2;
vector<p> r;
int Mp[51*51][51][51][51];
bool D(p m)
{
     if(m.X <= N && m.X >= 1)
      if(m.Y <= N && m.Y >= 1)
       return 1;
     
     return 0;
}
bool  une(p le,p ri)
{
          if(le.X != ri.X || le.Y != ri.Y)
           return true;
          
return false;
}
p operator +(p le,p ri)
{
           return p(le.X+ri.X,le.Y+ri.Y);
}
int dfs(int k,int x1,int x2,int x3)
{
    int ans = 0,mans=0;
    if(!D(p(x1,k-x1)))
     return 0;
    if(!D(p(x2,k-x2)))
     return 0;
    if(!D(p(x3,k-x3)))
     return 0;
    if(Mp[k][x1][x2][x3] != 0)
     return Mp[k][x1][x2][x3];
    ans = M[x1][k-x1];
    if(une(p(x2,k-x2),p(x1,k-x1)))
     ans += M[x2][k-x2];
    if(une(p(x3,k-x3),p(x1,k-x1))&& une(p(x3,k-x3),p(x2,k-x2)))
     ans += M[x3][k-x3];
    for(int i = 1;i<=2;i++)
     for(int j = 1;j<=2;j++)
      for(int z = 1;z<=2;z++)
       mans = max(mans,dfs(k+1,x1+r[i-1].X,x2+r[j-1].X,x3+r[z-1].X));
    Mp[k][x1][x2][x3] = ans+mans;
    return ans+mans;
}
int main(int argc, char *argv[])
{
  for(int cani = 0;cani<=4;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr451.in%d",cani);
    sprintf(ouf,"mr451.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    memset(M,0,sizeof(M));
    r.clear();
    memset(Mp,0,sizeof(Mp));

    scanf("%d",&N);
    r.push_back(p(1,0));
    r.push_back(p(0,1));
    for(int i = 1;i<=N;i++)
     for(int j = 1;j<=N;j++)
      scanf("%d",&M[i][j]);
    int ans = dfs(2,1,1,1);
    printf("%d",ans);
    
    fclose(stdin);fclose(stdout);
}
    
    return EXIT_SUCCESS;
}
