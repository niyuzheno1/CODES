#include <cstdlib>
#include <iostream>

using namespace std;
int ma[7][7];
 int bst[7][7] ={
 {0,0,0,0,0,0},
 {0,3,84 ,23 ,74 ,0},
 {0,11 ,33 ,20 ,35 ,0},
 {0,30 ,29 ,22 ,72 ,0},
 {0,43 ,84 ,66 ,51,0},
 {0,0,0,0,0,0}
};
int bs = 502;
int nst[7][7];
int ns = 0;
int main(int argc, char *argv[])
{
 srand(time(0));   
    for(int i = 1;i<=10;++i)
    {
     freopen("sample.in","w",stdout);       
     for(int i = 1;i<=4;printf("\n"),++i)
      for(int j = 1;j<=4;++j)
       printf("%d ",ma[i][j]==0?1:ma[i][j]);
     fclose(stdout);
     system("ans3");
     
     FILE * r = fopen("debug.txt","r");
     int c = 0;
     char p = 0;
     while(~(fscanf(r,"%c",&p))) 
      ++c;
     if(c > bs)
     {
      memcpy(bst,ma,sizeof(ma));
      bs = c;
     }
     else if(c>ns){
      memcpy(nst,ma,sizeof(ma));
      ns = c;
     }
     memset(ma,0,sizeof(ma));
     int n = rand()%16+5;
     for(int l = 0;l<=n;++l){
      int x =rand()%4+1, y= rand()%4+1;
      ma[x][y] = bst[x][y];
     }
     for(int i = 1;i<=4;++i)
      for(int j = 1;j<=4;++j)
      {
       int u = (rand()%2)||(ma[i][j]<=1),v=  rand()%100;
       ma[i][j] = (!u)?v:ma[i][j];
       if(ma[i][j] <= 2)
        ma[i][j] =  rand()%100;
      }
     
     fclose(r);
    }
    freopen("res.txt","w",stdout);
    printf("%d\n",bs);
    for(int i = 1;i<=4;printf("\n"),++i)
     for(int j = 1;j<=4;++j)
      printf("%d ",bst[i][j]==0?1:bst[i][j]);
    printf("%d\n",ns);
    for(int i = 1;i<=4;printf("\n"),++i)
     for(int j = 1;j<=4;++j)
      printf("%d ",nst[i][j]==0?1:nst[i][j]);
    return EXIT_SUCCESS;
}
