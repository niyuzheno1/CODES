//注意特殊的数0 
#include <cstdlib>
#include <iostream>

using namespace std;
int x;
int m;
char ans[100];
int main(int argc, char *argv[])
{
    freopen("neg2.in","r",stdin);
    freopen("neg2.out","w",stdout);
    scanf("%d",&x);
    if(x == 0)
    {
         printf("0");
    }
    while(x != 0)
    {
     int l = x/(-2);
     int r = x%(-2);
     if(r < 0)
      r+=2,l++;
     x = l;
     ans[m++] = r+'0';
    }
    for(int i = m-1;i>=0;i--)
     printf("%c",ans[i]);
    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}
