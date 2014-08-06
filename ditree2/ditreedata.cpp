#include <cstdlib>
#include <iostream>

using namespace std;
const int xx = 79,yy = 113;
int n,m;
int a;
char st[5];
int main(int argc, char *argv[])
{
    freopen("tree.in1","r",stdin);
    freopen("tree.in","w",stdout);
    scanf("%d%d",&n,&m);
    printf("%d %d\n",n,m);
    for(int i = 1;i<=n;i++){
     scanf("%d",&a);
     printf("%d ",a);
    }
    printf("\n");
    for(int i = 1;i<=m;i++)
    {
     scanf("%s",&st);
     if(st[0] == 'C')
     {
      int x,y;
      scanf("%d%d",&x,&y);
      if(x <= yy && x >= xx)
      printf("C %d %d\n",x,y);
     }
    }
    return EXIT_SUCCESS;
}
