#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const int delta = 7;
int n;
double a[29][29];
int main(int argc, char *argv[])
{
    freopen("numbers1.in","r",stdin);
    freopen("change.in","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     for(int j = 1;j<=28;j++)
       for(int k = 1;k<=28;k++)
        scanf("%lf",&a[j][k]);
     double average = 0;
     for(int j = 1;j<=28;j++)
      for(int k = 1;k<=28;k++)
      {
       double u = 0;
       for(int p = max(j-delta,0);p<=min(j+delta,28);p++)
        for(int q = max(k-delta,0);q<=min(k+delta,28);q++)
         u+=sqr(a[p][q]-a[j][k]);
       u/=double(sqr(2*delta+1));
       average += u;
      }
     printf("%lf\n",sqrt(average));
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
