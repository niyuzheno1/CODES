#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define L ch[0]
#define R ch[1]
#define ff fprintf
using namespace std;
const int A = 5;
const int B = 9;
FILE * d;
const double AL = log(double(B))-log(double(A));
struct scap
{
public:
       struct scapn
       {
        int n,nlast;
        int key;
        scapn * ch[2];
        scapn()
        {
         ch[0] = ch[1] = NULL;
         n = nlast = key = 0;
        }
        void updata()
        {
         n = 1;
         if(L != 0) n += L->n;
         if(R != 0) n += R->n;
        }
        void print()
        {
         if(L != 0) L->print();
         ff(d,"adress:%d n:%d key:%d L:%d R:%d \n",this,n,key,L,R);
         if(R != 0) R->print();
        }
        int print2(int d)
        {
         if(L == 0 && R == 0)
          return d;
         int ans = 0;
         if(L != 0)
          ans = max(L->print2(d+1),ans);
         if(R != 0)
          ans = max(R->print2(d+1),ans);
         return ans;
        }
       };
private:
  int maxd,maxn;
  scapn * rt;
  scapn* fl(scapn * a,scapn * b)
  {
       if(a == NULL)
        return b;
       a->R = fl(a->R,b);
       return fl(a->L,a);
  }
  scapn * build(scapn * a,int n)
  {
   if(n == 0)
   {
    a->L=0;
    a->updata();
    return a;
   }
   scapn * y = build(a,n/2);
   scapn * z = build(y->R,n-1-n/2);
   y->R = z->L;
   y->updata();
   z->L = y;
   return z;
  }
  void rb(scapn *& b)
  {
   int n = b->n;
   scapn * t = new scapn;
   scapn * head = fl(b,t);
   build(head,n);
   b = t->L;
  }
  bool insert(scapn *& a,int x,int y,int z)
  {
   if(a == NULL)
   {
    a = new scapn;
    a->n++;
    a->key = y;
    if(z*AL > maxd)
     return 1;
    else
     return 0;
   }
   bool ret = 0;
   a->n++;
   int t = (a->L!=NULL)?a->L->n:0;
   if(t > x)
    ret = insert(a->L,x,y,z+1);
   else
    ret = insert(a->R,x-t,y,z+1);
   int l = (a->L!=NULL)?a->L->n:0;
   int r = (a->R!=NULL)?a->R->n:0;
   if(ret && (a->n*A<l*B || a->n*A<r*B))
   {
    rb(a);
    ret = 0;
   }
   return ret;
  }
  scapn * _find(scapn * x,int y)
  {
   if(x == NULL || x->key == y)
    return x;
   if(x->key > y)
    return _find(x->L,y);
   else
    return _find(x->R,y);
  }
  void _dele(scapn * &y)
  {
   if(y->R == 0)
   {
    y = y->L;
    return;
   }
   if(y->L == 0)
   {
    y = y->R;
    return;
   }
   scapn * u = y,* p = y->L,*tmp = NULL;
   while(p->R != 0)
   {
    tmp = p;
    p = p->R;
   }
   if(tmp != NULL){
    tmp->R = p->L;
    p->L = u->L;
   }
   p->R = u->R;
   y = p;
  }
  scapn * _del(scapn * x,int y)
  {
   if(x == NULL)
    return x;
   if(x->key == y)
    {_dele(x);if(x != 0)x->updata();return x;}
   if(x->key > y)
    x->L = _del(x->L,y);
   if(x->key < y)
    x->R = _del(x->R,y);
   x->updata();
   return x;
  }
public:
  void ins(int x,int y)
  {
   insert(rt,x,y,0);
   maxn = max(maxn,rt->n);
   maxd = int(log(maxn));
  }
  void dpr()
  {
   if(rt != 0)
   rt->print();
  }
  void dpr2()
  {
   if(rt != 0)
   ff(d,"maxdepth:%d size:%d",rt->print2(0),rt->n);
  }
  void del(int x)
  {
   rt = _del(rt,x);
   if(rt != 0 && B*rt->n <= A*maxn){
    rb(rt);
    maxn = rt->n;
    maxd = int(log(maxn));
   }
  }
};
scap t;
int main(int argc, char *argv[])
{
    freopen("scap.in","r",stdin);freopen("scap.out","w",stdout);
    d = fopen("debug.txt","w");
    for(int i = 1;i<=10;i++)
     t.ins(i,i-1);
    for(int i = 3;i<=7;i++)
     t.del(i-1);
    t.dpr();
    fclose(stdin);fclose(stdout);fclose(d);
    return EXIT_SUCCESS;
}
