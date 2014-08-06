#include "mode.h"
#define MN 100005
int t,f,sg[MN],vis[MN];
void initsg()
{
     for(int i = 0;i<f;sg[i] = 0,++i);
     for(int i = f;i<=MN-5;++i){
      for(int l = 2,last=  0;l<=i;l=last+1){
       last = i/(i/l);
       int p = i/l,q = i%l,isq=l-q;
       vis[sg[(q&1)*(p+1)]^sg[(isq&1)*p]] = i;
       if(q >= p && l+p+1-q>=0)
        vis[sg[((q-p)&1)*(p+1)]^sg[((l+p+1-q)&1)*p]] = i;
      }
      int j = 0;
      for(;;++j) if(vis[j] != i) break;
      sg[i] = j;
     }
}
int main(int argc, char *argv[])
{
    setIO("sample");
    t = gi, f = gi;
    initsg();
    for(int j = 1;j<=t;++j){
     int n = gi,res = 0;
     for(int i = 1;i<=n;res^=sg[gi],++i);
     printf(j == 1 ? "%d" : " %d" ,res!=0);
    }
    closeIO();
    return EXIT_SUCCESS;
}
