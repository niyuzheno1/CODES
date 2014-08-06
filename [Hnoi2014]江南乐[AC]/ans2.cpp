#include "mode.h"

#define MN 100010
int t,f,sg[MN],vis[MN];

void initsg()
{
     for(int i = 0;i<f;++i) sg[i] = 0;
     for(int i = f;i<=100;++i)
     {
      int j = 0;
      for(j = 2;j<=i;++j)
      {
       int res = 0;
       int p = i/j;
       int q = i%j;
       int x = j-q;
       if(q&1) res ^= sg[p+1];
       if(x&1) res ^= sg[p];
       vis[res] = i;
      }
      for(j = 0;j<=INF;++j)
       if(vis[j] != i)
        break;
      sg[i] = j;
     }
}

int main()
{
    setIO("sample");
    scanf("%d%d",&t,&f);
    initsg();
    for(int i = 1,n;i<=t;++i){
            n = gi;
            int res = 0;
            for(int k = 1;k<=n;++k)
             res ^= sg[gi];
           printf(i == 1?"%d":" %d",res!=0);
    }
    closeIO();
    return EXIT_SUCCESS;
}
