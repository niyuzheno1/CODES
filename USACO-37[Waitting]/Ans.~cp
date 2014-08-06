#include <cstdlib>
#include <iostream>

using namespace std;
int n,m;
int l[51],r[1024];
int in[1024],t;
int re[51];
int ans;
void dfs(int x,int d)
{
    if(x > m)
    {
    ans = max(ans,d);
    return;
    }
    for(int i = in[x];i<=n;i++)
    if(re[i]+r[x] <= l[i])
    {
     re[i]+=r[x];
     dfs(x+1,d+1);
     re[i]-=r[x]; 
    }
    dfs(x+1,d);
}
int main(int argc, char *argv[])
{
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&l[i]);
    for(int i = 1;i<=m;i++)
     scanf("%d",&r[i]);
    sort(l+1,l+1+n);
    sort(r+1,r+1+m);
    dfs(1,0);
    int t = 1;
    for(int i = 1;i<=m;i++)
    {
     while(l[t] < r[i] && l[t] != 0)
      t++;
     in[i] = t;
     if(t > n){
     m = i;
     break;
     }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
