#include <cstdlib>
#include <iostream>
#include <cstdio>
#define ff fprintf
#define L ch[0]
#define R ch[1]
#define F ch[2]
using namespace std;
const int maxn = 602200,inf = 0x7f7f7f7f;
struct node
{
 int size;
 int key;
 int ch[3];
};
int tot,n,m;
node a[maxn];
FILE * d;
void aa(int x)
{
     for(int i = 0;i<=1;i++)
      a[a[x].ch[i]].F = x;
     a[x].size  = 1;
     for(int i = 0;i<=1;i++)
      a[x].size += a[a[x].ch[i]].size;
     a[0].size = 0;a[0].F = 0;
}
void r(int x)
{
  int y = a[x].F;
  int z = a[y].F;
  int l = a[x].R;
  a[x].R = y;
  a[y].L = l;
  a[z].ch[a[z].R == y] = x;
  aa(y);aa(x);aa(z);
}
void l(int x)
{
  int y = a[x].F;
  int z = a[y].F;
  int l = a[x].L;
  a[x].L = y;
  a[y].R = l;
  a[z].ch[a[z].R == y] = x;
  aa(y);aa(x);aa(z);
}
void splay(int x,int y)
{
 while(a[x].F != y)
 {
  int z = a[x].F;
  int u = a[z].F;
  if(u != y &&  (a[u].R == y)==(a[z].R == x))
   if(a[u].R == y)
    l(y);
   else
    r(y);
  if(a[z].R == x)
   l(x);
  else
   r(x);
 }
}
void pretest()
{
 tot = 5;
 a[0].L = 1;
 aa(0);
 a[1].L = 2;
 a[1].R = 5;
 aa(1);
 a[2].L = 3;
 a[2].R = 4;
 aa(2);
 splay(2,0);
 for(int i = 0;i<=tot;i++)
  ff(d,"%d:L%d R:%d F:%d\n",i,a[i].L,a[i].R,a[i].F);
 memset(a,0,sizeof(a));
}
int insert(int key)
{
     tot++;
     a[tot].key = key;
     a[tot].size = 1;
     if(a[0].L == 0)
      a[0].L = tot,aa(0);
     else
     {
      int x = a[0].L;
      int y;
      while(x)
      {
      aa(x);
       if(a[x].key >= key)
        y = x,x = a[x].R;
       else
        y = x,x = a[x].L;
       
      }
      if(a[y].key >= key)
       a[y].R = tot;
      else
       a[y].L = tot;
      aa(y);
      splay(tot,0);
     }
    return tot;
}
int find(int x)
{
    int y = a[0].L;
    if(!y)
     return -inf;
    int u = 0;
    while(y)
    {
     aa(y);
     if(x == a[a[y].L].size+1)
      return a[y].key;
     else if(a[a[y].L].size >= x)
      u=y,y = a[y].L;
     else
      x-=(a[a[y].L].size+1),u=y,y = a[y].R;
    
    }
    if(x != 0)
     return -inf;
    return a[y].key;
}
void del(int x)
{
     x = insert(x);
     a[0].L = a[x].L;
     a[x].F = 0;
     aa(0);
}
char str[110];
int u;
int main(int argc, char *argv[])
{
    freopen("cashier.in","r",stdin);
    freopen("cashier.out","w",stdout);
    d = fopen("debug.txt","w");
    u = 0;
    pretest();
    tot = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
     int x;
     scanf("%s%d",&str,&x);
     if(str[0] == 'I')
      insert(x-u);
     else if(str[0] == 'S')
      u-=x;
     else if(str[0] == 'A')
      u+=x;
     else if(str[0] == 'F'){
      int v = find(x);
      if(v == -inf)
       printf("%d\n",-1);
      else
      printf("%d\n",v+u);
     }
     del(m-u);
    }
    fclose(d);
    fclose(stdin);
    fclose(stdout);
    
    return EXIT_SUCCESS;
}
