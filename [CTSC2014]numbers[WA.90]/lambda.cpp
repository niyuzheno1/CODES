#include "mode.h"
#undef MP
#define lb(x) ((x)&(-x))
#define MK 30
#define MN 8010
const int MP = 3002;
struct cl
{
       int a[MK];
       int v;
};
cl a[MN];
int main(int argc, char *argv[])
{
    setIO("numbers1");
    FILE * pat = fopen ("numbers.txt","r");
    FILE * pat2 = fopen ("numbers2.txt","r");
    #define fr fscanf(pat,
    #define fr2 fscanf(pat2,
    for(int i = 1;i<=MP;++i)
    {
     for(int j = 1;j<=28;++j)
      for(int k = 1;k<=28;++k)
      {
       a[i].a[j] <<= 1;
       int x;
       fr2 "%d",&x);
       a[i].a[j] ^= x;
      }
    fr "%d",&a[i].v);
    }
    #undef fr
    #undef fr2
    int u = gi;
    int mid = 256/2;
    printf("%d\n",u);
    for(int i = 1;i<=60000;++i){
     int p[MK];
     CLEAR(p,0);
     for(int j = 1;j<=28;++j){
      int tmp = 0;
      for(int k = 1;k<=28;++k)
      {
       tmp<<=1;
       tmp^= (gi>mid?1:0);
      }
      p[j] = tmp;
     }
     int best = INF,bestans = 0;
     for(int j = 1;j <=MP;++j)
     {
      int now = 0;
      for(int k = 1;k<=28;++k)
      {
       int tmp = p[k]^a[j].a[k];
       while(tmp){
        ++now;
       tmp -= lb(tmp);
       }
      }
      if(now < best){
       best = now;
       bestans = a[j].v;
      }
     }
     printf("%d\n",bestans);
    }
    
    return EXIT_SUCCESS;
}