#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#define pi 3.141592653589793238462643383
using namespace std;
const int MAXN = 400005;
typedef complex<double> cd;
cd a[MAXN],b[MAXN],w[2][MAXN];
int n,na,nb,rev[MAXN];
int p = 0;
void FFT(cd * a,int f)
{
 cd x,y;
 int l;
 for(int i = 0;i<p;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
 for(int i = 1;i<p;i<<=1)
  for(int j =0,t=p/(i<<1);j<p;j+=i<<1)
   for(int k = l = 0;k<i;++k,l+=t)
   {
    x = w[f][l]*a[j+k+i];
    y = a[j+k];
    a[j+k] = y+x;
    a[j+k+i] =  y-x;
   }
 if(f) for(int i = 0;i<p;i++)real(a[i])/=p;
}
void prepare()
{
 int x,y;
 for(int i = 0;i<p;i++)
 {
  x = i;y=0;
  for(int j = 1;j<p;x>>=1,j<<=1)
   (y<<=1)|=x&1;
  rev[i] = y;
 }
 for(int i = 0;i<p;i++)
 {
  w[0][i] = cd(cos(2*pi*i/p),sin(2*pi*i/p));
  w[1][i] = cd(cos(2*pi*i/p),-sin(2*pi*i/p));
 }
}
void mult()
{
 prepare();
 FFT(a,0);
 FFT(b,0);
 for(int i = 0;i<p;i++)
  a[i] = a[i]*b[i];
 FFT(a,1);
}
double x[MAXN],ans[MAXN];

int main(int argc, char *argv[])
{
    #ifndef ONLINE_JUDGE
    freopen("zoj2014.in","r",stdin);freopen("zoj2014.out","w",stdout);
    #endif
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
     scanf("%lf",&x[i]);
   
    for(p=1;p<n;p*=2);p*=2;
    for(int i = 1;i<n;i++)
     b[i] = cd(1.0/i/i,0);
    for(int i = 0;i<n;i++)
     a[i] = cd(x[i],0);
    mult();
    for(int i = 0;i<n;i++)
     ans[i] += real(a[i]);
    for(int i = 0;i<p;i++)
     a[i] = b[i] = cd(0,0);
    for(int i = 1;i<n;i++)
     b[i] = cd(1.0/i/i,0);
    for(int i =0;i<n;i++)
     a[i] = cd(x[n-i-1],0);
    mult();
    for(int i = 0;i<n;i++)
     ans[i] -= real(a[n-i-1]);
    for(int i = 0;i<n;i++)
     printf("%.3lf\n",ans[i]);
    #ifndef ONLINE_JUDGE
    fclose(stdin);fclose(stdout);
    #endif
    return EXIT_SUCCESS;
}
