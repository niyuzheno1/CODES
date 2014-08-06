#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#define L ch[0]
#define R ch[1]
#define F ch[2]
using namespace std;
const int MAXN = 100010;
struct node
{
 int size,key,tag;
 int ch[3];
};
node p[MAXN];
int tot,n,m;
void pushdown(int x)
{
 if(x == 0) return;
 int l = p[x].L;
 int r = p[x].R;
 p[l].tag ^= p[x].tag;p[r].tag ^= p[x].tag;
 if(p[x].tag){
 int tmp = p[x].L;p[x].L = p[x].R;p[x].R = tmp;
}
 p[x].tag = 0;
}
void putup(int x)
{
 if(x == 0) return;
 int l = p[x].L;
 int r = p[x].R;
 p[x].size = p[l].size+p[r].size+1;
}
void rotate(int x)
{
 int y = p[x].F;
 int z = p[y].F;
 pushdown(y);pushdown(x);
 bool d = (p[y].R==x);
 p[y].ch[d] = p[x].ch[!d];
 p[p[y].ch[d]].F = y;
 p[x].ch[!d] = y;
 p[y].F = x;
 p[z].ch[p[z].R == y] = x;
 p[x].F = z;
 putup(y);putup(x);
}
void splay(int x,int rt)
{
 if(x == 0)
  return;
 while(p[x].F != rt)
 {
  int y = p[x].F;
  int z = p[y].F;
  if(z != rt && (p[y].R==x)==(p[z].R == y))
   rotate(y);
  rotate(x);
 }
}
int ins(int x)
{
 if(p[0].L == 0)
 {
  tot++;
  p[tot].key = x;
  p[tot].size = 1;
  p[0].L = tot;
  return tot;
 }
 int z = 0,y = p[0].L;
 while(y != 0)
 {
  if(p[y].key > x)
   z = y,y=p[y].L;
  if(p[y].key == x)
   return y;
  if(p[y].key < x)
   z = y,y=p[y].R;
 }
 tot++;
 p[tot].key = x;
 p[tot].size = 1;
 p[tot].F = z;
 p[z].size++;
 if(p[z].key > x)
  p[z].L = tot;
 if(p[z].key < x)
  p[z].R = tot;
 splay(tot,0);
 return y;
}
int findkth(int x,int y)
{
 pushdown(x);
 if(x == 0)
  return 0;
 int tmp = p[p[x].L].size+1;
 if(tmp == y)
  return x;
 if(tmp > y)
  return findkth(p[x].L,y);
 else
  return findkth(p[x].R,y-tmp);
}
int nex(int x)
{
 if(p[x].R == 0)
  return x;
 return nex(p[x].R);
}
int pre(int x)
{
 if(p[x].L == 0)
  return x;
 return pre(p[x].L);
}
void printans(int x)
{
 if(x == 0) return;
 pushdown(x);
 int l = p[x].L,r = p[x].R;
 printans(l);
 if(p[x].key != 0 && p[x].key != n+1)
 printf("%d ",p[x].key);
 printans(r);
}
int main(int argc, char *argv[])
{
    //freopen("tyvj1729.in","r",stdin);freopen("tyvj1729.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 0;i<=n+1;i++)
     ins(i);
    for(int i = 1;i<=m;i++)
    {
     int l,r;
     scanf("%d%d",&l,&r);
     /*if(l == 1 && r == n)
     {
      p[p[0].L].tag ^=1;
     }
     if(l == 1 && r != n)
     {
      int u = findkth(p[0].L,r+1);
      //u = pre(u);
      splay(u,0);
      p[p[p[0].L].L].tag ^= 1;
     }
     if(r == n && l != 1)
     {
      int u = findkth(p[0].L,l-1);
      //u = nex(u);
      splay(u,0);
      p[p[p[0].L].R].tag ^= 1;
     }*/
      int u = findkth(p[0].L,l);
      //u = nex(u);
      splay(u,0);
      u = findkth(p[0].L,r+2);
      //u = pre(u);
      splay(u,p[0].L);
      p[p[p[p[0].L].R].L].tag ^= 1;
     
    }
    printans(p[0].L);
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
