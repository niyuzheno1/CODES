#include <cstdlib>
#include <iostream>

using namespace std;
const int maxn = 100;

int a[maxn],b[maxn];
int n,m;
int newn;
char str[5];
int main(int argc, char *argv[])
{
    freopen("tree.in3","r",stdin);
    freopen("tree.in","w",stdout);
    scanf("%d%d",&n,&m);
    newn = n;
    for(int i = 1;i<=n;i++){
     scanf("%d",&a[i]);
     if(a[i] > 41)
      b[i] = 1,newn--;
    }
    for(int i = 1;i<=n;i++)
     b[i] = b[i]+b[i-1];
    printf("%d %d\n",newn,m);
    for(int i = 1;i<=n;i++)
     if(a[i] <= 41)
      printf("%d ",a[i]);
    for(int i = 1;i<=m;i++)
    {
     scanf("%s",str);
     if(str[0] == 'Q'){
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      x-=b[x];
      y-=b[y];
      printf("Q %d %d %d\n",x,y,z);
     }
     else{
      int x,y;
      scanf("%d%d",&x,&y);
      x-=b[x];
      printf("C %d %d\n",x,y);
     }
    }fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
