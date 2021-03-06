#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#define dprint(a,b) fprintf(debug,a,b);
using namespace std;
FILE * debug;
const int maxn = 200010;
int n;
struct tab
{
 int l,r;
 bool operator < (tab x) const
 {
      if(r == x.r)
       return l < x.l;
      else
       return r<x.r;
 }
};
tab a[maxn];
int b[maxn],tot;
tab c[maxn];
int d[maxn];
int ans2[maxn];
int ans1 = 0;
void dfs(int x)
{
     if(ans2[0])
      return;
     if(x == ans1)
     {
      for(int i = 1;i<=n;i++)
       if(d[i] == 1)
        ans2[0]++,ans2[ans2[0]] = i;
      return;
     }
     for(int i = 1;i<=n;i++)
      if(d[i] == 0)
      {
       int u = 0;
       for(int j = c[i].l;j<=c[i].r;j++)
        if(b[j] == 1){
         u = 1;
         break;
        }
       if(u) continue;
       d[i] = 1;
       for(int j = c[i].l;j<=c[i].r;j++)
        b[j] = 1;
       dfs(x+1);
       for(int j = c[i].l;j<=c[i].r;j++)
        b[j] = 0;
       d[i] = 0;
       
      }
}
int main(int argc, char *argv[])
{
    freopen("convention.in","r",stdin);
    freopen("convention.ans","w",stdout);
    debug = fopen("debug.txt","w");
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
     scanf("%d%d",&a[i].l,&a[i].r);
     c[i]=a[i];
    }
    sort(c+1,c+1+n);
    
    for(int i = 1;i<=n;i++)
     b[i] = 1;
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<i;j++)
      if(c[j].r < c[i].l)
       b[i] = max(b[i],b[j]+1),ans1 = max(ans1,b[i]);
    printf("%d\n",ans1);
    memset(b,0,sizeof(b));
    for(int i = 1;i<=n;i++)
    {
     d[i] = 1;
     for(int j = c[i].l;j<=c[i].r;j++)
      b[j] = 1;
     dfs(1);
     if(ans2[0])
      break;
     memset(b,0,sizeof(b));
     d[i] = 0;
    }
    for(int i = 1;i<=ans2[0];i++)
      printf("%d ",ans2[i]);
    fclose(debug);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
