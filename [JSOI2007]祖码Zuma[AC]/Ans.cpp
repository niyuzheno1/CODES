#include "mode.h"
#undef INF
#define INF 0x7f7f7f7f
const int MN = 510;
int f[MN][MN],rs[MN],b[MN],a[MN],n;
inline void dn(int & x,int y)
{
       x = min(x,y);
}
int solve(int x,int y)
{
 if(x > y) return INF;
 if(x == y) return f[x][x];
 if(f[x][y] != INF) return f[x][y];
 int res;
 if(a[x] == a[y]){
 res = solve(x+1,y-1); 
 dn(f[x][y],max(3-b[x]-b[y],0)+res);
 }
 for(int i = x;i<y;++i) dn(f[x][y],solve(x,i)+solve(i+1,y));
 return f[x][y];
}
int main(int argc, char *argv[])
{
    CLEAR(f,0x7f);
    setIO("sample");
    n = gi;
    int cnt = 0;
    a[0] = -INF;
    for(int i = 1,x;i<=n;++i){
     x = gi;
     if(a[cnt] != x){
      ++cnt;
      a[cnt] = x;
      b[cnt] = 1;
     }
     else ++b[cnt];
     f[cnt][cnt] = max(1,3-b[cnt]);
    }
    solve(1,cnt);
    printf("%d",f[1][cnt]);
    closeIO();
    return EXIT_SUCCESS;
}
