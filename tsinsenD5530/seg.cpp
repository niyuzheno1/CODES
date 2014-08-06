#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 100010;
const int id = 0;
int a[MAXN],b[MAXN];
struct seg
{
 struct segn
 {
  int flag,a2,b2,ab;
  segn()
  {
   flag = 0;
   a2 = 0;b2=0;ab=0;
  }
 };
 segn t[MAXN];
 int k;
 void init(int x)
 {
    k = 1;
    while(k<=x) k<<=1;
 }
 void updata(int x)
 {
  int l = 2*x,r = 2*x+1;
  t[x].a2 = t[l].a2+t[r].a2;
  t[x].b2 = t[l].b2+t[r].b2;
  t[x].ab = t[l].ab+t[r].ab;
  t[x].flag = id;
 }
 void down(int x)
 {
  t[x].a2 = 0;t[x].b2 = 0;t[x].ab = 0;
 }
 void ptol(int x)
 {
  int k = 0,y = x>>1;
  while(y)k++,y>>=1;
  for(int i = k;i>=1;i--)
   down(x>>i); 
 }
 void upd(int x)
 {
  while(true)
  {
   x>>=1;
   if(x == 0) break;
   updata(x);
  }
 }
 void modify(int x)
 {
  int l = x+k-1,r = x+k+1;
  ptol(l);ptol(r);
  t[l+1].flag = id;
  t[l+1].a2 = a[x]*a[x];
  t[l+1].b2 = b[x]*b[x];
  t[l+1].ab = a[x]*b[x];
  upd(l);upd(r);
 }
 int sum(int l,int r)
 {
  int ret = 0;
  l = l+k-1;r = r+k+1;
  down(l);down(r);
  while((l^r) != 1)
  {
   if((l&1)==0)ret += t[l^1].a2;
   if((r&1)==1)ret += t[r^1].a2;
   l/=2;r/=2;
  }
  upd(l);upd(r);
  return ret;
 }
};
seg tr;
void mkid()
{
 
}
int n;
int main(int argc, char *argv[])
{
    freopen("seg.in","r",stdin);freopen("seg.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&a[i],&b[i]);
    tr.init(n);
    for(int i = 1;i<=n;i++)
     tr.modify(i);
    printf("%d\n",tr.sum(1,n));
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
