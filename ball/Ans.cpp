#include <cstdlib>
#include <iostream>

using namespace std;
struct int65
{
 int a[100];
 int65()
 {
  memset(a,0,sizeof(a));
 }
 int65 operator + (int65 x)
 {
   int65 m;
   for(int i = 1;i<=99;i++)
    m.a[i] = a[i]+x.a[i];
   for(int i = 1;i<=99;i++)
    if(m.a[i] >= 10)
    {
     m.a[i+1] += m.a[i]/10;
     m.a[i] %= 10;
    } 
    return m;
 }
 int65 operator * (int x)
 {
   int65 m;
   for(int i = 1;i<=99;i++)
    m.a[i] = a[i]*x;
   for(int i = 1;i<=99;i++)
    if(m.a[i] >= 10)
    {
     m.a[i+1] +=m.a[i]/10;
     m.a[i] %= 10;
    } 
  return m;
 }
 int65 operator = (int65 x)
 {
  memcpy(a,x.a,sizeof(a));
 }
 void print()
 {
  int x = 99;
  while(a[x] == 0 && x>0)
   x--;
 
  for(int i = x;i>=1;i--)
   printf("%d",a[i]);
  if(x == 0)
   printf("0");
 }
};
int65 mi[101][101];
int main(int argc, char *argv[])
{
    freopen("ball.in","r",stdin);
    freopen("ball.out","w",stdout);
    mi[0][0].a[1] = 1;
    for(int i = 1;i<=100;i++)
     for(int j = 1;j<=100;j++){
       mi[i][j] = mi[i-1][j]*j;
       mi[i][j] = mi[i][j]+mi[i-1][j-1];
       }
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF){
     mi[n][m].print(); 
     printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
