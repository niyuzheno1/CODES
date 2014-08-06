#include <cstdlib>
#include <iostream>
#include <map>
using namespace std;
int n,tot;
struct note
{
 int p;
 int d;
 map<int,int> f;
};
note a[80010];
int p[80010];
void add(int x,int y)
{
     tot++;
     a[x].f[y] = tot;
     a[tot].d = y;
     a[tot].p = x;
}
int main(int argc, char *argv[])
{
    freopen("ttravel.in","r",stdin);
    freopen("ttravel.out","w",stdout);
    tot = 1;
    int t = 1;
    scanf("%d",&n);
    a[1].p = 1;
    a[1].d = -1;
    for(int i = 1;i<=n;i++)
    {
     char x[10];int y;
     scanf("%s",x);
     if(x[0] == 's')
     {
      t = a[t].p;
      printf("%d\n",a[t].d==0?-1:a[t].d);
     }
     else if(x[0] == 'a')
     {
      scanf("%d",&y);
      if(a[t].f[y] == 0)
       add(t,y);
      t = a[t].f[y];
      printf("%d\n",a[t].d==0?-1:a[t].d);
     }
     else
     {
      scanf("%d",&y);
      t = p[y-1];
      printf("%d\n",a[t].d==0?-1:a[t].d);
     }
     p[i] = t;
    }
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
