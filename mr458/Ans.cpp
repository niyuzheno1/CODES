#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#define X first
#define Y second
using namespace std;

typedef pair<int,int> p;
typedef pair<int,p> p2;
int n;
vector<p2> v;
map<int,int> m;
int f(int x)
{
    if(x != m[x])
         return f(m[x]);
    return x;
}
int u(int x,int y)
{
    x = f(x);y=f(y);
    m[x] = y;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr458.in%d",cani);
    sprintf(ouf,"mr458.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = 0;
    v.clear();
    m.clear();
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int d = 0;
     scanf("%d",&d);
     v.push_back(p2(d,p(0,i)));
     v.push_back(p2(d,p(i,0)));
    }
    for(int i = 0;i<=n;i++)
     m[i] = i;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=n;j++)
     {
     int d = 0;
     scanf("%d",&d);
     v.push_back(p2(d,p(i,j)));
     }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i = 0;i<v.size();i++)
    {
      if(f(v[i].Y.X) != f(v[i].Y.Y))
      {   
          ans += v[i].X;
          u(v[i].Y.X,v[i].Y.Y);
          
      }
    }
    printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
}
    
    return EXIT_SUCCESS;
}
