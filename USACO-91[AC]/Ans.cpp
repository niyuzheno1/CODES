#include <cstdlib>
#include <iostream>

using namespace std;
int n;
int ti;
struct seg
{
 struct note
 {
	 int l,r;
	 int mark,t;
	 int s;
	 int ls,rs;
	 int ss,sx;
 };
 note a[50010*4];
 int m;
 void init()
 {
  memset(a,0,sizeof(a));
  m = 1;
  while(m <= n)
   m<<=1;
  for(int i = 1;i<=n;i++){
	  a[m+i].l=i,a[m+i].r =i;
      cl(m+i);
  }
  for(int j = m;j>=1;j--){
	  a[j].r = max(a[2*j].r,a[2*j+1].r);
      //a[j].l = min(a[2*j].l==0?0x7f7f7f7f:a[2*j].l,a[2*j+1].l==0?0x7f7f7f7f:a[2*j+1].l);
	  if(a[2*j].l==0)
	   a[j].l = a[2*j+1].l;
	  else if(a[2*j+1].l == 0)
	   a[j].l = a[2*j].l;
	  else
	   a[j].l = min(a[2*j].l,a[2*j+1].l);
	  a[j].ls = a[j].r-a[j].l+1;
	  a[j].rs = a[j].r-a[j].l+1;
	  a[j].ss = a[j].r-a[j].l+1;
	  a[j].sx = a[j].r-a[j].l+1;
	  //a[j].s = a[j].l;
  }
 }
 void cl(int x)
 {
	 
	 if(a[x].mark == 1)
	 a[x].sx = a[x].ls = a[x].rs = a[x].ss = 0;
	 else if(a[x].mark == 0)
	 a[x].sx = a[x].ls = a[x].rs = a[x].ss = a[x].r-a[x].l+1;
 }
 void updata(int x)
 {
	
	 int l = 2*x,r = 2*x+1;
	 a[x].mark = 2;
	 a[x].t = ti;
	 a[x].ls = a[x].rs = a[x].ss = 0;
	 if(a[l].r == 0 && a[l].l == 0)
		 a[x].ls = a[r].ls;
	 else
	 a[x].ls = max(a[l].ls,(a[l].ls == a[l].r-a[l].l+1)?a[l].ls+a[r].rs:0);
	 if(a[r].r == 0 && a[r].l == 0)
		 a[x].rs = a[l].rs;
	 else
	 a[x].rs = max(a[r].rs,(a[r].rs == a[r].r-a[r].l+1)?a[r].rs+a[l].rs:0);
	 a[x].ss = a[l].rs+a[r].ls;
	 a[x].sx = max(a[l].sx,a[r].sx);
	 a[x].sx = max(a[x].sx,a[x].ss);
 }
 void dw(int x)
 {
	 
	 int l = 2*x,r = 2*x+1;
	 if(a[l].t < a[x].t && a[x].mark <= 1){
	   a[l].mark = a[x].mark;
	   a[l].t = a[x].t;
	   cl(l);
	 }
	 if(a[r].t < a[x].t && a[x].mark <= 1){
	   a[r].mark = a[x].mark;
	   a[r].t = a[x].t;
	   cl(r);
	 }
	 cl(x);
 }
 void down(int x)
 {
	 int y = x>>1,z = 0;
	 while(y >= 1)
		y>>=1,z++;
	 for(int i = z;i>=1;i--)
		dw(x>>i);
 }
 void up(int x)
 {
	 x>>=1;
	 while(x >= 1)
	  updata(x),x>>=1;
 }
 void b(int x,int y,int z)
 {
	 int l = x+m-1,r=y+m+1;
	 int ll = l,rr = r;
	 down(ll);down(rr);
	 while(true)
	 {
		 if((l^r) == 1)
		  break;
		 if((l&1) == 0)
		 {
			 a[l+1].t = ti;a[l+1].mark = z;
			 cl(l+1);
		 }
		 if((r&1) == 1)
		 {
			 a[r-1].t = ti;a[r-1].mark = z;
			 cl(r-1);
		 }
		 l>>=1;r>>=1;
	 }
	 up(ll);up(rr);
 }
 int f(int x,int y)
 {
  int r = 0;
  if(a[x].ls >= y)
	  return a[x].l;
  if(a[2*x].sx >= y)
	  return f(2*x,y);
  if(a[x].ss >= y)
	  return a[2*x].r-a[2*x].rs+1;
  if(a[2*x+1].sx >= y)
	  return f(2*x+1,y);
  return 0;
 }
};
seg o;
int main(int argc, char *argv[])
{
	freopen("hotel.in","r",stdin);
	freopen("hotel.out","w",stdout);
    int m;
    scanf("%d%d",&n,&m);
	o.init();
    for(int i = 1;i<=m;i++)
    {
	 ti = i;
     int t,x,d;
     scanf("%d",&t);
     if(t == 1){
      scanf("%d",&d);
      int u = o.f(1,d);
      if(u != 0)
       o.b(u,u+d-1,1);
      printf("%d\n",u);
     }
     else
     {
      scanf("%d%d",&x,&d);
      o.b(x,x+d-1,0);
     }
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
