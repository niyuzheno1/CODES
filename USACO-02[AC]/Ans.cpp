#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
int N,D;
int a[100000];
map<int,int> m;
int main(int argc, char *argv[])
{
    freopen("fracdec.in","r",stdin);
    freopen("fracdec.out","w",stdout);
    scanf("%d%d",&N,&D);
    int first = N/D;
    N -= D*first;
    printf("%d.",first);
    int f = 1;
    int ans2 = 0x7f7f7f7f;
    if(N == 0)
     printf("0");
    while(N != 0)
    {
     N *= 10;
     if(m.count(N)){
      ans2 = m[N];
      break;
     }
     m[N] = f;
     a[f] = N/D;f++;
     N %= D;
    }
    for(int i = 1;i<min(ans2,f);i++)
     printf("%d",a[i]);
    if(ans2 != 0x7f7f7f7f){
    printf("(");
    for(int i = ans2;i<f;i++)
     printf("%d",a[i]);
    printf(")");
    }
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
