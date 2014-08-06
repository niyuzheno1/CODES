#include <cstdlib>
#include <iostream>

using namespace std;
int n,d,l,t;
int ans1,ans2;
int a[1000010];
int b[1000010];
char inf[1100],ouf[1100];
int main(int argc, char *argv[])
{
for(int cani = 0;cani<=9;cani++){
    ans1=ans2=t = l = n = d = 0;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(inf,0,sizeof(inf));
    memset(ouf,0,sizeof(ouf));
    sprintf(inf,"mr437.in%d",cani);
    sprintf(ouf,"mr437.ou%d",cani);
    freopen(inf,"r",stdin);
    freopen(ouf,"w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i<=n;i++)
      scanf("%d",&a[i]);
   
    for(int i = 1;i<=n;i++)
    {
     if(b[a[i]] == 0)
      t++;
     b[a[i]]++;
     l++;
     while(l > d || b[a[i-l+1]] > 1)
     {
      b[a[i-l+1]]--;
      if(b[a[i-l+1]] == 0)
       t--;
      l--;
     }
     if(t > ans1)
      ans1 = t,ans2 = l;
     else if(t == ans1 && l < ans2)
      ans2 = l;
    }
    printf("%d %d\n",ans1,ans2);
    fclose(stdin);fclose(stdout);
}
    return EXIT_SUCCESS;
}
