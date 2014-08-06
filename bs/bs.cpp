#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
int CountO,CountX,maxO,maxX;

int process(int x,int y,int z,int a)
{
 if(z <= 0 )
  return min(y,a);
 if(a <= 0)
  return min(x,z);

 int m = 0,ans = 0;
 m = y/(x+1),a;
 if(m < a)
  ans = y%(x+1);
 else
  m = a;

 return x+m*(x+1)+ans;
}
int main(int argc, char *argv[])
{
    freopen("bs.in","r",stdin);
    freopen("bs.out","w",stdout);
    while(scanf("%d%d%d%d",&CountO,&CountX,&maxO,&maxX) != EOF)
    {
     
     if(CountO > CountX)
      printf("%d\n",process(CountX,CountO,maxX,maxO));
     else
      printf("%d\n",process(CountO,CountX,maxO,maxX));
    }
    fclose(stdin);
    fclose(stdout);
    
    return EXIT_SUCCESS;
}
