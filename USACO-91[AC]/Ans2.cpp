#include <cstdlib>
#include <iostream>

using namespace std;
const int inf = 0x7f7f7f7f;
int ti;
struct seg
{
 struct note
 {
  int len,l,r;
  int lsum,rsum,xsum;
  int s,t;
 };
 int m;
 note t[50010*4];
 void ptr(int n)
 {
  for(int i = 1;i<=m+n;i++)
  {
   printf("------------");
   printf("note=%d\n",i);
   printf("len=%d\n",t[i].len);
   printf("l=%d\n",t[i].l);
   printf("r=%d\n",t[i].r);
   printf("lsum=%d\n",t[i].lsum);
   printf("rsum=%d\n",t[i].rsum);
   printf("xsum=%d\n",t[i].xsum);
   printf("s=%d\n",t[i].s);
   printf("t=%d\n",t[i].t);
  }
 }
 void init(int n)
 {
  m = 1;
  while(m <= n)
   m<<=1;
  int p = 2*m-1;
  t[m].len = 0,t[m].t=t[m].l,t[m].s = 1,t[m].t = inf;
  for(int i = m+n+1;i<=p;i++)
   t[i].s = 1,t[i].t = inf;
  for(int i = m+1;i<=m+n;i++)
  {
   t[i].len = 1;t[i].l = t[i].r = i-m;
   t[i].lsum = t[i].rsum = t[i].xsum = 1;
   t[i].s = 0,t[i].t = 0;
  }
  for(int i = m-1;i>=1;i--)
  {
   int l = 2*i,r = 2*i+1;
   t[i].l = min(t[l].l==0?inf:t[l].l,t[l].r==0?inf:t[l].r);
   t[i].l = min(t[i].l,min(t[r].l==0?inf:t[r].l,t[r].r==0?inf:t[r].r));
   t[i].r = max(t[l].l,t[l].r);
   t[i].r = max(t[i].l,max(t[r].l,t[r].r));
   t[i].len = t[l].len + t[r].len;
   t[i].s = 2;
   t[i].lsum = t[i].len;
   t[i].rsum = t[i].len;
   t[i].xsum = t[i].len;
  }
 }
 int find(int x,int d)
 {
  if(t[x].xsum < d)
   return 0;
  int l = 2*x,r=2*x+1;
  if(t[x].lsum >= d)
   return t[x].l;
  if(t[l].xsum >= d)
   return find(l,d);
  if(t[l].rsum + t[r].lsum >= d)
   return t[l].r-t[l].rsum+1;
  if(t[r].xsum >= d)
   return find(r,d);
  if(t[r].rsum >= d)
   return t[r].r-t[r].rsum+1;
 }
 void rp(int x,int y,int z)
 {
  t[x].s = y;
  t[x].t = z;
  if(y == 1)
   t[x].lsum = t[x].rsum = t[x].xsum = 0;
  else if(y == 0)
   t[x].lsum = t[x].rsum = t[x].xsum = t[x].len;
 }
 void pass(int x)
 {
  int l = 2*x,r=2*x+1;
  if(t[x].t > t[l].t)
   rp(l,t[x].s,t[x].t);
  if(t[x].t > t[r].t)
   rp(r,t[x].s,t[x].t);
  t[x].t = 0;t[x].s = 2;
  t[x].lsum = t[x].rsum = t[x].xsum = 0;
 }
 void down(int x)
 {
  int p = 0,xx = (x>>1);
  while(xx > 0)
   xx>>=1,p++;
  for(int i = p;i>=1;i--)
   pass(x>>i);
 }
 void updata(int x)
 {
  int l = 2*x,r = 2*x+1;
  if(t[l].lsum == t[l].len)
   t[x].lsum = t[l].lsum+t[r].lsum;
  else
   t[x].lsum = t[l].lsum;
  if(t[r].rsum == t[r].len)
   t[x].rsum = t[r].rsum+t[l].rsum;
  else
   t[x].rsum = t[r].rsum;
  t[x].xsum = max(t[l].xsum,t[r].xsum);
  t[x].xsum = max(t[x].xsum,t[l].rsum+t[r].lsum);
  t[x].xsum = max(t[x].xsum,t[x].lsum);
  t[x].xsum = max(t[x].xsum,t[x].rsum);
 }
 void up(int x)
 {
   x >>= 1;
   while(x > 0)
    updata(x),x>>=1;
 }
 void c(int x,int y,int z)
 {
  int l,ll,r,rr;
  ll = l = x+m-1;rr = r = y+m+1;
  down(ll),down(rr);
  while(true)
  {
   if((l^r) == 1)
    break;
   if((l & 1) == 0)
    rp(l+1,z,ti);
   if((r & 1) == 1)
    rp(r-1,z,ti);
   l>>=1;r>>=1;
  }
  up(ll),up(rr);
 }
};
seg s;
int n,m;
int main(int argc, char *argv[])
{
    freopen("hotel.in","r",stdin);
    freopen("hotel.out","w",stdout);
    scanf("%d%d",&n,&m);
    s.init(n);
    for(int i = 1;i<=m;i++)
    {
     ti = i;
     int t,x,d;
     scanf("%d%d",&t,&x);
     if(t == 1){
      d = x;
      int p = s.find(1,d);
      printf("%d\n",p);
      if(p != 0)
      s.c(p,p+d-1,1);
     }
     else if(t==2){
      scanf("%d",&d);
      s.c(x,x+d-1,0);
     }
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
