#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
int mod;
char str[4][11];
int m;
int code(int pos)
{
 int ret = 0;
 for(int j = pos-1;j<=m;j++)
 {
 ret *= 2;
 if(str[1][j] == '1')
  ret+=1;
 }
 for(int j = 1;j<=m;j++){
   ret *= 2;
   if(str[2][j] == '1')
    ret+=1;
 }
 for(int j = 1;j<pos;j++){
  ret *= 2;
  if(str[3][j] == '1')
    ret+=1;
 }
 return ret;
}
void tran(int x,int y,int z)
{
 int flag = 0,nw = z;
 if(y != m && (z&1))
  flag = 1;
 if(y != 1 && (z&2))
  flag = 1;
 if((z & (1<<(m-1))))
  flag = 1;
 if((z & (1<<(2*m-1))))
  flag = 1;
 
 
 if(!flag)
 {
  nw = z;nw<<=1;nw%=mod;
  nw|=1;
  printf("%d\n",nw);
 }
 nw = z;nw<<=1;nw%=mod;
 printf("%d\n",nw);
}
int main(int argc, char *argv[])
{
    freopen("sta.in","r",stdin);
    freopen("sta.out","w",stdout);
    scanf("%d",&m);
    mod = (1<<(2*m+1));
    for(int i = 1;i<=3;i++)
     scanf("%s",&str[i][1]);
    int x = code(2);
    printf("%d\n",x);
    tran(1,1,x);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
