#include "mode.h"
#include "mathlab.h"
const int MAXN  = 100010;
int gc(int x,int y)
{ return gcd<int>(x,y); }
int a[4*MAXN],n,m,tot;
typedef map<int,vector<int> > mp;
typedef mp::iterator itor;
mp hash;
char getstr()
{
 char c = ' ';
 while(c == ' ' || c == '\n') c = getchar();
 return c;
}
void update(int x)
{
 for(x>>=1;x;x>>=1)
 {
  a[x] = 0;
  if(a[2*x] != 0)
   a[x] = gc(a[x],a[2*x]);
  if(a[2*x+1] != 0)
   a[x] = gc(a[x],a[2*x+1]);
 }
}
void inc(int x)
{
 tot++;
 hash[x].push_back(tot);
 a[m+tot] = x;
 update(m+tot);
}
void dec(int x)
{
 int u = (*hash[x].begin());
 hash[x].erase(hash[x].begin());
 a[m+u] = 0;
 update(m+u);
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi;
    m = 1;
    while(m <= n) m*=2;
    for(int i = 1;i<=n;++i)
    {
     char op;
     op = getstr();
     int x = gi;
     if(op == '+')
      inc(x);
     else
      dec(x);
     printf("%d\n",a[1]==0?1:a[1]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
