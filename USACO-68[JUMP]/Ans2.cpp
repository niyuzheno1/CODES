#include <cstdlib>
#include <iostream>

using namespace std;
int n;
int J[1010];
int num[1010];
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 1;i<=3*n;i++)
     scanf("%d",J[i]),num[i] = i;
    for(int i = 1;i<=3*n;i++)
     for(int j = i+1;j<=3*n;j++)
      if(J[num[i]] < J[num[j]])
       swap(num[i],num[j]);
    for(int i = 2*n+1;i<=3*n;i++)
     printf("%d\n",num[i]);
    int m1 = n*500+1,m2 = 0;
    for(int i = 1;i<=2*n;i++)
     m2 += J[num[i]];
    m2 -= m1;
    system("PAUSE");
    return EXIT_SUCCESS;
}
