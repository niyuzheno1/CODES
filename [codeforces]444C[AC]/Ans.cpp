#include "mode.h"
typedef int64 LL;
const LL li = 320;
#define MQ 325 
#define MN 200010
LL st[MQ],ty[MQ],ct[MQ],tg[MQ],a[MN],cg[MN];
int n,m,l,r,x;
void work1(){
 l = gi,r = gi,x = gi;
 for(int i = 1;i<=li;++i){
   int L=li*(i-1)+1,R=li*i;
   if(l <= L && R <= r){
        if(st[i] == 0){
        for(int j = L;j<=R;++j) ct[i] += abs(a[j]-x),cg[j] += abs(a[j]-x);
        ty[i] = x;
        st[i] = 1;
        }else {
        tg[i] += abs(x-ty[i]);
        ct[i] += li*abs(x-ty[i]);
        ty[i] = x;
        }
   }else if(!((l>R||r<L))){
    if(st[i] == 1){
     for(int j = L;j<=R;++j) a[j] = ty[i];
     st[i] = 0;
    }
    if(l > L) L = l;
    if(r < R) R = r;
    for(int j = L;j<=R;++j){
     ct[i] += abs(a[j]-x);
     cg[j] += abs(a[j]-x);
     a[j] = x;
    }
   }
 }
}

void work2(){
 l = gi,r = gi;
 LL ans = 0;
 for(int i = 1;i<=li;++i)
 {
  int L = li*(i-1)+1,R = li*i;
  if(l <= L && R <= r)
   ans+=ct[i];
  else if(!(l>R ||r < L)){
   if(l > L) L = l;
   if(r < R) R = r;
   for(int j = L;j<=R;++j)
    ans += tg[i]+cg[j];
  }
 }
 
 printf(I64D,ans);puts("");
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    for(int i = 1;i<=170000;a[i] = i,++i);
    for(int h = 1;h<=m;++h){
     int tp = gi;
     if(tp == 1) work1();
     else work2();
    } 
    closeIO();
    return EXIT_SUCCESS;
}
