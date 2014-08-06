
#include "mode.h"
#define MN 1010
typedef long long LL;
typedef pair<LL,LL> pLL;
const LL p[] = {100000007,6012121,1000003};
LL a[MN],n;
vector<pLL> b;
void s1(LL x)
{
     b.clear();
     x = abs(x);
     for(LL i = 2;i*i<=x;++i)
      if(x % i == 0)
      {
       LL c,d;c=i,d=1,x /= i;
       while(x % i == 0) x /= i,++d;
       b.pb(MP(c,d));
      }
     if(x != 0)
      b.pb(MP(x,1));
}
bool check(LL u)
{
     if(((a[0]/u+a[1])%u)==0) return 1;
     return 0;
}
bool check2(LL u,LL pr)
{
     LL res = 0;
     for(int i = n;i>=0;--i)
      res = (((res%pr)*(u%pr))%pr+(a[i]%pr))%pr;
     if(res == 0)
      return 1;
     return 0;
}
LL dfs(LL x,LL y)
{
  if(x == b.size())
  {
    if(check(y) && check2(y,p[0]) && check2(y,p[1]) && check2(y,p[2]))
     return 1;
    if(check(-y) && check2(-y,p[0]) && check2(-y,p[1]) && check2(-y,p[2]))
     return 1;
    return 0;
  }
  int flag = 0;
  LL now = 1;
  for(LL i = 0;i<=b[x].Y && !flag;++i)
  {
   flag = dfs(x+1,y*now);
   now = now * b[x].X;
  }
  return flag;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    int T = gi;
    while(T--)
    {
     n = gi;
     for(int i = 0;i<=n;++i) a[i] = gi;
     if(a[0] == 0){ puts("Yes");continue;}
     s1(a[0]);
     int flag = dfs(0,1);
     puts(flag==1?"Yes":"No");
    }
    closeIO();
    return EXIT_SUCCESS;
}
