#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdio>
using namespace std;
const int maxn = 100000,maxm = 10000,maxai = 10000;
int a[maxn];
int main(int argc, char *argv[])
{
    freopen("tree.in","w",stdout);
    srand(clock());
    int n;
    n = rand()%maxn;
    n++;
    
    int m = rand()%maxm;
    m++;
    printf("%d %d\n",n,m);
    for(int i = 1;i<=n;i++){
     a[i] = (rand()%maxai)+1;
     printf("%d ",a[i]);
    }
    printf("\n");
    for(int i = 1;i<=m;i++){
     int x = rand()%2;
     if(x == 0)
      printf("C %d %d\n",rand()%n+1,a[rand()%n+1]);
     else{
      int x,y;x=y=0;
      while(true){
      x = rand()%n+1,y=rand()%n+1;
      if(x == y)
        continue;
      printf("Q %d %d %d\n",min(x,y),max(x,y),(rand())%(y-x)+1);
      if(x != y)
        break;
      }
     }
    }
    return EXIT_SUCCESS;
}
