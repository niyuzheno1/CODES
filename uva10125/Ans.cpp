#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,n) for(int i = 0;i<n;i++)
#define repp(i,f,n) for(int i = f;i<n;i++)
using namespace std;
const int maxn = 1010;
int n;
int a[maxn];
int u[maxn*maxn],v[maxn*maxn];
int c[maxn*maxn],totc,totb;
struct p
{
  int c;
  int d;
  int u;
  int v;
}b[maxn*maxn];
void incc(int x,int na,int nb)
{
 c[totc] = x;
 u[totc] = na;
 u[totc] = nb;
 totc++;
}
void incb(int x,int y,int na,int nb)
{
 b[totb].c = x;
 b[totb].d = y;
 b[totb].u = na;
 b[totb].v = nb;
 totb++;
}
bool cmp(p a, p b)
{
     if(a.c == b.c)
      return a.d > b.d;
     else
      return a.c < b.c;
}
int bs(int x)
{
    int l = 0,r = totb;
    if(x < b[l].c || x > b[r-1].c)
     return -1;
    while(l<r)
    {
     int mid = (l+r)/2;
     if(b[mid].c > x)
      r = mid-1;
     else if(b[mid].c < x)
      l = mid+1;
     else if(b[mid].c == x)
      r = mid;
    }
    
    if(b[(l+r)/2].c != x)
     return -1;
    
    return (l+r)/2;
}
int main(int argc, char *argv[])
{
    while(true){
    scanf("%d",&n);
    totc = totb = 0;
    if(n == 0)
     break;
    rep(i,n)
     scanf("%d",&a[i]);
    rep(i,n)
     repp(j,i+1,n)
     {
      incc(a[i]+a[j],i,j);
      incb(a[i]-a[j],a[j],i,j);
      incb(a[j]-a[i],a[i],i,j);
     }
  
     
    sort(b,b+totb,cmp);
    bool found = false;
    int ans = -536870912;
    rep(i,totc)
    {
     int  x = bs(c[i]);
     while(u[i] == b[x].u || v[i] == b[x].v || v[i] == b[x].u || u[i] == b[x].v)
      x++;
     if(b[x].c != c[i] || x >= totb)
      continue;
     if(x != -1)
      ans = max(ans,b[x].c+b[x].d),found = true;
    }
    if(found)
    printf("%d\n",ans);
    else
    puts("no solution");
    }
    //system("PAUSE");
    return EXIT_SUCCESS;
}
