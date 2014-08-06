#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
struct Obj
{
 int D,P;
 bool operator < (Obj a) const
 {
  if(this->D - a.D == 0)
   return this->P - a.P > 0;
 return this->D - a.D < 0 ;
 }
};

Obj o[100010];

int main(int argc, char *argv[])
{
    scanf("%d",&N);
    for(int i = 1;i<=N;i++)
     scanf("%d %d",&o[i].D,&o[i].P);
    sort(o+1,o+1+N);
    int ans = 0;
    for(int i = 1;i<=N;i++)
     if(o[i].D != o[i-1].D)
      ans += o[i].P;
    printf("%d",ans);
    system("PAUSE");
    return EXIT_SUCCESS;
}
