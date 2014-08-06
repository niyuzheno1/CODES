#include "mode.h"
#include "algo.h"
#include "hash2.h"
typedef long long LL;
const int MN = 250;
const int MH = 10;
const int ML = 10;
#define Mod 1000000007
inline int & addto(int & a,const int & b){
       a = add<int,Mod>(a,a,b);
       return a;
}
inline int & subto(int & a,const int & b){a = sub<int,Mod>(a,a,b);return a;}
struct status
{
  LL h;
  int geth(int y) const
  {
   return (h>>(y*4))&15;
  }
  void seth(int y,int v)
  {
   h &= ~((15LL)<<(y*4));
   h |= ((LL)v)<<(y*4);
  }
  bool operator ==(status b)const
  {
   return h == b.h;
  }
  int operator %(int x) const
  {
   return h%x;
  }
};
typedef hash<status,int,1000003,100000,MN> ha;
typedef ha::node node;
int main(int argc, char *argv[])
{
    setIO("sample");
    int n0=gi,h0=gi;static int l0[MH+1];
    for(int i = 1;i<=h0;++i)l0[i]=gi;
    if(n0%4 != 0){
     puts("0");
     closeIO();
     return 0;
    }
    n0/=4;
    for(int i = 1;i<=h0;++i)
    {
     if(l0[i]%2 !=0){
     puts("0"),closeIO();
     return 0;
     }
     l0[i]/=2;
    }
    status sta1;
    sta1.h = 0;
    int hn = 0;
    for(int y = 0;y<ML;++y) sta1.seth(y,0);
    for(int i = 1;i<=h0;++i)
     for(int y = 0;y<l0[i];++y)
      ++hn,sta1.seth(y,sta1.geth(y)+1);
    hn = hn*2-sta1.geth(0);
    if(n0 < hn)
    {
     puts("0"),closeIO();
     return 0;
    }
    n0 -= hn;
    status sta;
    ha f,g;
    g[sta1][0] = 1;
    for(int x = 1;x<ML;++x)
    {
     f.clear();
     for(node * it = g.begin();it != g.end();++it)
     {
      sta = it->key;
      int h = sta1.geth(x);
      sta.seth(0,h);
      for(int ny = 1;ny < ML && sta.geth(ny)>h;++ny)
       sta.seth(ny,h);
      int *nf = f[sta];
      for(int n = 0;n<=n0;++n)
       addto(nf[n],it->val[n]);
     }
     f.swap(g);
     for(int y = 1;y<ML;++y,f.swap(g))
     {
      f.clear();
      for(node * it = g.begin();it != g.end();++it)
      {
       sta = it->key;
       int minN=0,maxN =n0;
       while(minN<=n0 && it->val[minN]==0)
       ++minN;
       if(minN > n0)continue;
       while(it->val[maxN]==0)--maxN;
       int sum = 0;
       for(int i = 1;i<ML;++i)
       {
        if(i < y)
         sum += sta.geth(i)*(ML-x-1);
        else
         sum += sta.geth(i)*(ML-x);
       }
       for(int h = 0;h<=sta.geth(y) && max(n0-sum,minN)<=min(n0-h,maxN);++h)
       {
        sta.seth(y,h);
        for(int ny = y+1;ny < ML && sta.geth(ny)>h;++ny)
         sta.seth(ny,h);
        int * nf = f[sta];
        for(int n = max(n0-sum,minN);n<=min(n0-h,maxN);++n)
         addto(nf[n+h],it->val[n]);
        sta = it->key;
       }
      }
     }
    }
    int res = 0;
    for(node * it = g.pool;it != g.tail;++it)
     addto(res,it->val[n0]);
    printf("%d\n",res);
    closeIO();
    return EXIT_SUCCESS;
}
