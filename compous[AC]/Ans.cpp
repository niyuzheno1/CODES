#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std;
const int MAXN = 5010,MAXM = 200010*2;
typedef bitset<MAXN> bi;
bi a[MAXN];
int ans = 0;
int n,m,h,t;
int q;
void setIO(string str)
{
 #ifndef ONLINE_JUDGE
 string input = str+".in";string output = str+".out";freopen(input.c_str(),"r",stdin);freopen(output.c_str(),"w",stdout);
 #endif
}
struct edge
{
 int v,n;
};
edge lk[MAXM];
int tot,st[MAXN*2],v[MAXN*2],qu[MAXN*2];
void add1(int x,int y)
{
 tot++;
 lk[tot].v = y;
 lk[tot].n = st[x];
 st[x] = tot;
}
void add(int x,int y)
{
 add1(x,y);
 add1(y,x);
}
void bfs(int x)
{
 h = 1,t=1;
 qu[t] = x;t++;
 while(h < t)
 {
  int x = qu[h];h++;
  v[x] = 1;
  for(int i = st[x];i;i=lk[i].n)
  if(!v[lk[i].v])
  {
  v[lk[i].v] = 1;
  qu[t] = lk[i].v;
  t++;
  }
 }
 
}
int main(int argc, char *argv[])
{
    //setIO("compous");
    ans = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++)
    {
     int x,y;scanf("%d%d",&x,&y);
     a[x].set(y);
     a[y].set(x);
     add(x,y);
    }
    for(int i = 1;i<=n;i++)
    {
     if(!v[i]){
      bfs(i);
      ans++;
     }
    }
    scanf("%d",&q);
    for(int i = 1;i<=q;i++)
    {
     char str[3];scanf("%s",str);
     char c = str[0];
     if(c == 'Q')
      printf("%d\n",ans);
     else
     {
      int x,y;
      scanf("%d%d",&x,&y);
      bi u = (a[x]&a[y]);
      if(c == 'D')
      {
       u.reset(x);u.reset(y);
       if(u.none())
        ans++;
       a[x].reset(y);a[y].reset(x);
      }
      else{
       if(u.none())
        ans--;
       a[x].set(y);a[y].set(x);
      }
     }
    }
    return EXIT_SUCCESS;
}
