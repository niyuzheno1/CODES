#include <cstdlib>
#include <iostream>

using namespace std;
const int xx = 79,yy=113;
int n,m;
char str[5];
int main(int argc, char *argv[])
{
    freopen("tree.in2","r",stdin);
    freopen("tree.in","w",stdout);
    scanf("%d%d",&n,&m);
    printf("%d %d\n",yy-xx+1,m);
    for(int i = 1;i<=n;i++){
     int a;
     scanf("%d",&a);
     if(i >= xx && i <= yy)
      printf("%d ",a);
    }
    printf("\n");
    for(int i = 1;i<=m;i++){
     scanf("%s",str);
     if(str[0] == 'C'){
      int x,y;
      scanf("%d%d",&x,&y);
      printf("C %d %d\n",x-xx+1,y);
     }
     else{
      int x,y,z;
      scanf("%d%d%d",&x,&y,&z);
      printf("Q %d %d %d",x-xx+1,y-xx+1,z);
     }
    }
    fclose(stdout);
    return EXIT_SUCCESS;
}
