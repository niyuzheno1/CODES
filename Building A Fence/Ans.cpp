#include <cstdlib>
#include <iostream>

using namespace std;
int N;
int ans;
int main(int argc, char *argv[])
{
    scanf("%d",&N);
    for(int i = 1;i<=N;i++)
     for(int j = 1;j<=N;j++)
      if(i+j<N)
       for(int k = 1;k<=N;k++)
        if(i+j+k<N)
        {
         int l = N-(i+j+k);
         if(i+j+k > l && i+j+l > k && i+k+l > j && j+k+l > i)
          ans++;
        }
       printf("%d",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
