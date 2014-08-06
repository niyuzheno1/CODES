#include <cstdlib>
#include <iostream>

using namespace std;

int q[10001];
int n,a,b,d;
char c[10001];
int pow(int a)
{
 int b = 1;
 for(int i = 0;i<d;i++)
  if(c[i] == '1'){
   b = (b*b)%10000;
   b = (b*a)%10000;
  }
  else
   b = (b*b)%10000;
 return b;
 
}
int main(int argc, char *argv[])
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    scanf("%d",&n);
   
    for(int i = 1;i<=n;i++)
    {
     memset(&q,0,sizeof(q));
     scanf("%d%d",&a,&b);
     itoa(b,c,2);
     d = strlen(c);
     for(int j = 1;j<=10000;j++)
      q[j] = pow(j)%10000;
     int u = a/10000;
     int v = a%10000;
     int sum1 = 0,sum2 = 0;
     for(int j = 1;j<=10000;j++)
      sum1+=q[j],sum1%=10000;
     for(int j = 1;j<=v;j++)
      sum2+=q[j],sum2%=10000;
     printf("%d\n",(sum1*u+sum2)%10000);
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
