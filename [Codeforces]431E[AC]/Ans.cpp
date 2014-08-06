#include "mode.h"
const int MN = 112345,MM = 212345;
struct Q{
 int64 type,x,y;
};
typedef map<int64,int64> mp;
typedef mp::iterator itor;
mp hash;
int64 a[MN],bitv[MM],bitn[MM];
Q q[MN];
void insert(int64 bit[],int pos,int64 val)
{
 for(int i = pos;i<MM;i+=lb(i))
  bit[i] += val;
}
int64 get(int64 bit[],int pos)
{
 int64 retv = 0LL;
 for(int i = pos;i>0;i-=lb(i))
  retv += bit[i];
 return retv;
}
double foo(double d)
{
 itor it = hash.upper_bound(int64(d));
 it--;
 return (get(bitn,it->Y)*d)-get(bitv,it->Y);
}
int main(int argc, char *argv[])
{
    setIO("431E");
    int64 n,nq,id=1;
    read(n);read(nq);
    for(int i = 0;i<n;++i)
     read(a[i]),hash[a[i]] = 0;
    for(int i = 0;i<nq;++i)
    {
     read(q[i].type);
     if(q[i].type == 1)
     {
      read(q[i].x);read(q[i].y);
      hash[q[i].y] = 0;
     }
     else
      read(q[i].x);
    }
    for(itor it = hash.begin();it != hash.end();it++)
     it->Y = id++;
    for(int i = 0;i<n;i++)
    {
     insert(bitv,hash[a[i]],a[i]);
     insert(bitn,hash[a[i]],1);
    }
    for(int i = 0;i<nq;i++)
    {
            if(q[i].type == 1)
            {
             q[i].x--;
             insert(bitv,hash[a[q[i].x]],-a[q[i].x]);
             insert(bitn,hash[a[q[i].x]],-1);
             a[q[i].x] = q[i].y;
             insert(bitv,hash[q[i].y],q[i].y);
             insert(bitn,hash[q[i].y],1);
            }
            else
            {
             double bot = 0.0,top = 1e15,mid;
             while(top-bot > 1e-5)
             {
              mid = (top+bot)/2;
              if(foo(mid) >= (double)q[i].x)
               top = mid;
              else
               bot = mid;
             }
             printf("%.5lf\n",mid);
            }
    }
    closeIO();
    return EXIT_SUCCESS;
}
