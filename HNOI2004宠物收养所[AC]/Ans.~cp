#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#define L ch[0]
#define R ch[1]
#define F ch[2]
#define ff fprintf
using namespace std;
const int  maxn  = 80000*2, inf = 0x7f7f7f7f,mod = 1000000;
struct node
{
 int key;
 int ch[3];
};
node h[maxn];
FILE * d;
int tot;
void ro(int x)
{
 int y = h[x].F;
 int z = h[y].F;
 int d = !(h[y].R == x);
 int l = h[x].ch[d];
 h[x].ch[d] = y;h[y].F = x;
 h[y].ch[!d] = l;h[l].F = y;
 h[z].ch[h[z].R == y] = x;
 h[x].F = z;
}
void splay(int x,int rt)
{
 while(h[x].F != rt)
 {
  int y = h[x].F;
  int z = h[y].F;
  if(z != rt && (h[z].R==y)==(h[y].R==x))
   ro(y);
  ro(x);
 }
}
void pretest()
{
 h[0].L = 1;h[1].F = 0;
 h[1].L = 2;h[2].F = 1;
 h[1].R = 3;h[3].F = 1;
 h[2].L = 4;h[4].F = 2;
 h[2].R = 5;h[5].F = 2;
 ro(2);
 for(int i = 0;i<=5;i++)
  ff(d,"%d: L:%d R:%d F:%d\n",i,h[i].L,h[i].R,h[i].F);
}
int insert(int x)
{
   if(h[0].L == 0)
   {
    tot++;
    h[tot].key = x;
    h[tot].F = 0;
    h[0].L = tot;
    return tot;
   }
   else
   {
    int u = h[0].L;
    while(u)
    {
     bool w = h[u].key<x;
     if(h[u].ch[w])
      u = h[u].ch[w];
     else
     {
      tot++;
      h[tot].key = x;
      h[tot].F = u;
      h[u].ch[w] = tot;
      splay(tot,0);
      return tot;
     } 
    }
   }
}
int getp()
{
  int u = h[h[0].L].L;
  int v = 0;
  while(u)
  {
   v = u,u = h[u].R;
  }
  return v;
}
int getn()
{
  int u = h[h[0].L].R;
  int v = 0;
  while(u)
  {
   v = u,u = h[u].L;
  }
  return v;
}
void del(int x)
{
     splay(x,0);
     if(h[x].L != 0){
      int u = getp();
      splay(u,x);
      h[0].L = u;
      h[u].F = 0;
      h[u].R = h[x].R;
      h[h[x].R].F = u;
     }
     else{
      h[0].L = h[x].R;
      h[h[x].R].F = 0;
     }
}
int la,n,ans;
int main(int argc, char *argv[])
{
    freopen("pet.in","r",stdin);
    freopen("pet.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%d",&n);
    h[0].key = inf;
    la = 2;
    int m = 0;
    for(int i = 1;i<=n;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     if(m == 0 || ((x^la)==0))
     {
      la = x;
      insert(y);
      m++;
     }
     else
     {
      int xx = insert(y);
      int u = getp();
      int v = getn();
      if(u == v && u == 0)
       continue;
      if(abs(h[u].key-y) <= abs(h[v].key-y))
       ans=(ans+abs(h[u].key-y))%mod,del(u);
      else if(abs(h[u].key-y) > abs(h[v].key-y))
       ans=(ans+abs(h[v].key-y))%mod,del(v);
      del(xx);
      m--;
     }
    }
    printf("%d",ans);
    fclose(d);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
