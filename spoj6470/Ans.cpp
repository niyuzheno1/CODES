#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 100000000;
int a[5000100],tot;
int b[100000010];
void pre()
{
 memset(b,1,sizeof(b));
 b[1] = 0;b[2] = 1;
 int j = 2;
 while(tot<=5000000)
 {
  while(b[j] ==0)
   j++;
  tot++;a[tot] = j;
  for(int i = j;i<=maxn;i+=j)
   b[i] = 0;
  j++;
 }
}
int main(int argc, char *argv[])
{
    pre();
    freopen("TDKPRIME.in","r",stdin);freopen("TDKPRIME.out","w",stdout);
    int Q;scanf("%d",&Q);
    while(--Q)
    {
     int x;scanf("%d",&x);
     printf("%d\n",a[x]);
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
