#include "mode.h"
#define MN 152
#define MM 5050
#define MHP 10010
#define eps 1e-9
#undef ff
#define uf fprintf
double x[MN][MN],y[MN][MN];
double f[MHP][MN];
double ff[MN];
int a[MN],d[MN],first[MN];
int last[MM*2],next[MM*2];
int n,m,hp,tot;
double ans;
void insert(int x,int y){
 if(x == n) return;
 ++tot;last[tot] = y;next[tot] = first[x];first[x] = tot;++d[x];
}

void work()
{
    for(int i = 1;i<=n;++i)
     for(int j = first[i];j;j=next[j])
             if(a[last[j]] == 0) 
				 x[last[j]][i] = x[last[j]][i]-1.0/d[i];
    for(int i = 1;i<=n;++i) ++x[i][i];
    for(int i = 1;i<=n;++i) y[i][i] = 1.0;
    //down process
    for(int i = 1;i<n;++i)
    {
    int j;
    for(j =i;j<=n;++j)
      if(abs(x[j][i]) > eps) break;
    for(int k = 1;k<=n;++k) swap(x[i][k],x[j][k]);
    for(int k = 1;k<=n;++k) swap(y[i][k],y[j][k]);
    for(int j = i+1;j<=n;++j)
     if(abs(x[j][i]) > eps){
      double s = x[j][i]/x[i][i];
      for(int k = 1;k<=n;++k) x[j][k] = x[j][k]-x[i][k]*s;
      for(int k = 1;k<=n;++k) y[j][k] = y[j][k]-y[i][k]*s;
     }
    } 
    //up process 
    for(int i = n;i>=2;--i)
     for(int j = 1;j<=i-1;++j)
      if(abs(x[j][i]) > eps)
      {
       double s = x[j][i]/x[i][i];
       for(int k = 1;k<=n;++k) x[j][k] = x[j][k] - x[i][k]*s;
       for(int k = 1;k<=n;++k) y[j][k] = y[j][k] - y[i][k]*s;
      }
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=n;++j)
      y[i][j] = y[i][j]/x[i][i];
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi, hp = gi;
    for(int i = 1;i<=n;++i) a[i] = gi;
    for(int i = 1;i<=m;++i)
    {
     int x,y;
     x = gi,y = gi;
     if(x != y) insert(x,y);
     insert(y,x);
    }
    work();
    f[hp][1] = 1;
    for(int i = hp;i>=1;--i)
    {
        memcpy(ff,f[i],sizeof(ff));
        ans = ans + ff[n];ff[n] = 0;
        for(int j = 1;j<=n;++j) f[i][j] = 0;
        for(int j = 1;j<=n;++j)
         for(int k = 1;k<=n;++k)
          f[i][j] = f[i][j] + ff[k]*y[j][k];
        ans = ans + f[i][n];f[i][n] = 0;
        for(int j = 1;j<=n;++j)
         for(int k = first[j];k;k=next[k])
         {
                  if(i-a[last[k]] > 0  && a[last[k]]>0)
                   f[i-a[last[k]]][last[k]] = f[i-a[last[k]]][last[k]] + f[i][j]/d[j]; 
         } 
    }
    printf("%.8f",ans);
    closeIO();
    return EXIT_SUCCESS;
}
