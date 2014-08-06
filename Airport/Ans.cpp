#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int maxn = 5010;
int a[maxn],b[maxn],n;
int na[maxn],nb[maxn];
bool ok(int t)
{
     int c = 0,d = 0;
     t++;
     memcpy(na,a,sizeof(na));
     memcpy(nb,b,sizeof(nb));
     rep(i,n)
     {
       c = na[i]+na[i+1];d = nb[i]+nb[i+1];
       if(c-1 > t || d-1 > t)
        return false;
       if(c > d)
        na[i+1] = c-1;
       else
        nb[i+1] = d-1;
     }
     return true;
}
int t;
int main(int argc, char *argv[])
{
    scanf("%d",&t);
    while(t--){
    int l,r;
    l = r = 0;
    scanf("%d",&n);
    rep(i,n){
    scanf("%d%d",&a[i],&b[i]);
    r = r + a[i]+b[i]; 
    }
    
    while(l < r)
    {
     int mid = (l+r)/2;
     if(ok(mid))
      r = mid;
     else
      l = mid+1;
    }
    
    printf("%d\n",(l+r)/2);
    }
    
    return EXIT_SUCCESS;
}
