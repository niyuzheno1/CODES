#include "mode.h"
#include "mathlab.h"
#define showci(uu) ff(debug,"%.4f %.4f",real(uu),imag(uu));
typedef complex<double> ci;
const int MN = 1000;
ci powG[MN];
ci a[MN];
ci b[MN];
void fft(int n,ci * a,int step,ci * out)
{
 if(n == 1)
 {
  out[0] = a[0];
  return ;
 }
 int m = n/2;
 fft(m,a,step+1,out);
 fft(m,a+(1<<step),step+1,out+m);
 for(int i = 0;i<m;++i)
 {
  ci e = out[i],o = out[i+m]*powG[i<<step];
  out[i] = e+o;
  out[i+m] = e-o;
 }
}

int main(int argc, char *argv[])
{
    setIO("sample");
    int n = gi;
    for(int i = 0;i<n;++i)
     a[i] = gi;
    int tn = 2*n;
    for(int i = 0;i<=tn;++i){
     double phie = (2*PI*double(i)/double(tn)); 
     powG[i] = ci(cos(phie),sin(phie));
    }
    fft(tn,a,0,b);
    for(int i = 0;i<=tn;++i,printf("\n"))
     printf("%.4f %.4f",real(b[i]),imag(b[i]));
    for(int i = 0;i<=tn;++i,endline())
     showci(powG[i]);
    closeIO();
    return EXIT_SUCCESS;
}
