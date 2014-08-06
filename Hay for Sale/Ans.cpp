#include <cstdlib>
#include <iostream>

using namespace std;
bool b[50010];
int C,H;
int V;
int main(int argc, char *argv[])
{
    scanf("%d%d",&C,&H);
    b[0] = 1;
    for(int i = 1;i<=H;i++){
     scanf("%d",&V);
     for(int j = V;j<=C;j++)
      b[j] = b[j-V] || b[j];
    }
    for(int i = C;i>=0;i--)
     if(b[i] != 0)
      {
             printf("%d",i);
             break;
      }
    system("PAUSE");
    return EXIT_SUCCESS;
}
