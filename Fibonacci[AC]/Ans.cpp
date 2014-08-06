#include "mode.h"

const int MM = 3,mod = 10000,MN = 2;
int n;
class Mat
{
public:
 int a[MM][MM];
 Mat()
 {CLEAR(a,0);}
 void operator =(Mat b)
 {
  for(int i = 1;i<=MN;++i)
   for(int j = 1;j<=MN;++j)
    a[i][j] = b.a[i][j];
 }
 Mat operator * (Mat & b)
 {
  Mat c;
  for(int i = 1;i<=MN;++i)
   for(int j = 1;j<=MN;++j)
    for(int k = 1;k<=MN;++k)
     c.a[i][j] += (a[i][k])%mod*(b.a[k][j])%mod,c.a[i][j] %= mod;
  return c;
 }
};
Mat m,a;
inline void PowK(Mat & c,int x)
{
 Mat u = m,v = m;
 while(x)
 {
   if(x & 1) u = u*v;
   x>>=1;
   v = v*v;
 }
 c = u;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    m.a[1][1] = 1;m.a[1][2] = 1;
    m.a[2][1] = 1;m.a[2][2] = 0;
    while(1)
    {
     n = gi;if(!(~n)) break;
     if(n == 0)
      puts("0");
     else
     {
      PowK(a,n-1);
      printf("%d\n",(a.a[2][1]*1+a.a[2][2]*0)%mod);
     }
    }
    closeIO();
    return EXIT_SUCCESS;
}
