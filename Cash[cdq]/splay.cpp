#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define L ch[0]
#define R ch[1]
#define F ch[2]
#define ff fprintf
using namespace std;
const int maxn = 1000100;
const double eps = 10e-10;
const double inf = 10e7;
FILE * d;
int cmp(double x)
{
    if(abs(x) < eps)
     return 0;
    if(x > 0)
     return 1;
    else
     return -1;
}
struct po
{
 double x,y;
 po()
 {
 x=y=0;
 }
 void print()
 {
  ff(d,"X:%lf Y:%lf",x,y);
 }
 po(double xx,double yy)
 {
  x = xx;y = yy;
 }
 bool operator<(po a)
 {
  return cmp(x-a.x)<0 || (cmp(x-a.x)==0&& cmp(y-a.y)<0);
 }
 bool operator==(po u)
 {
   return cmp(x-u.x)==0&&cmp(y-u.y)==0;
 }
 bool operator>(po a)
 {
  return cmp(x-a.x)>0 || (cmp(x-a.x)==0 && cmp(y-a.y)>0);
 }
 po operator=(po u)
 {
  x = u.x;y = u.y;
  return *this;
 }
 po operator-(po u)
 {
  return po(x-u.x,y-u.y);
 }
 bool operator != (po u)
 {
  return !(*this==u);
 }
};
double det(po x,po y)
{
 return x.x*y.y-x.y*y.x;
}
double dot(po x,po y)
{
 return x.x*y.x+x.y*y.y;
}
bool gori(po x,po y,po z)
{
 return cmp(det(z-x,y-x))>0;
}

struct node
{
 po key;
 int size,cnt;
 int ch[4];
};
node p[maxn];
int tot;
void updata(int x)
{
 if(x != 0)
 p[x].size = p[x].cnt+p[p[x].L].size+p[p[x].R].size;
}
void ro(int x)
{
 int y = p[x].F;
 int z = p[y].F;
 bool d = (p[y].L == x);
 int u = p[x].ch[d];
 p[y].ch[p[y].R == x] = u;
 if(u != 0)p[u].F = y;
 p[x].ch[d] = y;
 if(y != 0)p[y].F = x;
 p[z].ch[p[z].R == y] = x;
 if(x != 0)p[x].F = z;
 updata(y);updata(x);updata(z);
}
void splay(int x,int rt)
{
 while(p[x].F != rt)
 {
  int y = p[x].F;
  int z = p[y].F;
  if(z != rt && ((p[z].R==y)==(p[y].R == x)))
   ro(y);
  ro(x);
 }
}
void pretest();
int find(po x)
{
 if(p[0].L == 0)
  return -1;
 int y=0,u = p[0].L;
 while(u)
 {
  if(p[u].key > x)
   y=u,u = p[u].L;
  else if(p[u].key == x){
   splay(u,0);
   return u;
  }
  else if(p[u].key < x)
   y=u,u = p[u].R;
 }
 return y;
}
int insert(po x)
{
 int ret = find(x);
 if(ret == 2)
  ret = 2;
 if(ret == -1)
 {tot++;p[tot].cnt=p[tot].size=1;p[tot].key = x;p[0].L = tot;return tot;}
 if(p[ret].key == x)
  return ret;
 tot++;
 p[tot].key = x;
 p[tot].F = ret;
 p[tot].size = p[tot].cnt = 1;
 if(x < p[ret].key)
  p[ret].L = tot;
 else
  p[ret].R = tot;
 splay(tot,0);
 return tot;
}
int pre(int x)
{
 if(x == 0)
  return 0;
 while(p[x].R != 0)
 {
  x = p[x].R;
 }
 return x;
}
int nex(int x)
{
 if(x == 0)
  return 0;
 while(p[x].L != 0)
 {
  x = p[x].L;
 }
 return x;
}
int del(po x)
{
 int u = find(x);
 
 if( u==-1 || p[u].key != x)
  return -1;
 if(p[u].L == 0 && p[u].R == 0)
 {
  p[0].L = 0;
  return 1;
 }
 if(p[u].L == 0 && p[u].R != 0)
 {
  p[0].L = p[u].R;
  p[p[u].R].F = 0;
  updata(p[u].R);
  return 2;
 }
 if(p[u].L != 0)
 {
  int pr = pre(p[u].L);
  splay(pr,u);
  p[0].L = pr;
  p[pr].F = 0;
  p[pr].R = p[u].R;
  if(p[u].R != 0)
  p[p[u].R].F = pr;
  updata(pr);
  return 3;
 }
}
int findkth(int s)
{
 if(p[0].L == 0)
  return -1;
 int x = p[0].L;
 while(x)
 {
  if(p[p[x].L].size >= s)
   x = p[x].L;
  else if(p[p[x].L].size + p[x].cnt == s){
   splay(x,0);
   return x;
  }
  else if(s > p[p[x].L].size + p[x].cnt){
   s-=(p[p[x].L].size + p[x].cnt),x = p[x].R;
  }
 }
 if(x == 0)
  return -1;
}

void ins(po u)
{
 int v = insert(u);
 /*step 1*/
 int l = pre(p[v].L);
 int r = nex(p[v].R);
 po a = p[l].key,b = u,c = p[r].key;
 if(l != 0 && r != 0 && !gori(a,b,c))
 {
  del(u);
  return;
 }
 /*step 2*/
 while(l != 0)
 {
  splay(l,v);
  int ll = pre(p[l].L);
  if(ll == 0)
   break;
  a = p[ll].key;b = p[l].key;c = u;
  if(!gori(a,b,c))
  {
   del(p[l].key);
   splay(v,0);
   l = pre(p[v].L);
  }
  else
   break;
 }
 /*step 3*/
 while(r != 0)
 {
  splay(r,v);
  int rr = nex(p[r].R);
  if(rr == 0)
   break;
  a = u;b = p[r].key;c = p[rr].key;
  if(!gori(a,b,c))
  {
   del(p[r].key);
   splay(v,0);
   r = nex(p[v].R);
  }
  else
   break;
 }
}
po gpo(int s)
{
 int u = findkth(s);
 int v = pre(p[u].L);
 if(v == 0)
  return po(1,inf);
 else
  return p[u].key-p[v].key;
}
po gpo2(int s)
{
 int u = findkth(s);
 int v = nex(p[u].R);
 if(v == 0)
  return po(1,-inf);
 else
  return p[v].key-p[u].key;
}
int whe(po slope)
{
 if(p[0].L == 0)
  return -1;
 int l = 1,r = p[p[0].L].size;
 while(l < r)
 {
  int mid = (l+r)/2;
  po sl = gpo(mid);
  po s2 = gpo2(mid);
  if(cmp(det(slope,sl)) < 0)
   r = mid-1;
  else if(cmp(det(slope,sl)) > 0 && cmp(det(slope,s2))>0)
   l = mid+1;
  else if(cmp(det(slope,sl)) > 0)
   l = r = mid;
  else if(cmp(det(slope,sl)) == 0)
   l = r = mid;
 }
 return (l+r)/2;
}
void output(int,int);
double a[maxn],b[maxn],c[maxn];
double f[maxn];
int main(int argc, char *argv[])
{
    freopen("cash.in","r",stdin);
    freopen("cash.out","w",stdout);
    d = fopen("debug.txt","w");
    pretest();
    int n;double x;
    scanf("%d%lf",&n,&x);
    for(int i = 1;i<=n;i++)
     scanf("%lf%lf%lf",&a[i],&b[i],&c[i]);
    f[1] = x*c[1]/(a[1]*c[1]+b[1]);
    insert(po(f[1],f[1]/c[1]));
    output(0,tot);
    double ans = x;
    for(int i = 2;i<=n;i++)
    {
    int u = whe(po(b[i],-a[i]));
    u = findkth(u);
    splay(u,0);
    ans = max(ans,p[u].key.x*a[i]+p[u].key.y*b[i]);
    f[i] = ans*c[i]/(a[i]*c[i]+b[i]);
    ins(po(f[i],f[i]/c[i]));
    }
    for(int i = 1;i<=n;i++)
     ff(d,"%lf\n",f[i]);
    printf("%.3lf\n",ans);
    fclose(d);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
void output(int l,int r)
{
 ff(d,"this is the output:\n");
 for(int i = l;i<=r;i++){
  ff(d,"%d:L:%d R:%d F:%d size:%d cnt:%d key:",i,p[i].L,p[i].R,p[i].F,p[i].size,p[i].cnt);
  p[i].key.print();
  ff(d,"\n");
 }
}
void pretest()
{
 p[0].L = 1; p[1].F = 0; p[1].L = 2;p[1].R = 3;p[2].F = 1;p[2].L = 4;p[2].R = 5;p[3].F = 1;p[4].F = 2;p[5].F = 2;
 splay(2,0);
 output(0,5);
 memset(p,0,sizeof(p));
 for(int i = 1;i<=5;i++)
  insert(po(i,0));
 ins(po(3,1));
 int u = whe(po(2,1));
 ff(d,"%d",u);
 output(0,tot);
 memset(p,0,sizeof(p));tot=0;
}
