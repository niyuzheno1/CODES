#include <cstdlib>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <complex>
#include <vector>
#include <iterator>
#include <numeric>
using namespace std;

typedef long long LL;
LL n;
typedef complex<LL> poLL;
poLL a[50010];
poLL hull[50010];
poLL worst[50010];
LL ans,ans2[50010];
LL cross(poLL x,poLL y)
{
    return imag(conj(x)*y);
}
LL area(poLL x,poLL y,poLL z)
{
    return cross(y-x,z-x);
}
bool cmp(poLL x,poLL y)
{
     return (area(poLL(0,0),x,y)>0);
}
poLL s;
int main(int argc, char *argv[])
{
    freopen("schul.in","r",stdin);
    freopen("schul.out","w",stdout);
    scanf("%I64d",&n);
    for(LL i = 1;i<=n;i++)
    {
     LL p,t;
     scanf("%I64d%I64d",&p,&t);
     a[i] = poLL(t,p);
    }
    sort(a+1,a+1+n,cmp);
  
    LL H = 0;
    for(LL i = n;i>=1;i--)
    {
     while(H >= 1 && imag(hull[H-1]) <= imag(a[i]))
      H--;
     while(H >= 2 && area(hull[H-2],hull[H-1],a[i])>=0)
      H--;
     hull[H++] = a[i];
     s+=a[i];
     while(H>=2 && cross(s,hull[H-2]-hull[H-1]) <= 0)
      H--;
     worst[i-1] = hull[H-1];
    }
    H = 0;
    
    for(LL i = 1;i<=n;i++)
    {
     while(H >= 1 && real(hull[H-1]) >= real(a[i]))
      H--;
     while(H >= 2 && area(hull[H-2],hull[H-1],a[i])>=0)
      H--;
     hull[H++] = a[i];
     s-=a[i];
     while(H>=2 && cross(s,hull[H-2]-hull[H-1]) >= 0)
      H--;
     if(cross(s,worst[i]-hull[H-1]) < 0)
      ans++,ans2[ans] = i;
    }
    printf("%I64d\n",ans);
    for(LL i = 1;i<=ans;i++)
     printf("%I64d\n",ans2[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
