#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
const int d = 100001;
struct c
{
 int l,r;
};
c p[50010];
int f[50010][3];
int k,s;
struct seg
{
 int m;
 struct note
 {
	 int v;
 };
 note a[d*10];
 void init()
 {
	 memset(a,0,sizeof(a));
	 m = 1;
	 while(m <= 2*d)
		m<<=1;
 }
 void dw(int x)
 {
	 int l = 2*x;int r = 2*x+1;
	 if(a[l].v < a[x].v)
		 a[l].v = a[x].v;
	 if(a[r].v < a[x].v)
		 a[r].v = a[x].v;
	 a[x].v = 0;
 }
 void down(int x)
 {
	 int y = x>>1,z = 0;
	 while(y >= 1)
		  z++,y>>=1;
	 for(int i = z;i>=1;i--)
		 dw(x>>i);
 }
 void c(int x,int z)
 {
	 a[x].v = z;
 }
 void b(int x,int y,int z)
 {
	 int l = x+m-1;int r = y+m+1;
	 int ll = l,rr = r;
	 down(ll),down(rr);
	 while(true)
	 {
	   if((l ^ r) == 1)
		    break;
	   if((l & 1) == 0)
		  c(l+1,z);
	   if((r & 1) == 1)
		  c(r-1,z);
	   l >>= 1;r >>= 1;
	 }
	 //up(ll),up(rr);
 }
 int f(int x)
 {
	 int l = x+m-1;int r = x+m+1;
	 int ll = l,rr = r;
	 down(ll),down(rr);
	 int ans = 0;
	 while(true)
	 {
		 if((l^r) == 1)
			 break;
		 if((l & 1) == 0)
		  ans = a[l+1].v;
	     if((r & 1) == 1)
		  ans = a[r-1].v;
		 l >>= 1;r >>= 1;
	 }
	 //up(ll),up(rr);
	 return ans;
 }
};
seg o;
int main(int argc, char *argv[])
{
	freopen("obstacle.in","r",stdin);freopen("obstacle.out","w",stdout);
    scanf("%d%d",&k,&s);
    s += d;
	for(int i = 1;i<=k;i++){
     scanf("%d%d",&p[i].l,&p[i].r);
     p[i].l += d;
     p[i].r += d;
    }
	o.init();
    for(int i = 1;i<=k;i++)
    {
     int l = o.f(p[i].l);
     int r = o.f(p[i].r);
     if(l == 0)
      f[i][1] = abs(p[i].l-d);
     else
      f[i][1] = min(f[l][1]+abs(p[l].l-p[i].l),f[l][2]+abs(p[l].r-p[i].l));
	 if(r == 0)
	  f[i][2] = abs(p[i].r-d);
	 else
	  f[i][2] = min(f[r][1]+abs(p[r].l-p[i].r),f[r][2]+abs(p[r].r-p[i].r));
     o.b(p[i].l,p[i].r,i);
    }
	int ans = 0x7f7f7f7f;
	for(int i = 1;i<=d+100000;i++)
	{
	 int x = o.f(i);
	 if(x == 0)
	  ans = min(ans,abs(i-s)+abs(i-d));
	 else{
		 int q = min(f[x][1]+abs(p[x].l-i),f[x][2]+abs(p[x].r-i));
		 ans = min(ans,abs(i-s)+q);
	 }
	
	}
    printf("%d\n",ans);
	fclose(stdin);
    fclose(stdout);
	return EXIT_SUCCESS;
}
