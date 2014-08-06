#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <algorithm>
#define L ch[0]
#define R ch[1]
#define F ch[2]
#define ff fprintf
using namespace std;
const int maxn = 10000010;
struct node
{
 int ch[3];
 int num,size,key;
};
FILE * d;
node p[maxn];
int tot;
void aa(int x)
{
 if(x != 0)
 p[x].size = p[x].num+p[p[x].L].size+p[p[x].R].size;
}
void ro(int x)
{
 int y = p[x].F;int z = p[y].F;
 bool d1 = !(p[y].R == x);
 int l = p[x].ch[d1];
 p[x].ch[d1] = y;
 p[y].F = x;
 p[y].ch[p[y].R == x] = l;
 p[l].F = y;
 p[z].ch[p[z].R == y] = x;
 p[x].F = z;
 aa(y);aa(x);aa(z);
}
void splay(int x,int rt)
{
 while(p[x].F != rt)
 {
  int u = p[x].F;
  int v = p[u].F;
  if(v != rt && ((p[v].R==u)==(p[u].R==x)))
   ro(u);
  ro(x);
 }
}
void pretest()
{
 tot = 5;
 p[0].L = 1;p[1].F =0;
 p[1].L = 2;p[1].R = 3;
 p[2].F = 1;p[3].F = 1;
 p[2].L = 4;p[2].R = 5;
 p[4].F = 2;p[5].F = 2;
 ro(2);
 splay(4,0);
 for(int i = 0;i<=tot;i++)
  ff(d,"%d:L:%d R:%d F%d \n",i,p[i].L,p[i].R,p[i].F);
 tot = 0;
 memset(p,0,sizeof(p));
}
int ans2 = 0;
void ins(int x)
{
  if(p[0].L == 0)
  {
   tot++;
   p[tot].size = p[tot].num = 1;
   p[tot].key = x;
   p[tot].F = 0;
   p[0].L = tot;
  }
  else
  {
   int u = p[0].L;
   while(u)
   {
    if(p[u].key == x){
     p[u].num++;
     splay(u,0);
     return;
    }
    if(p[u].key > x && p[u].L != 0)
     u = p[u].L;
    else if(p[u].key < x && p[u].R != 0)
     u = p[u].R;
    else if(p[u].key > x && p[u].L == 0)
    {
     tot++;
     p[tot].F = u;
     p[tot].key = x;
     p[tot].size = p[tot].num = 1;
     p[u].L = tot;
     splay(tot,0);
     return;
    }
    else if(p[u].key < x && p[u].R == 0)
    {
     tot++;
     p[tot].F = u;
     p[tot].key = x;
     p[tot].size = p[tot].num = 1;
     p[u].R = tot;
     splay(tot,0);
     return;
    }
   }
  }
}
void del()
{
 int r = p[0].L;
 int x = p[r].R;
 ans2 += (p[r].size-p[x].size-1);
 p[0].L = x;
 p[x].F = 0;
}
int ser(int x)
{
 int y = p[0].L;
 while(y)
 {
  if(x <= p[p[y].L].size+p[y].num && x > p[p[y].L].size)
   return p[y].key;
  if(x <= p[p[y].L].size)
   y = p[y].L;
  else
   x-=(p[p[y].L].size+p[y].num),y = p[y].R;
 }
 return -1;
}
int n,m,tmp;
char str[6];
int main(int argc, char *argv[])
{
    freopen("cashier.in","r",stdin);
    freopen("cashier.out","w",stdout);
    d = fopen("debug.txt","w");
    pretest();
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
    {
   
     int x;
     scanf("%s%d",str,&x);
     if(str[0] == 'I'){
      if(x >= m)
      ins(x+tmp);
     }
     else if(str[0] == 'A')
      tmp-=x;
     else if(str[0] == 'S')
     {
      tmp+=x;
      ins(m+tmp-1);
      del();
     }
     else if(str[0] == 'F'){
      if(x > p[p[0].L].size || x < 1)
       printf("-1\n");
      else
      printf("%d\n",ser(p[p[0].L].size-x+1)-tmp);
     }
    }
    printf("%d\n",ans2);
    fclose(d);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
