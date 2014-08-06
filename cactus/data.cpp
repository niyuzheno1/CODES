#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
const int maxn = 1010,maxm = 10010;
int f[maxn],tot,n,type;
int nm[maxn];
int st[maxm],ed[maxm],vis[maxn];
int gf(int x)
{
    if(f[x] == x) 
     return x;
    else
     return f[x] = gf(f[x]);
}
void un(int x,int y)
{
  gf(x);gf(y);
  f[gf(x)] = f[gf(y)];
}
int main(int argc, char *argv[])
{
    srand(clock());
    freopen("cactus.in","w",stdout);
    n = rand()%maxn+1,type = rand()%3;
    int i = n-1;
    printf("%d %d\n",n,n);
    for(int i = 1;i<=n;i++)
     f[i] = i;
    while(i)
    {
     int j = rand()%n+1;int k = rand()%n+1;
       if(gf(j) != gf(k)){
       un(j,k),printf("2 %d %d\n",j,k);
       i--;
       }
    }
     while(true){
     int j = rand()%n+1;int k = rand()%n+1;
     if(j != k)
     { printf("2 %d %d",j,k);break;}
     }
    return EXIT_SUCCESS;
}
