#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#define L ch[0]
#define R ch[1]
#define ff fprintf
using namespace std;
const int A = 5,B = 9,AL = int(log(double(B))-log(double(A)));
const int MAXV = 70000,MAXN=70010;
struct seg
{
public:
  struct segn
  {
   segn*ch[2];
   int cnt;
   segn()
   {
    cnt = 0;
    ch[0] = ch[1] = NULL;
   }
  };
  segn * add(segn * a,int l,int r,int x,int y)
  {
   if(a == NULL)
    a = new segn;
   segn * b =  new segn;
   b->cnt = a->cnt+y;
   b->L = a->L;
   b->R = a->R;
   if(l == r)
    return b;
   int mid = (l+r)/2;
   if(x > mid)
    b->R = add(b->R,mid+1,r,x,y);
   else
    b->L = add(b->L,l,mid,x,y);
   return b;
  }
  segn * merge(segn * a,segn * b)
  {
   if(a == NULL)
    return b;
   if(b == NULL)
    return a;
   segn * c = new segn;
   c->cnt = a->cnt+b->cnt;
   c->L = merge(a->L,b->L);
   c->R = merge(a->R,b->R);
   return c;
  }
};
seg st;
int val[MAXN];
seg::segn * v[MAXN];
struct scap
{
 struct scapn
 {
  int n;
  int key;
  seg::segn * sum;
  scapn * ch[2];
  void updata()
  {
   n = 1;
   if(L != 0) n+=L->n;
   if(R != 0) n+=R->n; 
   updata2();
  }
  void updata2()
  {
   seg::segn * h = 0;
   if(L != 0 && R != 0)
    h = st.merge(L->sum,R->sum);
   else if(L != 0)
    h = L->sum;
   else if(R != 0)
    h = R->sum;
   /*<=> if(L != 0) sum += L->sum; if(R != 0) sum += R->sum;*/
   sum = st.add(h,0,MAXV,key,1);//<=> sum = key;
  }
  scapn()
  {
   n = key = 0;
   ch[0] = ch[1] = 0;
   sum =  0;
  } 
 };
private:
 scapn * rt;
 int maxn,maxd;
 scapn * fl(scapn * x,scapn * y)
 {
  if(x == NULL)
   return  y;
  x->R = fl(x->R,y);
  return fl(x->L,x);
 }
 scapn * bd(scapn * x,int n)
 {
  if(n == 0)
  {
   x->L = NULL;
   return x;
  }
  scapn * y = bd(x,n/2);
  scapn * z = bd(y->R,n-1-n/2);
  y->R = z->L;
  y->updata();
  z->L = y;
  z->updata();
  return z;
 }
 void rb(scapn * & a)
 {
  int n = a->n;
  scapn * t = new scapn;
  scapn * head = fl(a,t);
  t = bd(head,n);
  a = t->L;
 }
 bool _insert(scapn * &b,int x,int y,int d)
 {
  if(b == NULL)
  {
   b = new scapn;
   b->n = 1;b->key = y;
   b->sum = st.add(b->sum,0,MAXV,b->key,1);
   return d*AL > maxd;
  }
  int ret = 0;
  int l = (b->L!=NULL)?(b->L->n):0;
  if(l>=x)
   _insert(b->L,x,y,d+1);
  else
   _insert(b->R,x-l-1,y,d+1);
  b->updata();
  int r = (b->R!=NULL)?(b->R->n):0;
  int n = b->n;
  if(ret && (n*A <B*l || n*A<B*r))
  {
   rb(b);
   ret = 0;
  }
  return ret;
 }
 void _modify(scapn *&b,int x,int y)
 {
  int l = (b->L!=NULL)?(b->L->n):0;
  if(x <= l)
   _modify(b->L,x,y);
  else if(x == l+1)
  {
   b->sum = st.add(b->sum,0,MAXV,b->key,-1);
   b->key = y;
   b->sum = st.add(b->sum,0,MAXV,b->key,1);
   //b->updata2();
   return;
  }
  else
   _modify(b->R,x-l-1,y);
  b->updata2();
 }
 void _sum(scapn * & b,int x,int y,int & a,int & c,int * val,seg::segn ** d)
 {
  if(b == NULL)
   return;
  if(x<=1 && b->n <= y){
   c++;d[c] = b->sum;
   return;
  }
  int l = ((b->L!=NULL)?(b->L->n):0)+1;
  if(x < l)
    _sum(b->L,x,y,a,c,val,d);
  if(x<= l && y>=l){
   a++;
   val[a] = b->key;
  }
  if(y > l)
   _sum(b->R,x-l,y-l,a,c,val,d);
  return ;
 }
public:
 void ins(int idx,int x)
 {
  _insert(rt,idx,x,0);
  if(rt != 0){
   maxn = max(maxn,rt->n);
   maxd = int(log(double(maxn)));
  }
 }
 void mo(int idx,int x)
 {
  _modify(rt,idx,x);
 }
 int sum(int idx,int idy,int kth)
 {
  int lena=0,lenb=0;
  _sum(rt,idx,idy,lena,lenb,val,v);
  int l = 0,r = MAXV;
  int t = 0;
  while(l < r)
  {
   int mid = (l+r)/2;
   int ret = 0;
   for(int i = 1;i<=lena;i++)
    if(val[i] <= mid && val[i] >= l)
     ret++;
   for(int i = 1;i<=lenb;i++)
    if(v[i] != 0 && v[i]->L != 0)
     ret += v[i]->L->cnt;
   if(ret + t < kth)
   {
    for(int i = 1;i<=lenb;i++)
     if(v[i] != 0 )
      v[i] = v[i]->R;
    t += ret;
    l = mid+1;
   }
   else
   {
    for(int i = 1;i<=lenb;i++)
     if(v[i] != 0)
      v[i] = v[i]->L;
    r = mid;
   }
  }
  return (l+r)/2;
 }
};
scap sct;
int n,m,lastans = 0;
char str[5];
int main(int argc, char *argv[])
{
    //freopen("bzoj3056.in","r",stdin);freopen("bzoj3056.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int x;
     scanf("%d",&x);
     sct.ins(i,x);
    }
    scanf("%d",&m);
    for(int i = 1;i<=m;i++)
    {
     scanf("%s",str);
     int x,y,z=0;scanf("%d%d",&x,&y);
     x^=lastans,y^=lastans;
     if(str[0] == 'I')
      sct.ins(x-1,y);
     if(str[0] == 'M')
      sct.mo(x,y);
     if(str[0] == 'Q')
     {
      scanf("%d",&z);z^=lastans;
      printf("%d\n",(lastans=sct.sum(x,y,z)));
     }
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
