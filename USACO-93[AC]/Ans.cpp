#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> p;
set<p> all;
typedef set<p>::iterator it; 
int n,m;
p a[100010];
bool cmp(p x,p y)
{
     if(x.Y == y.Y)
      return x.X < y.X;
     return x.Y<y.Y;
}
int main(int argc, char *argv[])
{
    freopen("gourmet.in","r",stdin);
    freopen("gourmet.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&a[i].X,&a[i].Y);
    sort(a+1,a+1+n,cmp);
    for(int i = 1;i<=m;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     all.insert(p(x,y));
    }
    int ans = 0;
    for(int i = n;i>=1;i--)
    {
    int x = a[i].X,y = a[i].Y;
    while(true){
     it j = lower_bound(all.begin(),all.end(),p(x,y));
     if((*j).X == x){
      all.erase(j);
      break;
     }
     x = (*j).X;
    }
    ans+=x;
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
