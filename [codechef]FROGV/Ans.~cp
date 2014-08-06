#include "mode.h"
#define MN 100010
#define MM MN*2
int n,k,p,e = 1;
int a[MN],b[MN],Ind;
int st[MN],con[MN],v[MM],ne[MM];
bool cmp(int x,int y)
{
     return a[x] < a[y];
}
void ad(int x,int y)
{
     ++e;v[e] = y;ne[e] = st[x];st[x] = e;
}
void add(int x,int y)
{
     ad(x,y);ad(y,x);
}
void dfs(int x)
{
     if(con[x])return;
     con[x] = Ind;
     for(int i = st[x];i;i=ne[i])
     if(!con[v[i]]) dfs(v[i]);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi, k = gi,p = gi;
    for(int i = 1;i<=n;++i) a[i] = gi,b[i] = i;
    sort(b+1,b+1+n,cmp);
    for(int i = 1;i<n;++i)
     if(abs(a[b[i]]-a[b[i+1]]) <= k)
      add(b[i],b[i+1]);
    for(int i = 1;i<=n;++i)
     if(!con[i])
      ++Ind,dfs(1);
    for(int i = 1;i<=p;++i)
    {
            int u,v;
            scanf("%d%d",&u,&v);
            if(con[u] != con[v])
             puts("No");
            else
             puts("Yes");
    }
    closeIO();
    return EXIT_SUCCESS;
}
