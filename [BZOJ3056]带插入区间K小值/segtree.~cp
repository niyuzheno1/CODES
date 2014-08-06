#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define L ch[0]
#define R ch[1]
using namespace std;
struct seg
{
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
int main(int argc, char *argv[])
{
    st.add(0,1,3,1,1);
    return EXIT_SUCCESS;
}
