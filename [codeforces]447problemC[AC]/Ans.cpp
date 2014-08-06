#include "mode.h"
#undef INF
#define INF 0x7f7f7f7f
#define MN 100005
int n,a[MN],s[MN],e[MN],mx;
int main(int argc, char *argv[])
{
    setIO("sample");
    n=gi;a[n+1]=INF;
    for(int i = 1;i<=n;++i)
    {
     cin>>a[i];
     e[i] = (a[i-1]<a[i])?(e[i-1]+1):1;
     mx = max(mx,e[i]);
    }
    if(mx < n) ++ mx;
    for(int i = n;i;--i){
     s[i] = (a[i]<a[i+1])?(s[i+1]+1):1;
     if(a[i+1]-a[i-1]>1)
      mx = max(mx,e[i-1]+s[i+1]+1);
    }
    cout<<mx;
    closeIO();
    return EXIT_SUCCESS;
}
