#include "mode.h"
#define MN 100005
int n , q ,la;
int f[MN],g[MN],h[MN],sf[MN],sg[MN];
string s[MN];
map<string,int> mp;
int main(int argc, char *argv[])
{
    setIO("sample");
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=n;cin>>s[i],++i);
    f[n+1] = g[n+1] = h[n+1] = n+1;
    for(int i = n;i>=1;--i){
     sort(s[i].begin(),s[i].end());
      if(mp.find(s[i]) != mp.end() ) h[i] = mp[s[i]];
      else h[i] = n+1;
     mp[s[i]] = i;
    }
    for(int i = n;i>=1;--i){
     f[i] = min(f[i+1],h[i]);
     g[i] = min(g[i+1],min(h[h[i]],max(f[i+1],h[i])));
    }
    for(int i = 1;i<=n;++i){
     sf[i] = sf[i-1]+f[i];
     sg[i] = sg[i-1]+g[i];
    }
    while(q--){
    int l,r;
    scanf("%d%d",&l,&r);
    l = min((l^la)%n,(r^la)%n)+1;
    r = max ((l^la)%n,(r^la)%n)+1;
    int pos = upper_bound(f+l,f+r,r)-f-1;
    la = (pos-l+1)*r-(sf[pos]-sf[l-1])+pos-l+1;
    pos = upper_bound(g+l,g+r,r)-g-1;
    la -= (pos-l+1)*r-(sg[pos]-sg[l-1])+pos-l+1;
    printf("%d\n",la);
    }
    closeIO();
    return EXIT_SUCCESS;
}
