#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
const int64 inf = 0x7f7f7f7f;
int64 n;
struct r
{
 int64 h,w;
 bool operator < (r p) const
 {
  if(h == p.h)
   return w < p.w;
  return h < p.h;
 }
};
r a[50010];
struct px
{
int64 f;
int64 w;
};
px b[50010];
int64 he,t;
bool tail()
{
     int64 p = t-2,q = t-1,r = t;
     return (b[p].f-b[q].f)*(b[q].w-b[r].w) < (b[r].f-b[q].f)*(b[q].w-b[p].w);

}
int main(int argc, char *argv[])
{
    freopen("acquire.in","r",stdin);
    freopen("acquire.out","w",stdout);
    scanf("%I64d",&n);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&a[i].h,&a[i].w);
    sort(a+1,a+1+n);
    int64 j = 1;
    for(int64 i = 1;i<=n;i++)
    {
     a[j] = a[i];
     while(j-1>=1 && a[j].h>=a[j-1].h && a[j].w>=a[j-1].w)
      a[j-1]=a[j],j--;
     j++;
    }
    j--;
    n=j;
    he=t=1;
    b[1].f = 0;b[1].w = a[1].w;
    for(int64 i = 1;i<=n;i++)
    {
     j = he;
     int64 tmp = b[he].f+b[he].w*a[i].h;
     for(;j<=t;j++)
      if(b[j].f + b[j].w*a[i].h < tmp)
       tmp = b[j].f + b[j].w*a[i].h;
     t++;
     b[t].f = tmp;b[t].w = a[i+1].w;
     while(t-he+1 >= 3 && tail())
     {
      swap(b[t],b[t-1]);
      t--;
     }
    }
    printf("%I64d",b[t]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
