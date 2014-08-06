#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long int64;
const int64 MAXN  = 50010;
int64 n,m,sn;
int64 a[MAXN],b[MAXN],c[MAXN];
int64 gcd(int64 x,int64 y)
{
 if(y == 0)
  return x;
 return gcd(y,x%y);
}
struct lis
{
 int64 x,y;
 int64 ans1,ans2,num;
 void updata()
 {
  int64 x = gcd(ans1,ans2);
  ans1/=x;ans2/=x;
 }
 bool operator<(lis z) const
 {
  if(x/sn == z.x/sn)
   return y < z.y;
  else
   return x/sn<z.x/sn;
 }
};
bool cmp(lis x,lis y)
{
 return x.num < y.num;
}
lis l[MAXN];
void solve()
{
 int64 g = 0,tmp = 0,ll = 0,rr = 0;
 for(int64 i = 1;i<=m;i++)
 {
  if(l[i].x/sn != l[i-1].x/sn || i == 1)
  {
   g++;
   tmp = 0;
   ll = l[i].x;
   rr = l[i].x-1;
  }
  while(ll > l[i].x)
  {
   ll--;
   if(c[a[ll]] < g)
    b[a[ll]] = 0,c[a[ll]]=g;
   tmp-=b[a[ll]]*b[a[ll]];
   b[a[ll]]++;
   tmp+=b[a[ll]]*b[a[ll]];
  }
  while(ll < l[i].x)
  {
   if(c[a[ll]] < g)
    b[a[ll]] = 0,c[a[ll]]=g;
   tmp-=b[a[ll]]*b[a[ll]];
   b[a[ll]]--;
   tmp+=b[a[ll]]*b[a[ll]];
   ll++;
  }
  while(rr < l[i].y)
  {
   rr++;
   if(c[a[rr]] < g)
    b[a[rr]] = 0,c[a[rr]]=g;
   tmp-=b[a[rr]]*b[a[rr]];
   b[a[rr]]++;
   tmp+=b[a[rr]]*b[a[rr]];
  }
  while(rr > l[i].y)
  {
   if(c[a[rr]] < g)
    b[a[rr]] = 0,c[a[rr]]=g;
   tmp-=b[a[rr]]*b[a[rr]];
   b[a[rr]]--;
   tmp+=b[a[rr]]*b[a[rr]];
   rr--;
  }
  l[i].ans1 = tmp-(l[i].y-l[i].x+1);
  l[i].ans2 = (l[i].y-l[i].x+1)*(l[i].y-l[i].x);
  l[i].updata();
 }
}
int main()
{
    //freopen("A1206.in","r",stdin);freopen("A1206.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int64 i = 1;i<=n;i++)
     scanf("%lld",&a[i]);
    sn = int(sqrt(n))+1;
    for(int64 i = 1;i<=m;i++)scanf("%lld%lld",&l[i].x,&l[i].y),l[i].num = i;
    sort(l+1,l+1+m);
    solve();
    sort(l+1,l+1+m,cmp);
    for(int64 i = 1;i<=m;i++)
     printf("%I64d/%I64d\n",l[i].ans1,l[i].ans2);
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
