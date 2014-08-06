#include "mode.h"
#undef INF
#define INF 102345678900000LL
#define N 100000
int ma[N][20][20];
long long best = INF;
int a[18]; 
int n,b[N];
void check(int m)
{
 long long ret = 0;
 for(int i = m;i>=0;--i)
  ret = ret *10+a[i];
 if(ret < best) best = ret;
}

void dfs(int x,int y,bool z)
{
     int d,ny,nz;
     if(y == 1)
     {
      int dd = x;
      for(int i = 9;i>=1;--i)
       if(ma[0][i][x])
        a[dd] = i,++dd;
      if(ma[0][0][x])
      {
       if(dd <= x) a[dd] = 1,++dd;
       a[dd] = a[dd-1],a[dd-1] = 0,++dd;
      }
      if(dd == 0 || (x == dd && z))
       a[dd] = 1,++dd;
      check(dd-1);
     }
     else if(y == 2)
     {
      for(int j = 0;j<=9;++j)
      {
       a[x] = j;
       d = j;
       ny = 0;nz = false;
       if(j == 0 && ma[0][0][x] == 1) nz = true;
       for(int k = 0;k<=9;++k) ma[ny][k][x+1] = 0;
       for(int i = 0;i<y;++i)
       {
        for(int k = 0;k<=9;++k)
         if(ma[i][k][x] && k != d)
          ma[ny][k][x+1] = 1;
        d = (d+1)%10;
       }
       dfs(x+1,1,nz);
      }
     }
     else
     {
      for(int j = 0;j<=9;++j)
      {
       a[x] = j;
       d = j;
       ny = 0;
       nz = false;
       if(j == 0 && ma[0][0][x] == 1) nz = true; 
       for(int k = 0;k<=9;++k) ma[ny][k][x+1] = 0;
       for(int i = 0;i<y;++i)
       {
        for(int k = 0;k<=9;++k)
         if(ma[i][k][x] && k != d)
          ma[ny][k][x+1] = 1;
        d = (d+1)%10;
        if(d == 0 && i < y-1)
        {
         ++ny;
         for(int k = 0;k<10;++k) ma[ny][k][x+1] = 0;
        }
       }
       dfs(x+1,ny+1,nz);
      }
     
     }
}

long long gans()
{
 for(int i = 0 ;i<n;++i)
 {
  for(int j = 0;j<10;++j) ma[i][j][0] = 0;
  ma[i][b[i]][0] = 1;
 }
dfs(0,n,true);
return best;
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 0;i<n;++i) b[i] = gi;
    printf(I64D,gans());
    closeIO();
    return EXIT_SUCCESS;
}
