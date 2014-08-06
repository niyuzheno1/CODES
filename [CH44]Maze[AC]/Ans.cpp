#include "mode.h"
#include "mathlab.h"
typedef long long ll;
#define MM 10001
#define ML 1<<15

int m,N,K;
ll n;
int a[MM],b[MM];

cx A[ML],B[ML],C[ML];
void mut(int a[],int b[],int flag){
 if(flag){
  for(int i = 0;i<N;++i) A[i] = C[i] = 0.0;
  for(int i = 0;i<m;++i) A[i] = a[i];
  fft(A,N,1);
  for(int i = 0;i<N;++i) C[i] = A[i]*A[i];
  fft(C,N,-1);
 }
 else{
  for(int i = 0;i<N;++i) A[i] = B[i] = C[i] = 0.0;
  for(int i = 0;i<m;++i) A[i] = a[i],B[i] = b[i];
  fft(A,N,1);fft(B,N,1);
  for(int i = 0;i<N;++i) C[i] = A[i]*B[i];
  fft(C,N,-1);
 }
 for(int i = 0;i<m;++i){
  a[i] = (int)((C[i].a/N)+0.5);
  a[i] %= 19;
 }
}
void pow(int a[],ll k){
 static int res[MM],t[MM];
 res[0] = -1;
 for(int i = 0;i<m;++i) t[i] = a[i];
 while(k){
  if(k & 1){
   if(res[0] == -1)    for(int i = 0;i<m;++i) res[i] = t[i];
  else mut(res,t,0);
  }
  k>>=1;
  if(k == 0) break;
  mut(t,t,1);
 }
 for(int i = 0;i<m;++i) a[i]= res[i];
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi,K = gi;
    for(int i = 0;i<m;a[i] = gi,++i);
    for(int i = 0;i<K;b[i] = gi,++i);
    for(N = 1;N<(m<<1);N<<=1);
    pow(b,n-1);
    mut(a,b,0);
    for(int i = 0;i<m;++i)
     printf(i==0?"%d":" %d",a[i]); 
    puts("");
    closeIO();
    return EXIT_SUCCESS;
}
