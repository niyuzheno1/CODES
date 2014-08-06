#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#define X first
#define Y second
using namespace std;
int a[100][100],m,n,ans;
char r[100];
typedef pair<int,int> p;
map<p,int> b;
p operator +(p a,p b)
{
 return p(a.X+b.X,a.Y+b.Y);
}
vector<p> d;
queue<p> q;
void c(p x)
{
  q.push(x);
  while(!q.empty())
  {
   p u = q.front();q.pop();
   /*if(s(u))
    continue;*/
   
   for(int i = 0;i<d.size();i++)
    if(a[u.X+d[i].X][u.Y+d[i].Y] != 0 && !b[u+d[i]]){
     b[u+d[i]] = true;
     q.push(u+d[i]);
     }
  }
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
 for(int cani = 4;cani<=4;cani++){
    d.clear();b.clear();
    memset(a,0,sizeof(a));
    m = n =ans=0;
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr454.in%d",cani);
    sprintf(ouf,"mr454.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    d.push_back(p(1,0));
    d.push_back(p(0,1));
    d.push_back(p(-1,0));
    d.push_back(p(0,-1));
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=m;i++)
    {
     scanf("%s",&r[1]);
     for(int j = 1;j<=n;j++)
      a[i][j] = r[j]-'0';
    }
    for(int i = 1;i<=m;i++)
     for(int j = 1;j<=n;j++)
      if(a[i][j] != 0 && !b[p(i,j)])
       //if(!s(p(i,j)))
       c(p(i,j)),ans++;
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
