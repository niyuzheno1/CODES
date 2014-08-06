#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
int64 A,B;
int64 gcd(int64 x,int64 y)
{
    if(y == 0)
     return x;
    if(x < y)
     return gcd(y,x);
    return gcd(y,x%y);
}
int64 n,ans;
int64 m[10];
int64 f[10];
void dfs(int64 x,int64 y,int64 d,int64 u)
{
    if(x == 0)
    {
     if(d < n || u < ans)
     {
      n = d;
      ans = u;
      for(int64 i = 1;i<=d-1;i++)
       f[i] = m[i];
     }
     return;
    }
    if(d >= n)
     return;
    for(m[d] = u+1;m[d] <= min(y,ans);m[d]++)
    {
     int64 nx = x*m[d]-y;
     if(nx < 0)
      continue;
     int64 ny = y*m[d];
     int64 gc = gcd(nx,ny);
     nx /= gc;ny /= gc;
     if(ny > ans)
      continue;
     dfs(nx,ny,d+1,max(u,m[d]));
    }
}
int main(int argc, char *argv[])
{
    freopen("egpyt.in","r",stdin);
    freopen("egpyt.out","w",stdout);
    n = 6;
    ans = 0x7f7f7f7f;
    scanf("%I64d%I64d",&A,&B);
    int mm = gcd(A,B);
    A/=mm;B/=mm;
    dfs(A,B,1,0);
    printf("%I64d\n",n-1);
    for(int64 i = 1;i<=n-2;i++)
     printf("%I64d ",f[i]);
    printf("%I64d\n",f[n-1]);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
