#include "mode.h"
#define A a[0]

typedef int64 Arr[3][3];
const Arr Matrix1 = {{3,0,0},{-1,1,0},{-1,0,1}},
Matrix2 = {{1,1,0},{1,2,0},{0,0,0}};
int64 p,d[1000000];
Arr a,b,c;
void mul(Arr & a,Arr & b,int k1,int k2,int k3)
{
 for(int i = 0;i<k1;++i)
  for(int j = 0;j<k2;++j)
  {
   c[i][j] = 0;
   for(int k = 0;k<k3;k++)
    c[i][j] = (c[i][j]+a[i][k]*b[k][j])%p;
  }
memcpy(a,c,sizeof(a));
}
void calc(Arr & a,Arr & b,int k,int64 x)
{
 while(x)
 {
  if(x & 1) mul(a,b,1,k,k);
  mul(b,b,k,k,k);
  x>>=1;
 }
}
int main(int argc, char *argv[])
{
    setIO("60E");
    int64 x,y,sum=0;
    int n;read(n);read(x);read(y);read(p);
    for(int i = 0;i<n;i++)
    {
     read(d[i]);d[i]%=p;sum = (sum+d[i])%p;
    }
    if(n == 1)
    {
    printf("%I64d\n",d[0]);return 0;
    }
    A[0] = sum,A[1] = d[0],A[2] = d[n-1];
    memcpy(b,Matrix1,sizeof(b));
    calc(a,b,3,x);
    sum = A[0];
    
    A[0] = d[n-2],A[1] = d[n-1];
    memcpy(b,Matrix2,sizeof(b));
    calc(a,b,2,x/2);
    A[2] = A[0]*(x&1)+A[1];
    
    A[0] = sum,A[1]=d[0];
    memcpy(b,Matrix1,sizeof(b));
    calc(a,b,3,y);
    if(A[0] < 0) A[0]+=p;
    printf("%I64d\n",A[0]);
    closeIO();
    return EXIT_SUCCESS;
}
