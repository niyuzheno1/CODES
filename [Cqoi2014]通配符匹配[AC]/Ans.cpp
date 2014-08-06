#include "mode.h"
#define MN 100010
char tmp[MN],a[MN];
int n ,f[ MN ],u;
int main(int argc, char *argv[])
{
    setIO("sample");
    gets(tmp+1);
    n = strlen(tmp+1);
    f[1] = 1;u = 1;
    for(int i = 1;i<=n;++i)
    {
     if(tmp[i] == '*') f[u] = u; //case 1
     else {
      a[u] = tmp[i];/*
      int v = f[u];
      while(f[v] != v && a[v] != a[u] && a[u] != '?' && a[v] != '?') v = f[v];
      
      f[u] = ((a[u-1] == '?'||a[v] == a[u-1] || a[v] == '?')&& f[u-1] != u-1   )?(v+1):v;*/
      if(f[u] == 0)f[u] = u-1;++u;
     }
    }
    int T = gi;
    while(T--){
     gets(tmp+1);
     u = 1;int m = strlen(tmp+1),ans = 0;
     for(int i = 1;i<=m;++i)
     {
      while(f[u] != u && tmp[i] != a[u] && a[u] != '?') u = f[u];
      if(tmp[i] == a[u] || a[u] == '?') ++u;
      if(a[u] == 0)
       ans = 1;
     }
     if(a[u] == 0) ans = 1;
     if(ans) puts("YES");
     else puts("NO");
    }
    closeIO();
    return EXIT_SUCCESS;
}
