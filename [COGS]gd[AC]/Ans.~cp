#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110,maxe = 210;
struct lin
{
 int n,v;
};
int dfn[maxn],ti,n,st[maxn],tot,low[maxn];
lin lk[maxe];
int ans1,ans2[maxn];
void add1(int x,int y)
{
 tot++;
 lk[tot].n = st[x];lk[tot].v = y;
 st[x] = tot;
}
void add(int x,int y)
{
 add1(x,y);add1(y,x);
}
int dfs(int x,int y,int root)
{
 if(x == 8)
  x = 8;
 if(x == 10)
  x = 10;
 if(low[x])
  return low[x];
 ti++;
 dfn[x] = ti,low[x] = ti;
 int si = 0;
 bool flag = 0;
 for(int i = st[x];i!=0;i=lk[i].n)
 {
  int v = lk[i].v;
  if(v != y){
   if(!low[v]){
    si++;
    int t = dfs(v,x,0);
    if(t >= dfn[x] && !flag && !root)
    {
    low[x] = min(low[x],t);
    flag = 1;
    ans1++;
    ans2[ans1] = x;
    }
   }
   else
    low[x] = min(dfn[v],low[x]);
  }
 }
 if(root == 1)
 {
  if(si > 1)
  {
   ans1++;
   ans2[ans1] = x;
  }
 }
 
 return low[x];
}
int main(int argc, char *argv[])
{
    freopen("gd.in","r",stdin);
    freopen("gd.out","w",stdout);
    scanf("%d",&n);
    int x,y;
    while(scanf("%d%d",&x,&y) != EOF)
     add(x,y);
    dfs(1,0,1);
    printf("%d\n",ans1);
    sort(ans2+1,ans2+ans1+1);
    for(int i = 1;i<=ans1;i++)
     printf("%d\n",ans2[i]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
