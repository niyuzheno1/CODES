#include "mode.h"
#define MN 10010
#define MM 2000010
int n,m,ans = 0,st[MN],tot;
int hash[MN],color[MN],label[MN],v[MN],a[MN];
struct edge{int v,f,n;};
edge lk[MM];
void add(int x,int y)
{
 ++tot;lk[tot].v = y;lk[tot].n = st[x];st[x] = tot;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m=gi;
    CLEAR(st,0xff);
    for(int i = 1,x,y;i<=m;++i){
     x = gi;y =gi;add(x,y);add(y,x);
    } 
    label[0] = -1;
    for(int i = n;i>=1;--i){
     int k = 0;
     for(int j = 1;j<=n;++j)
      if(label[j]>label[k] && !v[j]) k = j;
     a[i] = k;v[k] = 1;
     TRA(j,k) ++label[lk[j].v];
    }
    for(int i = n;i>=1;--i)
     {
      TRA(j,a[i]) hash[color[lk[j].v]] = i;
      int j = 0;
      while(hash[++j] == i); color[a[i]] = j;
     }
     for(int i = 1;i<=n;++i) if(color[i]>ans) ans = color[i];
     printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
