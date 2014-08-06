#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
const int inf = 0x7f7f7f7f;
int p,q;
int b[1010];
int f[111][111];
int dfs(int x,int y,int m,int n)
{
  if(x+1 > y-1)
   return 0;
  int ans = inf;
  if(f[x][y]) 
   return f[x][y];
  for(int i = x+1;i<=y-1;i++)
   ans = min(ans,dfs(x,i,m,b[i]-1)+dfs(i,y,b[i]+1,n)+n-m);
  return f[x][y] = ans;
   
}
int main(int argc, char *argv[])
{
    freopen("prison.in","r",stdin);
    freopen("prison.out","w",stdout);
    scanf("%d%d",&p,&q);
    for(int i = 1;i<=q;i++)
     scanf("%d",&b[i]);
    b[0] = 1;b[q+1] = p;
    printf("%d\n",dfs(0,q+1,1,p));
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
