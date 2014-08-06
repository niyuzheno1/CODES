#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
const string s = "#()";
int n,m;
char str[13];
int code()
{
 int ret = 0;
 for(int i = 0;i<strlen(str);i++)
 {
  ret <<= 2;
  ret += s.find(str[i]);
 }
 return ret;
}
void decode(int x)
{
 for(int i = 0,u=0;i<=m;i++)
  u = (x>>(2*i))%4,str[m-i] = s[u];
}
void pri()
{
 for(int i = 0;i<=m;i++)
  printf("%c",str[i]);
 printf("\n");
}
int lc(int y,int z)
{
 if(y == 1)
  return 0;
 else
  return (z>>(2*(y-1)))%4;
}
int llc(int y)
{
 if(y == 1)
  return 0;
 else
  return 2*(y-1);
}
int uc(int y,int z)
{
 return (z>>(2*(y)))%4;
}
int uuc(int y)
{
 return (2*(y));
}
void undo(int & x,int y,int p,int q)
{
 x ^= (p<<llc(y));
 x ^= (q<<uuc(y));
}
int findpre(int y,int x)
{
 while(y>=0)
 {
  if((x & (1<<y)))
   break;
  y-=2;
 }
 return y;
}
int findne(int y,int x)
{
 while(y<=2*m)
 {
  int u = 2<<y;
  if((x&u))
   break;
  y+=2;
 }
 return y;
}
void tran(int x,int y,int z)
{
 int p = lc(y,z),q = uc(y,z);
 if((p==1 && q == 2) && x == n && y == m)
 {
  /**/
 }
 if(p==2&&q==1)
 {
  int u = z;
  undo(u,y,p,q);
  decode(u);
  pri();
 }
 if(p==0&&q==0)
 {
  int u = z;
  undo(u,y,1,2);
  decode(u);
  pri();
 }
 if((p == 0 && q != 0)||(p != 0 && q == 0))
 {
  int u = z;
  decode(u);pri();
  if(y != 1){
  undo(u,y,p,q);
  undo(u,y,q,p);
  decode(u);pri();
  }
 }
 if(p == 2 && q == 2)
 {
  int u = z;
  undo(u,y,p,q);
  int v = findpre(2*(y-1),u);
  if(v < 0)
   return;
  u ^= (1<<v);
  u ^= (2<<v);
  decode(u);pri();
 }
 if(p == 1 && q == 1)
 {
  int u = z;
  undo(u,y,p,q);
  int v = findne(2*(y+1),u);
  if(v > 2*m)
   return;
  u ^= (2<<v);
  u ^= (1<<v);
  decode(u);pri();
 }
}
int main(int argc, char *argv[])
{
    freopen("report.in","r",stdin);freopen("report.txt","w",stdout);
    scanf("%s",&str);
    n = 3,m=7;
    int x = code();
    //decode(x);
    tran(2,3,x);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
