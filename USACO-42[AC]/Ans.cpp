#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;
const int inf  = 0x7f7f7f7f;
int c,h,b;
int hash[1010];
int x[1010],t[1010];
int f[1010][1010][3];
void up(int & a,int t)
{
 if(a != -1)
 a = min(a,t);
 else
 a = t;
}
int main(int argc, char *argv[])
{
    freopen("turnin.in","r",stdin);
    freopen("turnin.out","w",stdout);
    memset(hash,0xff,sizeof(hash));
    scanf("%d%d%d",&c,&h,&b);
    for(int i = 1;i<=c;i++)
    {
     int x,y;
     scanf("%d%d",&x,&y);
     hash[x] = max(y,hash[x]);
    }
    c = 0;
    for(int i = 0;i<=h;i++)
    if(hash[i] != -1)
    {
    c++;x[c] = i;t[c] = hash[i];
    }
    x[c+1] = x[c];
    memset(f,0xff,sizeof(f));
    f[0][0][1] = 0;f[0][0][2] = x[c];
    for(int d = 1;d<=c;d++)
     for(int i = 0;i<=d;i++)
     {
      int j = d-i;
      int l = i,r = c-j+1;
      if((i-1)>=0 && f[i-1][j][1] != -1)
      {
       int tx = f[i-1][j][1] + x[l]-x[l-1];
       if(tx < t[l])
        tx = t[l];
       up(f[i][j][1],tx);
      }
      if((i-1)>=0 && f[i-1][j][2] != -1 )
      {
       int tx = f[i-1][j][2] + x[r]-x[l];
       if(tx < t[l])
        tx = t[l];
       up(f[i][j][1],tx);
      }
      if((j-1)>=0 && f[i][j-1][1] != -1)
      {
       int tx = f[i][j-1][1] + x[r]-x[l];
       if(tx < t[r])
        tx = t[r];
       up(f[i][j][2],tx);
      }
      if((j-1)>=0 && f[i][j-1][2] != -1)
      {
       int tx = f[i][j-1][2] + x[r+1]-x[r];
       if(tx < t[r])
        tx = t[r];
       up(f[i][j][2],tx);
      }
      if(f[i][j][1] != -1)
      {
       int tx = f[i][j][1] + x[r]-x[l];
       if(tx < t[r])
        tx = t[r];
       up(f[i][j][2],tx);
      }
      if(f[i][j][2] != -1)
      {
       int tx = f[i][j][2] + x[r]-x[l];
       if(tx < t[l])
        tx = t[l];
       up(f[i][j][1],tx);
      }
     }
    int ans = inf;
    for(int i = 0;i<=c;i++){
     if(f[i][c-i][1] != -1)
      ans = min(ans,f[i][c-i][1]+abs(x[i]-b));
     if(f[i][c-i][2] != -1)
      ans = min(ans,f[i][c-i][2]+abs(x[i+1]-b));
    }
    printf("%d\n",ans);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
