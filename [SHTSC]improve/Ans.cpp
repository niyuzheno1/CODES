#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#define ff fprintf
using namespace std;
int n,m,p,k;
const int inf = 0x7f7f7f7f;
struct node
{
 int key;
 int delta;
 int l,r,num,cnt;
};
node a[100010*2];
FILE * d;
void init()
{
 k = 1;
 while(k <= n)
  k<<=1;
 for(int i = 1;i<=n;i++){
  scanf("%d",&a[i+k].key);
  a[i+k].l=a[i+k].key;
  a[i+k].r=a[i+k].key;
 }
 for(int i = k-1;i>=1;i--){
  int ll = 2*i,rr = 2*i+1;
  if(a[rr].r == -1)
   a[i].r = a[ll].r;
  else
   a[i].r = a[rr].r;
  if(a[rr].l != -1 && a[ll].r != -1)
   if(a[rr].l < a[ll].r)
     a[i].cnt++;
  a[i].num =a[i].cnt+a[ll].num+a[rr].num;
  if(a[ll].l == -1)
   a[i].l = a[rr].l;
  else
   a[i].l = a[ll].l;
  if(a[i].l != -1 && a[i].r != -1)
   a[i].key = 0;
 }
}
void down(int x)
{
 a[x].num = 0;
 a[2*x].delta = (a[2*x].delta+a[x].delta)%p;
 a[2*x+1].delta = (a[2*x+1].delta+a[x].delta)%p;
 a[x].delta = 0;
}
void pass(int x)
{
 int y = (x/2),z = 0;
 while(y)
  y>>=1,z++;
 for(int i = z;i>=1;i--)
  down(x>>i);
}
void updata(int x)
{
 int ll = 2*x;
 int rr = 2*x+1;
 a[x].cnt = 0;
 if(a[ll].key == -1 && a[rr].key == -1)
 {
 a[x].key = -1;
 return;
 }
 if(a[ll].key == -1)
 {
 a[x].l = (a[rr].l+a[rr].delta)%p;
 a[x].r = (a[rr].r+a[rr].delta)%p;
 a[x].cnt = 0;
 a[x].num = a[ll].num+a[rr].num+a[x].cnt;
 return;
 }
 if(a[rr].key == -1)
 {
 a[x].l = (a[ll].l+a[ll].delta)%p;
 a[x].r = (a[ll].r+a[ll].delta)%p;
 a[x].cnt = 0;
 a[x].num = a[ll].num+a[rr].num+a[x].cnt;
 return;
 }
 a[x].l = (a[ll].l+a[ll].delta)%p;
 a[x].r = (a[rr].r+a[rr].delta)%p;
 if((a[ll].r+a[ll].delta)%p > (a[rr].l+a[rr].delta)%p )
  a[x].cnt++;
 a[x].num = a[ll].num+a[rr].num+a[x].cnt;
}
void up(int x)
{
 x/=2;
 while(x)
  updata(x),x>>=1;
}
void add(int l,int r,int c)
{
 l = l+k-1;r=r+k+1;
 int ll = l,rr = r;
 pass(ll);pass(rr);
 while((l ^ r) != 1)
 {
  if((l%2) == 0)
   a[l+1].delta=(a[l+1].delta+c)%p;
  if((r%2) == 1)
   a[r-1].delta=(a[r-1].delta+c)%p;
  l = l/2;
  r = r/2;
 }
 up(ll);up(rr);
}
int sum(int l,int r)
{
    int x = 0;
    l = l+k-1;r=r+k+1;
    int ll = l,rr = r;
    pass(ll);pass(rr);
    int pp = -1,q = inf;
    while((l ^ r) != 1)
    {
    if((l%2) == 0){
     if(pp !=-1 && (pp)%p > (a[l+1].l+a[l+1].delta)%p )
      x++;
     x+=a[l+1].num,pp = (a[l+1].r+a[l+1].delta)%p;
    }
    if((r%2) == 1){
     if(q != inf && (a[r-1].r+a[r-1].delta)%p > q%p)
      x++;
     x+=a[r-1].num,q = (a[r-1].l+a[r-1].delta)%p;
    }
    l = l/2;
    r = r/2;
    }
    if(pp != -1 && q != inf){
     if(pp > q)
      x++;
      }
 up(ll);up(rr);
 return x;
}
int main(int argc, char *argv[])
{
    freopen("improve.in","r",stdin);
    freopen("improve.out","w",stdout);
    d = fopen("debug.txt","w");
    scanf("%d%d%d",&n,&m,&p);
    for(int i = 1;i<=100010*2-1;i++)
     a[i].key = a[i].l=a[i].r = -1;
    init();
    
    for(int i = 1;i<=m;i++)
    {
     int o,l,r;
     scanf("%d%d%d",&o,&l,&r);
     if(o == 1)
     {
      int delta;
      scanf("%d",&delta);
      add(l,r,delta);
      for(int i = 1;i<=k+n;i++)
     ff(d,"%d: L:%d R:%d num:%d delta:%d\n",i,a[i].l,a[i].r,a[i].num,a[i].delta);
     }
     else if(o == 2)
      printf("%d\n",sum(l,r));
     
    }
    fclose(stdin);fclose(stdout);fclose(d);
    return EXIT_SUCCESS;
}
