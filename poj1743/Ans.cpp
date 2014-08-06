#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 20000+10;
const int inf = 0x7f7f7f7f;
int n,k;
int s[maxn],f[maxn];
int rk[maxn],sa[maxn],tmp[maxn],lcp[maxn];
bool cmp(int x,int y)
{
 if(rk[x] == rk[y])
 {
  int u = (x+k<=n?rk[x+k]:-inf);
  int v = (y+k<=n?rk[y+k]:-inf);
  return u<v;
 }
 else
  return rk[x]<rk[y];
}
void gsa()
{
 for(int i = 0;i<=n;i++)
  rk[i] = s[i],sa[i] = i;
 for(k=1;k<=n;k*=2)
 {
  sort(sa+1,sa+1+n,cmp);
  tmp[sa[0]] = 0;
  for(int i = 1;i<=n;i++)
  {
   int u = cmp(sa[i-1],sa[i]);
   tmp[sa[i]] = tmp[sa[i-1]]+u;
  }
  for(int i =1;i<=n;i++)
   rk[i] = tmp[i];
 }
}
void glc()
{
 for(int i =1;i<=n;i++)
  rk[sa[i]] = i;
 int h = 0;
 for(int i =1;i<=n;i++)
 {
  int j = sa[rk[i]-1];
  if(h>0) h--;
  for(;i+h<=n&&j+h<=n;h++)
   if(s[i+h] != s[j+h])
    break;
  lcp[rk[i]-1] = h;
 }
}
bool gt(int x)
{
 int l = sa[0],r=sa[0];
 for(int i = 0;i<=n;i++)
 {
  if(lcp[i] < x)
  {
   l = sa[i];
   r = sa[i];
   continue;
  }
  l = min(l,sa[i]);
  r = max(r,sa[i]);
  if(r-l > x)
   return 1;
 }
 return 0;
}
int sol()
{
 int l = 0,r=n;
 while(l<r)
 {
  int mid = (l+r)/2;
  if(gt(mid))
   l = mid+1;
  else
   r = mid-1;
 }
 return (l+r)/2;
}
int main(int argc, char *argv[])
{
   // freopen("poj1743.in","r",stdin);
    //freopen("poj1743.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&f[i]);
    for(int i = 1;i<=n-1;i++)
     s[i] = f[i+1]-f[i];
    n = n-1;
    gsa();
    glc();
    int ans = sol();
    if(ans>=5)
    printf("%d\n",ans);
    else
    printf("0\n");
    //fclose(stdin);
    //fclose(stdout);
    return EXIT_SUCCESS;
}
