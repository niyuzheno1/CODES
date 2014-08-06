#include <cstdlib>
#include <iostream>

using namespace std;
int s[25010];
int v[100010];
int p[100010];
int n,l,c;
int pa;
int lb(int x)
{
    return x&(-x);
}
void add(int x,int y)
{
 while(x <= n)
 {
  s[x] += y;
  x+=lb(x);
 }
}
int sum(int x)
{
 int ans = 0;
 while(x>0)
 {
  ans += s[x];
  x-=lb(x);
 }
 return ans;
}
int main(int argc, char *argv[])
{
    freopen("running.in","r",stdin);
    freopen("running.out","w",stdout);
    scanf("%d%d%d",&n,&l,&c);
    for(int i = 1;i<=n;i++)
     scanf("%d",&v[i]);
    sort(v+1,v+1+n);
    int t = l;
    for(int i = 1;i<=n;i++)
    {
    int pu = (v[i]*t/c);
    int u = (v[i]*t)%c;
    if(u == 0)
     pu--,u = c;
    p[i] = pu*(i-1)-pa;
    p[i] += sum(c+1)-sum(c-u+1);
    pa+=pu;
    add(u+1,1);
    }
    int ans = 0;
    for(int i = 1;i<=n;i++)
     ans += p[i]/*,printf("%d\n",p[i]);*/;
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
