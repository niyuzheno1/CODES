#include <cstdio>
#ifdef WIN32 
#define I64D "%I64d"
#else
#define I64D "%lld"
#endif
typedef long long int64;
int64 a[505];
int main(int argc, char *argv[])
{
    //setIO("sample");
    a[1] = 1;
    int k;
    for(int i = 2;i<=504;++i)
    {
     a[i] = a[i-1]+i*(i+1)/2;
     k = i-1;
     
     while(k > 0){
      a[i] += k/2+1;
      k -= (k/2+1)*2;
     }
    }
    scanf("%d",&k);
    while(~scanf("%d",&k)) printf(I64D,a[k]),puts("");
    //closeIO();
    return 0;
}
