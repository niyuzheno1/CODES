#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define sqr(x) ((x)*(x))
#define ff fprintf
#define X first
#define Y second
using namespace std;
typedef pair<double,int> p;
const int MAXN = 3010;
const double eps = 10e-2;
double a[29][29];
double b[MAXN];
int c[MAXN],n;
int delta,bestdiff,bestdelta,diff;
FILE * d,*r;
vector<p> v;
bool cmp(double x,double y)
{
 if(abs(y-x)<eps)
  return 0;
 else
  return 1;
}
int main(int argc, char *argv[])
{
    bestdiff = 0x7f7f7f7f;
    freopen("table1.txt","w",stdout);
    d = fopen("table2.txt","r");r = fopen("debug.txt","w");
    n = 2999;
    for(int i = 1;i<=n;i++)
     fscanf(d,"%d",&c[i]);
    for(delta = 1;delta<=14;delta++)
    {
     v.clear();
     freopen("numbers1.in","r",stdin);
     scanf("%d",&c[0]);
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
     b[i] = sqrt(average);
     }
     diff = 0;
     for(int i = 1;i<=n;i++)
      v.push_back(p(b[i],c[i]));
     sort(v.begin(),v.end());
     int tmp  = 0x7f;
     double last = 0;
     for(int i = 0;i<v.size();i++){
      if(cmp(v[i].X,last)==0 && tmp != v[i].Y)
      {
       tmp = v[i].Y;
       diff++;
      }
      last = v[i].X;
     }
     if(diff < bestdiff)
     {
      bestdiff = diff;
      bestdelta = delta;
     }
     fclose(stdin);
    }
    ff(r,"bestdelta:%d\n",bestdelta);
    ff(r,"bestdiff:%d\n",bestdiff);
    delta = bestdelta;
    for(int idx = 0;idx<1;idx++)
    {
     v.clear();
     freopen("numbers1.in","r",stdin);
     scanf("%d",&c[0]);
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
     printf("%lf\n",sqrt(average));
     }
     
     fclose(stdin);
    }
    fclose(stdout);fclose(d);fclose(r);
    return EXIT_SUCCESS;
}