#include "mode.h"
#define MN 110
int n , m , a[MN][MN] ,b[MN][MN],num;
struct tri{
       int a,b,c;
       bool operator < (tri u) const
       {
            return c>u.c;
       }
};
inline void next(int & x,int & y,int p){
 ++y;
 if(y+p-1 > m)++x,y = 1;
}
tri u[MN*MN];
bool check(tri inf){
 memcpy(b,a,sizeof(b));
 int x=1,y=1;
 while(true)
 {
  int t = b[x][y];
  if(x > n || y > m) break;
  if(t){
  if(x + inf.a-1 > n || y+inf.b-1>m) return false;
  for(int i = x;i<x+inf.a;++i)
   for(int j = y;j<y+inf.b;++j){
    b[i][j]-=t;
    if(b[i][j] < 0 ) return false;
   }
  }
  next(x,y,inf.b);
 }
 return true;
}
int main(int argc, char *argv[])
{
    setIO("sample");
    n = gi,m = gi;
    int all = 0;
    for(int i = 1;i<=n;++i)
     for(int j = 1;j<=m;++j){
      a[i][j] = gi; all += a[i][j];
      ++num;u[num].a = i;u[num].b = j;u[num].c = i*j;
     }
    sort(u+1,u+1+num);
    for(int i = 1;i<=num;++i)
    {
     if(all%u[i].c) continue;
     if(check(u[i])){ printf("%d\n",all/u[i].c);break;}
    }
    closeIO();
    return EXIT_SUCCESS;
}
