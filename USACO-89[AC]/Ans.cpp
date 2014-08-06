#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
int n,q;
struct s
{
 int l,r,a,n,b;
 bool operator < (s x) const
 {
  if(a == x.a)
   return l < x.l;
  return a<x.a;
 }
};
s p[25010];
s qu[25010];
int se[25010];
int tot = 1;
struct segm
{
int m;
struct s
{
 int n,t,m;
};
s a[1000010*4];
void updata(int x)
{
 int l = 2*x,r = 2*x+1;
 a[x].m = min(a[l].m==0?0x7f7f7f7f:a[l].m,a[r].m==0?0x7f7f7f7f:a[r].m);
}
void dw(int x)
{
 int l = 2*x,r = 2*x+1;
 if(a[x].t > a[l].t)
  a[l].t = a[x].t,a[l].n = a[x].n,a[l].m = a[l].n;
 if(a[x].t > a[r].t)
  a[r].t = a[x].t,a[r].n = a[x].n,a[r].m = a[r].n;
 a[x].t = a[x].n = a[x].m = 0;
}
void ch(int x,int n,int t)
{
 a[x].n = n;
 a[x].m = n;
 a[x].t = t;
}
void up(int x)
{
 x >>= 1;
 while(x >= 1)
  updata(x),x>>=1;
}
void down(int x)
{
  int u = 0,v = x>>1;
  while(v >= 1)
   v>>=1,u++;
  for(int i = u;i>=1;i--)
   dw(x>>i);
}
void c(int l,int r,int n,int t)
{
 l = l+m-1,r = r+m+1;
 int ll = l,rr = r;
 down(ll),down(rr);
 while(true)
 {
  if((l ^ r) == 1)
   break;
  if((l & 1) == 0)
   ch(l+1,n,t);
  if((r & 1) == 1)
   ch(r-1,n,t);
  l /= 2;r /= 2;
 }
 up(ll),up(rr);
}
int s(int l,int r)
{
 int ans = 0;
 l = l+m-1,r = r+m+1;
 int ll = l,rr = r;
 down(ll),down(rr);
 while(true)
 {
  if((l ^ r) == 1)
   break;
  if((l & 1) == 0)
   ans = a[l+1].n;
  if((r & 1) == 1)
   ans = a[r-1].n;
  l /= 2;r /= 2;
 }
 up(ll),up(rr);
 return ans;
}
int f(int l,int r)
{
 int ans = 0x7f7f7f7f;
 l = l+m-1,r = r+m+1;
 int ll = l,rr = r;
 down(ll),down(rr);
 while(true)
 {
  if((l ^ r) == 1)
   break;
  if((l & 1) == 0)
   ans = min(ans,a[l+1].m==0?0x7f7f7f7f:a[l+1].m);
  if((r & 1) == 1)
   ans = min(ans,a[r-1].m==0?0x7f7f7f7f:a[r-1].m);
  l /= 2;r /= 2;
 }
 up(ll),up(rr);
 return ans;
}
 void init()
 {
  m =1;
  memset(a,0,sizeof(a));
  while(m <= n)
     m = m<<1;
 }
};
segm seg;
bool ok(int x)
{
 memset(se,0,sizeof(se));
 tot = 0;
 seg.init();
 for(int i = 1;i<=q;i++)
  if(p[i].n <= x){
   tot++;
   qu[tot] = p[i];
  }
 sort(qu+1,qu+1+tot);
 
 for(int i = 1;i<=tot;i++)
  /*if(qu[i].b != qu[i+1].b || i+1 > tot)*/
   seg.c(qu[i].l,qu[i].r,qu[i].b,i);
 for(int i = 1;i<=tot;i++)
  if(qu[i].b == qu[i-1].b){
   qu[i].r = min(qu[i].r,qu[i-1].r);
   if(qu[i].r < qu[i].l)
    return false;
  }
 for(int i = 1;i<=tot;i++)
  if(qu[i].b != qu[i+1].b || i+1 > tot)
   if(seg.f(qu[i].l,qu[i].r) > qu[i].b)
    return false;
 /*for(int i = 1;i<=n;i++)
   se[seg.s(i,i)] = 1;
 for(int i = 1;i<=tot;i++)
   if(!se[qu[i].b])
    return false;*/
 return true;
}
int main(int argc, char *argv[])
{
    freopen("bales.in","r",stdin);
    freopen("bales.out","w",stdout);
    scanf("%d%d",&n,&q);
    for(int i = 1;i<=q;i++)
    {
     scanf("%d%d%d",&p[i].l,&p[i].r,&p[i].a);
     p[i].n = i;
    }
    sort(p+1,p+1+q);
    for(int i = 1;i<=q;i++){
     if(p[i].a == p[i-1].a)
      tot--;
     p[i].b = tot;
     tot++;
    }
    int ll = 0,rr = q+1;
    while(ll < rr)
    {
     int mid = (ll+rr)/2;
     if(ok(mid))
      ll = mid+1;
     else
      rr = mid;
    }
    if((ll+rr)/2 >= q)
     printf("0");
    else
     printf("%d",(ll+rr)/2);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
