#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define Release
using namespace std;
typedef long long int64;
const int64 MAXN = 10010,MOD = 1000000000+7;
void setIO(string x)
{
#ifndef Release
 string input = x+".in";
 string output = x + ".out";
 freopen(input.c_str(),"r",stdin);
 freopen(output.c_str(),"w",stdout);
#endif
}
void closeIO()
{
 fclose(stdin);
 fclose(stdout);
}
int64 T;
char str[MAXN];
int main(int argc, char *argv[])
{
    setIO("2059");
    scanf("%lld",&T);
    while(T--)
    {
     scanf("%s",&str[1]);
     int64 n = strlen(&str[1]);
     char last = 0;
     int64 len = 0;
     int64 ans = 1;
     for(int64 i = 1;i<=n+1;i++){
      if(str[i] == '?')
       len++;
      if(len == 1 && str[i] == '?')
       last = str[i-1];
      if(str[i] != '?' && len > 0)
      {
       if(str[i] == 0 || str[i]==last || last == 0)
        ans *= 1;
       else
        ans = (ans%MOD*(len+1)%MOD)%MOD;
       len = 0;last = 0;
      }
     }
     printf("%lld\n",ans%MOD);
    }
    closeIO();
    return EXIT_SUCCESS;
}
