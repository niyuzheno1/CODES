#include <cstdlib>
#include <iostream>
#define zero(a) memset(a,0,sizeof(a))
using namespace std;
int n;
struct m
{
 int x,y,n;
};
m a[1000];
bool cmp(int x,int y)
{
 return a[x].x+max(a[x].y,a[y].x)+a[y].y > a[y].x + max(a[y].y,a[x].x)+a[x].y;
}
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=4;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr471.in%d",cani);
    sprintf(ouf,"mr471.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    n = 0;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i].x);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i].y),a[i].n = i;
    bool flag = true;
    while(flag){
    flag = 0;
    for(int i = 1;i<=n-1;i++)
     if(cmp(i,i+1))
     {
      a[0] = a[i];
      a[i] = a[i+1];
     a[i+1]= a[0];
     flag = true;
     }
    }
    int s = 0,ans = 0,u = 0,v = 0;
    for(int i = 1;i<=n;i++)
    {
     while(s >= 0 && i<=n)
     {
      s-=a[i].x;
      u+=a[i].y;
      if(s < 0)
       break;
      s = u;
      i++;
     }
     ans += u+abs(s);
     s = u;
     u = 0;
    }
    printf("%d\n",ans);
    for(int i = 1;i<=n-1;i++)
     printf("%d ",a[i].n);
    printf("%d\n",a[n].n);
    fclose(stdin);fclose(stdout);
}  
    
    return EXIT_SUCCESS;
}
