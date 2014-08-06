/*
max{up1 - S1 , up1+ w1 + dw1- S2} >= max{up1 - S2 , up1+ w2 + dw1- S1}
<=> up1+ w1 + dw1- S2 > up1 - S2  (1) &&  up1+ w1 + dw1- S2 > up1+ w2 + dw1- S1 (2) and so on.
(1)=> w1   > up1 - dw1 ,w1 > w2 -S1 + S2
  suppose up1 - dw1>w2 -S1 + S2 => up1+S1>dw1+S2+w2 it is impossible
so answer fullfills condition {w1+S1>w2+S2}
*/
#include <cstdlib>
#include <iostream>

using namespace std;

struct cow
{
 int W,S;
 bool operator <(cow a) const 
 {
  return W+S<a.W+a.S;
 }
};
int N;
int ans1,ans2 = 0;
cow cows[50010];
int main(int argc, char *argv[])
{
    scanf("%d",&N);
    for(int i = 1;i<=N;i++)
    scanf("%d%d",&cows[i].W,&cows[i].S);
    sort(cows+1,cows+1+N);
    for(int i = 1;i<=N;i++)
    {
     ans2 = max(ans2,ans1-cows[i].S);
     ans1+=cows[i].W;
    }
    printf("%d",ans2);
    system("PAUSE");
    return EXIT_SUCCESS;
}
