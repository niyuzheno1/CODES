#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
int c[10];
int main()
{
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);
    int x,y;
    scanf("%d%d",&x,&y);
     for(int i = x;i<=y;i++)
      for(int j = i;j != 0;j/=10)
       c[j%10]++;
    for(int i = 0;i<=8;i++)
     printf("%d ",c[i]);
    printf("%d",c[9]);
    fclose(stdin);fclose(stdout);
    return 0;
}
