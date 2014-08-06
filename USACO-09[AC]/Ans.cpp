#include <cstdlib>
#include <iostream>

using namespace std;
int n;
struct p
{
      int s,e;
      bool operator < (p x) const
      {
           if(s == x.s)
            return e < x.e;
           return s < x.s;
      }
};
p pr[50010];
int main(int argc, char *argv[])
{
    freopen("sgraze.in","r",stdin);
    freopen("sgraze.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&pr[i].s,&pr[i].e);
    sort(pr+1,pr+1+n);
    int r = 0;
    int ans = 0;
    for(int i = 1;i<=n;i++)
    {
     if(pr[i].s >= r)
      r = pr[i].e,ans++;
     if(pr[i].e < r)
      r = pr[i].e;
    }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
