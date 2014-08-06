#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int maxn = 1000000;
int f[maxn],s[maxn],n,a,b,c;
int x[maxn],y[maxn];
int head = 0,tail = 0;
int comp(int k,int a)
{
    if((y[a]-y[a+1])<=k*(x[a]-x[a+1]))
     return -1;
    else
     return 1;
}
int cross(int a1,int a2,int b1,int b2)
{
    return a1*b2-a2*b1;
}
int comp2()
{
    if(cross(x[tail-1]-x[tail-2],y[tail-1]-y[tail-2],x[tail]-x[tail-2],y[tail]-y[tail-2]) > 0)
     return 1;
    else
     return -1;
}
int main(int argc, char *argv[])
{
    freopen("commando.in","r",stdin);
    freopen("commando.out","w",stdout);
    scanf("%d",&n);
    scanf("%d%d%d",&a,&b,&c);
    for(int i = 1;i<=n;i++)
     scanf("%d",&s[i]);
    for(int i = 1;i<=n;i++)
     s[i] = s[i-1]+s[i];
    tail++;head = tail;
    x[tail] = 0,y[tail] = 0;
    for(int i = 1;i<=n;i++)
    {
     while(tail-head+1>= 2 && comp(s[i],head)<0)
      head++;
     f[i] = -x[head]*s[i]+y[head]+a*s[i]*s[i]+b*s[i]+c;
     tail++;
     x[tail] = 2*a*s[i];y[tail] = f[i]+a*s[i]*s[i]-b*s[i];
     
     while(tail-head+1>=3  && comp2()<0)
     {
     swap(x[tail-1],x[tail]);
     swap(y[tail-1],y[tail]);
     tail--;
     }
    }
    printf("%d",f[n]);
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
