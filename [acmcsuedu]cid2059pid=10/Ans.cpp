#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
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
int T;
int f[MAXN];
int main(int argc, char *argv[])
{
    setIO("2059");
    scanf("%d",&T);
    while(T--)
    {
     int N,M,L;
     scanf("%d%d%d",&N,&M,&L);
     for(int i = 1;i<=N;i++)
      scanf("%d",&a[i]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
