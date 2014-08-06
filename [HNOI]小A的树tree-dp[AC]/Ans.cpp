#include "mode.h"
#define tra(x,v,y) for(int64 x = st[y],v; x != 0; x = lk[x]) if((v = ve[x]) != fa[y])
using namespace std;
const int64 MN = 100010;
int64 k,n,a[MN],tot,st[MN],lk[MN*2],ve[MN*2],fa[MN],q[MN],ans[4],Ans[4];
int64 sum[MN],num[MN],a0[MN],a1[MN],size[MN];
void add(int64 x,int64 y)
{
     ++tot;lk[tot] = st[x];ve[tot] = y;st[x] = tot;
}
void up(int64 x)
{
     int64 t1 = 0,t2 = 0;num[x] = 0;sum[x] = 0;
     int64 y = ((a[x]&(1<<(k-1))))?1:0;size[x] = 1;
     tra(i,v,x) size[x] += size[v];
     if(y) a1[x] = 1,a0[x] = 0; else a0[x] = 1,a1[x]=0;
     if(y){
      tra(i,v,x) ans[1] += 2*sum[v],t1+=sum[v];
      tra(i,v,x) ans[1] += sum[v]*(t1-sum[v]);
      sum[x]+=t1+1;
     }
     if(y){
     num[x] = size[x];
     tra(i,v,x) ans[2] += size[v]*(size[x]-size[v]);
     ans[2] += num[x];
     }else{
     t1 = size[x];
     tra(i,v,x) ans[2] += 2*num[v]*(t1-size[v]),num[x] += num[v],t1-=num[v];
     }
     if(y)
     {
      t1 = 0,t2 = 0;
      tra(i,v,x) a0[x]+=a1[v],a1[x]+=a0[v],t1+=a0[v],t2+=a1[v];
      ans[3]+=2*t1+1;
      tra(i,v,x) ans[3] += 2*(t1-a0[v])*a0[v],ans[3]+=2*(t2-a1[v])*a1[v],t1-=a0[v],t2-=a1[v];
     }
     else
     {
      t1 = 0,t2 = 0;
      tra(i,v,x) a0[x]+=a0[v],a1[x]+=a1[v],t1+=a0[v],t2+=a1[v];
      ans[3]+=2*t2;
      tra(i,v,x) ans[3] += 2*a1[v]*(t1-a0[v]);//(t1-a0[v])*a1[v],ans[3]+=(t2-a1[v])*a0[v],t1-=a0[v],t2-=a0[v];
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int64 T = gi;
    while(T--)
    {
     n = gi;
     for(int64 i = 1;i<=n;++i) a[i] = gi;
     for(int64 i = 1,x,y;i<n;++i) x=gi,y=gi,add(x,y),add(y,x);
     tot = 1;
     q[1] = 1;
     for(int64 i = 1;i<=tot;++i)
      tra(j,v,q[i])
        fa[v] = q[i],q[++tot] = v;
     for(k = 1;k<=20;++k)
     {
     memset(ans,0,sizeof(ans));
     for(int64 i = tot;i>=1;--i)
       up(q[i]);
     for(int64 i = 1;i<=n;++i)
      ans[1] += ((a[i]&(1<<(k-1))))?1:0;
     for(int64 i = 1;i<=3;++i)
      Ans[i] += ans[i]*(1<<(k-1));
     if(ans[2])
      swap(ans[2],ans[2]);
     }
     for(int64 i = 1;i<=3;printf("%c",i==3?'\n':' '),++i)
      printf("%.3f",double(Ans[i])/double(n*n));
    }
    closeIO();
    return EXIT_SUCCESS;
}
