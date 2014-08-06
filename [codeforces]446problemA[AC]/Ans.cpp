#include "mode.h"
#define MN 100002
int n,m,res[MN][2],x[MN];
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 0;i<n;++i) x[i] = gi;
    int ans = min(2,n),cur=  0;
    for(int i = n-1;i>=0;--i){
     for(int t = 0;t<2;++t)
     {
      res[i][t] = 1;
      if(i+1<n && x[i]<x[i+1])
       res[i][t] += res[i+1][t];
     }
     if(i + 2 < n && x[i]+2<=x[i+2])
      res[i][1] = max(res[i][1],res[i+2][0]+2);
     ans = max(ans,max(res[i][0],res[i][1]));
     cur = max(cur,res[i][0]);
    }
    if(cur < n)++cur;
    ans = max(ans,cur);
    printf("%d\n",ans);
    closeIO();
    return EXIT_SUCCESS;
}
