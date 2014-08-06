#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define ff fprintf
using namespace std;
const int maxn = 200100;
int n,m,k;
int str[maxn];
int s[maxn],sa[maxn],rk[maxn];
int tmp[maxn];
FILE * d;
bool cmp(int x,int y)
{
 if(rk[x] == rk[y])
 {
  int u = (x+k<=m?rk[x+k]:-1);
  int v = (y+k<=m?rk[y+k]:-1);
  return u<v;
 }
 else
  return rk[x]<rk[y];
}
void csa()
{
 for(int i = 1;i<=m;i++)
  rk[i] = s[i],sa[i] = i;
 for(k = 1;k<=m;k*=2)
 {
  sort(sa+1,sa+1+m,cmp);
  tmp[sa[1]] = 0;
  for(int i = 2;i<=m;i++)
  {
   int u = cmp(sa[i-1],sa[i]);
   tmp[sa[i]] = tmp[sa[i-1]]+u;
  }
  for(int i = 1;i<=m;i++)
   rk[i] = tmp[i];
 }
}
int main(int argc, char *argv[])
{
    /*freopen("poj3581.in","r",stdin);
    freopen("poj3581.out","w",stdout);
    d = fopen("debug.txt","w");*/
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&str[i]);
    for(int i = 1;i<=n;i++)
     s[i] = str[n-i+1];
    m = n+1;str[m] = -1;
    csa();
    int p1 = 0;
    for(int i = 1;i<=m;i++)
    {
     p1 = m-sa[i];
     if(n-p1>=2 && p1>=1)
      break;
    }
    //ff(d,"%d\n",p1);
    m = 0;
    for(int i = n;i>p1;i--)
    {
     m++;
     s[m] = str[i];
    }
    for(int i = n;i>p1;i--)
    {
     m++;
     s[m] = str[i];
    }
    m++,s[m] = -1;
    csa();
    int p2 = 0;
    for(int i = 1;i<=m;i++)
    {
     p2 = n-sa[i]+1;
     if(p2-p1>=1 && n-p2>=1)
      break;
    }
    //ff(d,"%d\n",p2);
    m = 0;
    for(int i = p1;i>=1;i--)
    {
     m++;s[m] = str[i];
    }
    for(int i = p2;i>p1;i--)
    {
     m++;s[m] = str[i];
    }
    for(int i = n;i>p2;i--)
    {
     m++;s[m] = str[i];
    }
    for(int i = 1;i<n;i++)
     printf("%d\n",s[i]);
    printf("%d\n",s[n]);
    /*fclose(d);
    fclose(stdin);
    fclose(stdout);*/
    return EXIT_SUCCESS;
}
