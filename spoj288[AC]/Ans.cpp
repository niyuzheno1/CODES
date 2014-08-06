#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long int64;
int64 pow(int64 x,int64 y,int64 z)
{
 int64 a = 1,b=a;
 while(y > 0){
  if(y & 1) x = (a%z*b%z)%z;
  b = (b%z*b%z)%z;
  y>>=1;
 }
 return a;
}
bool test(int64 x,int64 y)
{
  if(x == 1) return false;
  if(x == 2) return true;
  if((x&1) == 0) return false;
  int64 s = x-1;
  while((s&1)==0) s>>=1;
  while(y--)
  {
   int64 u = rand()%(x-1)+1;
   int64 tmp = s;
   int64 po = pow(u,tmp,x);
   if(po == 1 || po == -1)
    continue;
   while((s != x-1) &&(po != x-1)){
    po = (po%x*po%x)%x;
    s<<=1;
   }
   if(po != x-1)
    return false;
  }
  return true;
}
int main(int argc, char *argv[])
{
    srand(time(0));
    //freopen("spoj288.in","r",stdin);freopen("spoj288.out","w",stdout);
    int64 T;
    scanf("%lld",&T);
    while(T--)
    {
     int64 x;scanf("%lld",&x);
     printf("%s\n",test(x,18)?"YES":"NO");
    }
    //fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
