#include <cstdlib>
#include <iostream>

using namespace std;
#define maxn 100000
#define pt   1000000003LL
#define pv   200003
#define fl 147804523
long long ca[maxn],n;
long long h1[maxn],h2[maxn],hs2[pv];
int add(int x,int y)
{
    long long c = x % pv;
    c = c * 47 % pv;
     while(hs2[c] != 0 && h1[hs2[c]] != x)
     {
      c++;
      c %= pv;if(x == 0) c = 1;
     }
     if(hs2[c] == 0)
     {
      hs2[c] = y;
      return -1;
     }else
     return hs2[c];
}
bool t1(int x,int y)
{
     for(int i = 1;i<=n;i++)
     {
      int u = (x+i)%n;int v = (y+i)%n;
      if(u == 0)
       u = n;
      if(v == 0)
       v = n;
      if(ca[u] != ca[v])
       return false;
     }
     return true;
}
int main(int argc, char *argv[])
{
    scanf("%I64d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%I64d",&ca[i]);
    h1[0] = 0;
    long long big = 1;
    for(int i = 1;i<=n;i++){
     h1[0] = (h1[0]*fl%pt+ca[i])%pt;
     big *= fl;
     big %= pt;
    }
    for(int i = 1;i<=n;i++){
     h1[i] = (h1[i-1]*fl%pt+ca[i])%pt;
     h1[i] = (h1[i]+pt-(ca[i]*big)%pt)%pt;
    }
    for(int i = n;i>=1;i--)
     h2[0] = (h2[0]*fl%pt+ca[i])%pt;
    for(int i = n;i>=1;i--){
     h2[i] = (h2[((i+1) == n+1)? 0 : i+1]*fl%pt+ca[i])%pt;
     h2[i] = (h2[i]+pt-(ca[i]*big)%pt)%pt;
    }
    long long a = 0,b = 0;
    for(int i = 1;a == 0 && i<=n;i++)
     if((b = add(h1[i],i))!= -1)
      if(t1(b,i))
       a = i-b;
    if(a == 0)
     a = n;
    b = 0;
    int c = 0;
    for(int i = 1;i<=n;i++){
     if(h1[i] == h2[i])
     {
      b |= 1;
      c = i%a;
     }
     if(h1[i] == h2[i+1 == n+1 ? 1:i+1] && ((b & 1) == 0))
     {
      b |= 2;
      c = (i+1)%a;
     }
    }
    if(c == 0)
       c = a;
    if(b & 1)
     a = a/2+1;
    else if(b & 2)
     a = a/2;
    long long ans = 0;
    for(int i = 0;i<a;i++)
     ans += ca[(i+c)==n ? n :(i+c)%n];
    printf("%I64d",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
