#include "mode.h"
#include "data.h"
const int MN  = 100010,N = MN-10;
int n,x,k,d;

pii a[MN];
int b[MN];
int c[MN];
int f[MN];

int get(int x)
{
 int ans = 0;
 for(;x;x-=lb(x))
  ans = max(ans,c[x]);
 return ans;
}

void ins(int x,int y)
{
 for(;x<=N;x+=lb(x))
  c[x] = max(c[x],y);
}

int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    for(int i = 1;i<=n;++i)
    {
     char c = 0;while(c != 'N' && c != 'K') c = getchar();
     if(c == 'N') ++k;
     else
     {++d;a[d].X = gi;a[d].X -= k;a[d].Y = d;}
    }
    sort(a+1,a+1+d);
    int tmp = 0;
    for(int i = 1;i<=d;++i){
     if(a[i].X != a[i-1].X || i == 1)
      ++tmp;
     b[a[i].Y] = tmp;
    }
    for(int i = 1;i<=d;++i)
    {
    f[i] = get(b[i])+1;
    ins(b[i]+1,f[i]);
    }
    printf("%d\n",get(N)+k);
    closeIO();
    return EXIT_SUCCESS;
}
