#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;

int w[100010];
int s[100010];
int h[100010];
int f[100010];
int q[100010],he,t,n;
int main(int argc, char *argv[])
{
    freopen("tower.in","r",stdin);
    freopen("tower.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&w[i]);
    for(int i = 1;i<=n;i++)
     s[i] = s[i-1]+w[i];
    he++,t++;
    q[he] = n+1;
    for(int i = n;i>=1;i--)
    {
    while(t-he+1 >= 2 && s[q[he+1]-1]-f[q[he+1]] >= s[i-1])
     he++;
    f[i] = s[q[he]-1]-s[i-1];
    h[i] = h[q[he]]+1;
    t++;q[t] = i;
    while(t-he+1 >=2 && s[q[t-1]-1]-f[q[t-1]]<=s[q[t]-1]-f[q[t]])
     t--,q[t] = q[t+1];
    }
    int ans = h[1];
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
