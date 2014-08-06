#include <cstdlib>
#include <iostream>
#include <cstring>
#include <algorithm>
#define dprint(a,b) fprintf(debug,a,b);
using namespace std;
const int maxn = 10000010,maxm = 10000010;
int n,m;
int a[maxn];
int b[maxn];
FILE * debug;
int main(int argc, char *argv[])
{
    freopen("tree.in","r",stdin);
    debug = fopen("tree.err","w");
    freopen("tree.ans","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++)
     scanf("%d",&a[i]);
    int xx = 0;
    for(int i = 1;i<=m;i++)
    {
     char str[6];
     int x,y,z;
     scanf("%s %d %d",&str,&x,&y);
     if(str[0] == 'Q'){
       scanf("%d",&z);
       memcpy(b,a,sizeof(a));
       sort(b+x,b+y+1);
       xx++;
       if(xx == 17){
        dprint("a:",0);
        for(int i = x;i<=y;i++)
         dprint("%d ",a[i]);
        dprint("\nb:",0);
        for(int i = x;i<=y;i++)
         dprint("%d ",b[i]);
        dprint("\n",0);
        xx = 17;
       }
       printf("%d\n",b[x+z-1]);
     }else
       a[x] = y;
    }
    fclose(stdin);fclose(stdout);
    system("PAUSE");
    return EXIT_SUCCESS;
}
