#include <cstdlib>
#include <iostream>
#include <map>

using namespace std;
const int inf = 0x7f7f7f7f;
typedef pair<int,int> p;
map<int,int> mp;
int s[101],f[101];
int n;

int main(int argc, char *argv[])
{
    freopen("smrtfun.in","r",stdin);
    freopen("smrtfun.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d%d",&s[i],&f[i]);
    for(int i = -100000;i<=100000;i++)
     mp[i] = -inf;
    int l = 0,r = 0;
    mp[0] = 0;
    for(int i = 1;i<=n;i++)
    {
     int ll = l,rr =r;
     if(s[i] >= 0){
      for(int j = r;j>=l;j--)
       if(mp[j] != -inf)
        mp[j+s[i]] = max(mp[j+s[i]],mp[j]+f[i]),ll=min(j+s[i],ll),rr=max(rr,j+s[i]);
       }
     else
      for(int j =l;j<=r;j++)
       if(mp[j] != -inf)
        mp[j+s[i]] = max(mp[j+s[i]],mp[j]+f[i]),ll=min(j+s[i],ll),rr=max(rr,j+s[i]);
      l=ll,r=rr;
    }
    int ans = 0;
    for(int i = 0;i<=100000;i++)
     if(mp[i] > 0)
      ans = max(ans,mp[i]+i);
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
