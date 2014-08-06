#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define zero(x) memset(x,0,sizeof(x))
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int n;
struct o
{
 int x,y,r,c;
 int n;
}p[5010];
bool cmp1(o x,o y)
{
  if(x.c != y.c)
     return x.c > y.c;
  else
    return x.y >y.y;
}
bool cmp2(o x,o y)
{
     if(x.x != y.x)
      return x.x > y.x;
     else
      return x.r > y.r;
}
int ansx[5010],ansy[5010];
int mapy[5010],mapx[5010];
int main(int argc, char *argv[])
{
    while(true){
    zero(ansx),zero(ansy),zero(mapy),zero(mapx);
    scanf("%d",&n);
    if(n == 0)
     break;
    rep(i,n){
     scanf("%d%d%d%d",&p[i].x,&p[i].y,&p[i].r,&p[i].c);
     p[i].n = i;
    }
    sort(p,p+n,cmp1);
    bool f2 = false;
   
    rep(i,n)
    {
     int flag = p[i].c;
     while(mapy[flag] && flag>=p[i].y)
      flag--;
     if(flag < p[i].y)
     {
      f2 = true;
      break;
     }
     mapy[flag] = true;
     ansy[p[i].n] = flag;
    }
    if(!f2)
    {
     sort(p,p+n,cmp2);
     rep(i,n)
     {
      int flag = p[i].x;
     while(mapx[flag] && flag<=p[i].r)
      flag++;
      if(flag > p[i].r)
      {
       f2 = true;
       break;
      }
      mapx[flag] = true;
      ansx[p[i].n] = flag;
     }
    }
    if(!f2){
    rep(i,n)
     printf("%d %d\n",ansx[i],ansy[i]);
    }
    else
     puts("IMPOSSIBLE");
   }
    return EXIT_SUCCESS;
}

