#include "mode.h"
const int MAXN = 4000010;
int n,m,k1,k2,tot,tot2,q;
int a[MAXN],b[MAXN],l[MAXN],r[MAXN],l1[MAXN],r1[MAXN];
void up1(int x)
{
 int ll = l[x],rr = r[x];
 a[x] = a[ll]+a[rr];
}
void bd1(int & x,int lf,int rf)
{
 tot++;x = tot;
 if(lf == rf){a[x] = 0;return;}
 int mid = (lf+rf)>>1;
 bd1(l[x],lf,mid);
 bd1(r[x],mid+1,rf);
 up1(x);
}
void m1(int t,int lf,int rf,int x,int v)
{
 if(lf == rf)
 {a[t] += v;return;}
 int mid = (lf+rf)>>1;
 if(x > mid)
  m1(r[t],mid+1,rf,x,v);
 else
  m1(l[t],lf,mid,x,v);
 up1(t);
}
int cal1(int t,int lf,int rf,int lc,int rc)
{
 if(lc<=lf && rf <= rc)
  return a[t];
 int ret = 0,mid = (lf+rf)>>1;
 if(rc <= mid)
  ret = cal1(l[t],lf,mid,lc,rc);
 else if(lc > mid)
  ret = cal1(r[t],mid+1,rf,lc,rc);
 else
  ret = cal1(l[t],lf,mid,lc,mid)+cal1(r[t],mid+1,rf,mid+1,rc);
 return ret;
}
void mk(int & t,int lf,int rf)
{
 tot2++;t = tot2;
 if(lf == rf){bd1(b[t],1,m);return;}
 int mid = (lf+rf)>>1;
 mk(l1[t],lf,mid);
 mk(r1[t],mid+1,rf);
 bd1(b[t],1,m);
}
void m2(int t,int lf,int rf,int x,int k,int val)
{
 if(lf == rf)
 {
  m1(b[t],1,m,k,val);
  return;
 }
 int mid = (lf+rf)>>1;
 if(x <= mid)
  m2(l1[t],lf,mid,x,k,val);
 else
  m2(r1[t],mid+1,rf,x,k,val);
 m1(b[t],1,m,k,val);
}
int cal2(int t,int lf,int rf,int x,int y,int k,int tx)
{
 if(x<=lf && rf <= y)
  return cal1(b[t],1,m,k,tx);
 int ret = 0,mid = (lf+rf)>>1;
 if(y <= mid)
  ret = cal2(l1[t],lf,mid,x,y,k,tx);
 else if(x > mid)
  ret = cal2(r1[t],mid+1,rf,x,y,k,tx);
 else
  ret = cal2(l1[t],lf,mid,x,mid,k,tx)+cal2(r1[t],mid+1,rf,mid+1,y,k,tx);
 return ret;
}
int main(int argc, char *argv[])
{
    setIO("AOMap");
    n = gi,m=gi,q = gi;
    int tr = 0;
    mk(tr,1,n);
    for(int i = 1;i<=n;i++)
     for(int j = 1;j<=m;j++)
     {
      int u = gi;
      m2(tr,1,n,i,j,u);
     }
    for(int k = 1;k<=q;k++)
    {
     if(k == q)
      k = q;
     int x1=gi,y1=gi,x2=gi,y2=gi;
     printf("%d\n",cal2(tr,1,n,x1,x2,y1,y2));
    }
    closeIO();
    return EXIT_SUCCESS;
}
