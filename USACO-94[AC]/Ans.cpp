#include <cstdlib>
#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
typedef long long int64;
int64 n,l;
typedef multiset<int64> ms;
ms s;
int64 w[100010],h[100010];
int64 dp[100010],sa[100010];
int64 * sb;
int main(int argc, char *argv[])
{
    freopen("bookshelf.in","r",stdin);
    freopen("bookshelf.out","w",stdout);
    scanf("%I64d%I64d",&n,&l);
    for(int64 i = 1;i<=n;i++)
     scanf("%I64d%I64d",&h[i],&w[i]);
    sb = sa;
    int64 tp = 0,sm = 0;
    int64 j = 1;
    for(int64 i = 1;i<=n;i++)
    {
     for(sb[tp++]=1;tp-2>=0&&h[i-sb[tp-1]] <= h[i];tp--)
     {
     s.erase(dp[i-sb[tp-1]-sb[tp-2]]+h[i-sb[tp-1]]);
     sb[tp-2] += sb[tp-1];
     }
     s.insert(dp[i-sb[tp-1]]+h[i]);
     sm += w[i];
     for(;sm>l;j++)
     {
      sm-=w[j];
      s.erase(dp[j-1]+h[j+sb[0]-1]);
      if(--sb[0] == 0){
      sb++;
      tp--;
      }
      else
       s.insert(dp[j]+h[j+sb[0]]);
     }
     dp[i] = (*s.begin());
    }
    printf("%I64d",dp[n]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
