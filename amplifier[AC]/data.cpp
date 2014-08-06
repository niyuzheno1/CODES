#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;
const int MAXN = 10;
const int MAXV = 2*100000000;
int gi()
{
 int u = 0;
 int flag = rand()%2;
 int num = rand()%MAXV;
 if(flag)
  return -num;
 else
  return num;
}
int main(int argc, char *argv[])
{
    srand(time(0));
    freopen("amplifier.in","w",stdout);
    int n = abs(gi()%MAXN);
    printf("%d\n",n);
    for(int i = 1;i<=n;i++)
      printf("%d %d\n",gi()%MAXV,gi()%MAXV);
    printf("%d\n",abs(gi())%180);
    printf("%d\n",abs(gi())%100); 
    fclose(stdout);
    return EXIT_SUCCESS;
}
