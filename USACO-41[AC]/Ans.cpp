#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 0x7f7f7f7f;
int n,k;
int x[1010];
int f[1010][1010][3];
int dfs(int d,int y,int z,bool l)
{
 if(f[y][z][l])
  return f[y][z][l];
 if(y == 1 && z == n)
  return 0;
 int ans = inf;
 if(y != 1)
 {
  if(l == 1)
   ans = min(ans,dfs(d+1,y-1,z,1)+abs(x[y]-x[y-1])*(n-d));
  else
   ans = min(ans,dfs(d+1,y-1,z,1)+abs(x[z]-x[y-1])*(n-d));
 }
 if(z != n)
 {
  if(l == 1)
   ans = min(ans,dfs(d+1,y,z+1,0)+abs(x[z+1]-x[y])*(n-d));
  else
   ans = min(ans,dfs(d+1,y,z+1,0)+abs(x[z+1]-x[z])*(n-d));
 }
 f[y][z][l] = ans;
 return ans;
 
}
int main(int argc, char *argv[])
{
    freopen("ontherun.in","r",stdin);
    freopen("ontherun.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++)
     scanf("%d",&x[i]);
    n++;
    x[n] = k;
    sort(x+1,x+1+n);
    int p = 0;
    for(int i = 1;i<=n;i++)
     if(x[i] == k){
      p = i;
      break;
     }
    printf("%d\n",dfs(1,p,p,1));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
