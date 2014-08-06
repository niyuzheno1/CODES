#include <cstdlib>
#include <iostream>

using namespace std;
int n,ans = 0,mans = 0;
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
     int val = 0;
     scanf("%d",&val);
     ans += val;
     if(ans<0)
      ans= 0;
     mans = max(mans,ans);
    }
    printf("%d",mans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
