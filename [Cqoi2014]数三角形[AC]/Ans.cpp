#include "mode.h"
int n , m ;
long long c[1001*1001+1][4],ans,tmp;
int gcd(int a,int b){
 return b==0?a:gcd(b,a%b);
}
void calc(){
 c[0][0] = 1;
 for(int i = 1;i<=n*m;++i) c[i][0] = 1;
 for(int i = 1;i<=n*m;++i){
  for(int j = 1;j<=3;++j) c[i][j] = c[i-1][j]+c[i-1][j-1];
 }
}
void solve(){
 ans = c[n*m][3];
 ans -= n*c[m][3];
 ans -= m*c[n][3];
 for(int i = 1;i<n;++i)
  for(int j = 1;j<m;++j){
   int tmp = gcd(i,j)+1;
   if(tmp > 2) ans -= (tmp-2)*2*(n-i)*(m-j);
  }
 printf(I64D,ans);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m= gi;++n,++m;
    calc();solve();
    closeIO();
    return EXIT_SUCCESS;
}
