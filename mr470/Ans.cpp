#include <cstdlib>
#include <iostream>
#define zero(x) memset(x,0,sizeof(x))
using namespace std;
int d;
int t;
char inf[101],ouf[101];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    zero(inf);
    zero(ouf);
    sprintf(inf,"mr470.in%d",cani);
    sprintf(ouf,"mr470.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    d = t = 0;
    t = 8;
    while(d==0 && t >= 0)
     scanf("%d",&d),t--;
    if(t+1 == -1)
    printf("0");
    else if(t+1 == 0)
    {
    printf("%d",d);
    }
    else{
    if(d == 1)
    printf("x^%d",t+1);
    else
    printf("%dx^%d",d,t+1);
     while(t >=0)
     {
      d=0;
      while(d==0 && t >=0)
       scanf("%d",&d),t--;
      if(d == 1){
       if(t+1 == 0)
        printf("+%d",t+1);
       else if(t+1 > 0)
        printf("+x^%d",d,t+1);
        }
      else if(d >= 0){
       if(t+1 == 0)
        printf("+%d",d);
       else if(t+1 > 0)
        printf("+%dx^%d",d,t+1);}
      else{
       if(t+1 == 0)
        printf("%d",d);
       else if(t+1 > 0)
        printf("%dx^%d",d,t+1);}
     }
    }
    	fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
