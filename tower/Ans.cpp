#include <cstdlib>
#include <iostream>

using namespace std;
int h[100];
int n;
int f[101][500010]; 
int main(int argc, char *argv[])
{
    freopen("tower9.in","r",stdin);
    freopen("tower.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
     scanf("%d",&h[i]);
    memset(f,0xff,sizeof(f));
    f[0][0] = 0;
    for(int i = 0;i<=n;i++)
     for(int j = 0;j<=500000;j++)
     if(f[i][j] != -1){
      f[i+1][j] = max(f[i][j],f[i+1][j]);
      if(j+h[i]<=500000)
      f[i+1][j+h[i+1]] = max(f[i][j]+h[i+1],f[i+1][j+h[i+1]]);
      if(abs(h[i]-j)<=500000)
      f[i+1][abs(h[i+1]-j)] = max(f[i][j]+max(0,h[i+1]-j),f[i+1][abs(h[i+1]-j)]);
     }
    printf("%d",f[n][0]);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
