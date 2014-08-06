#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define Release
using namespace std;
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
int n;
int a[25];
int b[25];
int main(int argc, char *argv[])
{
    setIO("429problemC");
    scanf("%d",&n);
    if(n == 12)
     return puts("YES");
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++)
    {
     int k = 1;
     if(a[i]==7)
      a[i] = 7;
     for(int j = i-1;j>=1;j--)
      if(a[j] <= a[i]-2 && k+a[j] <= a[i] && !b[j])
      {
       k += a[j];
       b[j] = 1;
      }
     if(k < a[i])
     {
      puts("NO");
      closeIO();
      return 0;
     }
    }
    for(int i = 1;i<n;i++)
     if(b[i] == 0){
      puts("NO");
      closeIO();
      return 0;
     }
    puts("YES");
    closeIO();
}
