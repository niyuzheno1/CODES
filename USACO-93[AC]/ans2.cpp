#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#define X first
#define Y second

using namespace std;
typedef long long int64;
typedef pair<int64,int64> p;
set<p> all;
typedef set<p>::iterator it;
int64 n,m;
p a[100010];
p b[100010];
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
    scanf("%I64d%I64d",&n,&m);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&a[i].X,&a[i].Y);
    sort(a+1,a+1+n,cmp);
    for(int64 i = 1;i<=m;i++)
     scanf("%I64d%I64d",&b[i].X,&b[i].Y);
    sort(b+1,b+1+m,cmp);
    int64 ans = 0,j = m;
    for(int64 i = n;i>=1;i--)
    {
     while(j >=1 && b[j].Y >= a[i].Y  )
      all.insert(b[j]),j--;
     it pt = all.lower_bound(a[i]);
     ans += (*pt).X;
     all.erase(pt);
    }
    printf("%I64d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
