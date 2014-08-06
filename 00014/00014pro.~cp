#include <cstdlib>
#include <iostream>

using namespace std;
int a[60][2];
int tot;
int set[20000][60];
int map[50];
int b[50];
int n;
void dfs(int x)
{
  if(x>n){
   for(int i = 1;i<=tot;i++)
   {
    bool flag = true;
    for(int j = 1;j<=n;j++)
     if(set[i][j] != map[j]){
      flag = false;
      break;
     }
    if(flag)
     return;
   }
   long long y = 0;
   for(int i = 1;i<=n;i++)
    if(map[i] == 2)
      y++;
   b[y]++;
   tot++;
   for(int j = 1;j<=n;j++)
    set[tot][j] = map[j];
   return;
  }
  
  for(int i = 0;i<=1;i++)
  {
  
  
   map[a[x][i]]++;
   dfs(x+1);
   map[a[x][i]]--;
  }
 
  return;
}
int main(int argc, char *argv[])
{
    freopen("output.txt","w",stdout);
    for(n = 1;n<=50;n++){
    tot = 0;
    memset(&a,0,sizeof(a));
    memset(&set,0,sizeof(set));
    memset(&map,0,sizeof(map));
    memset(&b,0,sizeof(b));
   
    for(int i = 1;i<=n;i++)
     a[i][0] = i;
   
    for(int i = 1;i<=n;i++)
     a[i][1] = (i)%(n)+1;
    dfs(1);
    printf("%d :",n);
    for(int i = 0;i<=n;i++)
     printf("%d ",b[i]);
    printf("\n");
   }fclose(stdout);
    return EXIT_SUCCESS;
}
