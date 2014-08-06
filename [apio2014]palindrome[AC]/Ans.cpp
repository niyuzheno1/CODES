#include "mode.h"
#include "str.h"
#define MN 300003
#define MC 600006
typedef pii pi;
typedef long long ll;
const int ba = 233;
char s[MN],t[MC];
int n,tn,d[MC];
pi d1[MN],d2[MN];
int b[MN],bn,L[MN],R[MN],st[MN],stn;
int h[MN],p[MN];
void pre() {
      p[0] = 1;
      for(int i  =1;i<=n;++i)
       p[i] = p[i-1]*ba;
      int hh = 0;
      for(int i = 0;i<n;++i){
       hh = hh*ba+s[i]-'a'+1;
       h[i] = hh;
      }
}
inline void manachers(){
       tn = 0;
       t[tn++] = '*';
       for(int i = 0 ;i<n;++i)
        t[tn++] = s[i],t[tn++] = '*';
       int j = 0;
       for(int i = 0;i<tn;++i){
         d[i] = 0;
         if(j + d[j] > i)
          d[i] = min(j+d[j]-i,d[2*j-i]);
         while(i + d[i] < tn && i - d[i] >= 0 && t[i+d[i]] == t[i-d[i]])
          ++d[i];
         if(i + d[i] > j + d[j])
          j = i;
       }
       for(int i = 0;i<n;++i){
        int j = 2*i+1;
        d1[i].X = i,d1[i].Y = d[j]/2;
        d2[i].X = i,d2[i].Y = d[j-1]/2;
       }
}
inline ll calc(int odd,pi a[]){
   ll res = 0;
   cmpSA comp;
   comp.hl = h;comp.p = p;comp.s = s;
   sort(a,a+n,comp);
   bn = 0;
   for(int i = 0;i<n;++i){
     res = max(res,(2ll*a[i].Y-odd));
     if(i < n-1)
      b[bn++] = comp.slcp(a[i],a[i+1]);
   }
   stn = 0;
   for(int i = 0;i<bn;++i){
    while(stn > 0 && b[st[stn-1]] >= b[i])
     --stn;
    L[i] = stn > 0 ? st[stn-1] : -1;
    st[stn++] = i;
   }
   stn = 0;
   for(int i = bn-1;i>=0;--i){
    while(stn > 0 && b[st[stn-1]]>=b[i])
     --stn;
    R[i] = stn > 0 ?st[stn-1] : bn;
    st[stn++] = i;
   }
   for(int i = 0;i<bn;++i)
    res = max(res,(2ll*b[i]-odd)*(R[i]-L[i]));
   return res;
}
int main(int argc, char *argv[])
{
    setIO("palindrome");
    gets(s);
    n = strlen(s);
    pre();
    manachers();
    ll res = max(0ll,calc(1,d1));
    res = max(res,calc(0,d2));
    printf("%d\n",res);
    closeIO();
    return EXIT_SUCCESS;
}
