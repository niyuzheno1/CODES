#include <cstdlib>
#include <iostream>

using namespace std;
int n,m;
int p[40010];
int g1[40010];
int s1[40010];
int s2[40010];
int f[40010];
int main(int argc, char *argv[])
{
    freopen("cleanup.in","r",stdin);
    freopen("cleanup.out","w",stdout);
    memset(f,0x7f,sizeof(f));
    f[0] = 0;
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&p[i]);
    for(int i = 1;i<=n;i++)
     if(!g1[p[i]])
     {
     g1[p[i]] = 1;
     s1[i] = s1[i-1]+1;
     }else
     s1[i] = s1[i-1];
    memset(g1,0x7f,sizeof(g1));
    g1[0] = 0;
    for(int i = n;i>=1;i--)
    {
     s2[i] = g1[p[i]];
     g1[p[i]] = i;
    }
    for(int i = 1;i<=n;i++){
     
     int x = s1[i];
     for(int j = 1;j<=i;j++)
     {
     if(s2[j-1] > i)
      x--;
     f[i] = min(f[i],f[j-1]+x*x);
     }
    }
    printf("%d",f[n]);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
