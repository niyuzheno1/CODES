#include <cstdlib>
#include <iostream>

using namespace std;
int T,S,N;
struct Lesson
{
 int M,L,A;
};
Lesson lessons[110];
int P[110];
int f[10100][110];
int ans = 0;
int main(int argc, char *argv[])
{
    memset(&f,0xfe,sizeof(f));
    memset(&P,0x7f,sizeof(P));
    scanf("%d %d %d",&T,&S,&N);
    for(int i = 1;i<=S;i++)
     scanf("%d %d %d",&lessons[i].M,&lessons[i].L,&lessons[i].A);
    for(int i = 1;i<=N;i++)
    {
     int C,D;
     scanf("%d %d",&C,&D);
     P[C] = min(P[C],D);
    }
    f[0][1] = 0;
    for(int i = 0;i<=T;i++)
     for(int j = 1;j<=100;j++)
     {
      f[i+1][j] = max(f[i][j],f[i+1][j]);
      for(int l = 1;l<=S;l++)
        if(lessons[l].M == i )
         f[i+lessons[l].L][lessons[l].A] = max(f[i+lessons[l].L][lessons[l].A],f[i][j]);
      for(int l = j;l>=0;l--)
      if(i + P[l]-1 <= T)
       f[i+P[l]][j] = max(f[i][j] + 1,f[i+P[l]][j]);
     }
  
     for(int j = 0;j<=100;j++)
      ans= max(ans,f[T][j]);
    
    printf("%d",ans);
    
    return EXIT_SUCCESS;
}
