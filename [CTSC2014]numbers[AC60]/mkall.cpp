#include <cstdlib>
#include <iostream>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const int MAXM = 3000;
int n,m;
struct p{
double a[29][29];
int u;
};
p a[MAXM];
p formal;
double v;
double dis(p u,p vv)
{
 double ret = 0;
 for(int i = 1;i<=28;i++)
  for(int j = 1;j<=28;j++){
   ret += sqr(u.a[i][j]-vv.a[i][j]);
   if(sqrt(ret) > v)
    return sqrt(ret);
  }
 return sqrt(ret);
}

void cmp(p x,int po)
{
 double u = dis(x,formal);
 if(u < v){
  v = u;
  a[0].u = po;
 }
}
FILE * r;
int main(int argc, char *argv[])
{
    m = 2999;
    freopen("numbers1.in","r",stdin);
    freopen("numbers1.out","w",stdout);
    scanf("%d",&n);
    r = fopen("table2.txt","r");
    for(int i = 1;i<=m;i++)
    {
     int x;fscanf(r,"%d",&x);
     a[i].u = x;
     for(int j = 1;j<=28;j++)
      for(int k = 1;k<=28;k++)
       scanf("%lf",&a[i].a[j][k]);
    }
    freopen("numbers1.in","r",stdin);
    scanf("%d",&n);
    printf("%d\n",n);
    for(int i = 1;i<=n;i++)
    {
     double start,end = 0;
     start = clock();
     for(int j = 1;j<=28;j++)
      for(int k = 1;k<=28;k++)
       scanf("%lf",&formal.a[j][k]);
     a[0].u = 1;
     v = 10e7;
     for(int k = 1;k<=50;k++){
      int j = rand()%2999+1;
      cmp(a[j],j);
     }
     end = clock();
     double stime = (end-start)/CLK_TCK;
     printf("%d\n",a[a[0].u].u);
    }
     
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
