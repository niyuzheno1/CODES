#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXBLOCK = 10100;
template <class T>
class mem
{
public:
 int used,m;
 T p[MAXBLOCK];
 T * u[MAXBLOCK];
 T * add()
 {
  T * ret = 0;
  if(used)
  {ret = u[used];used--;} 
  else{m++;ret = &u[m];}
  return ret;
 }
 void dec(T * v)
 {
  used++;
  u[used] = v;
  return;
 }
};
int main(int argc, char *argv[])
{
    system("PAUSE");
    return EXIT_SUCCESS;
}
