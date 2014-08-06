#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define sqr(x) ((x)*(x))
using namespace std;
int delta = 1;
double a[30][30];
FILE * d;
int main(int argc, char *argv[])
{
    int n = 0;
	freopen("numbers1.in","r",stdin);
	freopen("table1.out","w",stdout);
    d = fopen("table2.txt","r");
    scanf("%d",&n);
    n = 1000;
    printf("{");
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
       /*
       u = sqr(a[j][k]);*/
       average += u;
      }
     average = sqrt(average);
     if(i != n)
     printf("%lf,",average);
     else
     printf("%lf",average);
    }
    printf("}");
    fclose(stdin);fclose(stdout);fclose(d);
    return EXIT_SUCCESS;
}
