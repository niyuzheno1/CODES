#include "mode.h"
#include "data.h"
#define MN 10010
#define MK 6000
#define MKK 610
int a[MN];
int n,k;
int f[MN][MKK];
struct T1
{
 int b[MK];
 void add(int x,int y)
 {
  ++x;
  for(int i = x;i<MK;b[i] = max(y,b[i]),i+=lb(i));
 }
 int query(int x)
 {
  ++x;
  int ret = 0;
  for(int i = x;i;ret = max(ret,b[i]),i-=lb(i));
  return ret;
 }
 void init()
 {
  CLEAR(b,0);
 }
};
struct T2
{
 int b[MKK];
 void add(int x,int y)
 {
  ++x;
  for(int i = x;i<MKK;b[i] = max(y,b[i]),i+=lb(i));
 }
 int query(int x)
 {
  ++x;
  int ret = 0;
  for(int i = x;i;ret = max(ret,b[i]),i-=lb(i));
  return ret;
 }
 void init()
 {
  CLEAR(b,0);
 }
};
T1 t[MKK];
T2 t2[MK];

int query1(int x,int y)
{
    return t[x].query(y);
}

int query2(int x,int y)
{
    return t2[x].query(y);
}

int add1(int x,int y,int z)
{
    t[x].add(y,z);
}

int add2(int x,int y,int z)
{
    t2[x].add(y,z);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,k = gi;
    for(int i = 1;i<=n;a[i]=gi,++i);
    for(int i = 1;i<=n;++i){
     int lastans = 0;
     for(int j = 0;j<=k;++j)
     {
      lastans = max(lastans,query1(j,a[i]+j));
      lastans = max(lastans,query2(a[i]+j,j));
      f[i][j] = lastans+1;
     }
     for(int j = 0;j<=k;++j){
     add1(j,a[i]+j,f[i][j]);
     add2(a[i]+j,j,f[i][j]);
     }
    }
    int ans = 0;
    for(int i = 1;i<=n;++i)
     for(int j = 0;j<=k;++j)
      ans = max(ans,f[i][j]);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
