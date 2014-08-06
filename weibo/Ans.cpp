#include <cstdlib>
#include <iostream>

using namespace std;
struct s
{
 int a,b,x,y;
 bool operator <(s v) const
 {
  if(v.x == x)
   return b < v.b;
  else
   return x < v.x;
 }
};
s b[500010*2];
int tot;
int n,m;
char a[10];
int ans[200010];
int c[200010];
void add(int a,int bb,int x,int y)
{
     tot++;
     b[tot].a = a;b[tot].b = bb;
     b[tot].x = x;b[tot].y = y;
}
int main(int argc, char *argv[])
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=m;i++){
     int x,y;
     scanf("%s",&a);
     scanf("%d",&x);
     if(a[0] == '+' || a[0] == '-'){
      scanf("%d",&y);
      add(a[0]=='+'?1:2,i,x,y);
      add(a[0]=='+'?1:2,i,y,x);
     }
     else
      add(0,i,x,0);
    }
    sort(b+1,b+tot+1);
    int count = 0,tmp = 0;
    for(int i = 1;i<=tot+1;i++)
    {
     if(tmp != b[i].x)
     {
      count = 0;
      tmp = b[i].x;
     }
     
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
