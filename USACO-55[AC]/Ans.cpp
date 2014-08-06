#include <cstdlib>
#include <iostream>

using namespace std;
int n,m;
int f[1010*2];
int gf(int x)
{
    if(x == f[x])
     return x;
    return (f[x]=gf(f[x]));
}
int main(int argc, char *argv[])
{
    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=2*n;i++)
     f[i] = i;
    bool flag = 0;
    for(int i = 1;i<= m;i++){
     int x,y;char z[10];
     scanf("%d%d%s",&x,&y,z);
     if(z[0] == 'T')
     {
      f[gf(x)] = f[gf(y)];
      f[gf(n+x)] = f[gf(n+y)];
     }
     else
     {
      f[gf(n+x)] = f[gf(y)];
      f[gf(n+y)] = f[gf(x)];
     }
     for(int j = 1;j<=n;j++)
      if(f[j] == f[n+j]){
       printf("%d\n",i-1),i=m+1;
       flag = 1;
       break;
      }
    }
    if(!flag)
     printf("%d",m);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
