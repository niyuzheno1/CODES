#include <cstdlib>
#include <iostream>
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
struct scap
{
 struct scapn
 {
  int n;
  int key;
  int sum;
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
   sum = key;
   if(L != 0) sum += L->sum;
   if(R != 0) sum += R->sum;
  }
  scapn()
  {
   n = key = 0;
   ch[0] = ch[1] = 0;
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
   b->key = y;
   b->updata2();
   return;
  }
  else
   _modify(b->R,x-l-1,y);
  b->updata2();
 }
 int _sum(scapn * & b,int x,int y)
 {
  if(b == NULL)
   return 0;
  if(x<=1 && b->n <= y)
   return b->sum;
  int ret = 0;
  int l = ((b->L!=NULL)?(b->L->n):0)+1;
  if(x < l)
   ret += _sum(b->L,x,y);
  if(x<= l && y>=l)
   ret += b->key;
  if(y > l)
   ret += _sum(b->R,x-l,y-l);
  return ret;
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
 int sum(int idx,int idy)
 {
  return _sum(rt,idx,idy);
 }
};
FILE * d;
scap tr;
int main(int argc, char *argv[])
{
    d = fopen("debug.txt","w");
    for(int i = 1;i<=10;i++)
     tr.ins(i,i);
    ff(d,"%d",tr.sum(1,6));
    fclose(d);
    return EXIT_SUCCESS;
}
