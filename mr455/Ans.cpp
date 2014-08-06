#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
typedef pair<p,int> p2;
queue<p2> q;
int m,n,sx,sy;
map<p,int> l;
map<p,int> r;
vector<p> d;
char c[1000];
p operator +(p x,p  y)
{
 return p(x.X+y.X,x.Y+y.Y);
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    l.clear();r.clear();d.clear();
    memset(c,0,sizeof(c));
    m = n = sx= sy = 0;
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr455.in%d",cani);
    sprintf(ouf,"mr455.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    for(int i = -1;i<=1;i++)
     for(int j = -1;j<=1;j++)
      if(i != 0 || j != 0)
       d.push_back(p(i,j));
    scanf("%d%d%d%d",&m,&n,&sx,&sy);
	swap(m,n);
    swap(sx,sy);
    sx = m-sx+1;
    
    for(int i = 1;i<=m;i++){
     scanf("%s",&c[1]);
     for(int j = 1;j<=n;j++)
     if(c[j] == '.')
      l[p(i,j)] = 1;
    }
    q.push(p2(p(sx,sy),0));
    r[p(sx,sy)] = 1;
    int ans = 1;
    while(!q.empty())
    {
     p2 u = q.front();q.pop();
     for(int i = 0;i<d.size();i++)
      if(l[u.X+d[i]] == 1 && r[u.X+d[i]]==0)
      {
       r[u.X+d[i]] = 1;
       q.push(p2(u.X+d[i],u.Y+1));
       ans = max(ans,u.Y+1);
      }
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}

