#include <cstdlib>
#include <iostream>

using namespace std;
typedef long long int64;
int64 gcd(int64 x,int64 y,int64 & a,int64 & b)
{
    if(y == 0)
    {
     a = 1;
     b = 0;
     return x;
    }
    int64 c = gcd(y,x%y,a,b);
    int64 tmp = b;
    b = a-(x/y)*b;
    a = tmp;
    return c;
}
int main(int argc, char *argv[])
{
    freopen("mod.in","r",stdin);
    freopen("mod.out","w",stdout);
    int64 a,b,x,y;
    x = y = 0;
    scanf("%I64d %I64d",&a,&b);
    int64 u = gcd(a,b,x,y);
    while(x < 0)
     x += b;
    while(x-b > 0)
     x-=b;
    printf("%I64d",x);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
