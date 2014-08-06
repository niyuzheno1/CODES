#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
using namespace std;
typedef long long int64;
int64 gcd(int64 x,int64 y)
{
      if(y == 0)
       return x;
      return gcd(y,x%y);
}
int64 phi(int64 d)
{
  int64 x,y,i,k;
  x = rand()%d;
  y = x; k = 2;i=1;
  while(true)
  {
   i++;
   x = ((x*x)%d+1)%d;
   int64 m = gcd(y-x,d);
   if(m < d && m > 1)
    return m;
   
   if(m == d)
    return d;
   if(i == k)
   {
        y = x;
        k = 2*k;
   }
  }
}
int64 x;
multiset<int64> s;
map<int64,int64> m;
int main(int argc, char *argv[])
{
    srand(time(0));
    scanf("%I64d",&x);
    s.insert(x);
    bool flag = true;
    while(flag)
    {
     flag = false;
     for(multiset<int64>::iterator it = s.begin();it != s.end();it++){
      int64 u = phi(*it);
      if(u != *it && u != 1)
      {
       int64 v = *it/u;
       s.erase(*it);
       s.insert(u);
       s.insert(v);
       flag = true;
      }
     }
    }
    printf("%I64d=",x);
    for(multiset<int64>::iterator it = s.begin();it != s.end();it++)
     m[*it]++;
    for(multiset<int64>::iterator it = s.begin();it != s.end();it++){
     if(it != s.begin())
      printf("*");
     printf("%I64d^%I64d",*it,m[*it]);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
