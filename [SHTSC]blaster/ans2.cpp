#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
#define ff fprintf
using namespace std;
typedef long long int64;
const int64 maxn = 1010;
FILE * D;
set<int64> fl;
int64 n,m,a,b;
int64 c[maxn],d[maxn];
int64 t,len;
int64 calc1(int64 u){return (a*u+b)%m+1;}
int64 calc2(int64 u){return (a*u)%m;}
int64 inv(int64 a,int64 b)
{
 int64 p = 1;
 int64 ret = 1;
 for(int64 i = 0;i<=64;i++)
 {
  p = (p%m)*(p%m);
  p %= m;
  if(i == 0)
   p = (p%m)*(a%m);
  p %=m;
  if(((1) & (b>>i))){
   ret=(ret%m)*(p%m);
   ret%=m;
  }
 }
 return ret;
}
int64 findring()
{
 int64 len = inv(a,m-2);
 return len;
}
void getq()
{
 int64 st = len;
 while(true)
 {
  int64 a1 = calc1(st);
  if(fl.find(a1) != fl.end())
   break;
  fl.insert(a1);
  t++;
  c[t] = calc1(st);
  int64 last = st;
  st+=len;
  while(calc1(st-1) < calc1(st))
   st--;
  d[t] = st-last;
 }
 for(int64 i = 1;i<=t;i++)
  ff(D,"%I64d %I64d\n",c[i],d[i]);
}
int main(int argc, char *argv[])
{
    freopen("blaster.in","r",stdin);
    freopen("blaster.out","w",stdout);
    D = fopen("debug.txt","w");
    scanf("%I64d%I64d%I64d%I64d",&n,&m,&a,&b);
    len = findring();
    ff(D,"ringlen:%I64d\n",len);
    getq();
    fclose(D);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
