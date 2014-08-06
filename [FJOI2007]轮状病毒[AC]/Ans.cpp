#include "mode.h"
const int M = 100000000-1,N=100000000;
struct gao
{
 int p[10],len;
 void operator = (gao y)
 {
  len = y.len;for(int i = 0;i<=y.len;++i) p[i] = y.p[i];
 }
 gao()
 {
      CLEAR(p,0);len = 0;
 }
 gao operator +(gao y)
 {
  gao tmp;
  int u = max(len,y.len);
  for(int i = 0;i<=u;++i){
   tmp.p[i] += p[i]+y.p[i];
   while(tmp.p[i] > M)
   {
    tmp.p[i+1] += tmp.p[i]/N;u=max(u,i+1);
    tmp.p[i] %= N;
   }
  }
  tmp.len = u;
  return tmp;
 }
 gao operator -(gao y)
 {
  gao tmp;
  int u = max(len,y.len);
  for(int i = 0;i<=u;++i){
   tmp.p[i] += p[i]-y.p[i];
   while(tmp.p[i] < 0)
   {
    tmp.p[i] += N;
    tmp.p[i+1] -= 1;
   }
  }
  tmp.len = u;
  return tmp;
 }
 void pri(int u)
 {
  string fz = "";
  int x = N;
  while(x != 0)
  {
   int l = (x-1)/10+1,r = x-1;
   if(l<=u&&u<=r){
    printf("%s",fz.c_str());
    printf("%d",u); 
   }
   x/=10;
   fz+='0';
  }
  if(u == 0)
   printf("%s",fz.c_str());
 }
 void print()
 {
  int x = 9;
  while(p[x] == 0 && x > 0) --x;
  printf("%d",p[x]);
  --x;
  if(x >= 0)
  {
   for(int i = x;i>=0;--i)
    pri(p[i]);
  }
 }
};
gao a1,a2,a3,c;
void swap(gao & u,gao & v)
{
 gao tmp = u;u = v,v = tmp;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi;
    if(n == 1) puts("1");
    else if(n == 2) puts("5");
    else{
    a1.p[0] = 1;a2.p[0] = 5;c.p[0] = 2;
    for(int i = 3;i<=n;++i){
     a3 = a2+a2+a2-a1+c;
     swap(a2,a1);
     swap(a3,a2);
     }
    a2.print();
    }
    closeIO();
    return EXIT_SUCCESS;
}
