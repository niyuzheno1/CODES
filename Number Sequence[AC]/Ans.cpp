#include "mode.h"
const int MN = 3,mod = 7;
class Mat
{
public:
      int a[MN+1][MN+1];
      Mat(){CLEAR(a,0);}
      void operator = (Mat  x)
      {
       for(int i = 1;i<=MN;++i)for(int j = 1;j<=MN;++j)a[i][j] = x.a[i][j];
      }
      Mat operator * (Mat &  x)
      {
       Mat tmp;
       for(int i = 1;i<=MN;++i)
        for(int j = 1;j<=MN;++j)
         for(int k = 1;k<=MN;++k)
          tmp.a[i][j] = (tmp.a[i][j]+a[i][k]*x.a[k][j])%mod,tmp.a[i][j] %= mod;
       return tmp;
      }
};
Mat m;
void PowK(Mat & c,int k)
{
 Mat u=m,v=m;
 while(k)
 {
  if(k & 1) u = u*v;
  k>>=1;
  v = v*v;
 }
 c = u;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    while(true)
    {
     CLEAR(m.a,0);
     m.a[1][1] = gi;m.a[1][2] = gi;
     m.a[2][1] = 1;m.a[3][2] = 1;
     int n = gi;--n;
     if(m.a[1][1] == 0 && m.a[1][2] == 0 && n == -1)
      break;
     Mat a;PowK(a,n);
     printf("%d\n",(1*a.a[3][1]+1*a.a[3][2]+0*a.a[3][3])%7);
    }
    closeIO();
    return EXIT_SUCCESS;
}
