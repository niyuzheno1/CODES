#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1010;
FILE * d;
char str[maxn];
int n,k;
int rk[maxn],sa[maxn],tmp[maxn];
int lcp[maxn];
bool cmp(int x,int y)
{
 if(rk[x] == rk[y])
 {
  int u = x+k<=n?rk[x+k]:-1;
  int v = y+k<=n?rk[y+k]:-1;
  return u<v;
 }
 else
  return rk[x] < rk[y];
}
void sol()
{
 for(int i = 1;i<=n;i++)
  rk[i] = str[i],sa[i] = i;
 for(k = 1;k<=n;k*=2)
 {
  sort(sa+1,sa+1+n,cmp);
  tmp[0] = 0;
  for(int i = 1;i<=n;i++){
   tmp[sa[i]] = tmp[sa[i-1]]+((cmp(sa[i-1],sa[i]))?1:0);
   }
  for(int i = 1;i<=n;i++)
   rk[i] = tmp[i];
 }
 for(int i = 1;i<=n;i++)
  printf("%d\n",sa[i]);
}
void lc()
{
 for(int i = 1;i<=n;i++)
  rk[sa[i]] = i;
 int h=0,j=0;
 for(int i = 1;i<=n;i++)
 {
  j = sa[rk[i]-1];
  if(h > 0)
   h--;
  int m = i;
  for(;i+h<=n&&j+h<=n;h++)
   if(str[i] != str[j])
    break;
  lcp[rk[i]-1] = h;
 }
 for(int i = 1;i<=n;i++)
  printf("%d\n",lcp[i]);
}
int main(int argc, char *argv[])
{
    freopen("sa.in","r",stdin);
    freopen("sa.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%s",&str[1]);
    n = strlen(&str[1]);
    sol();lc();
    fclose(d);fclose(stdout);fclose(stdin);
    return EXIT_SUCCESS;
}
