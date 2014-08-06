#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define lc(y) (2*(2*y-2))
#define uc(y) (2*(2*y-1))
#define urc(y) (2*(2*y))
using namespace std;
const int maxn = 13;
const string tab = "*()";
char str[maxn];
int n,m;
int tra()
{
 int u = 0,ret=0;
 for(int i = n;i>=1;i--)
 {
  u = tab.find(str[i]);
  ret*=4;
  ret+=u;
 }
 return ret;
}
void undo(int & x,int y,int p,int q,int g)
{
  x ^=(p<<uc(y));x ^=(q<<lc(y));
  x ^=(g<<urc(y));
}
void decode(int x)
{
 for(int i = 0;i<=m;i++){
  int u = i;
  int v = (x>>(2*i))%4;
  printf("%c",tab[v]);
 }
 printf("\n");
}
void tran(int x,int y,int z)
{
 int p = (z>>uc(y))%4;
 int q = (z>>lc(y))%4;
 int g = (z>>urc(y))%4;
 int nw=0;
 if(p == 0 && q == 0)
 {
  nw = z;
  undo(nw,y,p,q,g);
  undo(nw,y,2,1,g);
  decode(nw);
 }
 if(p == 1 && q == 1)
 {
  nw = z;
  undo(nw,y,p,q,g);
  undo(nw,y,0,0,1);
  decode(nw);
 }
 if(q == 2 && p == 1)
 {
  nw = z;
  undo(nw,y,p,q,g);
  undo(nw,y,0,0,g);
  decode(nw);
 }
 if(q == 1&& p == 2)
 {
  if(x == n && y == m)
   ;
 }
 if((q == 0 && p != 0) || (p == 0&&q!=0))
 {
  nw = z;
  decode(nw);
 }
}
int main(int argc, char *argv[])
{
    freopen("report.in","r",stdin);freopen("report.txt","w",stdout);
    scanf("%s",&str[1]);n = strlen(&str[1]);
    int x = tra();m = n;
    tran(1,2,x);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
