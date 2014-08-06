#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ff fprintf
using namespace std;
const int inf = 0x7f7f7f7f;
const int maxn = 1010;
int c[maxn],d[maxn];
int s[maxn],t[maxn];
int ts,tt;
FILE * D;
int n,m,a,b;
int inv(int a,int b)
{
 if(b == 1)
  return a;
 else if(b % 2 == 0){
  int x=inv(a,b/2);
  return x*x;
 }else if(b % 2 != 0){
  int x = inv(a,b/2);
  return x*x*a;
 }
}
int calc(int x)
{
    return (a*x+b)%m+1;
}
int gen()
{
 int u = inv(a,m-2);
 ff(D,"%d\n",u);
 int ax = 0,ay = 0;
 int l = 1,r=n;
 if(calc(1) > calc(2))
 while(true)
 {
  ax = ay;
  ay = (a*l+b)%m+1;
  if(l>1 && ax > ay)
   break;
  ts++;
  s[ts] = ay;l++;
 }
 ax = 0,ay = 0;
 if(calc(n-1) < calc(n))
 while(true)
 {
  ax = ay;
  ay = (a*r+b)%m+1;
  if(r<n &&ay > ax){
   r++;
   break;
  }
  tt++;
  t[tt] = ay;r--;
 }
 
 int ans = 0;
 if(l>=r)
 {
  for(int i = 1;i<=ts;i++)
   for(int j = 1;j<i;j++)
    if(s[i] < s[j])
     ans++;
   return ans;
 }
 else
 {
  ts--;tt--;
  int i=l,j;
  c[0] = calc(i);
  for(j=1;i<r;j++)
  {
   int las = i;
   i+=u;
   int x = calc(i-1);
   int y = calc(i);
   if(x < y)
    i--;
   if(i > r){
    i = las;
    break;
   }
   d[j-1] = i-las;
   c[j] = calc(i);
  }j--;
  d[j] = r-i+1;
  for(i = 0;i<=j;i++)
   ff(D,"%d th:a:%d d:%d\n",i,c[i],d[i]);
 }
}
int main(int argc, char *argv[])
{
    freopen("blaster.in","r",stdin);
    freopen("blaster.out","w",stdout);
    D = fopen("debug.txt","w");
    
    scanf("%d%d%d%d",&n,&m,&a,&b);
    if(a<=1000)
    {
     printf("%d",gen());
    }
    fclose(D);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
