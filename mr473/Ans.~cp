#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>
#define X first
#define Y second
#define pb push_back
#define zero(x) memset(x,0,sizeof(x))
using namespace std;
typedef pair<int,int> p;
typedef pair<p,p> o;
vector<o> v,t;
int a[110];
int n,k,ans;
int cmp(o  x,o  y)
{
 return x.Y.X<y.Y.X;
}

void d()
{
     sort(v.begin(),v.end());
     o x = v[0];
     ans += x.X.X;
     for(int i = 1;i<v.size();i++)
      if(v[i].Y.X > x.Y.Y)
      {
       v[i].Y.X = v[i].Y.X-x.Y.Y+x.Y.X-1;
       v[i].Y.Y = v[i].Y.Y-x.Y.Y+x.Y.X-1;
       
      }
     v.erase(v.begin());
}
void u()
{
     sort(v.begin(),v.end(),cmp);
     for(int i = 0;i<v.size()-1;i++)
      if(v[i].X.Y+1 == v[i+1].X.Y && v[i].X.Y == v[i+1].X.Y)
      {
       v[i].Y.Y = v[i+1].Y.Y;
       v[i].X.X = v[i].Y.Y-v[i].Y.X+1;
       v.erase(v.begin()+i+1);
       i--;
      }
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    v.clear();
    t.clear();
    zero(a);
    n = k = ans = 0;
    sprintf(inf,"mr473.in%d",cani);
    sprintf(ouf,"mr473.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)
     {
     a[0] = i;
     for(int j = i;j<=n;j++)
      if(a[j] != a[i])
      {
              i = j-1;
              break;
      }
     v.pb(o(p(i-a[0]+1,a[i]),p(a[0],i)));
     }
     while(v.size() > k){
      d();
      u();
     }
     printf("%d\n",ans);
     fclose(stdin);fclose(stdout);
}
    system("PAUSE");
    return EXIT_SUCCESS;
}
