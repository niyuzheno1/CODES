#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#define L ch[0]
#define R ch[1]
#define F ch[2]
using namespace std;
const int maxn = 100010;
typedef int po;
struct node
{
 po key;
 int size,cnt;
 int ch[4];
};
node p[maxn];
int tot;
void updata(int x)
{
 if(x != 0)
 p[x].size = p[x].cnt+p[p[x].L].size+p[p[x].R].size;
}
void ro(int x)
{
 int y = p[x].F;
 int z = p[y].F;
 bool d = (p[y].L == x);
 int u = p[x].ch[d];
 p[y].ch[p[y].R == x] = u;
 if(u != 0)p[u].F = y;
 p[x].ch[d] = y;
 if(y != 0)p[y].F = x;
 p[z].ch[p[z].R == y] = x;
 if(x != 0)p[x].F = z;
 updata(y);updata(x);updata(z);
}
void splay(int x,int rt)
{
 while(p[x].F != rt)
 {
  int y = p[x].F;
  int z = p[y].F;
  if(z != rt && ((p[z].R==y)==(p[y].R == x)))
   ro(y);
  ro(x);
 }
}
void pretest();
int find(po x)
{
 if(p[0].L == 0)
  return -1;
 int y=0,u = p[0].L;
 while(u)
 {
  if(p[u].key > x)
   y=u,u = p[u].L;
  else if(p[u].key == x){
   splay(u,0);
   return u;
  }
  else if(p[u].key < x)
   y=u,u = p[u].R;
 }
 return y;
}
int insert(po x)
{
 int ret = find(x);
 if(ret == -1)
 {tot++;p[tot].cnt=p[tot].size=1;p[tot].key = x;p[0].L = tot;return tot;}
 if(p[ret].key == x){
  p[ret].cnt++;p[ret].size++;
  return ret;
 }
 tot++;
 p[tot].key = x;
 p[tot].F = ret;
 p[tot].size = p[tot].cnt = 1;
 if(x < p[ret].key)
  p[ret].L = tot;
 else
  p[ret].R = tot;
 splay(tot,0);
 return tot;
}
int pre(int x)
{
 if(x == 0)
  return 0;
 while(p[x].R != 0)
 {
  x = p[x].R;
 }
 return x;
}
int nex(int x)
{
 if(x == 0)
  return 0;
 while(p[x].L != 0)
 {
  x = p[x].L;
 }
 return x;
}
int del(po x)
{
 int u = find(x);
 
 if( u==-1 || p[u].key != x)
  return -1;
 if(p[u].cnt > 1){
  p[u].cnt--;
  p[u].size--;
  return 0;
 }
 if(p[u].L == 0 && p[u].R == 0)
 {
  p[0].L = 0;
  return 1;
 }
 if(p[u].L == 0 && p[u].R != 0)
 {
  p[0].L = p[u].R;
  p[p[u].R].F = 0;
  updata(p[u].R);
  return 2;
 }
 if(p[u].L != 0)
 {
  int pr = pre(p[u].L);
  splay(pr,u);
  p[0].L = pr;
  p[pr].F = 0;
  p[pr].R = p[u].R;
  if(p[u].R != 0)
  p[p[u].R].F = pr;
  updata(pr);
  return 3;
 }
}
int findkth(int s)
{
 if(p[0].L == 0)
  return -1;
 int x = p[0].L;
 while(x)
 {
  if(p[p[x].L].size >= s)
   x = p[x].L;
  else if(p[p[x].L].size + p[x].cnt == s){
   splay(x,0);
   return x;
  }
  else if(s > p[p[x].L].size + p[x].cnt){
   s-=(p[p[x].L].size + p[x].cnt),x = p[x].R;
  }
 }
 if(x == 0)
  return -1;
}

int main(int argc, char *argv[])
{
    freopen("tyvj1728.in","r",stdin);
    freopen("tyvj1728.out","w",stdout);
    int n;scanf("%d",&n);
    for(int i= 1;i<=n;i++)
    {
     int a,b;scanf("%d%d",&a,&b);
     if(a == 1)
      insert(b);
     if(a == 2)
      del(b);
     if(a == 3)
     {
      insert(b);
      int u = find(b);
      printf("%d\n",p[p[u].L].size+1);
      del(b);
     }
     if(a == 4)
     {
      int u = findkth(b);
      printf("%d\n",p[u].key);
     }
     if(a == 5)
     {
      insert(b);
      int u = find(b);
      int v = pre(p[u].L);
      printf("%d\n",p[v].key);
      del(b);
     }
     if(a == 6)
     {
      insert(b);
      int u = find(b);
      int v = nex(p[u].R);
      printf("%d\n",p[v].key);
      del(b);
     }
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
