#include "mode.h"

using namespace std;

int main(int argc, char *argv[])
{
    freopen("numbers1.in","r",stdin);
    freopen("numbers2.out","w",stdout);
    int x = gi;
    int mid = 256/2;
    for(int k = 1;k<=60000;++k){
     if(k == 3006)
     {
       for(int i = 1;i<=28;printf("\n"),++i)
        for(int j = 1;j<=28;++j)
         {
         x = gi;
         int u =  x > mid;
         printf("%d ",u);
        }
        break;
     } 
    for(int i = 1;i<=28;++i)
     for(int j = 1;j<=28;++j)
     {
      x = gi;
      int u =  x > mid;
     }

    }
    return EXIT_SUCCESS;
}