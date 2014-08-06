#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 210000;
int n,a[MAXN],m;
struct squ
{
 int next;
 int w;
 int l,r;
 squ()
 {
  l =0;
  r = INF;
 }
};
squ b[MAXN];
void updata(int x,int y)
{
 a[x] = y;
 int l=b[x].l,r = b[x].r;
 for(int i = r;i>=l;i--)
 {
   if(i > n)
    b[i].next = 0,b[i].w = 0;
   else if(i+a[i] > b[i].r)
   {
    b[i].next = i+a[i];
    b[i].w = 1;
   }
   else if(i+a[i] <= b[i].r)
   {
    b[i].next = b[i+a[i]].next;
    b[i].w = b[i+a[i]].w+1;
   }
  }
}
int cal(int x)
{
 int ret = 0;
 while(x)
 {
  ret += b[x].w;
  x = b[x].next;
 }
 return ret;
}
void init()
{
  scanf("%d",&n);
  for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
  m = int(sqrt(n))+1;
  b[1].l = 1;
  b[m*m].r = m*m;
  for(int i = m*m;i>=1;i--)
  if(i%m == 0){
    b[i].l = i;
    b[i-1].r = i-1;
  }
  for(int i = 2;i<=m*m;i++)
   b[i].l = max(b[i].l,b[i-1].l);
  for(int i = m*m-1;i>=1;i--)
   b[i].r = min(b[i].r,b[i+1].r);
  for(int i = m*m;i>=1;i--)
  {
   if(i > n)
    b[i].next = 0,b[i].w = 0;
   else if(i+a[i] > b[i].r)
   {
    b[i].next = i+a[i];
    b[i].w = 1;
   }
   else if(i+a[i] <= b[i].r)
   {
    b[i].next = b[i+a[i]].next;
    b[i].w = b[i+a[i]].w+1;
   }
  }
}
int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    #endif
    init();
    scanf("%d",&m);
    for(int i = 1;i<=m;i++)
    {
     int op,x,y;
     scanf("%d%d",&op,&x);
     x++;
     if(op == 1)
      printf("%d\n",cal(x));
     else{
      scanf("%d",&y);
      updata(x,y);
     }
    }
    #ifndef ONLINE_JUDGE
    fclose(stdin);fclose(stdout);
    #endif
    return EXIT_SUCCESS;
}
