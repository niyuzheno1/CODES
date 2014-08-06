#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define ff fprintf
using namespace std;
const int maxn = 1010;
char str[maxn];
int str2[maxn];
int rk[maxn],sa[maxn];
FILE * d;
int k;
int n;
bool cmp(int x,int y)
{
 if(sa[x] == sa[y])
 {
  int u = ((x+(1<<k))<=n)?sa[x+1<<k]:0;
  int v = ((y+(1<<k))<=n)?sa[y+1<<k]:0;
  return u<v;
 }
 else
  return sa[x]<sa[y];
}
void sol()
{
 for(int i = 1;i<=n;i++)
  sa[i] = str2[i];
 for(int i = 1;i<=n;i++)
  rk[i] = i;
 int m = int(log(n)/log(2));
 for(k = 1;k<=m;k++)
 {
  sort(rk+1,rk+n+1,cmp);
  for(int i = 1;i<=n;i++)
   sa[rk[i]] = i;
 }
 for(int i = 1;i<=n;i++)
  printf("%d\n",sa[i]);
}
int main(int argc, char *argv[])
{
    freopen("sa.in","r",stdin);
    freopen("sa.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%s",&str[1]);
    for(int i = 1;i<=strlen(&str[1]);i++)
     str2[i] = str[i];
    n = strlen(&str[1]);
    sol();
    fclose(d);fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
