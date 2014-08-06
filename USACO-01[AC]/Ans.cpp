#include <cstdlib>
#include <iostream>

#define dump printf
#define dbig print
using namespace std;
typedef long long int64;
int64 pow(int64 x,int64 y)
{
      int64 ret = 1;
      for(int i = 1;i<=y;i++)
       ret = ret*x; 
      return ret;
}
int64 mod = 10000000;
int wei;
struct bignum
{
       int64 a[20001];
       int len;
       bignum()
       {
        memset(a,0,sizeof(a));
        len = 0;
       }
       bignum operator * (bignum x)
       {
              bignum tmp;
              for(int i = 1;i<=len;i++)
               for(int j = 1;j<=x.len;j++)
                tmp.a[i+j-1] += a[i]*x.a[j];
              tmp.len = len+x.len-1;
              for(int i = 1;i<=tmp.len;i++)
               if(tmp.a[i] >= mod){
                tmp.a[i+1] += tmp.a[i]/mod;
                tmp.a[i] %= mod;
                tmp.len = max(tmp.len,i+1);
               }
              return tmp;
       }
};
int64 n,p;
char str[300];
void itoa(char * a,int64 b,int64 c,int64 d)
{
     int l = 0;
     while(b != 0)
     {
      a[l] = b%c+d;
      l++;
      b /= c;
     }
}
int itoa2(int64 * a,int64 b,int64 c)
{
     int l = 1;
     while(b != 0)
     {
      a[l] = b%c;
      l++;
      b /= c;
     }
     return l;
}
bignum ans,base;
char buffer[200000];
void print(bignum a)
{
  char * pr = buffer;
  for(int i = a.len;i>=1;i--)
   for(int j = wei;j>=1;j--)
   {
    int64 x = pow(10,j);
    int64 y = x/10;
    x--;
    if((a.a[i]<=x && a.a[i] >= y)||(j==1&& a.a[i] == 0)){
     if(i != a.len)
     for(int z = wei;z>j;z--)
      sprintf(pr,"0"),pr++;
     sprintf(pr,"%I64d",a.a[i]);
     while(*pr != 0)
      pr++;
    }
   }
}
void printans()
{
     int po = 0;
     for(int i = 0;i<=strlen(buffer);i++)
     {
      printf("%c",buffer[i]);
      po++;
      if(po == 70){
       printf("\n");
       po = 0;
      }
     }
}
int main(int argc, char *argv[])
{
    freopen("cruel1.in","r",stdin);
    freopen("cruel1.out","w",stdout);
    mod *= 10;
    wei = 8;
    scanf("%I64d%I64d",&n,&p);
    itoa(str,p,2,'0');
  
    base.len = itoa2(base.a,n,mod)-1;
    ans.a[1] = 1;ans.len = 1;
    
    for(int i = strlen(str)-1;i>=0;i--){
     ans = ans*ans;
     if(str[i] == '1')
      ans = ans*base;
    }
    print(ans);printans();
    fclose(stdin);fclose(stdout);
    return EXIT_SUCCESS;
}
