#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10100,inf = 0x7f7f7f7f;
struct node
{
 int mv;
 int l,r;
};
struct zkw
{
 int n,d,k;
 node a[maxn*4];
 int too(int x){return x+k;}
 void upd(int x)
 {
  a[x].mv = max(a[2*x].mv,a[2*x+1].mv);
 }
 void upda(int x)
 {
  x>>=1;
  while(x)
  {
   upd(x);
   x>>=1;
  }
 }
 void init(int x)
 {
  k = 1;
  n = x;
  while(k<=x)
   k<<=1;
  for(int i = 1;i<=n;i++){
   int v = too(i);
   a[v].mv = 0;
   a[v].l = a[v].r = i;
  }
  for(int i = k;i>=1;i--){
   int l = 2*i,r = 2*i+1;
   if(a[l].l == 0)
   {
    a[i].l = a[r].l;
    a[i].r = a[r].r;
    a[i].mv = a[r].mv;
   }
   if(a[r].r == 0)
   {
    a[i].l = a[l].l;
    a[i].r = a[l].r;
    a[i].mv = a[l].mv;
   }
   if(a[l].l != 0 && a[r].r != 0)
   {
    a[i].l = a[l].l;
    a[i].r = a[r].r;
    a[i].mv = max(a[l].mv,a[r].mv);
   }
  }
 }
 void change(int x,int y)
 {
  int u = too(x);
  a[u].mv = y;
  upda(u);
 }
 int query(int l,int r)
 {
  l = too(l-1),r = too(r+1);
  int ans = -inf;
  while(l+1 < r)
  {
   if((l&1)==0)
    ans = max(ans,a[l^1].mv);
   if((r&1)==1)
    ans = max(ans,a[r^1].mv);
   l>>=1;r>>=1;
  }
  return ans;
 }
};
zkw tr;
int main(int argc, char *argv[])
{
    freopen("seg.txt","w",stdout);
    tr.init(5);
    tr.change(1,3);
    printf("%d\n",tr.query(1,5));
    fclose(stdout);
    return EXIT_SUCCESS;
}
