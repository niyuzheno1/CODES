#include <cstdlib>
#include <iostream>
#define rep(i,n) for(int i = 1;i<=n;i++)
using namespace std;
int n;
int x[2010],y[2010];
int p(int x,int y)
{
    if(x > y)
     return 200;
    if(x == y)
     return 0;
    else
     return -200;
}
int main(int argc, char *argv[])
{
    freopen("horse.in","r",stdin);
    freopen("horse.out","w",stdout);
    scanf("%d",&n);
    rep(i,n)
     scanf("%d",&x[i]);
    rep(i,n)
     scanf("%d",&y[i]);
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    int k = 1,m = n;
    int ans = 0;
    int l = 1,r = n;
    while(l <= r)
    {
      if(x[r] > y[m]){
       ans += 200;
       r--,m--;
      }else if(x[r] < y[m]){
       ans -= 200;
       l++;m--;
      }
      else
      {
          if(x[l] > y[k])
           ans += 200,k++,l++;
          else
           ans = ans +p(x[l],y[m]),m--,l++;
      }
    }
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
