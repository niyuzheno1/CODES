#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
const int d = 100001;
struct c
{
 int l,r;
};
c p[50010];
int f[50010][3];
int k,s;
struct seg
{
 int m;
 struct note
 {
 };
 note a[d*4];
 void init()
 {
 }
 void b(int x,int y,int z)
 {
 }
 int f(int x)
 {
      return 0;
 }
};
seg o;
int main(int argc, char *argv[])
{
    scanf("%d%d",&k,&s);
    for(int i = 1;i<=k;i++){
     scanf("%d%d",&p[i+1].l,&p[i+1].r);
     p[i+1].l += d;
     p[i+1].r += d;
    }
    for(int i = 1;i<=k;i++)
    {
     int l = o.f(p[i+1].l);
     int r = o.f(p[i+1].r);
     if(l == 0)
      f[i+1][1] = p[i+1].l*2;
     else
      f[i+1][1] = min(f[l][1]+abs(p[l].l-p[i+1].l),f[l][2]+abs(p[l].r-p[i+1].l));
     o.b(p[i+1].l,p[i+1].r,i);
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
