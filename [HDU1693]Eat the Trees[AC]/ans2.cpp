#include "mode.h"
#define MN 13
int64 f[MN][MN][1<<(MN+1)],ans;
int a[MN][MN];
int U ;
inline void sh(int & x)
{
  x<<=1;x&=U;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int iCase = 0,T = gi;
    while(T--){
    printf("Case %d: ",++iCase);
    CLEAR(a,0);CLEAR(f,0);ans = 0;
    int n=gi,m=gi;
    f[0][m][0] = 1;
    for(int i = 1;i<=n;++i) for(int j = 1;j<=m;++j) a[i][j] = gi;
    U = (1<<(m+1))-1;
    for(int i = 0;i<=n;++i)
     for(int j = (i==0)?m:1;j<=m;++j)
     {
      for(int k = 0;k<=U;++k)
      {
       if(!f[i][j][k])continue;
       int now = k;
       int u1 = (now & (1<<j));
       int u2 = (now & (1<<(j-1)));
       if(a[i][j] == 0)
       {
        if(u1) now ^= (1<<j);
        if(u2)now ^= (1<<(j-1));
        if(j == m) sh(now),f[i+1][1][now] += f[i][j][k];
        else f[i][j+1][now] += f[i][j][k];
       }else{
        if(u1 && u2)
        {
         now ^= (1<<j),now ^= (1<<(j-1));
         if(j == m) sh(now),f[i+1][1][now] += f[i][j][k];
         else f[i][j+1][now] += f[i][j][k];
        }
        else if(u1 || u2)
        {
             if(u1) now ^= (1<<j);
             if(u2) now ^= (1<<(j-1));
             if(a[i][j+1])
             {
              int nowp = now^(1<<j);
              f[i][j+1][nowp] += f[i][j][k];
             }
             if(a[i+1][j])
             {
              int nowp = now^(1<<(j-1));
              if(j == m ) sh(nowp),f[i+1][1][nowp] += f[i][j][k];
              else f[i][j+1][nowp] += f[i][j][k];
             }
        }
        else
       {
           if(!u1) now ^= (1<<j);
           if(!u2) now ^= (1<<(j-1));
           if(a[i][j+1] && a[i+1][j])
           {
            f[i][j+1][now] += f[i][j][k];
           }
       }
       }
       
      }
     }
    for(int i = 0;i<=U;++i)
     ans += f[n+1][1][i];
    printf("There are %I64d ways to eat the trees.",ans);
    puts("");
    }
    closeIO();
    
    return EXIT_SUCCESS;
}
