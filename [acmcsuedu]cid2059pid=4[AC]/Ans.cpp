#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
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
int main(int argc, char *argv[])
{
    setIO("2059");
    int T;
    scanf("%d",&T);
    while(T--)
    {
     int n,x,y,a;
     int m = 0;
     scanf("%d%d%d",&n,&x,&y);
     for(int i = 1;i<=n;i++){
      scanf("%d",&a);
      if(i == 1 && a == x)
       m |= 1;
      if(i == n && a == y)
       m |= (1<<1);
     }
     if(m == 0)
      puts("OKAY");
     if(m == 1)
      puts("EASY");
     if(m == 2)
      puts("HARD");
     if(m == 3)
      puts("BOTH");
    }
    closeIO();
    return EXIT_SUCCESS;
}
