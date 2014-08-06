#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 100010;
vector<int> a[MAXN];
vector<int> ans;
int b[MAXN],c[MAXN],n;
void dfs(int x,int y,int z,int fa)
{
     if((b[x]^y) != c[x]){
      ans.push_back(x);
      y ^= 1;
     }
     for(int i = 0;i<a[x].size();i++)
      if(a[x][i] != fa)
      dfs(a[x][i],z,y,x);
     
}
int main(int argc, char *argv[])
{
    //freopen("429problemA.in","r",stdin);
    //freopen("429problemA.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n-1;i++)
    {
    int x,y;scanf("%d%d",&x,&y);
    a[x].push_back(y);a[y].push_back(x);
    }
    for(int i = 1;i<=n;i++)
     scanf("%d",&b[i]);
    for(int i = 1;i<=n;i++)
     scanf("%d",&c[i]);
    dfs(1,0,0,0);
    printf("%d\n",ans.size());
    for(int i = 0;i<ans.size();i++)
     printf("%d\n",ans[i]);
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
