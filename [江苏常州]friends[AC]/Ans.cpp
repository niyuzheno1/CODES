#include "mode.h"

#define md INF
#undef v
#undef int65
struct int65
{
 long long v;
 int65()
 {
        v=0;
 }
 int65(int64 _v)
 {
  while(_v > md) _v %= md;
  while(_v < 0) _v += md;
  v = _v;
 }
 int65 operator * (int65 p)
 {
  return int65((v*p.v)%md);
 }
 int65 operator + (int65 p){
  return int65((v+p.v)%md);
 }
 int65 operator - (int65 p){
  return int65((v-p.v)%md);
 }
 bool operator == (int65 p){
  return v == p.v;
 }
};
int64 n;
#define p 79
const int64 MN = 2000001;
char a[MN];
int65 pow[MN];
int65 pre[MN],b[2];
int65 getnew(int l,int r)
{
      if(r < l) return int65(0);
      else
       return pre[r]-pre[l-1]*pow[r-l+1];
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    if(n % 2 == 0){
          printf("NOT POSSIBLE\n");closeIO();return 0;
    }
    bool unique = true;
    scanf("%s",a+1);
    pow[0].v = 1;
    for(int i = 0;i<=n;++i)
     pow[i+1] = pow[i]*int65(p);
    for(int i = 1;i<=n;++i) pre[i] = (pre[i-1]*int65(p)+int65(a[i]));
    b[0] = pre[n/2];
    b[1] = (pre[n]-((pre[n/2+1])*(pow[n/2])));
    int ans = 0;
    if(b[0] ==b[1]){printf("%s",&a[n/2+2]); closeIO();return 0;}
    for(int i = 1;i<=n/2;++i)
     if(getnew(1,i-1)*pow[n/2-i+1]+getnew(i+1,n/2+1)==b[1])
      ans = ans? (unique = false):i;
    for(int i = n/2+2;i<=n;++i)
     if(getnew(n/2+1,i-1)*pow[n-i]+getnew(i+1,n) == b[0])
      ans = ans? (unique = false):i;
    if(unique){
     if(ans == 0)
      printf("NOT POSSIBLE");
     else if(ans <= n/2+1)
      printf("%s",&a[n/2+2]);
     else 
      for(int i = 1;i<=n/2;++i) printf("%c",a[i]);
     puts("");
    }
    else printf("NOT UNIQUE\n");
    closeIO();
    return EXIT_SUCCESS;
}
