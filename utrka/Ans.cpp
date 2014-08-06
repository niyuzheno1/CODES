#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 310,maxm = 310*(310-1),inf = 0x7f7f7f7f;
int n,m,st[maxn];
struct lk
{
 int b,m,s,ne;
};
lk l[maxm];
int tot;
bool v[maxn];
void add(int x,int y,int z,int a)
{
 tot++;
 l[tot].ne = st[x];
 l[tot].b = y;
 l[tot].m = z;
 l[tot].s = a;
 st[x] = tot;
}
int ans1,ans2;
void dfs(int x,int  stx,int m,int s,int de)
{
 if(x == stx && v[x])
 {
      if(m < s){
       if(ans1 > de)
        ans1 = de,ans2 = s-m;
       else if(ans1 == de)
        ans2 = max(ans2,s-m);
      }
      return;
 }
 if(de > ans1)
  return;
 for(int i = st[x];i!=0;i=l[i].ne)
 if(!v[l[i].b])
  {
  v[l[i].b] = 1;
  dfs(l[i].b,stx,l[i].m+m,l[i].s+s,de+1);
  v[l[i].b] = 0;
  }
}
int main(int argc, char *argv[])
{
    freopen("utrka.in","r",stdin);
    freopen("utrka.out","w",stdout);
    ans1 = inf;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
    {
     int a,b,mi,s;
     scanf("%d%d%d%d",&a,&b,&mi,&s);
     add(a,b,mi,s);
    }
    dfs(1,1,0,0,0);
    printf("%d %d\n",ans1,ans2);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
