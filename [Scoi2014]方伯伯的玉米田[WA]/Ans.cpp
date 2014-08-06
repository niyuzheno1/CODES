#include "mode.h"
const int MN = 11000,MA = 5510;
int n,m,p,a[MN];
struct BIT
{
 int p[MA];
 int getmax(int r)
 {
  int ret = 0;
  for(;r;r-=lb(r))
   ret = max(ret,p[r]);
  return ret;
 }
 void change(int x,int y)
 {
  for(;x<=m;x+=lb(x))
   p[x] = max(p[x],y); 
 }
};
BIT s[MA];
int getmax(int x,int y)
{
 int ret = 0;
 for(;x;x-=lb(x))
  ret = max(ret,s[x].getmax(y));
 return ret;
}
void change(int x,int y,int z)
{
 for(;x<=p;x+=lb(x))
  s[x].change(y,z);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    for(int i = 1;i<=n;i++)
     a[i] = gi,p=max(p,a[i]+m+1);
    m++;
    int u = 0;
    for(int i = 1;i<=n;i++)
     for(int j = m;j>=1;j--)
     {
      int ans = getmax(a[i]+j,j);
      u = max(ans+1,u);
      change(a[i]+j,j,ans+1);
     }
    printf("%d\n",u);
    closeIO();
    return EXIT_SUCCESS;
}
