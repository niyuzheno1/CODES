#include <cstdlib>
#include <iostream>

using namespace std;
typedef int s[6];
int n;
s a;
int b[9];

void checka(s m)
{
     for(int i = 0;i<5;i++)
      {
       int x = m[i];
       
       while(x != 0)
       {
        printf("%d ",x%(16));
        x>>=4;
       }
       printf("\n");
      }
}
void clear(s & m)
{
 s tmp;
 memcpy(tmp,m,sizeof(s));
}
int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i = 0;i<5;i++)
    {
     b[0] =0;
     int x= 0;
     scanf("%d",&x);
     while(x != 0)
     {
      
      b[0]++;
      b[b[0]] = x;
      scanf("%d",&x);
     } 
     for(int j = b[0];j>=1;j--)
     {
      a[i]<<=4;
      a[i] ^= b[j];
     }
    }
    checka(a);
    system("PAUSE");
    return EXIT_SUCCESS;
}
