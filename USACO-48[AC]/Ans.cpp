#include <cstdlib>
#include <iostream>

using namespace std;
int n;
const int inf = 0x7f7f7f7f;
struct p
{
  int h,a,c;
  bool operator < (p  b) const
  {
   if(a == b.a)
    return h < b.h;
   else
    return a < b.a;
  }
};
p e[410];
int f[410][40010];
int dfs(int x,int y)
{
    if(y > 40000)
     return -inf;
    if(f[x][y])
     return f[x][y];
    if(x > n)
     return 0;
    int ans = 0;
    for(int i = 0;i<=e[x].c;i++)
     if(y + e[x].h*i <= e[x].a)
      ans = max(ans,dfs(x+1,y+e[x].h*i) + e[x].h*i);
    
    f[x][y] = ans;
    return ans;
}
int main(int argc, char *argv[])
{
    freopen("elevator.in","r",stdin);
    freopen("elevator.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d%d",&e[i].h,&e[i].a,&e[i].c);
    sort(e+1,e+1+n);
    printf("%d",dfs(1,0));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
