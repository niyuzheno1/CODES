#include "mode.h"
const int64 MN = 11,mod = 9973; 
int64 n ,k;
class mat
{
public:
 int64 a[MN][MN];
 mat()
 {
 CLEAR(a,0);
 }
 void operator =(mat y) 
 {
  for(int64 i = 1;i<=n;++i)
   for(int64 j = 1;j<=n;++j)
    a[i][j] = y.a[i][j];
 }
 mat operator *(mat & y)
 {
  mat tmp;
  for(int64 i = 1;i<=n;++i)
   for(int64 j = 1;j<=n;++j)
    for(int64 k = 1;k<=n;++k)
     tmp.a[i][j] += ((a[i][k])%mod*(y.a[k][j])%mod)%mod,tmp.a[i][j] %= mod;
  return tmp;
 }
};
bool flag;
mat m;
void PowM(mat & u,int64 x)
{
 mat a=m,b=m;
 while(x)
 {
  if(x & 1)
   b = b*a;
  x/=2;
  a = (a*a);
 }
 u = b;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int64 T =gi;
    while(T--)
    {
     n = gi; k = gi;flag = 0;
     for(int64 i = 1;i<=n;++i)
      for(int64 j = 1;j<=n;++j)
       m.a[i][j] = gi;
      mat a;
      PowM(a,k-1);
      int64 ans = 0;
      for(int64 i = 1;i<=n;++i)
       ans += a.a[i][i],ans%=mod;
      printf(I64D,ans);puts("");
    }
    closeIO();
    return EXIT_SUCCESS;
}
