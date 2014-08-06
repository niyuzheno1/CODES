#include <cstdlib>
#include <iostream>

using namespace std;
int n;
int s[51];
int sum = 0;
int l,r;
int main(int argc, char *argv[])
{
    freopen("group.in","r",stdin);
    freopen("group.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&s[i]),sum+=s[i];
    scanf("%d%d",&l,&r);
    if(sum < l*n || sum > r*n)
     puts("-1");
    else{
     int ll,rr;
     ll = rr = 0;
     for(int i = 1;i<=n;i++)
     if(s[i] >= r)
      rr += s[i]-r;
     else if(s[i] <= l)
      ll += l-s[i];
     printf("%d\n",max(ll,rr));
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
