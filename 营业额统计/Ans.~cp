#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#define L ch[0]
#define R ch[1]
#define F ch[2]
#define ff fprintf
using namespace std;
typedef long long int64;
const int64 inf = 0x7f7f7f7f7f7f7f7fLL;
FILE * d;
const int64 maxn = 1000000;
struct node
{
 int64 key;
 int64 ch[3];
};
node h[maxn];
int64 tot,n;
void aa(int64 x)
{
     for(int64 i = 0;i<=1;i++)
      h[h[x].ch[i]].F = x;
}
void r(int64 x)
{
 int64 y = h[x].F;
 int64 z = h[y].F;
 int64 l = h[x].R;
 h[y].L = l;h[x].R = y;h[z].ch[h[z].ch[1]==y] = x;
 aa(x);aa(y);aa(z);
}
void l(int64 x)
{
 int64 y = h[x].F;
 int64 z = h[y].F;
 int64 l = h[x].L;
 h[y].R = l;h[x].L = y;h[z].ch[h[z].ch[1]==y] = x;
 aa(x);aa(y);aa(z);
}
void splay(int64 x,int64 z)
{
     while(h[x].F != z)
     {
      int64 y = h[x].F;
      int64 u = h[y].F;
      if(u != z && ((h[y].R == x)==(h[u].R == y)))
       if(y == h[u].L)
        r(y);
       else
        l(y);
      if(x == h[y].L)
       r(x);
      else
       l(x);
     }
}
void dpr()
{
     for(int64 i = 1;i<=tot;i++)
      ff(d,"%d:L:%d R:%d F:%d\n",i,h[i].L,h[i].R,h[i].F);
}
int64 ins(int64 x)
{
     tot++;
     h[tot].key = x;
     if(tot == 1)
     {
      h[0].L = 1;
     }
     else
     {
      int64 z = 0;
      int64 y = h[0].L;
      while(y)
      {
       if(h[y].key < x)
        z=y,y = h[y].R;
       else
        z=y,y = h[y].L;
      }
      if(h[z].key < x)
       h[z].R = tot;
      else
       h[z].L = tot;
      aa(z);
      splay(tot,0);
     }
     return tot;
}
int getp(int x)
{
 int y = x;
 while(x != 0)
 {
  y = x;x = h[x].R;
 }
 return h[y].key;
}
int getn(int x)
{
  int y = x;
  while(x != 0)
  {
   y = x;x = h[x].L;
  }
  return h[y].key;
}
int64 find(int64 x)
{
 int64 ret=inf;
 int64 u= ins(x);
 int64 LL = h[u].L==0?inf:getp(h[u].L);
 int64 RR = h[u].R==0?inf:getn(h[u].R);
 ret = min(abs(LL-x),abs(RR-x));
 if(ret > (1LL<<31LL))
  return x;
 /*
 int64 y = h[0].L;
 if(!y)
  return abs(x);
 int64 z = 0;
 while(y)
 {
  ret = min(ret,abs(h[y].key-x));
  if(h[y].key < x)
   z=y,y = h[y].R;
  else
   z=y,y = h[y].L;
 }
 if(z != 0)splay(z,0);*/
 return ret;
}
int main(int argc, char *argv[])
{
    scanf("%I64d",&n);
    int64 ans = 0;
    for(int64 i = 1;i<=n;i++){
     int64 x;
     scanf("%I64d",&x);
     ans += find(x);
    }
    printf("%I64d",ans);
    return EXIT_SUCCESS;
}
