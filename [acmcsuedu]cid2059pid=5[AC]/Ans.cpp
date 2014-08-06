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
int getint()
{
 int u = 0;
 char v = getchar();
 while(!isdigit(v))
  v = getchar();
 while(isdigit(v)){
  u *= 10;
  u += v-'0';
  v = getchar();
 }
 return u;
}
char getchare()
{
  char v = getchar();
  while(v != 'R' && v != 'U' && v != 'L' && v!= 'D' && v!='?' && v != '\n' && v != EOF)
   v= getchar();
  return v;
}
int T;
int p[6];
int main(int argc, char *argv[])
{
    setIO("2059");
    T = getint();
    while(T--)
    {
     memset(p,0,sizeof(p));
     char c = 0;
     while(c != '\n' && c!=EOF)
     {
      if(c == 'L')
       p[1]++;
      if(c == 'R')
       p[2]++;
      if(c == 'U')
       p[4]++;
      if(c == 'D')
       p[3]++;
      if(c == '?')
       p[5]++;
      c = getchare();
     }
     printf("%d %d %d %d\n",p[2]-p[1]-p[5],p[4]-p[3]-p[5],p[2]-p[1]+p[5],p[4]-p[3]+p[5]);
    }
    closeIO();
    return EXIT_SUCCESS;
}
