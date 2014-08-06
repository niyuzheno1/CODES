#include <cstdlib>
#include <iostream>

using namespace std;
const int dx[] = {0,0,0,1,-1};
const int dy[] = {0,1,-1,0,0};
const int maxn = 8;
typedef int mx[maxn][maxn];
mx a;
int n;
int b[maxn];
int ans[6][4];
bool clean(mx a,mx & b)
{
     bool flag = false;
     mx tmp,less;
     memcpy(tmp,a,sizeof(tmp));
     memset(less,0,sizeof(less));
     for(int i = 0;i<5;i++)
      for(int j = 0;j<7;j++)
       if(a[i][j] != 0)
        for(int k = 1;k<=4;k++)
         if(i+dx[k] < 5 && i+dx[k] >= 0)
         if(j+dy[k] < 7 && j+dy[k] >= 0)
         if(i+dx[k]*2 < 5 && i+dx[k]*2 >= 0)
         if(j+dy[k]*2 < 7 && j+dy[k]*2 >= 0)
         if(a[i][j] == a[i+dx[k]][j+dy[k]] && a[i+dx[k]][j+dy[k]]  == a[i+dx[k]*2][j+dy[k]*2])
         {
         less[i][j] = 1;
         less[i+dx[k]][j+dy[k]]=1;
         less[i+dx[k]*2][j+dy[k]*2]=1;
         flag = true;
         }
     for(int i = 0;i<5;i++)
       for(int j = 0;j<7;j++)
        if(less[i][j])
         tmp[i][j] = 0;
    memcpy(b,tmp,sizeof(tmp));
    return flag;
}
bool down(mx a,mx & b)
{
     bool flag = false;
  int d[10];
  memset(&d,0,sizeof(d));
  for(int i = 0;i<5;i++)
      for(int j = 0;j<7;j++)
       if(a[i][j] == 0){
        d[i] = j;
        break;
       }
  for(int i = 0;i<5;i++){
    int k = d[i];
    for(int j = d[i]+1;j<7;j++)
     if(a[i][j] != 0)
     {
      swap(a[i][j],a[i][k]);
      k++;
      flag = true;
     }
    a[i][7] = k;
  }
  memcpy(b,a,sizeof(b));
  return flag;
}
bool flag = false;
bool check(mx a)
{
     for(int i = 0;i<5;i++)
      for(int j = 0;j<7;j++)
       if(a[i][j] != 0)
        return false;
     return true;
}
void checka(mx tmp)
{/*
      for(int i = 0;i<=4;i++){
         for(int j = 0;j<7;j++)
          printf("%d ",tmp[i][j]);
         printf("\n");
        }
       */
}
void dfs(mx a,int d)
{
    
     if(check(a) == true)
     {
      if(d == 0)
       printf("0\n");
      for(int i =1;i<=d-1;i++)
       printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
      flag = true;
      return;
     }
     if(d > n)
      return;
     
     mx tmp;
     
     
     for(int i = 0;i<=4;i++)
      for(int j = 0;j<a[i][7];j++)
      if(a[i][j] != 0){
       memcpy(tmp,a,sizeof(tmp));
       if(i <= 3 && tmp[i+1][j] != tmp[i][j]){
       int k = tmp[i][j];
       tmp[i][j] = tmp[i+1][j];
       tmp[i+1][j] = k;
       bool change = true;
       while(change)
       {
        change = false;
        bool ret = down(tmp,tmp); 
        change = ret || change;
        ret = clean(tmp,tmp);
        change = ret || change;
       }
       
       ans[d][0] = i;ans[d][1] = j;ans[d][2] = 1;
     
       if(i == 1 && j == 0 && d == 1)
        checka(tmp);
       dfs(tmp,d+1);
       if(flag)
        return;
        }
       if(i > 0 && tmp[i-1][j] != tmp[i][j]){
       memcpy(tmp,a,sizeof(tmp));
       int k = tmp[i][j];
       tmp[i][j] = tmp[i-1][j];
       tmp[i-1][j] = k;
       bool change = true;
       while(change)
       {
        change = false;
        bool ret = down(tmp,tmp); 
        change = ret || change;
        ret = clean(tmp,tmp);
        change = ret || change;
       }
       
       ans[d][0] = i;ans[d][1] = j;ans[d][2] = -1;
       dfs(tmp,d+1);
       if(flag)
        return;}
      }
     
}

int main(int argc, char *argv[])
{
    freopen("mayan.in","r",stdin);
    freopen("mayan.out","w",stdout);
    scanf("%d",&n);
    for(int i = 0;i<5;i++)
    {
     int x = 1;
     
     while(x != 0)
     {
      scanf("%d",&x);
      a[i][b[i]] = x;
      b[i]++;
     }
     a[i][7] = b[i];
    }
    
    bool change = true;
    while(change)
       {
        change = false;
        bool ret = down(a,a); 
        change = ret || change;
        ret = clean(a,a);
        change = ret || change;
       }
    dfs(a,1);
    if(!flag)
     printf("-1\n");
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
